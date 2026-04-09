# 1 "data/maps/TurnbackCave_Red/scripts.pory"

# 2 "data/maps/TurnbackCave_Red/scripts.pory"
.set LOCALID_PALKIA, 1
# 3 "data/maps/TurnbackCave_Red/scripts.pory"

# 4 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_MapScripts::
# 5 "data/maps/TurnbackCave_Red/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TurnbackCave_Red_OnResume
# 6 "data/maps/TurnbackCave_Red/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TurnbackCave_Red_OnTransition
# 7 "data/maps/TurnbackCave_Red/scripts.pory"
	.byte 0
# 8 "data/maps/TurnbackCave_Red/scripts.pory"

# 9 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_OnResume:
# 10 "data/maps/TurnbackCave_Red/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TurnbackCave_Red_EventScript_TryRemovePalkia
# 11 "data/maps/TurnbackCave_Red/scripts.pory"
	end
# 12 "data/maps/TurnbackCave_Red/scripts.pory"

# 13 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_EventScript_TryRemovePalkia::
# 14 "data/maps/TurnbackCave_Red/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/TurnbackCave_Red/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/TurnbackCave_Red/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/TurnbackCave_Red/scripts.pory"
	return
# 18 "data/maps/TurnbackCave_Red/scripts.pory"

# 19 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_OnTransition:
# 20 "data/maps/TurnbackCave_Red/scripts.pory"
	call_if_unset FLAG_DEFEATED_PALKIA, TurnbackCave_Red_EventScript_ShowPalkia
# 21 "data/maps/TurnbackCave_Red/scripts.pory"
	end
# 22 "data/maps/TurnbackCave_Red/scripts.pory"

# 23 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_EventScript_ShowPalkia::
# 24 "data/maps/TurnbackCave_Red/scripts.pory"
	clearflag FLAG_HIDE_PALKIA
# 25 "data/maps/TurnbackCave_Red/scripts.pory"
	return
# 26 "data/maps/TurnbackCave_Red/scripts.pory"

# 27 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_EventScript_Palkia::
# 28 "data/maps/TurnbackCave_Red/scripts.pory"
	lock
# 29 "data/maps/TurnbackCave_Red/scripts.pory"
	faceplayer
# 30 "data/maps/TurnbackCave_Red/scripts.pory"
	waitse
# 31 "data/maps/TurnbackCave_Red/scripts.pory"
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 32 "data/maps/TurnbackCave_Red/scripts.pory"
	delay 40
# 33 "data/maps/TurnbackCave_Red/scripts.pory"
	waitmoncry
# 34 "data/maps/TurnbackCave_Red/scripts.pory"
	setwildbattle SPECIES_PALKIA, 45
# 35 "data/maps/TurnbackCave_Red/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 36 "data/maps/TurnbackCave_Red/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 37 "data/maps/TurnbackCave_Red/scripts.pory"
	waitstate
# 38 "data/maps/TurnbackCave_Red/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 39 "data/maps/TurnbackCave_Red/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 40 "data/maps/TurnbackCave_Red/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TurnbackCave_Red_EventScript_DefeatedPalkia
# 41 "data/maps/TurnbackCave_Red/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TurnbackCave_Red_EventScript_RanFromPalkia
# 42 "data/maps/TurnbackCave_Red/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TurnbackCave_Red_EventScript_RanFromPalkia
# 43 "data/maps/TurnbackCave_Red/scripts.pory"
	setflag FLAG_DEFEATED_PALKIA
# 44 "data/maps/TurnbackCave_Red/scripts.pory"
	release
# 45 "data/maps/TurnbackCave_Red/scripts.pory"
	end
# 46 "data/maps/TurnbackCave_Red/scripts.pory"

# 47 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_EventScript_DefeatedPalkia::
# 48 "data/maps/TurnbackCave_Red/scripts.pory"
	setflag FLAG_DEFEATED_PALKIA
# 49 "data/maps/TurnbackCave_Red/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 50 "data/maps/TurnbackCave_Red/scripts.pory"
	end
# 51 "data/maps/TurnbackCave_Red/scripts.pory"

# 52 "data/maps/TurnbackCave_Red/scripts.pory"
TurnbackCave_Red_EventScript_RanFromPalkia::
# 53 "data/maps/TurnbackCave_Red/scripts.pory"
	setvar VAR_0x8004, SPECIES_PALKIA
# 54 "data/maps/TurnbackCave_Red/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 55 "data/maps/TurnbackCave_Red/scripts.pory"
	end
