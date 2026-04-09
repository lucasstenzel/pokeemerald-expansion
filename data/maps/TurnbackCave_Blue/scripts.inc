# 1 "data/maps/TurnbackCave_Blue/scripts.pory"

# 2 "data/maps/TurnbackCave_Blue/scripts.pory"
.set LOCALID_DIALGA, 1
# 3 "data/maps/TurnbackCave_Blue/scripts.pory"

# 4 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_MapScripts::
# 5 "data/maps/TurnbackCave_Blue/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TurnbackCave_Blue_OnResume
# 6 "data/maps/TurnbackCave_Blue/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TurnbackCave_Blue_OnTransition
# 7 "data/maps/TurnbackCave_Blue/scripts.pory"
	.byte 0
# 8 "data/maps/TurnbackCave_Blue/scripts.pory"

# 9 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_OnResume:
# 10 "data/maps/TurnbackCave_Blue/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TurnbackCave_Blue_EventScript_TryRemoveDialga
# 11 "data/maps/TurnbackCave_Blue/scripts.pory"
	end
# 12 "data/maps/TurnbackCave_Blue/scripts.pory"

# 13 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_EventScript_TryRemoveDialga::
# 14 "data/maps/TurnbackCave_Blue/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/TurnbackCave_Blue/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/TurnbackCave_Blue/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/TurnbackCave_Blue/scripts.pory"
	return
# 18 "data/maps/TurnbackCave_Blue/scripts.pory"

# 19 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_OnTransition:
# 20 "data/maps/TurnbackCave_Blue/scripts.pory"
	call_if_unset FLAG_DEFEATED_DIALGA, TurnbackCave_Blue_EventScript_ShowDialga
# 21 "data/maps/TurnbackCave_Blue/scripts.pory"
	end
# 22 "data/maps/TurnbackCave_Blue/scripts.pory"

# 23 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_EventScript_ShowDialga::
# 24 "data/maps/TurnbackCave_Blue/scripts.pory"
	clearflag FLAG_HIDE_DIALGA
# 25 "data/maps/TurnbackCave_Blue/scripts.pory"
	return
# 26 "data/maps/TurnbackCave_Blue/scripts.pory"

# 27 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_EventScript_Dialga::
# 28 "data/maps/TurnbackCave_Blue/scripts.pory"
	lock
# 29 "data/maps/TurnbackCave_Blue/scripts.pory"
	faceplayer
# 30 "data/maps/TurnbackCave_Blue/scripts.pory"
	waitse
# 31 "data/maps/TurnbackCave_Blue/scripts.pory"
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
# 32 "data/maps/TurnbackCave_Blue/scripts.pory"
	delay 40
# 33 "data/maps/TurnbackCave_Blue/scripts.pory"
	waitmoncry
# 34 "data/maps/TurnbackCave_Blue/scripts.pory"
	setwildbattle SPECIES_DIALGA, 45
# 35 "data/maps/TurnbackCave_Blue/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 36 "data/maps/TurnbackCave_Blue/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 37 "data/maps/TurnbackCave_Blue/scripts.pory"
	waitstate
# 38 "data/maps/TurnbackCave_Blue/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 39 "data/maps/TurnbackCave_Blue/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 40 "data/maps/TurnbackCave_Blue/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TurnbackCave_Blue_EventScript_DefeatedDialga
# 41 "data/maps/TurnbackCave_Blue/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TurnbackCave_Blue_EventScript_RanFromDialga
# 42 "data/maps/TurnbackCave_Blue/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TurnbackCave_Blue_EventScript_RanFromDialga
# 43 "data/maps/TurnbackCave_Blue/scripts.pory"
	setflag FLAG_DEFEATED_DIALGA
# 44 "data/maps/TurnbackCave_Blue/scripts.pory"
	release
# 45 "data/maps/TurnbackCave_Blue/scripts.pory"
	end
# 46 "data/maps/TurnbackCave_Blue/scripts.pory"

# 47 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_EventScript_DefeatedDialga::
# 48 "data/maps/TurnbackCave_Blue/scripts.pory"
	setflag FLAG_DEFEATED_DIALGA
# 49 "data/maps/TurnbackCave_Blue/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 50 "data/maps/TurnbackCave_Blue/scripts.pory"
	end
# 51 "data/maps/TurnbackCave_Blue/scripts.pory"

# 52 "data/maps/TurnbackCave_Blue/scripts.pory"
TurnbackCave_Blue_EventScript_RanFromDialga::
# 53 "data/maps/TurnbackCave_Blue/scripts.pory"
	setvar VAR_0x8004, SPECIES_DIALGA
# 54 "data/maps/TurnbackCave_Blue/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 55 "data/maps/TurnbackCave_Blue/scripts.pory"
	end
