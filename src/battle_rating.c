#include "global.h"
#include "battle.h"
#include "battle_rating.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "constants/flags.h"
#include "constants/species.h"

// Forward declarations for static functions
static u32 GetPlayerPartyHPPercentage(void);
static u32 CountLowHPPlayerMons(u32 thresholdPercent);

// Thresholds for "epic" battle detection (adjust as needed)
#define EPIC_MIN_TURNS              12
#define EPIC_MIN_PLAYER_FAINTS      3
#define EPIC_MIN_OPPONENT_FAINTS    4
#define EPIC_MIN_TOTAL_FAINTS       8
#define EPIC_PARTY_LOW_HP_THRESHOLD 100  // Percentage
#define EPIC_INDIVIDUAL_LOW_HP_THRESHOLD    25  // Percentage
#define EPIC_MIN_SWITCHES           2

// Point values for battle rating calculation
#define POINTS_PER_TURN             1
#define POINTS_PER_PLAYER_FAINT     3
#define POINTS_PER_OPPONENT_FAINT   2
#define POINTS_PER_SWITCH           1
#define POINTS_PER_HEALING_ITEM     2
#define POINTS_PER_REVIVE           3
#define POINTS_LOW_HP_SURVIVAL      5

// Threshold for epic battle rating
#define EPIC_BATTLE_THRESHOLD       40

// Check if the battle qualifies as "epic"
bool8 WasEpicBattle(void)
{
    // Long battle
    if (gBattleResults.battleTurnCounter < EPIC_MIN_TURNS)
        return FALSE;

    // Many faints on player side (hard-fought)
    if (gBattleResults.playerFaintCounter < EPIC_MIN_PLAYER_FAINTS)
        return FALSE;

    // Minimum opponent pokemon faints
    if (gBattleResults.opponentFaintCounter < EPIC_MIN_OPPONENT_FAINTS)
        return FALSE;

    // Total faints threshold
    u32 totalFaints = gBattleResults.playerFaintCounter + gBattleResults.opponentFaintCounter;
    if (totalFaints < EPIC_MIN_TOTAL_FAINTS)
        return FALSE;

    if (gBattleResults.playerSwitchesCounter < EPIC_MIN_SWITCHES)
       return FALSE;

    // Survived at very low HP
    if (GetPlayerPartyHPPercentage() > EPIC_PARTY_LOW_HP_THRESHOLD)
        return FALSE;

    return WasEpicBattleByRating();
}


// Calculate total remaining HP percentage for player's party
static u32 GetPlayerPartyHPPercentage(void)
{
    u32 i;
    u32 totalHP = 0;
    u32 totalMaxHP = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            totalHP += GetMonData(&gPlayerParty[i], MON_DATA_HP);
            totalMaxHP += GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
        }
    }

    if (totalMaxHP == 0)
        return 0;

    return (totalHP * 100) / totalMaxHP;
}

// Check if battle rating exceeds the epic threshold
bool8 WasEpicBattleByRating(void)
{
    return CalculateBattleRating() >= EPIC_BATTLE_THRESHOLD;
}

// Calculate a numerical battle rating based on various metrics
u32 CalculateBattleRating(void)
{
    u32 rating = 0;

    // Points for battle length
    rating += gBattleResults.battleTurnCounter * POINTS_PER_TURN;

    // Points for faints on both sides
    rating += gBattleResults.playerFaintCounter * POINTS_PER_PLAYER_FAINT;
    rating += gBattleResults.opponentFaintCounter * POINTS_PER_OPPONENT_FAINT;

    // Points for switches and item usage
    rating += gBattleResults.playerSwitchesCounter * POINTS_PER_SWITCH;
    rating += gBattleResults.numHealingItemsUsed * POINTS_PER_HEALING_ITEM;
    rating += gBattleResults.numRevivesUsed * POINTS_PER_REVIVE;

    // Additional points for each mon surviving at critical HP
    rating += CountLowHPPlayerMons(EPIC_INDIVIDUAL_LOW_HP_THRESHOLD) * POINTS_LOW_HP_SURVIVAL;

    return rating;
}

// Count how many player Pokemon are below a certain HP threshold
static u32 CountLowHPPlayerMons(u32 thresholdPercent)
{
    u32 i;
    u32 count = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (species != SPECIES_NONE)
        {
            u32 hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
            u32 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);

            if (hp > 0 && maxHP > 0)
            {
                u32 hpPercent = (hp * 100) / maxHP;
                if (hpPercent <= thresholdPercent)
                    count++;
            }
        }
    }

    return count;
}

// Get individual battle statistics for more granular checks
void GetBattleStatistics(struct BattleStatistics *stats)
{
    stats->turnCount = gBattleResults.battleTurnCounter;
    stats->playerFaints = gBattleResults.playerFaintCounter;
    stats->opponentFaints = gBattleResults.opponentFaintCounter;
    stats->playerSwitches = gBattleResults.playerSwitchesCounter;
    stats->healingItemsUsed = gBattleResults.numHealingItemsUsed;
    stats->revivesUsed = gBattleResults.numRevivesUsed;
    stats->playerHPPercent = GetPlayerPartyHPPercentage();
    stats->lowHPMonCount = CountLowHPPlayerMons(EPIC_INDIVIDUAL_LOW_HP_THRESHOLD);
}

// Pokemon available for release as roamers after epic battles
// Each entry has a species and a flag to track if it's been released
static const struct {
    u16 species;
    u16 flag;
} sEpicBattleRoamerPool[] = {
    { SPECIES_HEATRAN,    FLAG_EPIC_ROAMER_RELEASED_0 },
    { SPECIES_ARCEUS,     FLAG_EPIC_ROAMER_RELEASED_1 },
    { SPECIES_XERNEAS,    FLAG_EPIC_ROAMER_RELEASED_2 },
    { SPECIES_YVELTAL,    FLAG_EPIC_ROAMER_RELEASED_3 },
    { SPECIES_SOLGALEO,   FLAG_EPIC_ROAMER_RELEASED_4 },
    { SPECIES_LUNALA,     FLAG_EPIC_ROAMER_RELEASED_5 },
    { SPECIES_NECROZMA,   FLAG_EPIC_ROAMER_RELEASED_6 },
    { SPECIES_ZACIAN,     FLAG_EPIC_ROAMER_RELEASED_7 },
    { SPECIES_ZAMAZENTA,  FLAG_EPIC_ROAMER_RELEASED_8 },
};

#define EPIC_ROAMER_POOL_SIZE ARRAY_COUNT(sEpicBattleRoamerPool)
#define EPIC_ROAMER_LEVEL 45

// Try to release a random legendary from the pool as a roamer
// Returns TRUE if successful, FALSE if pool is empty or roamer slots full
bool8 TryReleaseRandomRoamer(void)
{
    // Require 5th gym badge
    if (!FlagGet(FLAG_BADGE05_GET))
        return FALSE;

    u32 i;
    u32 availableCount = 0;
    u32 availableIndices[EPIC_ROAMER_POOL_SIZE];

    // Build list of available (unreleased) legendaries
    for (i = 0; i < EPIC_ROAMER_POOL_SIZE; i++)
    {
        if (!FlagGet(sEpicBattleRoamerPool[i].flag))
        {
            availableIndices[availableCount] = i;
            availableCount++;
        }
    }

    // No legendaries left to release
    if (availableCount == 0)
        return FALSE;

    // Pick a random one from available
    u32 chosenIdx = availableIndices[Random() % availableCount];
    u16 species = sEpicBattleRoamerPool[chosenIdx].species;
    u16 flag = sEpicBattleRoamerPool[chosenIdx].flag;

    // Try to add as roamer
    if (TryAddRoamer(species, EPIC_ROAMER_LEVEL))
    {
        FlagSet(flag);  // Mark as released so it won't be picked again
        return TRUE;
    }

    return FALSE;
}
