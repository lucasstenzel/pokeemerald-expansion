# 1 "data/maps/Route103/scripts.pory"

# 2 "data/maps/Route103/scripts.pory"
.set LOCALID_RIVAL, 2
# 3 "data/maps/Route103/scripts.pory"

# 4 "data/maps/Route103/scripts.pory"
Route103_MapScripts::
# 5 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
# 6 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
# 7 "data/maps/Route103/scripts.pory"
	.byte 0
# 8 "data/maps/Route103/scripts.pory"

# 9 "data/maps/Route103/scripts.pory"
Route103_OnTransition:
# 10 "data/maps/Route103/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 12 "data/maps/Route103/scripts.pory"
	end
# 13 "data/maps/Route103/scripts.pory"

# 14 "data/maps/Route103/scripts.pory"
Route103_OnLoad:
# 15 "data/maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 16 "data/maps/Route103/scripts.pory"
	call_if_unset FLAG_BADGE06_GET, Route103_CloseLakeEntrance
# 17 "data/maps/Route103/scripts.pory"
	end
# 18 "data/maps/Route103/scripts.pory"

# 19 "data/maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 20 "data/maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 21 "data/maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 22 "data/maps/Route103/scripts.pory"
	return
# 23 "data/maps/Route103/scripts.pory"

# 24 "data/maps/Route103/scripts.pory"
Route103_CloseLakeEntrance::
# 25 "data/maps/Route103/scripts.pory"
	setmetatile 34, 7, METATILE_General_RockWall_RockBase, TRUE
# 26 "data/maps/Route103/scripts.pory"
	setmetatile 34, 8, METATILE_General_RockWall_SandBase, TRUE
# 27 "data/maps/Route103/scripts.pory"
	return
# 28 "data/maps/Route103/scripts.pory"

# 29 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 30 "data/maps/Route103/scripts.pory"
	lockall
# 31 "data/maps/Route103/scripts.pory"
	checkplayergender
# 32 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
# 33 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
# 34 "data/maps/Route103/scripts.pory"
	end
# 35 "data/maps/Route103/scripts.pory"

# 36 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalMay::
# 37 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 38 "data/maps/Route103/scripts.pory"
	closemessage
# 39 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 40 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 41 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 42 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 43 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 44 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 45 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 46 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 47 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 48 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartMayBattleTreecko
# 49 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartMayBattleTorchic
# 50 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartMayBattleMudkip
# 51 "data/maps/Route103/scripts.pory"
	case 3, Route103_EventScript_StartMayBattleGible
# 52 "data/maps/Route103/scripts.pory"
	end
# 53 "data/maps/Route103/scripts.pory"

# 54 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 55 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 56 "data/maps/Route103/scripts.pory"
	closemessage
# 57 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 58 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 59 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 60 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 61 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 62 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 63 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 64 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 65 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 66 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 67 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 68 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 69 "data/maps/Route103/scripts.pory"
	case 3, Route103_EventScript_StartBrendanBattleGible
# 70 "data/maps/Route103/scripts.pory"
	end
# 71 "data/maps/Route103/scripts.pory"

# 72 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 73 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 74 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 75 "data/maps/Route103/scripts.pory"
	end
# 76 "data/maps/Route103/scripts.pory"

# 77 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 78 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 79 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 80 "data/maps/Route103/scripts.pory"
	end
# 81 "data/maps/Route103/scripts.pory"

# 82 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 83 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 84 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 85 "data/maps/Route103/scripts.pory"
	end
# 86 "data/maps/Route103/scripts.pory"

# 87 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleGible::
# 88 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_GIBLE, Route103_Text_MayDefeated
# 89 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 90 "data/maps/Route103/scripts.pory"
	end
# 91 "data/maps/Route103/scripts.pory"

# 92 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 93 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 94 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 95 "data/maps/Route103/scripts.pory"
	end
# 96 "data/maps/Route103/scripts.pory"

# 97 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 98 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 99 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 100 "data/maps/Route103/scripts.pory"
	end
# 101 "data/maps/Route103/scripts.pory"

# 102 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 103 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 104 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 105 "data/maps/Route103/scripts.pory"
	end
# 106 "data/maps/Route103/scripts.pory"

# 107 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleGible::
# 108 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_GIBLE, Route103_Text_BrendanDefeated
# 109 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 110 "data/maps/Route103/scripts.pory"
	end
# 111 "data/maps/Route103/scripts.pory"

# 112 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 113 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 114 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 115 "data/maps/Route103/scripts.pory"
	end
# 116 "data/maps/Route103/scripts.pory"

# 117 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 118 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 119 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 120 "data/maps/Route103/scripts.pory"
	end
# 121 "data/maps/Route103/scripts.pory"

# 122 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 123 "data/maps/Route103/scripts.pory"
	closemessage
# 124 "data/maps/Route103/scripts.pory"
	switch VAR_FACING
# 125 "data/maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 126 "data/maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 127 "data/maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 128 "data/maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 129 "data/maps/Route103/scripts.pory"
	end
# 130 "data/maps/Route103/scripts.pory"

# 131 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 132 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 133 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 134 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 135 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 136 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 137 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 138 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 139 "data/maps/Route103/scripts.pory"
	end
# 140 "data/maps/Route103/scripts.pory"

# 141 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 142 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 143 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 144 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 145 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 146 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 147 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 148 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 149 "data/maps/Route103/scripts.pory"
	end
# 150 "data/maps/Route103/scripts.pory"

# 151 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 152 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 153 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 154 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 155 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 156 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 157 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 158 "data/maps/Route103/scripts.pory"
	end
# 159 "data/maps/Route103/scripts.pory"

# 160 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 161 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 162 "data/maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 163 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 164 "data/maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 165 "data/maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 166 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 167 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 168 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 169 "data/maps/Route103/scripts.pory"
	releaseall
# 170 "data/maps/Route103/scripts.pory"
	end
# 171 "data/maps/Route103/scripts.pory"

# 172 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 173 "data/maps/Route103/scripts.pory"
	walk_left
# 174 "data/maps/Route103/scripts.pory"
	walk_down
# 175 "data/maps/Route103/scripts.pory"
	step_end
# 176 "data/maps/Route103/scripts.pory"

# 177 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 178 "data/maps/Route103/scripts.pory"
	jump_2_down
# 179 "data/maps/Route103/scripts.pory"
	delay_16
# 180 "data/maps/Route103/scripts.pory"
	walk_down
# 181 "data/maps/Route103/scripts.pory"
	walk_down
# 182 "data/maps/Route103/scripts.pory"
	walk_down
# 183 "data/maps/Route103/scripts.pory"
	walk_down
# 184 "data/maps/Route103/scripts.pory"
	step_end
# 185 "data/maps/Route103/scripts.pory"

# 186 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 187 "data/maps/Route103/scripts.pory"
	delay_16
# 188 "data/maps/Route103/scripts.pory"
	delay_4
# 189 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 190 "data/maps/Route103/scripts.pory"
	delay_16
# 191 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 192 "data/maps/Route103/scripts.pory"
	step_end
# 193 "data/maps/Route103/scripts.pory"

# 194 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 195 "data/maps/Route103/scripts.pory"
	walk_down
# 196 "data/maps/Route103/scripts.pory"
	step_end
# 197 "data/maps/Route103/scripts.pory"

# 198 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 199 "data/maps/Route103/scripts.pory"
	jump_2_down
# 200 "data/maps/Route103/scripts.pory"
	delay_16
# 201 "data/maps/Route103/scripts.pory"
	walk_down
# 202 "data/maps/Route103/scripts.pory"
	walk_down
# 203 "data/maps/Route103/scripts.pory"
	walk_down
# 204 "data/maps/Route103/scripts.pory"
	step_end
# 205 "data/maps/Route103/scripts.pory"

# 206 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 207 "data/maps/Route103/scripts.pory"
	delay_16
# 208 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 209 "data/maps/Route103/scripts.pory"
	step_end
# 210 "data/maps/Route103/scripts.pory"

# 211 "data/maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 212 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 213 "data/maps/Route103/scripts.pory"
	end
# 214 "data/maps/Route103/scripts.pory"

# 215 "data/maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 216 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 217 "data/maps/Route103/scripts.pory"
	end
# 218 "data/maps/Route103/scripts.pory"

# 219 "data/maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 220 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 221 "data/maps/Route103/scripts.pory"
	end
# 222 "data/maps/Route103/scripts.pory"

# 223 "data/maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 224 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 225 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 226 "data/maps/Route103/scripts.pory"
	end
# 227 "data/maps/Route103/scripts.pory"

# 228 "data/maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 229 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 230 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 231 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 232 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 233 "data/maps/Route103/scripts.pory"
	end
# 234 "data/maps/Route103/scripts.pory"

# 235 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 236 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 237 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 238 "data/maps/Route103/scripts.pory"
	release
# 239 "data/maps/Route103/scripts.pory"
	end
# 240 "data/maps/Route103/scripts.pory"

# 241 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 242 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 243 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 244 "data/maps/Route103/scripts.pory"
	end
# 245 "data/maps/Route103/scripts.pory"

# 246 "data/maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 247 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 248 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 249 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 250 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 251 "data/maps/Route103/scripts.pory"
	end
# 252 "data/maps/Route103/scripts.pory"

# 253 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 254 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 255 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 256 "data/maps/Route103/scripts.pory"
	release
# 257 "data/maps/Route103/scripts.pory"
	end
# 258 "data/maps/Route103/scripts.pory"

# 259 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 260 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 261 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 262 "data/maps/Route103/scripts.pory"
	end
# 263 "data/maps/Route103/scripts.pory"

# 264 "data/maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 265 "data/maps/Route103/scripts.pory"
	lock
# 266 "data/maps/Route103/scripts.pory"
	faceplayer
# 267 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route103_EventScript_ReceivedGoodRod
# 268 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
# 269 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route103_EventScript_ReceiveGoodRod
# 270 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route103_EventScript_DeclineGoodRod
# 271 "data/maps/Route103/scripts.pory"
	end
# 272 "data/maps/Route103/scripts.pory"

# 273 "data/maps/Route103/scripts.pory"
Route103_EventScript_ReceiveGoodRod::
# 274 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
# 275 "data/maps/Route103/scripts.pory"
	giveitem ITEM_GOOD_ROD
# 276 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 277 "data/maps/Route103/scripts.pory"
	setflag FLAG_RECEIVED_GOOD_ROD
# 278 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_TryYourLuckFishing, MSGBOX_DEFAULT
# 279 "data/maps/Route103/scripts.pory"
	release
# 280 "data/maps/Route103/scripts.pory"
	end
# 281 "data/maps/Route103/scripts.pory"

# 282 "data/maps/Route103/scripts.pory"
Route103_EventScript_DeclineGoodRod::
# 283 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DontYouLikeToFish, MSGBOX_DEFAULT
# 284 "data/maps/Route103/scripts.pory"
	release
# 285 "data/maps/Route103/scripts.pory"
	end
# 286 "data/maps/Route103/scripts.pory"

# 287 "data/maps/Route103/scripts.pory"
Route103_EventScript_ReceivedGoodRod::
# 288 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
# 289 "data/maps/Route103/scripts.pory"
	release
# 290 "data/maps/Route103/scripts.pory"
	end
# 291 "data/maps/Route103/scripts.pory"

# 292 "data/maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 293 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 294 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 295 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 296 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 297 "data/maps/Route103/scripts.pory"
	release
# 298 "data/maps/Route103/scripts.pory"
	end
# 299 "data/maps/Route103/scripts.pory"

# 300 "data/maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 301 "data/maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 302 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 303 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 304 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 305 "data/maps/Route103/scripts.pory"
	release
# 306 "data/maps/Route103/scripts.pory"
	end
# 307 "data/maps/Route103/scripts.pory"

# 308 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 309 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 310 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 311 "data/maps/Route103/scripts.pory"
	end
# 312 "data/maps/Route103/scripts.pory"

# 313 "data/maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 314 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 315 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 316 "data/maps/Route103/scripts.pory"
	end
# 317 "data/maps/Route103/scripts.pory"

# 318 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 319 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 320 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 321 "data/maps/Route103/scripts.pory"
	end
# 322 "data/maps/Route103/scripts.pory"

# 323 "data/maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 324 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 325 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 326 "data/maps/Route103/scripts.pory"
	end
# 327 "data/maps/Route103/scripts.pory"

# 328 "data/maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 329 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 330 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 331 "data/maps/Route103/scripts.pory"
	end
# 332 "data/maps/Route103/scripts.pory"

# 333 "data/maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 334 "data/maps/Route103/scripts.pory"
	.string "Let's see… The Pokémon found\n"
# 335 "data/maps/Route103/scripts.pory"
	.string "on Route 103 include…$"
# 336 "data/maps/Route103/scripts.pory"

# 337 "data/maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 338 "data/maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 339 "data/maps/Route103/scripts.pory"
	.string "…Oh, I see, my dad gave you\n"
# 340 "data/maps/Route103/scripts.pory"
	.string "a Pokémon as a gift.\p"
# 341 "data/maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 342 "data/maps/Route103/scripts.pory"
	.string "battle!\p"
# 343 "data/maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 344 "data/maps/Route103/scripts.pory"
	.string "a trainer is like.$"
# 345 "data/maps/Route103/scripts.pory"

# 346 "data/maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 347 "data/maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 348 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 349 "data/maps/Route103/scripts.pory"

# 350 "data/maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 351 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has\n"
# 352 "data/maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 353 "data/maps/Route103/scripts.pory"
	.string "I mean, you just got that Pokémon,\n"
# 354 "data/maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 355 "data/maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 356 "data/maps/Route103/scripts.pory"
	.string "kind of Pokémon easily.\p"
# 357 "data/maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 358 "data/maps/Route103/scripts.pory"
	.string "the lab.$"
# 359 "data/maps/Route103/scripts.pory"

# 360 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 361 "data/maps/Route103/scripts.pory"
	.string "Okay, so it's this one and\n"
# 362 "data/maps/Route103/scripts.pory"
	.string "that one that live on Route 103…$"
# 363 "data/maps/Route103/scripts.pory"

# 364 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 365 "data/maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 366 "data/maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a Pokémon.\p"
# 367 "data/maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 368 "data/maps/Route103/scripts.pory"
	.string "battle?\p"
# 369 "data/maps/Route103/scripts.pory"
	.string "I'll teach you what being a trainer's\n"
# 370 "data/maps/Route103/scripts.pory"
	.string "about!$"
# 371 "data/maps/Route103/scripts.pory"

# 372 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 373 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 374 "data/maps/Route103/scripts.pory"

# 375 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 376 "data/maps/Route103/scripts.pory"
	.string "I think I get it.\n"
# 377 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 378 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 379 "data/maps/Route103/scripts.pory"
	.string "Look, your Pokémon already likes you,\n"
# 380 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 381 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 382 "data/maps/Route103/scripts.pory"
	.string "could befriend any Pokémon with ease,\l"
# 383 "data/maps/Route103/scripts.pory"
	.string "which is a great quality in a trainer.\p"
# 384 "data/maps/Route103/scripts.pory"
	.string "Anyway, we should head back to the lab.$"
# 385 "data/maps/Route103/scripts.pory"

# 386 "data/maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 387 "data/maps/Route103/scripts.pory"
	.string "My Pokémon is staggeringly tired…\n"
# 388 "data/maps/Route103/scripts.pory"
	.string "I should have brought a Potion…$"
# 389 "data/maps/Route103/scripts.pory"

# 390 "data/maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 391 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 392 "data/maps/Route103/scripts.pory"
	.string "it'll be a shortcut to Oldale Town.\p"
# 393 "data/maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 394 "data/maps/Route103/scripts.pory"

# 395 "data/maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 396 "data/maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 397 "data/maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
# 398 "data/maps/Route103/scripts.pory"

# 399 "data/maps/Route103/scripts.pory"
Route103_Text_YouAgreeGoodRodIsGood:
# 400 "data/maps/Route103/scripts.pory"
	.string "Hmm!\n"
# 401 "data/maps/Route103/scripts.pory"
	.string "A Good Rod is really good!\p"
# 402 "data/maps/Route103/scripts.pory"
	.string "Wouldn't you agree?$"
# 403 "data/maps/Route103/scripts.pory"

# 404 "data/maps/Route103/scripts.pory"
Route103_Text_IdenticalMindsTakeThis:
# 405 "data/maps/Route103/scripts.pory"
	.string "Hmm!\n"
# 406 "data/maps/Route103/scripts.pory"
	.string "We're of identical minds!\p"
# 407 "data/maps/Route103/scripts.pory"
	.string "Hmm!\n"
# 408 "data/maps/Route103/scripts.pory"
	.string "Take this Good Rod!$"
# 409 "data/maps/Route103/scripts.pory"

# 410 "data/maps/Route103/scripts.pory"
Route103_Text_TryYourLuckFishing:
# 411 "data/maps/Route103/scripts.pory"
	.string "Wherever there's water, try your luck\n"
# 412 "data/maps/Route103/scripts.pory"
	.string "at fishing.$"
# 413 "data/maps/Route103/scripts.pory"

# 414 "data/maps/Route103/scripts.pory"
Route103_Text_DontYouLikeToFish:
# 415 "data/maps/Route103/scripts.pory"
	.string "Don't you like to fish?$"
# 416 "data/maps/Route103/scripts.pory"

# 417 "data/maps/Route103/scripts.pory"
Route103_Text_TryCatchingMonWithGoodRod:
# 418 "data/maps/Route103/scripts.pory"
	.string "Try catching all sorts of Pokémon\n"
# 419 "data/maps/Route103/scripts.pory"
	.string "with your Good Rod.$"
