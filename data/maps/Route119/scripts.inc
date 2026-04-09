# 1 "data/maps/Route119/scripts.pory"

# 2 "data/maps/Route119/scripts.pory"
.set LOCALID_RIVAL, 16
# 3 "data/maps/Route119/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 25
# 4 "data/maps/Route119/scripts.pory"
.set LOCALID_SCOTT, 43
# 5 "data/maps/Route119/scripts.pory"

# 6 "data/maps/Route119/scripts.pory"
Route119_MapScripts::
# 7 "data/maps/Route119/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
# 8 "data/maps/Route119/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
# 9 "data/maps/Route119/scripts.pory"
	.byte 0
# 10 "data/maps/Route119/scripts.pory"

# 11 "data/maps/Route119/scripts.pory"
Route119_OnResume:
# 12 "data/maps/Route119/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
# 13 "data/maps/Route119/scripts.pory"
	end
# 14 "data/maps/Route119/scripts.pory"

# 15 "data/maps/Route119/scripts.pory"
Route119_EventScript_TryRemoveKecleon::
# 16 "data/maps/Route119/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 17 "data/maps/Route119/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 18 "data/maps/Route119/scripts.pory"
	removeobject VAR_LAST_TALKED
# 19 "data/maps/Route119/scripts.pory"
	return
# 20 "data/maps/Route119/scripts.pory"

# 21 "data/maps/Route119/scripts.pory"
Route119_OnTransition:
# 22 "data/maps/Route119/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 23 "data/maps/Route119/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 24 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
# 25 "data/maps/Route119/scripts.pory"
	call_if_unset FLAG_DEFEATED_ZAPDOS_GALARIAN, Route119_EventScript_ShowZapdosGalar
# 26 "data/maps/Route119/scripts.pory"
	end
# 27 "data/maps/Route119/scripts.pory"

# 28 "data/maps/Route119/scripts.pory"
Route119_EventScript_ShowZapdosGalar::
# 29 "data/maps/Route119/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS_GALARIAN
# 30 "data/maps/Route119/scripts.pory"
	return
# 31 "data/maps/Route119/scripts.pory"

# 32 "data/maps/Route119/scripts.pory"
Route119_EventScript_ZapdosGalar::
# 33 "data/maps/Route119/scripts.pory"
	lock
# 34 "data/maps/Route119/scripts.pory"
	faceplayer
# 35 "data/maps/Route119/scripts.pory"
	waitse
# 36 "data/maps/Route119/scripts.pory"
	playmoncry SPECIES_ZAPDOS_GALAR, CRY_MODE_ENCOUNTER
# 37 "data/maps/Route119/scripts.pory"
	delay 40
# 38 "data/maps/Route119/scripts.pory"
	waitmoncry
# 39 "data/maps/Route119/scripts.pory"
	setwildbattle SPECIES_ZAPDOS_GALAR, 70
# 40 "data/maps/Route119/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 41 "data/maps/Route119/scripts.pory"
	special StartRegiBattle
# 42 "data/maps/Route119/scripts.pory"
	waitstate
# 43 "data/maps/Route119/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 44 "data/maps/Route119/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 45 "data/maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route119_EventScript_DefeatedZapdosGalar
# 46 "data/maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route119_EventScript_RanFromZapdosGalar
# 47 "data/maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route119_EventScript_RanFromZapdosGalar
# 48 "data/maps/Route119/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS_GALARIAN
# 49 "data/maps/Route119/scripts.pory"
	release
# 50 "data/maps/Route119/scripts.pory"
	end
# 51 "data/maps/Route119/scripts.pory"

# 52 "data/maps/Route119/scripts.pory"
Route119_EventScript_DefeatedZapdosGalar::
# 53 "data/maps/Route119/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS_GALARIAN
# 54 "data/maps/Route119/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 55 "data/maps/Route119/scripts.pory"
	end
# 56 "data/maps/Route119/scripts.pory"

# 57 "data/maps/Route119/scripts.pory"
Route119_EventScript_RanFromZapdosGalar::
# 58 "data/maps/Route119/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS_GALAR
# 59 "data/maps/Route119/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 60 "data/maps/Route119/scripts.pory"
	end
# 61 "data/maps/Route119/scripts.pory"

# 62 "data/maps/Route119/scripts.pory"
Route119_EventScript_MoveInstituteWorkersDownstairs::
# 63 "data/maps/Route119/scripts.pory"
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
# 64 "data/maps/Route119/scripts.pory"
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
# 65 "data/maps/Route119/scripts.pory"
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
# 66 "data/maps/Route119/scripts.pory"
	return
# 67 "data/maps/Route119/scripts.pory"

# 68 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger1::
# 69 "data/maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 1
# 70 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 71 "data/maps/Route119/scripts.pory"
	end
# 72 "data/maps/Route119/scripts.pory"

# 73 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalTrigger2::
# 74 "data/maps/Route119/scripts.pory"
	setvar VAR_TEMP_1, 2
# 75 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalEncounter
# 76 "data/maps/Route119/scripts.pory"
	end
# 77 "data/maps/Route119/scripts.pory"

# 78 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalEncounter::
# 79 "data/maps/Route119/scripts.pory"
	lockall
# 80 "data/maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 81 "data/maps/Route119/scripts.pory"
	checkplayergender
# 82 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
# 83 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
# 84 "data/maps/Route119/scripts.pory"
	delay 65
# 85 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
# 86 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
# 87 "data/maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 88 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 89 "data/maps/Route119/scripts.pory"
	delay 30
# 90 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 91 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 92 "data/maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 93 "data/maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL
# 94 "data/maps/Route119/scripts.pory"
	delay 30
# 95 "data/maps/Route119/scripts.pory"
	checkplayergender
# 96 "data/maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
# 97 "data/maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
# 98 "data/maps/Route119/scripts.pory"
	releaseall
# 99 "data/maps/Route119/scripts.pory"
	end
# 100 "data/maps/Route119/scripts.pory"

# 101 "data/maps/Route119/scripts.pory"
Route119_EventScript_PlayMayMusic::
# 102 "data/maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 103 "data/maps/Route119/scripts.pory"
	return
# 104 "data/maps/Route119/scripts.pory"

# 105 "data/maps/Route119/scripts.pory"
Route119_EventScript_PlayBrendanMusic::
# 106 "data/maps/Route119/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 107 "data/maps/Route119/scripts.pory"
	return
# 108 "data/maps/Route119/scripts.pory"

# 109 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleMay::
# 110 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
# 111 "data/maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 112 "data/maps/Route119/scripts.pory"
	case 0, Route119_EventScript_BattleMayTreecko
# 113 "data/maps/Route119/scripts.pory"
	case 1, Route119_EventScript_BattleMayTorchic
# 114 "data/maps/Route119/scripts.pory"
	case 2, Route119_EventScript_BattleMayMudkip
# 115 "data/maps/Route119/scripts.pory"
	case 3, Route119_EventScript_BattleMayGible
# 116 "data/maps/Route119/scripts.pory"
	end
# 117 "data/maps/Route119/scripts.pory"

# 118 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleMayTreecko::
# 119 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
# 120 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 121 "data/maps/Route119/scripts.pory"
	end
# 122 "data/maps/Route119/scripts.pory"

# 123 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleMayTorchic::
# 124 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
# 125 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 126 "data/maps/Route119/scripts.pory"
	end
# 127 "data/maps/Route119/scripts.pory"

# 128 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleMayMudkip::
# 129 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
# 130 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 131 "data/maps/Route119/scripts.pory"
	end
# 132 "data/maps/Route119/scripts.pory"

# 133 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleMayGible::
# 134 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_GIBLE, Route119_Text_MayDefeat
# 135 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedMay
# 136 "data/maps/Route119/scripts.pory"
	end
# 137 "data/maps/Route119/scripts.pory"

# 138 "data/maps/Route119/scripts.pory"
Route119_EventScript_DefeatedMay::
# 139 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
# 140 "data/maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 141 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
# 142 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 143 "data/maps/Route119/scripts.pory"
	end
# 144 "data/maps/Route119/scripts.pory"

# 145 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendan::
# 146 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
# 147 "data/maps/Route119/scripts.pory"
	switch VAR_STARTER_MON
# 148 "data/maps/Route119/scripts.pory"
	case 0, Route119_EventScript_BattleBrendanTreecko
# 149 "data/maps/Route119/scripts.pory"
	case 1, Route119_EventScript_BattleBrendanTorchic
# 150 "data/maps/Route119/scripts.pory"
	case 2, Route119_EventScript_BattleBrendanMudkip
# 151 "data/maps/Route119/scripts.pory"
	case 3, Route119_EventScript_BattleBrendanGible
# 152 "data/maps/Route119/scripts.pory"
	end
# 153 "data/maps/Route119/scripts.pory"

# 154 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanTreecko::
# 155 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
# 156 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 157 "data/maps/Route119/scripts.pory"
	end
# 158 "data/maps/Route119/scripts.pory"

# 159 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanTorchic::
# 160 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
# 161 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 162 "data/maps/Route119/scripts.pory"
	end
# 163 "data/maps/Route119/scripts.pory"

# 164 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanMudkip::
# 165 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
# 166 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 167 "data/maps/Route119/scripts.pory"
	end
# 168 "data/maps/Route119/scripts.pory"

# 169 "data/maps/Route119/scripts.pory"
Route119_EventScript_BattleBrendanGible::
# 170 "data/maps/Route119/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_GIBLE, Route119_Text_BrendanDefeat
# 171 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_DefeatedBrendan
# 172 "data/maps/Route119/scripts.pory"
	end
# 173 "data/maps/Route119/scripts.pory"

# 174 "data/maps/Route119/scripts.pory"
Route119_EventScript_DefeatedBrendan::
# 175 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
# 176 "data/maps/Route119/scripts.pory"
	call Route119_EventScript_GiveFlyHM
# 177 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
# 178 "data/maps/Route119/scripts.pory"
	goto Route119_EventScript_RivalExitScottArrive
# 179 "data/maps/Route119/scripts.pory"
	end
# 180 "data/maps/Route119/scripts.pory"

# 181 "data/maps/Route119/scripts.pory"
Route119_EventScript_GiveFlyHM::
# 182 "data/maps/Route119/scripts.pory"
	giveitem ITEM_LIFE_ORB
# 183 "data/maps/Route119/scripts.pory"
	giveitem ITEM_HEAVY_DUTY_BOOTS
# 184 "data/maps/Route119/scripts.pory"
	giveitem ITEM_LEFTOVERS
# 185 "data/maps/Route119/scripts.pory"
	giveitem ITEM_PP_MAX, 999
# 186 "data/maps/Route119/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLY
# 187 "data/maps/Route119/scripts.pory"
	return
# 188 "data/maps/Route119/scripts.pory"

# 189 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalExitScottArrive::
# 190 "data/maps/Route119/scripts.pory"
	closemessage
# 191 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
# 192 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
# 193 "data/maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL
# 194 "data/maps/Route119/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 195 "data/maps/Route119/scripts.pory"
	delay 30
# 196 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
# 197 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
# 198 "data/maps/Route119/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 199 "data/maps/Route119/scripts.pory"
	setvar VAR_ROUTE119_STATE, 1
# 200 "data/maps/Route119/scripts.pory"
	savebgm MUS_DUMMY
# 201 "data/maps/Route119/scripts.pory"
	fadedefaultbgm
# 202 "data/maps/Route119/scripts.pory"
	delay 60
# 203 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
# 204 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
# 205 "data/maps/Route119/scripts.pory"
	addobject LOCALID_SCOTT
# 206 "data/maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
# 207 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 208 "data/maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 209 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
# 210 "data/maps/Route119/scripts.pory"
	closemessage
# 211 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
# 212 "data/maps/Route119/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
# 213 "data/maps/Route119/scripts.pory"
	removeobject LOCALID_SCOTT
# 214 "data/maps/Route119/scripts.pory"
	delay 30
# 215 "data/maps/Route119/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 216 "data/maps/Route119/scripts.pory"
	specialvar VAR_0x8006, GetLevelCapForText
# 217 "data/maps/Route119/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_0x8006
# 218 "data/maps/Route119/scripts.pory"
	msgbox LevelCapIncreasedTo, MSGBOX_DEFAULT
# 219 "data/maps/Route119/scripts.pory"
	waitfanfare
# 220 "data/maps/Route119/scripts.pory"
	closemessage
# 221 "data/maps/Route119/scripts.pory"
	delay 30
# 222 "data/maps/Route119/scripts.pory"
	releaseall
# 223 "data/maps/Route119/scripts.pory"
	end
# 224 "data/maps/Route119/scripts.pory"

# 225 "data/maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos1::
# 226 "data/maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 27, 25
# 227 "data/maps/Route119/scripts.pory"
	return
# 228 "data/maps/Route119/scripts.pory"

# 229 "data/maps/Route119/scripts.pory"
Route119_EventScript_SetScottPos2::
# 230 "data/maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 28, 25
# 231 "data/maps/Route119/scripts.pory"
	return
# 232 "data/maps/Route119/scripts.pory"

# 233 "data/maps/Route119/scripts.pory"
Route119_EventScript_ScottExit1::
# 234 "data/maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
# 235 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 236 "data/maps/Route119/scripts.pory"
	return
# 237 "data/maps/Route119/scripts.pory"

# 238 "data/maps/Route119/scripts.pory"
Route119_EventScript_ScottExit2::
# 239 "data/maps/Route119/scripts.pory"
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
# 240 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 241 "data/maps/Route119/scripts.pory"
	return
# 242 "data/maps/Route119/scripts.pory"

# 243 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter1::
# 244 "data/maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
# 245 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 246 "data/maps/Route119/scripts.pory"
	return
# 247 "data/maps/Route119/scripts.pory"

# 248 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalEnter2::
# 249 "data/maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
# 250 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 251 "data/maps/Route119/scripts.pory"
	return
# 252 "data/maps/Route119/scripts.pory"

# 253 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalExit1::
# 254 "data/maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
# 255 "data/maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
# 256 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 257 "data/maps/Route119/scripts.pory"
	return
# 258 "data/maps/Route119/scripts.pory"

# 259 "data/maps/Route119/scripts.pory"
Route119_EventScript_RivalExit2::
# 260 "data/maps/Route119/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
# 261 "data/maps/Route119/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
# 262 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 263 "data/maps/Route119/scripts.pory"
	return
# 264 "data/maps/Route119/scripts.pory"

# 265 "data/maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos1::
# 266 "data/maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 25, 32
# 267 "data/maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
# 268 "data/maps/Route119/scripts.pory"
	return
# 269 "data/maps/Route119/scripts.pory"

# 270 "data/maps/Route119/scripts.pory"
Route119_EventScript_SetRivalPos2::
# 271 "data/maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 26, 32
# 272 "data/maps/Route119/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
# 273 "data/maps/Route119/scripts.pory"
	return
# 274 "data/maps/Route119/scripts.pory"

# 275 "data/maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit1:
# 276 "data/maps/Route119/scripts.pory"
	delay_16
# 277 "data/maps/Route119/scripts.pory"
	walk_in_place_faster_right
# 278 "data/maps/Route119/scripts.pory"
	delay_8
# 279 "data/maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 280 "data/maps/Route119/scripts.pory"
	step_end
# 281 "data/maps/Route119/scripts.pory"

# 282 "data/maps/Route119/scripts.pory"
Route119_Movement_PlayerWatchRivalExit2:
# 283 "data/maps/Route119/scripts.pory"
	delay_16
# 284 "data/maps/Route119/scripts.pory"
	walk_in_place_faster_left
# 285 "data/maps/Route119/scripts.pory"
	delay_8
# 286 "data/maps/Route119/scripts.pory"
	walk_in_place_faster_up
# 287 "data/maps/Route119/scripts.pory"
	step_end
# 288 "data/maps/Route119/scripts.pory"

# 289 "data/maps/Route119/scripts.pory"
Route119_Movement_RivalEnter1:
# 290 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 291 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 292 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 293 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 294 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 295 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 296 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 297 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 298 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 299 "data/maps/Route119/scripts.pory"
	step_end
# 300 "data/maps/Route119/scripts.pory"

# 301 "data/maps/Route119/scripts.pory"
Route119_Movement_RivalEnter2:
# 302 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 303 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 304 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 305 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 306 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 307 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 308 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 309 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 310 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 311 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 312 "data/maps/Route119/scripts.pory"
	step_end
# 313 "data/maps/Route119/scripts.pory"

# 314 "data/maps/Route119/scripts.pory"
Route119_Movement_RivalExit1:
# 315 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 316 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 317 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 318 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 319 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 320 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 321 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 322 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 323 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 324 "data/maps/Route119/scripts.pory"
	step_end
# 325 "data/maps/Route119/scripts.pory"

# 326 "data/maps/Route119/scripts.pory"
Route119_Movement_RivalExit2:
# 327 "data/maps/Route119/scripts.pory"
	walk_fast_left
# 328 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 329 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 330 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 331 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 332 "data/maps/Route119/scripts.pory"
	walk_fast_right
# 333 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 334 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 335 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 336 "data/maps/Route119/scripts.pory"
	walk_fast_up
# 337 "data/maps/Route119/scripts.pory"
	step_end
# 338 "data/maps/Route119/scripts.pory"

# 339 "data/maps/Route119/scripts.pory"
Route119_Movement_ScottEnter:
# 340 "data/maps/Route119/scripts.pory"
	walk_down
# 341 "data/maps/Route119/scripts.pory"
	walk_down
# 342 "data/maps/Route119/scripts.pory"
	walk_down
# 343 "data/maps/Route119/scripts.pory"
	walk_down
# 344 "data/maps/Route119/scripts.pory"
	walk_left
# 345 "data/maps/Route119/scripts.pory"
	walk_left
# 346 "data/maps/Route119/scripts.pory"
	walk_down
# 347 "data/maps/Route119/scripts.pory"
	step_end
# 348 "data/maps/Route119/scripts.pory"

# 349 "data/maps/Route119/scripts.pory"
Route119_Movement_ScottExit1:
# 350 "data/maps/Route119/scripts.pory"
	walk_up
# 351 "data/maps/Route119/scripts.pory"
	walk_right
# 352 "data/maps/Route119/scripts.pory"
	walk_right
# 353 "data/maps/Route119/scripts.pory"
	walk_up
# 354 "data/maps/Route119/scripts.pory"
	walk_up
# 355 "data/maps/Route119/scripts.pory"
	walk_up
# 356 "data/maps/Route119/scripts.pory"
	walk_up
# 357 "data/maps/Route119/scripts.pory"
	walk_up
# 358 "data/maps/Route119/scripts.pory"
	step_end
# 359 "data/maps/Route119/scripts.pory"

# 360 "data/maps/Route119/scripts.pory"
Route119_Movement_ScottExit2:
# 361 "data/maps/Route119/scripts.pory"
	walk_up
# 362 "data/maps/Route119/scripts.pory"
	walk_right
# 363 "data/maps/Route119/scripts.pory"
	walk_up
# 364 "data/maps/Route119/scripts.pory"
	walk_up
# 365 "data/maps/Route119/scripts.pory"
	walk_up
# 366 "data/maps/Route119/scripts.pory"
	walk_up
# 367 "data/maps/Route119/scripts.pory"
	walk_up
# 368 "data/maps/Route119/scripts.pory"
	step_end
# 369 "data/maps/Route119/scripts.pory"

# 370 "data/maps/Route119/scripts.pory"
Route119_EventScript_CyclingTriathleteM::
# 371 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
# 372 "data/maps/Route119/scripts.pory"
	end
# 373 "data/maps/Route119/scripts.pory"

# 374 "data/maps/Route119/scripts.pory"
Route119_EventScript_RouteSignFortree::
# 375 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
# 376 "data/maps/Route119/scripts.pory"
	end
# 377 "data/maps/Route119/scripts.pory"

# 378 "data/maps/Route119/scripts.pory"
Route119_EventScript_WeatherInstituteSign::
# 379 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
# 380 "data/maps/Route119/scripts.pory"
	end
# 381 "data/maps/Route119/scripts.pory"

# 382 "data/maps/Route119/scripts.pory"
Route119_EventScript_Brent::
# 383 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
# 384 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
# 385 "data/maps/Route119/scripts.pory"
	end
# 386 "data/maps/Route119/scripts.pory"

# 387 "data/maps/Route119/scripts.pory"
Route119_EventScript_Donald::
# 388 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
# 389 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
# 390 "data/maps/Route119/scripts.pory"
	end
# 391 "data/maps/Route119/scripts.pory"

# 392 "data/maps/Route119/scripts.pory"
Route119_EventScript_Taylor::
# 393 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
# 394 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
# 395 "data/maps/Route119/scripts.pory"
	end
# 396 "data/maps/Route119/scripts.pory"

# 397 "data/maps/Route119/scripts.pory"
Route119_EventScript_Doug::
# 398 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
# 399 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 400 "data/maps/Route119/scripts.pory"
	end
# 401 "data/maps/Route119/scripts.pory"

# 402 "data/maps/Route119/scripts.pory"
Route119_EventScript_Greg::
# 403 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
# 404 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
# 405 "data/maps/Route119/scripts.pory"
	end
# 406 "data/maps/Route119/scripts.pory"

# 407 "data/maps/Route119/scripts.pory"
Route119_EventScript_Kent::
# 408 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
# 409 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
# 410 "data/maps/Route119/scripts.pory"
	end
# 411 "data/maps/Route119/scripts.pory"

# 412 "data/maps/Route119/scripts.pory"
Route119_EventScript_Jackson::
# 413 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
# 414 "data/maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 415 "data/maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
# 416 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
# 417 "data/maps/Route119/scripts.pory"
	release
# 418 "data/maps/Route119/scripts.pory"
	end
# 419 "data/maps/Route119/scripts.pory"

# 420 "data/maps/Route119/scripts.pory"
Route119_EventScript_RegisterJackson::
# 421 "data/maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 422 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 423 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
# 424 "data/maps/Route119/scripts.pory"
	register_matchcall TRAINER_JACKSON_1
# 425 "data/maps/Route119/scripts.pory"
	release
# 426 "data/maps/Route119/scripts.pory"
	end
# 427 "data/maps/Route119/scripts.pory"

# 428 "data/maps/Route119/scripts.pory"
Route119_EventScript_RematchJackson::
# 429 "data/maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
# 430 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
# 431 "data/maps/Route119/scripts.pory"
	end
# 432 "data/maps/Route119/scripts.pory"

# 433 "data/maps/Route119/scripts.pory"
Route119_EventScript_Catherine::
# 434 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
# 435 "data/maps/Route119/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 436 "data/maps/Route119/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
# 437 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
# 438 "data/maps/Route119/scripts.pory"
	release
# 439 "data/maps/Route119/scripts.pory"
	end
# 440 "data/maps/Route119/scripts.pory"

# 441 "data/maps/Route119/scripts.pory"
Route119_EventScript_RegisterCatherine::
# 442 "data/maps/Route119/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 443 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 444 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
# 445 "data/maps/Route119/scripts.pory"
	register_matchcall TRAINER_CATHERINE_1
# 446 "data/maps/Route119/scripts.pory"
	release
# 447 "data/maps/Route119/scripts.pory"
	end
# 448 "data/maps/Route119/scripts.pory"

# 449 "data/maps/Route119/scripts.pory"
Route119_EventScript_RematchCatherine::
# 450 "data/maps/Route119/scripts.pory"
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
# 451 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
# 452 "data/maps/Route119/scripts.pory"
	end
# 453 "data/maps/Route119/scripts.pory"

# 454 "data/maps/Route119/scripts.pory"
Route119_EventScript_Hugh::
# 455 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
# 456 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
# 457 "data/maps/Route119/scripts.pory"
	end
# 458 "data/maps/Route119/scripts.pory"

# 459 "data/maps/Route119/scripts.pory"
Route119_EventScript_Phil::
# 460 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
# 461 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
# 462 "data/maps/Route119/scripts.pory"
	end
# 463 "data/maps/Route119/scripts.pory"

# 464 "data/maps/Route119/scripts.pory"
Route119_EventScript_Yasu::
# 465 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
# 466 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
# 467 "data/maps/Route119/scripts.pory"
	end
# 468 "data/maps/Route119/scripts.pory"

# 469 "data/maps/Route119/scripts.pory"
Route119_EventScript_Takashi::
# 470 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
# 471 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
# 472 "data/maps/Route119/scripts.pory"
	end
# 473 "data/maps/Route119/scripts.pory"

# 474 "data/maps/Route119/scripts.pory"
Route119_EventScript_Hideo::
# 475 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
# 476 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
# 477 "data/maps/Route119/scripts.pory"
	end
# 478 "data/maps/Route119/scripts.pory"

# 479 "data/maps/Route119/scripts.pory"
Route119_EventScript_Chris::
# 480 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
# 481 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
# 482 "data/maps/Route119/scripts.pory"
	end
# 483 "data/maps/Route119/scripts.pory"

# 484 "data/maps/Route119/scripts.pory"
Route119_EventScript_Fabian::
# 485 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
# 486 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
# 487 "data/maps/Route119/scripts.pory"
	end
# 488 "data/maps/Route119/scripts.pory"

# 489 "data/maps/Route119/scripts.pory"
Route119_EventScript_Dayton::
# 490 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
# 491 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
# 492 "data/maps/Route119/scripts.pory"
	end
# 493 "data/maps/Route119/scripts.pory"

# 494 "data/maps/Route119/scripts.pory"
Route119_EventScript_Raquel::
# 495 "data/maps/Route119/scripts.pory"
	trainerbattle_single TRAINER_RAQUEL, Route119_Text_RaquelIntro, Route119_Text_RaquelDefeat
# 496 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_RaquelPostBattle, MSGBOX_AUTOCLOSE
# 497 "data/maps/Route119/scripts.pory"
	end
# 498 "data/maps/Route119/scripts.pory"

# 499 "data/maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt1::
# 500 "data/maps/Route119/scripts.pory"
	lock
# 501 "data/maps/Route119/scripts.pory"
	faceplayer
# 502 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
# 503 "data/maps/Route119/scripts.pory"
	closemessage
# 504 "data/maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 505 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 506 "data/maps/Route119/scripts.pory"
	release
# 507 "data/maps/Route119/scripts.pory"
	end
# 508 "data/maps/Route119/scripts.pory"

# 509 "data/maps/Route119/scripts.pory"
Route119_EventScript_BridgeAquaGrunt2::
# 510 "data/maps/Route119/scripts.pory"
	lock
# 511 "data/maps/Route119/scripts.pory"
	faceplayer
# 512 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
# 513 "data/maps/Route119/scripts.pory"
	closemessage
# 514 "data/maps/Route119/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 515 "data/maps/Route119/scripts.pory"
	waitmovement 0
# 516 "data/maps/Route119/scripts.pory"
	release
# 517 "data/maps/Route119/scripts.pory"
	end
# 518 "data/maps/Route119/scripts.pory"

# 519 "data/maps/Route119/scripts.pory"
Route119_EventScript_Boy1::
# 520 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
# 521 "data/maps/Route119/scripts.pory"
	end
# 522 "data/maps/Route119/scripts.pory"

# 523 "data/maps/Route119/scripts.pory"
Route119_EventScript_Boy2::
# 524 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
# 525 "data/maps/Route119/scripts.pory"
	end
# 526 "data/maps/Route119/scripts.pory"

# 527 "data/maps/Route119/scripts.pory"
Route119_EventScript_TrainerTipsDecoration::
# 528 "data/maps/Route119/scripts.pory"
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
# 529 "data/maps/Route119/scripts.pory"
	end
# 530 "data/maps/Route119/scripts.pory"

# 531 "data/maps/Route119/scripts.pory"
Route119_EventScript_ScottWonAtFortreeGymCall::
# 532 "data/maps/Route119/scripts.pory"
	lockall
# 533 "data/maps/Route119/scripts.pory"
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
# 534 "data/maps/Route119/scripts.pory"
	waitmessage
# 535 "data/maps/Route119/scripts.pory"
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
# 536 "data/maps/Route119/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 537 "data/maps/Route119/scripts.pory"
	releaseall
# 538 "data/maps/Route119/scripts.pory"
	end
# 539 "data/maps/Route119/scripts.pory"

# 540 "data/maps/Route119/scripts.pory"
Route119_Text_MayIntro:
# 541 "data/maps/Route119/scripts.pory"
	.string "May: {PLAYER}{KUN}!\n"
# 542 "data/maps/Route119/scripts.pory"
	.string "Where were you? I was looking for you!\p"
# 543 "data/maps/Route119/scripts.pory"
	.string "How much stronger have you gotten?\n"
# 544 "data/maps/Route119/scripts.pory"
	.string "Let me check for you!\p"
# 545 "data/maps/Route119/scripts.pory"
	.string "Ready with your Pokémon?\n"
# 546 "data/maps/Route119/scripts.pory"
	.string "Of course you are! Go!$"
# 547 "data/maps/Route119/scripts.pory"

# 548 "data/maps/Route119/scripts.pory"
Route119_Text_MayDefeat:
# 549 "data/maps/Route119/scripts.pory"
	.string "Achah!\n"
# 550 "data/maps/Route119/scripts.pory"
	.string "{PLAYER}{KUN}, you're strong!\p"
# 551 "data/maps/Route119/scripts.pory"
	.string "I was worried that you might be\n"
# 552 "data/maps/Route119/scripts.pory"
	.string "struggling with your training.$"
# 553 "data/maps/Route119/scripts.pory"

# 554 "data/maps/Route119/scripts.pory"
Route119_Text_MayPresentForYou:
# 555 "data/maps/Route119/scripts.pory"
	.string "May: But I had absolutely nothing to\n"
# 556 "data/maps/Route119/scripts.pory"
	.string "worry about! Keep it up!\p"
# 557 "data/maps/Route119/scripts.pory"
	.string "And, here! I have a present for you.$"
# 558 "data/maps/Route119/scripts.pory"

# 559 "data/maps/Route119/scripts.pory"
Route119_Text_MayExplainFly:
# 560 "data/maps/Route119/scripts.pory"
	.string "Some pretty decent battle items, if I\n"
# 561 "data/maps/Route119/scripts.pory"
	.string "do say so myself! Keep going, {PLAYER},\l"
# 562 "data/maps/Route119/scripts.pory"
	.string "you're raising your Pokémon really well.$"
# 563 "data/maps/Route119/scripts.pory"

# 564 "data/maps/Route119/scripts.pory"
Route119_Text_BrendanIntro:
# 565 "data/maps/Route119/scripts.pory"
	.string "Brendan: {PLAYER}! So this is where\n"
# 566 "data/maps/Route119/scripts.pory"
	.string "you've been looking for Pokémon?\p"
# 567 "data/maps/Route119/scripts.pory"
	.string "Let me see how good you got.\n"
# 568 "data/maps/Route119/scripts.pory"
	.string "I'll test you!\p"
# 569 "data/maps/Route119/scripts.pory"
	.string "Now!\n"
# 570 "data/maps/Route119/scripts.pory"
	.string "It's a battle, so battle!$"
# 571 "data/maps/Route119/scripts.pory"

# 572 "data/maps/Route119/scripts.pory"
Route119_Text_BrendanDefeat:
# 573 "data/maps/Route119/scripts.pory"
	.string "Hmm…\n"
# 574 "data/maps/Route119/scripts.pory"
	.string "You've gotten pretty darn decent.$"
# 575 "data/maps/Route119/scripts.pory"

# 576 "data/maps/Route119/scripts.pory"
Route119_Text_BrendanIllGiveYouThis:
# 577 "data/maps/Route119/scripts.pory"
	.string "Brendan: I'd say you're good enough\n"
# 578 "data/maps/Route119/scripts.pory"
	.string "to search for Pokémon anywhere.\p"
# 579 "data/maps/Route119/scripts.pory"
	.string "Here, I'll give you these.\n"
# 580 "data/maps/Route119/scripts.pory"
	.string "Try them out.$"
# 581 "data/maps/Route119/scripts.pory"

# 582 "data/maps/Route119/scripts.pory"
Route119_Text_BrendanExplainFly:
# 583 "data/maps/Route119/scripts.pory"
	.string "Some pretty decent battle items, if I\n"
# 584 "data/maps/Route119/scripts.pory"
	.string "do say so myself! Keep going, {PLAYER},\l"
# 585 "data/maps/Route119/scripts.pory"
	.string "you're raising your Pokémon really well.$"
# 586 "data/maps/Route119/scripts.pory"

# 587 "data/maps/Route119/scripts.pory"
Route119_Text_ScottWayToGoBeSeeingYou:
# 588 "data/maps/Route119/scripts.pory"
	.string "Scott: Hahahah!\n"
# 589 "data/maps/Route119/scripts.pory"
	.string "Way to go, {PLAYER}{KUN}!\p"
# 590 "data/maps/Route119/scripts.pory"
	.string "I just passed by a trainer riding\n"
# 591 "data/maps/Route119/scripts.pory"
	.string "a Bike.\p"
# 592 "data/maps/Route119/scripts.pory"
	.string "You just beat that trainer, didn't you?\n"
# 593 "data/maps/Route119/scripts.pory"
	.string "It was pretty obvious that you did.\p"
# 594 "data/maps/Route119/scripts.pory"
	.string "The kid looked really upset with\n"
# 595 "data/maps/Route119/scripts.pory"
	.string "a face all red from anger.\p"
# 596 "data/maps/Route119/scripts.pory"
	.string "I sure seem to run into you often.\n"
# 597 "data/maps/Route119/scripts.pory"
	.string "Are you off to Fortree Gym next?\p"
# 598 "data/maps/Route119/scripts.pory"
	.string "I expect that you'll do well at the Gym.\n"
# 599 "data/maps/Route119/scripts.pory"
	.string "Well, I'll be seeing you!$"
# 600 "data/maps/Route119/scripts.pory"

# 601 "data/maps/Route119/scripts.pory"

# 602 "data/maps/Route119/scripts.pory"
Route119_Text_ScottYouWonAtFortreeGym:
# 603 "data/maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 604 "data/maps/Route119/scripts.pory"
	.string "… … … … … Beep!\p"
# 605 "data/maps/Route119/scripts.pory"
	.string "Scott: Hiya, {PLAYER}{KUN}, it's me!\p"
# 606 "data/maps/Route119/scripts.pory"
	.string "Just as I thought, you won at\n"
# 607 "data/maps/Route119/scripts.pory"
	.string "the Fortree Gym.\p"
# 608 "data/maps/Route119/scripts.pory"
	.string "Your strength…\n"
# 609 "data/maps/Route119/scripts.pory"
	.string "Perhaps you really are the trainer\l"
# 610 "data/maps/Route119/scripts.pory"
	.string "that I've been searching for.\p"
# 611 "data/maps/Route119/scripts.pory"
	.string "In other news, did you guys feel\n"
# 612 "data/maps/Route119/scripts.pory"
	.string "that massive tremor just now?\p"
# 613 "data/maps/Route119/scripts.pory"
	.string "I actually happened to be walking\n"
# 614 "data/maps/Route119/scripts.pory"
	.string "on Route 120 and noticed one of\l"
# 615 "data/maps/Route119/scripts.pory"
	.string "the caves that was sealed up is\l"
# 616 "data/maps/Route119/scripts.pory"
	.string "open now.\p"
# 617 "data/maps/Route119/scripts.pory"
	.string "I wonder if that means any other\n"
# 618 "data/maps/Route119/scripts.pory"
	.string "caves around Hoenn have opened?\p"
# 619 "data/maps/Route119/scripts.pory"
	.string "That's all from me, keep up the\n"
# 620 "data/maps/Route119/scripts.pory"
	.string "great work, {PLAYER}, I'll be\l"
# 621 "data/maps/Route119/scripts.pory"
	.string "rooting for you!\p"
# 622 "data/maps/Route119/scripts.pory"
	.string "… … … … … …\n"
# 623 "data/maps/Route119/scripts.pory"
	.string "… … … … … Click!$"
# 624 "data/maps/Route119/scripts.pory"

# 625 "data/maps/Route119/scripts.pory"
Route119_Text_StayAwayFromWeatherInstitute:
# 626 "data/maps/Route119/scripts.pory"
	.string "We're standing lookout here.\p"
# 627 "data/maps/Route119/scripts.pory"
	.string "Hey, you! Stay away from the Weather\n"
# 628 "data/maps/Route119/scripts.pory"
	.string "Institute. It's not safe.$"
# 629 "data/maps/Route119/scripts.pory"

# 630 "data/maps/Route119/scripts.pory"
Route119_Text_DontGoNearWeatherInstitute:
# 631 "data/maps/Route119/scripts.pory"
	.string "Lookout duty is surprisingly boring.\p"
# 632 "data/maps/Route119/scripts.pory"
	.string "Hey, you! Please don't go near the\n"
# 633 "data/maps/Route119/scripts.pory"
	.string "Weather Institute.$"
# 634 "data/maps/Route119/scripts.pory"

# 635 "data/maps/Route119/scripts.pory"
Route119_Text_ThoughtFlyByCatchingBirdMons:
# 636 "data/maps/Route119/scripts.pory"
	.string "I thought you FLY by catching a whole\n"
# 637 "data/maps/Route119/scripts.pory"
	.string "flock of Bird Pokémon, and then\l"
# 638 "data/maps/Route119/scripts.pory"
	.string "hanging on to them somehow.\p"
# 639 "data/maps/Route119/scripts.pory"
	.string "But it turns out there's an HM move\n"
# 640 "data/maps/Route119/scripts.pory"
	.string "called FLY!\p"
# 641 "data/maps/Route119/scripts.pory"
	.string "I wish I'd known about that a long\n"
# 642 "data/maps/Route119/scripts.pory"
	.string "time ago…$"
# 643 "data/maps/Route119/scripts.pory"

# 644 "data/maps/Route119/scripts.pory"
Route119_Text_TallGrassSnaresBikeTires:
# 645 "data/maps/Route119/scripts.pory"
	.string "Tch…\n"
# 646 "data/maps/Route119/scripts.pory"
	.string "It's a no-go…\p"
# 647 "data/maps/Route119/scripts.pory"
	.string "The tall grass snares BIKE tires.\n"
# 648 "data/maps/Route119/scripts.pory"
	.string "There's no way you can cycle here.$"
# 649 "data/maps/Route119/scripts.pory"

# 650 "data/maps/Route119/scripts.pory"
Route119_Text_CanYourMonMakeSecretBase:
# 651 "data/maps/Route119/scripts.pory"
	.string "Can your Pokémon use its SECRET POWER\n"
# 652 "data/maps/Route119/scripts.pory"
	.string "on a big pile of grass and make a\l"
# 653 "data/maps/Route119/scripts.pory"
	.string "SECRET BASE? Not anymore!$"
# 654 "data/maps/Route119/scripts.pory"

# 655 "data/maps/Route119/scripts.pory"
Route119_Text_RouteSignFortree:
# 656 "data/maps/Route119/scripts.pory"
	.string "ROUTE 119\n"
# 657 "data/maps/Route119/scripts.pory"
	.string "{RIGHT_ARROW} FORTREE CITY$"
# 658 "data/maps/Route119/scripts.pory"

# 659 "data/maps/Route119/scripts.pory"
Route119_Text_WeatherInstitute:
# 660 "data/maps/Route119/scripts.pory"
	.string "WEATHER INSTITUTE$"
# 661 "data/maps/Route119/scripts.pory"

# 662 "data/maps/Route119/scripts.pory"
Route119_Text_TrainerTipsDecoration:
# 663 "data/maps/Route119/scripts.pory"
	.string "Trainer Tips\p"
# 664 "data/maps/Route119/scripts.pory"
	.string "Many trainers have Pokémon whose\n"
# 665 "data/maps/Route119/scripts.pory"
	.string "levels scale with the highest-level\l"
# 666 "data/maps/Route119/scripts.pory"
	.string "Pokémon in your party.$"
