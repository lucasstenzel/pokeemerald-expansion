# 1 "data/maps/TurnbackCave_Gray/scripts.pory"

# 2 "data/maps/TurnbackCave_Gray/scripts.pory"
.set LOCALID_GIRATINA, 1
# 3 "data/maps/TurnbackCave_Gray/scripts.pory"

# 4 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_MapScripts::
# 5 "data/maps/TurnbackCave_Gray/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TurnbackCave_Gray_OnResume
# 6 "data/maps/TurnbackCave_Gray/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TurnbackCave_Gray_OnTransition
# 7 "data/maps/TurnbackCave_Gray/scripts.pory"
	.byte 0
# 8 "data/maps/TurnbackCave_Gray/scripts.pory"

# 9 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_OnResume:
# 10 "data/maps/TurnbackCave_Gray/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TurnbackCave_Gray_EventScript_TryRemoveGiratina
# 11 "data/maps/TurnbackCave_Gray/scripts.pory"
	end
# 12 "data/maps/TurnbackCave_Gray/scripts.pory"

# 13 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_EventScript_TryRemoveGiratina::
# 14 "data/maps/TurnbackCave_Gray/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/TurnbackCave_Gray/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/TurnbackCave_Gray/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/TurnbackCave_Gray/scripts.pory"
	return
# 18 "data/maps/TurnbackCave_Gray/scripts.pory"

# 19 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_OnTransition:
# 20 "data/maps/TurnbackCave_Gray/scripts.pory"
	call_if_unset FLAG_DEFEATED_GIRATINA, TurnbackCave_Gray_EventScript_ShowGiratina
# 21 "data/maps/TurnbackCave_Gray/scripts.pory"
	end
# 22 "data/maps/TurnbackCave_Gray/scripts.pory"

# 23 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_EventScript_ShowGiratina::
# 24 "data/maps/TurnbackCave_Gray/scripts.pory"
	clearflag FLAG_HIDE_GIRATINA
# 25 "data/maps/TurnbackCave_Gray/scripts.pory"
	return
# 26 "data/maps/TurnbackCave_Gray/scripts.pory"

# 27 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_EventScript_Giratina::
# 28 "data/maps/TurnbackCave_Gray/scripts.pory"
	lock
# 29 "data/maps/TurnbackCave_Gray/scripts.pory"
	faceplayer
# 30 "data/maps/TurnbackCave_Gray/scripts.pory"
	waitse
# 31 "data/maps/TurnbackCave_Gray/scripts.pory"
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
# 32 "data/maps/TurnbackCave_Gray/scripts.pory"
	delay 40
# 33 "data/maps/TurnbackCave_Gray/scripts.pory"
	waitmoncry
# 34 "data/maps/TurnbackCave_Gray/scripts.pory"
	setwildbattle SPECIES_GIRATINA, 45
# 35 "data/maps/TurnbackCave_Gray/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 36 "data/maps/TurnbackCave_Gray/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 37 "data/maps/TurnbackCave_Gray/scripts.pory"
	waitstate
# 38 "data/maps/TurnbackCave_Gray/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 39 "data/maps/TurnbackCave_Gray/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 40 "data/maps/TurnbackCave_Gray/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TurnbackCave_Gray_EventScript_DefeatedGiratina
# 41 "data/maps/TurnbackCave_Gray/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TurnbackCave_Gray_EventScript_RanFromGiratina
# 42 "data/maps/TurnbackCave_Gray/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TurnbackCave_Gray_EventScript_RanFromGiratina
# 43 "data/maps/TurnbackCave_Gray/scripts.pory"
	setflag FLAG_DEFEATED_GIRATINA
# 44 "data/maps/TurnbackCave_Gray/scripts.pory"
	release
# 45 "data/maps/TurnbackCave_Gray/scripts.pory"
	end
# 46 "data/maps/TurnbackCave_Gray/scripts.pory"

# 47 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_EventScript_DefeatedGiratina::
# 48 "data/maps/TurnbackCave_Gray/scripts.pory"
	setflag FLAG_DEFEATED_GIRATINA
# 49 "data/maps/TurnbackCave_Gray/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 50 "data/maps/TurnbackCave_Gray/scripts.pory"
	end
# 51 "data/maps/TurnbackCave_Gray/scripts.pory"

# 52 "data/maps/TurnbackCave_Gray/scripts.pory"
TurnbackCave_Gray_EventScript_RanFromGiratina::
# 53 "data/maps/TurnbackCave_Gray/scripts.pory"
	setvar VAR_0x8004, SPECIES_GIRATINA
# 54 "data/maps/TurnbackCave_Gray/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 55 "data/maps/TurnbackCave_Gray/scripts.pory"
	end
