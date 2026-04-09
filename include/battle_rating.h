#ifndef GUARD_BATTLE_RATING_H
#define GUARD_BATTLE_RATING_H

struct BattleStatistics
{
    u8 turnCount;
    u8 playerFaints;
    u8 opponentFaints;
    u8 playerSwitches;
    u8 healingItemsUsed;
    u8 revivesUsed;
    u8 playerHPPercent;
    u8 lowHPMonCount;
};

// Calculate a numerical battle rating (higher = more epic)
u32 CalculateBattleRating(void);

// Returns TRUE if the battle was "epic" based on simple thresholds
bool8 WasEpicBattle(void);

// Returns TRUE if battle rating exceeds the epic threshold
bool8 WasEpicBattleByRating(void);

// Fill a BattleStatistics struct with current battle data
void GetBattleStatistics(struct BattleStatistics *stats);

// Try to release a random legendary from the pool as a roamer
// Returns TRUE if successful, FALSE if pool is empty or roamer slots full
bool8 TryReleaseRandomRoamer(void);

#endif // GUARD_BATTLE_RATING_H
