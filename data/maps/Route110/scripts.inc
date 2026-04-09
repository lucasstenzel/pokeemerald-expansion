# 1 "data/maps/Route110/scripts.pory"

# 2 "data/maps/Route110/scripts.pory"
.set LOCALID_CHALLENGE_BIKER, 21
# 3 "data/maps/Route110/scripts.pory"
.set LOCALID_RIVAL, 28
# 4 "data/maps/Route110/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 29
# 5 "data/maps/Route110/scripts.pory"
.set LOCALID_BIRCH, 36
# 6 "data/maps/Route110/scripts.pory"
.set LOCALID_WALLY, 37
# 7 "data/maps/Route110/scripts.pory"

# 8 "data/maps/Route110/scripts.pory"
Route110_MapScripts::
# 9 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
# 10 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
# 11 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
# 12 "data/maps/Route110/scripts.pory"
	.byte 0
# 13 "data/maps/Route110/scripts.pory"

# 14 "data/maps/Route110/scripts.pory"
Route110_OnResume:
# 15 "data/maps/Route110/scripts.pory"
	special UpdateCyclingRoadState
# 16 "data/maps/Route110/scripts.pory"
	end
# 17 "data/maps/Route110/scripts.pory"

# 18 "data/maps/Route110/scripts.pory"
Route110_OnTransition:
# 19 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 20 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 21 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
# 22 "data/maps/Route110/scripts.pory"
	end
# 23 "data/maps/Route110/scripts.pory"

# 24 "data/maps/Route110/scripts.pory"
Route110_EventScript_SaveCyclingMusic::
# 25 "data/maps/Route110/scripts.pory"
	savebgm MUS_CYCLING
# 26 "data/maps/Route110/scripts.pory"
	return
# 27 "data/maps/Route110/scripts.pory"

# 28 "data/maps/Route110/scripts.pory"
Route110_OnFrame:
# 29 "data/maps/Route110/scripts.pory"
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
# 30 "data/maps/Route110/scripts.pory"
	.2byte 0
# 31 "data/maps/Route110/scripts.pory"

# 32 "data/maps/Route110/scripts.pory"
Route110_EventScript_BeginCylcingRoadChallenge::
# 33 "data/maps/Route110/scripts.pory"
	special Special_BeginCyclingRoadChallenge
# 34 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
# 35 "data/maps/Route110/scripts.pory"
	return
# 36 "data/maps/Route110/scripts.pory"

# 37 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt1::
# 38 "data/maps/Route110/scripts.pory"
	lock
# 39 "data/maps/Route110/scripts.pory"
	faceplayer
# 40 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
# 41 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 42 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 43 "data/maps/Route110/scripts.pory"
	release
# 44 "data/maps/Route110/scripts.pory"
	end
# 45 "data/maps/Route110/scripts.pory"

# 46 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt2::
# 47 "data/maps/Route110/scripts.pory"
	lock
# 48 "data/maps/Route110/scripts.pory"
	faceplayer
# 49 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
# 50 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 51 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 52 "data/maps/Route110/scripts.pory"
	release
# 53 "data/maps/Route110/scripts.pory"
	end
# 54 "data/maps/Route110/scripts.pory"

# 55 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt3::
# 56 "data/maps/Route110/scripts.pory"
	lock
# 57 "data/maps/Route110/scripts.pory"
	faceplayer
# 58 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
# 59 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 60 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 61 "data/maps/Route110/scripts.pory"
	release
# 62 "data/maps/Route110/scripts.pory"
	end
# 63 "data/maps/Route110/scripts.pory"

# 64 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt4::
# 65 "data/maps/Route110/scripts.pory"
	lock
# 66 "data/maps/Route110/scripts.pory"
	faceplayer
# 67 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
# 68 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 69 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 70 "data/maps/Route110/scripts.pory"
	release
# 71 "data/maps/Route110/scripts.pory"
	end
# 72 "data/maps/Route110/scripts.pory"

# 73 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy1::
# 74 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
# 75 "data/maps/Route110/scripts.pory"
	end
# 76 "data/maps/Route110/scripts.pory"

# 77 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGirl1::
# 78 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
# 79 "data/maps/Route110/scripts.pory"
	end
# 80 "data/maps/Route110/scripts.pory"

# 81 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy1::
# 82 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
# 83 "data/maps/Route110/scripts.pory"
	end
# 84 "data/maps/Route110/scripts.pory"

# 85 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldMan::
# 86 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
# 87 "data/maps/Route110/scripts.pory"
	end
# 88 "data/maps/Route110/scripts.pory"

# 89 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldWoman::
# 90 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
# 91 "data/maps/Route110/scripts.pory"
	end
# 92 "data/maps/Route110/scripts.pory"

# 93 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy2::
# 94 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
# 95 "data/maps/Route110/scripts.pory"
	end
# 96 "data/maps/Route110/scripts.pory"

# 97 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy2::
# 98 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
# 99 "data/maps/Route110/scripts.pory"
	end
# 100 "data/maps/Route110/scripts.pory"

# 101 "data/maps/Route110/scripts.pory"
Route110_EventScript_SlateportCitySign::
# 102 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
# 103 "data/maps/Route110/scripts.pory"
	end
# 104 "data/maps/Route110/scripts.pory"

# 105 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadSign::
# 106 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
# 107 "data/maps/Route110/scripts.pory"
	end
# 108 "data/maps/Route110/scripts.pory"

# 109 "data/maps/Route110/scripts.pory"
Route110_EventScript_VandalizedSign::
# 110 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
# 111 "data/maps/Route110/scripts.pory"
	end
# 112 "data/maps/Route110/scripts.pory"

# 113 "data/maps/Route110/scripts.pory"
Route110_EventScript_Route103Sign::
# 114 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
# 115 "data/maps/Route110/scripts.pory"
	end
# 116 "data/maps/Route110/scripts.pory"

# 117 "data/maps/Route110/scripts.pory"
Route110_EventScript_SeasideParkingSign::
# 118 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
# 119 "data/maps/Route110/scripts.pory"
	end
# 120 "data/maps/Route110/scripts.pory"

# 121 "data/maps/Route110/scripts.pory"
Route110_EventScript_MauvilleCitySign::
# 122 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
# 123 "data/maps/Route110/scripts.pory"
	end
# 124 "data/maps/Route110/scripts.pory"

# 125 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsPrlzSleep::
# 126 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
# 127 "data/maps/Route110/scripts.pory"
	end
# 128 "data/maps/Route110/scripts.pory"

# 129 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsRegisterItems::
# 130 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
# 131 "data/maps/Route110/scripts.pory"
	end
# 132 "data/maps/Route110/scripts.pory"

# 133 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrickHouseSign::
# 134 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
# 135 "data/maps/Route110/scripts.pory"
	end
# 136 "data/maps/Route110/scripts.pory"

# 137 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadResultsSign::
# 138 "data/maps/Route110/scripts.pory"
	lockall
# 139 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
# 140 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
# 141 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
# 142 "data/maps/Route110/scripts.pory"
	releaseall
# 143 "data/maps/Route110/scripts.pory"
	end
# 144 "data/maps/Route110/scripts.pory"

# 145 "data/maps/Route110/scripts.pory"
Route110_EventScript_NoRecordSet::
# 146 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
# 147 "data/maps/Route110/scripts.pory"
	releaseall
# 148 "data/maps/Route110/scripts.pory"
	end
# 149 "data/maps/Route110/scripts.pory"

# 150 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeGuy::
# 151 "data/maps/Route110/scripts.pory"
	lock
# 152 "data/maps/Route110/scripts.pory"
	faceplayer
# 153 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 154 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
# 155 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
# 156 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
# 157 "data/maps/Route110/scripts.pory"
	release
# 158 "data/maps/Route110/scripts.pory"
	end
# 159 "data/maps/Route110/scripts.pory"

# 160 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerNotRidingBike::
# 161 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
# 162 "data/maps/Route110/scripts.pory"
	release
# 163 "data/maps/Route110/scripts.pory"
	end
# 164 "data/maps/Route110/scripts.pory"

# 165 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerRidingAcroBike::
# 166 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
# 167 "data/maps/Route110/scripts.pory"
	release
# 168 "data/maps/Route110/scripts.pory"
	end
# 169 "data/maps/Route110/scripts.pory"

# 170 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edward::
# 171 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
# 172 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
# 173 "data/maps/Route110/scripts.pory"
	end
# 174 "data/maps/Route110/scripts.pory"

# 175 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jaclyn::
# 176 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
# 177 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
# 178 "data/maps/Route110/scripts.pory"
	end
# 179 "data/maps/Route110/scripts.pory"

# 180 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edwin::
# 181 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
# 182 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 183 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
# 184 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
# 185 "data/maps/Route110/scripts.pory"
	release
# 186 "data/maps/Route110/scripts.pory"
	end
# 187 "data/maps/Route110/scripts.pory"

# 188 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
# 189 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 190 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 191 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
# 192 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_EDWIN_1
# 193 "data/maps/Route110/scripts.pory"
	release
# 194 "data/maps/Route110/scripts.pory"
	end
# 195 "data/maps/Route110/scripts.pory"

# 196 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRematch::
# 197 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
# 198 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
# 199 "data/maps/Route110/scripts.pory"
	end
# 200 "data/maps/Route110/scripts.pory"

# 201 "data/maps/Route110/scripts.pory"
Route110_EventScript_Dale::
# 202 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
# 203 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
# 204 "data/maps/Route110/scripts.pory"
	end
# 205 "data/maps/Route110/scripts.pory"

# 206 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jacob::
# 207 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
# 208 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
# 209 "data/maps/Route110/scripts.pory"
	end
# 210 "data/maps/Route110/scripts.pory"

# 211 "data/maps/Route110/scripts.pory"
Route110_EventScript_Anthony::
# 212 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
# 213 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 214 "data/maps/Route110/scripts.pory"
	end
# 215 "data/maps/Route110/scripts.pory"

# 216 "data/maps/Route110/scripts.pory"
Route110_EventScript_Benjamin::
# 217 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
# 218 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 219 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
# 220 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
# 221 "data/maps/Route110/scripts.pory"
	release
# 222 "data/maps/Route110/scripts.pory"
	end
# 223 "data/maps/Route110/scripts.pory"

# 224 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
# 225 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 226 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 227 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
# 228 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_BENJAMIN_1
# 229 "data/maps/Route110/scripts.pory"
	release
# 230 "data/maps/Route110/scripts.pory"
	end
# 231 "data/maps/Route110/scripts.pory"

# 232 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRematch::
# 233 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
# 234 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
# 235 "data/maps/Route110/scripts.pory"
	end
# 236 "data/maps/Route110/scripts.pory"

# 237 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jasmine::
# 238 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
# 239 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
# 240 "data/maps/Route110/scripts.pory"
	end
# 241 "data/maps/Route110/scripts.pory"

# 242 "data/maps/Route110/scripts.pory"
Route110_EventScript_Abigail::
# 243 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
# 244 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 245 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
# 246 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
# 247 "data/maps/Route110/scripts.pory"
	release
# 248 "data/maps/Route110/scripts.pory"
	end
# 249 "data/maps/Route110/scripts.pory"

# 250 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
# 251 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 252 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 253 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
# 254 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ABIGAIL_1
# 255 "data/maps/Route110/scripts.pory"
	release
# 256 "data/maps/Route110/scripts.pory"
	end
# 257 "data/maps/Route110/scripts.pory"

# 258 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRematch::
# 259 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
# 260 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
# 261 "data/maps/Route110/scripts.pory"
	end
# 262 "data/maps/Route110/scripts.pory"

# 263 "data/maps/Route110/scripts.pory"
Route110_EventScript_Isabel::
# 264 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
# 265 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 266 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
# 267 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
# 268 "data/maps/Route110/scripts.pory"
	release
# 269 "data/maps/Route110/scripts.pory"
	end
# 270 "data/maps/Route110/scripts.pory"

# 271 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
# 272 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 273 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 274 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
# 275 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ISABEL_1
# 276 "data/maps/Route110/scripts.pory"
	release
# 277 "data/maps/Route110/scripts.pory"
	end
# 278 "data/maps/Route110/scripts.pory"

# 279 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRematch::
# 280 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
# 281 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
# 282 "data/maps/Route110/scripts.pory"
	end
# 283 "data/maps/Route110/scripts.pory"

# 284 "data/maps/Route110/scripts.pory"
Route110_EventScript_Timmy::
# 285 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
# 286 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
# 287 "data/maps/Route110/scripts.pory"
	end
# 288 "data/maps/Route110/scripts.pory"

# 289 "data/maps/Route110/scripts.pory"
Route110_EventScript_Unused::
# 290 "data/maps/Route110/scripts.pory"
	end
# 291 "data/maps/Route110/scripts.pory"

# 292 "data/maps/Route110/scripts.pory"
Route110_EventScript_Kaleb::
# 293 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
# 294 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
# 295 "data/maps/Route110/scripts.pory"
	end
# 296 "data/maps/Route110/scripts.pory"

# 297 "data/maps/Route110/scripts.pory"
Route110_EventScript_Joseph::
# 298 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
# 299 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
# 300 "data/maps/Route110/scripts.pory"
	end
# 301 "data/maps/Route110/scripts.pory"

# 302 "data/maps/Route110/scripts.pory"
Route110_EventScript_Alyssa::
# 303 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
# 304 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
# 305 "data/maps/Route110/scripts.pory"
	end
# 306 "data/maps/Route110/scripts.pory"

# 307 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeEnd::
# 308 "data/maps/Route110/scripts.pory"
	lockall
# 309 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
# 310 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 311 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_CyclingChallengeResults
# 312 "data/maps/Route110/scripts.pory"
	releaseall
# 313 "data/maps/Route110/scripts.pory"
	end
# 314 "data/maps/Route110/scripts.pory"

# 315 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeResults::
# 316 "data/maps/Route110/scripts.pory"
	special FinishCyclingRoadChallenge
# 317 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
# 318 "data/maps/Route110/scripts.pory"
	switch VAR_RESULT
# 319 "data/maps/Route110/scripts.pory"
	case 10, Route110_EventScript_ChallengeReactionBest
# 320 "data/maps/Route110/scripts.pory"
	case 9, Route110_EventScript_ChallengeReactionGood
# 321 "data/maps/Route110/scripts.pory"
	case 8, Route110_EventScript_ChallengeReactionGood
# 322 "data/maps/Route110/scripts.pory"
	case 7, Route110_EventScript_ChallengeReactionGood
# 323 "data/maps/Route110/scripts.pory"
	case 6, Route110_EventScript_ChallengeReactionOk
# 324 "data/maps/Route110/scripts.pory"
	case 5, Route110_EventScript_ChallengeReactionOk
# 325 "data/maps/Route110/scripts.pory"
	case 4, Route110_EventScript_ChallengeReactionOk
# 326 "data/maps/Route110/scripts.pory"
	case 3, Route110_EventScript_ChallengeReactionBad
# 327 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_ChallengeReactionBad
# 328 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_ChallengeReactionBad
# 329 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_ChallengeReactionWorst
# 330 "data/maps/Route110/scripts.pory"
	end
# 331 "data/maps/Route110/scripts.pory"

# 332 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBest::
# 333 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
# 334 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 335 "data/maps/Route110/scripts.pory"
	end
# 336 "data/maps/Route110/scripts.pory"

# 337 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionGood::
# 338 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
# 339 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 340 "data/maps/Route110/scripts.pory"
	end
# 341 "data/maps/Route110/scripts.pory"

# 342 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionOk::
# 343 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
# 344 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 345 "data/maps/Route110/scripts.pory"
	end
# 346 "data/maps/Route110/scripts.pory"

# 347 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBad::
# 348 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
# 349 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 350 "data/maps/Route110/scripts.pory"
	end
# 351 "data/maps/Route110/scripts.pory"

# 352 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionWorst::
# 353 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
# 354 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 355 "data/maps/Route110/scripts.pory"
	end
# 356 "data/maps/Route110/scripts.pory"

# 357 "data/maps/Route110/scripts.pory"
Route110_EventScript_EndChallenge::
# 358 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
# 359 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 360 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 361 "data/maps/Route110/scripts.pory"
	return
# 362 "data/maps/Route110/scripts.pory"

# 363 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger1::
# 364 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 365 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 366 "data/maps/Route110/scripts.pory"
	end
# 367 "data/maps/Route110/scripts.pory"

# 368 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger2::
# 369 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 370 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 371 "data/maps/Route110/scripts.pory"
	end
# 372 "data/maps/Route110/scripts.pory"

# 373 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger3::
# 374 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 375 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 376 "data/maps/Route110/scripts.pory"
	end
# 377 "data/maps/Route110/scripts.pory"

# 378 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalScene::
# 379 "data/maps/Route110/scripts.pory"
	lockall
# 380 "data/maps/Route110/scripts.pory"
	checkplayergender
# 381 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
# 382 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
# 383 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 384 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 385 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 386 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 387 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 388 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 389 "data/maps/Route110/scripts.pory"
	delay 30
# 390 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
# 391 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
# 392 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
# 393 "data/maps/Route110/scripts.pory"
	checkplayergender
# 394 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
# 395 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
# 396 "data/maps/Route110/scripts.pory"
	releaseall
# 397 "data/maps/Route110/scripts.pory"
	end
# 398 "data/maps/Route110/scripts.pory"

# 399 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayMayMusic::
# 400 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 401 "data/maps/Route110/scripts.pory"
	return
# 402 "data/maps/Route110/scripts.pory"

# 403 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayBrendanMusic::
# 404 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 405 "data/maps/Route110/scripts.pory"
	return
# 406 "data/maps/Route110/scripts.pory"

# 407 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattle::
# 408 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
# 409 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 410 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_MayBattleTreecko
# 411 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_MayBattleTorchic
# 412 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_MayBattleMudkip
# 413 "data/maps/Route110/scripts.pory"
	case 3, Route110_EventScript_MayBattleGible
# 414 "data/maps/Route110/scripts.pory"
	end
# 415 "data/maps/Route110/scripts.pory"

# 416 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTreecko::
# 417 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
# 418 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 419 "data/maps/Route110/scripts.pory"
	end
# 420 "data/maps/Route110/scripts.pory"

# 421 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTorchic::
# 422 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
# 423 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 424 "data/maps/Route110/scripts.pory"
	end
# 425 "data/maps/Route110/scripts.pory"

# 426 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleMudkip::
# 427 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
# 428 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 429 "data/maps/Route110/scripts.pory"
	end
# 430 "data/maps/Route110/scripts.pory"

# 431 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleGible::
# 432 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_GIBLE, Route110_Text_MayDefeated
# 433 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 434 "data/maps/Route110/scripts.pory"
	end
# 435 "data/maps/Route110/scripts.pory"

# 436 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayDefeated::
# 437 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
# 438 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveFly
# 439 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RivalThatsNotAll, MSGBOX_DEFAULT
# 440 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveRestOfItems
# 441 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RivalExplainRestOfItems, MSGBOX_DEFAULT
# 442 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 443 "data/maps/Route110/scripts.pory"
	end
# 444 "data/maps/Route110/scripts.pory"

# 445 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattle::
# 446 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 447 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 448 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_BrendanBattleTreecko
# 449 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_BrendanBattleTorchic
# 450 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_BrendanBattleMudkip
# 451 "data/maps/Route110/scripts.pory"
	case 3, Route110_EventScript_BrendanBattleGible
# 452 "data/maps/Route110/scripts.pory"
	end
# 453 "data/maps/Route110/scripts.pory"

# 454 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTreecko::
# 455 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
# 456 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 457 "data/maps/Route110/scripts.pory"
	end
# 458 "data/maps/Route110/scripts.pory"

# 459 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTorchic::
# 460 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
# 461 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 462 "data/maps/Route110/scripts.pory"
	end
# 463 "data/maps/Route110/scripts.pory"

# 464 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleMudkip::
# 465 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
# 466 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 467 "data/maps/Route110/scripts.pory"
	end
# 468 "data/maps/Route110/scripts.pory"

# 469 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleGible::
# 470 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_GIBLE, Route110_Text_BrendanDefeated
# 471 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 472 "data/maps/Route110/scripts.pory"
	end
# 473 "data/maps/Route110/scripts.pory"

# 474 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanDefeated::
# 475 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
# 476 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveFly
# 477 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RivalThatsNotAll, MSGBOX_DEFAULT
# 478 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveRestOfItems
# 479 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RivalExplainRestOfItems, MSGBOX_DEFAULT
# 480 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 481 "data/maps/Route110/scripts.pory"
	end
# 482 "data/maps/Route110/scripts.pory"

# 483 "data/maps/Route110/scripts.pory"
Route110_EventScript_GiveFly::
# 484 "data/maps/Route110/scripts.pory"
	giveitem ITEM_HM_FLY
# 485 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RivalExplainFlyHM, MSGBOX_DEFAULT
# 486 "data/maps/Route110/scripts.pory"
	return
# 487 "data/maps/Route110/scripts.pory"

# 488 "data/maps/Route110/scripts.pory"
Route110_EventScript_GiveRestOfItems::
# 489 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_DOWSING_MACHINE
# 490 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_FIRE_PUNCH
# 491 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_ICE_PUNCH
# 492 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_THUNDER_PUNCH
# 493 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_FIRE_FANG
# 494 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_ICE_FANG
# 495 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_THUNDER_FANG
# 496 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_PSYCHIC_FANGS
# 497 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TM_POISON_FANG
# 498 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_GREAT_BALL, 99
# 499 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_ULTRA_BALL, 99
# 500 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_DIVE_BALL, 99
# 501 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_DUSK_BALL, 99
# 502 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_SHINY_STONE, 10
# 503 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_ICE_STONE, 10
# 504 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_BLACK_SLUDGE, 10
# 505 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TOXIC_ORB, 10
# 506 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_FLAME_ORB, 10
# 507 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_SMOKE_BALL, 10
# 508 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_THICK_CLUB, 10
# 509 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_WEAKNESS_POLICY, 10
# 510 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_GRASSY_SEED, 10
# 511 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_ELECTRIC_SEED, 10
# 512 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_PSYCHIC_SEED, 10
# 513 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_MISTY_SEED, 10
# 514 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_TERRAIN_EXTENDER, 10
# 515 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_SHED_SHELL, 10
# 516 "data/maps/Route110/scripts.pory"
	giveitemfast ITEM_LIGHT_CLAY, 10
# 517 "data/maps/Route110/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 518 "data/maps/Route110/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ReceivedSeveralItems, MSGBOX_DEFAULT
# 519 "data/maps/Route110/scripts.pory"
	waitfanfare
# 520 "data/maps/Route110/scripts.pory"
	setflag FLAG_RIVAL_110
# 521 "data/maps/Route110/scripts.pory"
	return
# 522 "data/maps/Route110/scripts.pory"

# 523 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit::
# 524 "data/maps/Route110/scripts.pory"
	closemessage
# 525 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
# 526 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
# 527 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
# 528 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
# 529 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
# 530 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL
# 531 "data/maps/Route110/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 532 "data/maps/Route110/scripts.pory"
	delay 45
# 533 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
# 534 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
# 535 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
# 536 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 537 "data/maps/Route110/scripts.pory"
	setvar VAR_ROUTE110_STATE, 1
# 538 "data/maps/Route110/scripts.pory"
	delay 30
# 539 "data/maps/Route110/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 540 "data/maps/Route110/scripts.pory"
	specialvar VAR_0x8006, GetLevelCapForText
# 541 "data/maps/Route110/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_0x8006
# 542 "data/maps/Route110/scripts.pory"
	msgbox LevelCapIncreasedTo, MSGBOX_DEFAULT
# 543 "data/maps/Route110/scripts.pory"
	waitfanfare
# 544 "data/maps/Route110/scripts.pory"
	closemessage
# 545 "data/maps/Route110/scripts.pory"
	delay 30
# 546 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 547 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 548 "data/maps/Route110/scripts.pory"
	releaseall
# 549 "data/maps/Route110/scripts.pory"
	end
# 550 "data/maps/Route110/scripts.pory"

# 551 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer1::
# 552 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
# 553 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 554 "data/maps/Route110/scripts.pory"
	return
# 555 "data/maps/Route110/scripts.pory"

# 556 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer2::
# 557 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
# 558 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 559 "data/maps/Route110/scripts.pory"
	return
# 560 "data/maps/Route110/scripts.pory"

# 561 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer3::
# 562 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
# 563 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 564 "data/maps/Route110/scripts.pory"
	return
# 565 "data/maps/Route110/scripts.pory"

# 566 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit1::
# 567 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
# 568 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 569 "data/maps/Route110/scripts.pory"
	return
# 570 "data/maps/Route110/scripts.pory"

# 571 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit2::
# 572 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
# 573 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 574 "data/maps/Route110/scripts.pory"
	return
# 575 "data/maps/Route110/scripts.pory"

# 576 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit3::
# 577 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
# 578 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 579 "data/maps/Route110/scripts.pory"
	return
# 580 "data/maps/Route110/scripts.pory"

# 581 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival1::
# 582 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
# 583 "data/maps/Route110/scripts.pory"
	return
# 584 "data/maps/Route110/scripts.pory"

# 585 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival2::
# 586 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
# 587 "data/maps/Route110/scripts.pory"
	return
# 588 "data/maps/Route110/scripts.pory"

# 589 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival3::
# 590 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
# 591 "data/maps/Route110/scripts.pory"
	return
# 592 "data/maps/Route110/scripts.pory"

# 593 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer1:
# 594 "data/maps/Route110/scripts.pory"
	walk_down
# 595 "data/maps/Route110/scripts.pory"
	walk_left
# 596 "data/maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 597 "data/maps/Route110/scripts.pory"
	step_end
# 598 "data/maps/Route110/scripts.pory"

# 599 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer2:
# 600 "data/maps/Route110/scripts.pory"
	walk_down
# 601 "data/maps/Route110/scripts.pory"
	step_end
# 602 "data/maps/Route110/scripts.pory"

# 603 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer3:
# 604 "data/maps/Route110/scripts.pory"
	walk_down
# 605 "data/maps/Route110/scripts.pory"
	walk_right
# 606 "data/maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 607 "data/maps/Route110/scripts.pory"
	step_end
# 608 "data/maps/Route110/scripts.pory"

# 609 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit1:
# 610 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 611 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 612 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 613 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 614 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 615 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 616 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 617 "data/maps/Route110/scripts.pory"
	step_end
# 618 "data/maps/Route110/scripts.pory"

# 619 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit2:
# 620 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 621 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 622 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 623 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 624 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 625 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 626 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 627 "data/maps/Route110/scripts.pory"
	walk_fast_down
# 628 "data/maps/Route110/scripts.pory"
	step_end
# 629 "data/maps/Route110/scripts.pory"

# 630 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit3:
# 631 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 632 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 633 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 634 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 635 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 636 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 637 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 638 "data/maps/Route110/scripts.pory"
	step_end
# 639 "data/maps/Route110/scripts.pory"

# 640 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene1::
# 641 "data/maps/Route110/scripts.pory"
	lockall
# 642 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 643 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 644 "data/maps/Route110/scripts.pory"

# 645 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene2::
# 646 "data/maps/Route110/scripts.pory"
	lockall
# 647 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 648 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 649 "data/maps/Route110/scripts.pory"

# 650 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene3::
# 651 "data/maps/Route110/scripts.pory"
	lockall
# 652 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 653 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 654 "data/maps/Route110/scripts.pory"

# 655 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene4::
# 656 "data/maps/Route110/scripts.pory"
	lockall
# 657 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 4
# 658 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 659 "data/maps/Route110/scripts.pory"

# 660 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene::
# 661 "data/maps/Route110/scripts.pory"
	addobject LOCALID_BIRCH
# 662 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
# 663 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 664 "data/maps/Route110/scripts.pory"
	playse SE_PIN
# 665 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 666 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 667 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
# 668 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 669 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
# 670 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
# 671 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
# 672 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
# 673 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
# 674 "data/maps/Route110/scripts.pory"
	closemessage
# 675 "data/maps/Route110/scripts.pory"
	delay 20
# 676 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
# 677 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 678 "data/maps/Route110/scripts.pory"
	delay 10
# 679 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 680 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 681 "data/maps/Route110/scripts.pory"
	delay 20
# 682 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
# 683 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 684 "data/maps/Route110/scripts.pory"
	delay 30
# 685 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
# 686 "data/maps/Route110/scripts.pory"
	closemessage
# 687 "data/maps/Route110/scripts.pory"
	delay 30
# 688 "data/maps/Route110/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 689 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
# 690 "data/maps/Route110/scripts.pory"
	waitfanfare
# 691 "data/maps/Route110/scripts.pory"
	closemessage
# 692 "data/maps/Route110/scripts.pory"
	delay 30
# 693 "data/maps/Route110/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 694 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
# 695 "data/maps/Route110/scripts.pory"
	closemessage
# 696 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
# 697 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
# 698 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
# 699 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
# 700 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_BIRCH
# 701 "data/maps/Route110/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 702 "data/maps/Route110/scripts.pory"
	releaseall
# 703 "data/maps/Route110/scripts.pory"
	end
# 704 "data/maps/Route110/scripts.pory"

# 705 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer1::
# 706 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
# 707 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 708 "data/maps/Route110/scripts.pory"
	return
# 709 "data/maps/Route110/scripts.pory"

# 710 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer2::
# 711 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
# 712 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 713 "data/maps/Route110/scripts.pory"
	return
# 714 "data/maps/Route110/scripts.pory"

# 715 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer3::
# 716 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
# 717 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 718 "data/maps/Route110/scripts.pory"
	return
# 719 "data/maps/Route110/scripts.pory"

# 720 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer4::
# 721 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
# 722 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 723 "data/maps/Route110/scripts.pory"
	return
# 724 "data/maps/Route110/scripts.pory"

# 725 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit1::
# 726 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
# 727 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 728 "data/maps/Route110/scripts.pory"
	return
# 729 "data/maps/Route110/scripts.pory"

# 730 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit2::
# 731 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
# 732 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 733 "data/maps/Route110/scripts.pory"
	return
# 734 "data/maps/Route110/scripts.pory"

# 735 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit3::
# 736 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
# 737 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 738 "data/maps/Route110/scripts.pory"
	return
# 739 "data/maps/Route110/scripts.pory"

# 740 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit4::
# 741 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
# 742 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 743 "data/maps/Route110/scripts.pory"
	return
# 744 "data/maps/Route110/scripts.pory"

# 745 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchEntrance:
# 746 "data/maps/Route110/scripts.pory"
	walk_down
# 747 "data/maps/Route110/scripts.pory"
	walk_down
# 748 "data/maps/Route110/scripts.pory"
	walk_down
# 749 "data/maps/Route110/scripts.pory"
	step_end
# 750 "data/maps/Route110/scripts.pory"

# 751 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer1:
# 752 "data/maps/Route110/scripts.pory"
	walk_down
# 753 "data/maps/Route110/scripts.pory"
	walk_left
# 754 "data/maps/Route110/scripts.pory"
	walk_left
# 755 "data/maps/Route110/scripts.pory"
	walk_down
# 756 "data/maps/Route110/scripts.pory"
	step_end
# 757 "data/maps/Route110/scripts.pory"

# 758 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer2:
# 759 "data/maps/Route110/scripts.pory"
	walk_down
# 760 "data/maps/Route110/scripts.pory"
	walk_left
# 761 "data/maps/Route110/scripts.pory"
	walk_down
# 762 "data/maps/Route110/scripts.pory"
	step_end
# 763 "data/maps/Route110/scripts.pory"

# 764 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer3:
# 765 "data/maps/Route110/scripts.pory"
	walk_down
# 766 "data/maps/Route110/scripts.pory"
	walk_down
# 767 "data/maps/Route110/scripts.pory"
	step_end
# 768 "data/maps/Route110/scripts.pory"

# 769 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer4:
# 770 "data/maps/Route110/scripts.pory"
	walk_down
# 771 "data/maps/Route110/scripts.pory"
	walk_right
# 772 "data/maps/Route110/scripts.pory"
	walk_down
# 773 "data/maps/Route110/scripts.pory"
	step_end
# 774 "data/maps/Route110/scripts.pory"

# 775 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit1:
# 776 "data/maps/Route110/scripts.pory"
	walk_up
# 777 "data/maps/Route110/scripts.pory"
	walk_up
# 778 "data/maps/Route110/scripts.pory"
	walk_right
# 779 "data/maps/Route110/scripts.pory"
	walk_up
# 780 "data/maps/Route110/scripts.pory"
	walk_up
# 781 "data/maps/Route110/scripts.pory"
	walk_up
# 782 "data/maps/Route110/scripts.pory"
	step_end
# 783 "data/maps/Route110/scripts.pory"

# 784 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit2:
# 785 "data/maps/Route110/scripts.pory"
	walk_up
# 786 "data/maps/Route110/scripts.pory"
	walk_up
# 787 "data/maps/Route110/scripts.pory"
	walk_up
# 788 "data/maps/Route110/scripts.pory"
	walk_up
# 789 "data/maps/Route110/scripts.pory"
	walk_up
# 790 "data/maps/Route110/scripts.pory"
	step_end
# 791 "data/maps/Route110/scripts.pory"

# 792 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit3:
# 793 "data/maps/Route110/scripts.pory"
	walk_up
# 794 "data/maps/Route110/scripts.pory"
	walk_up
# 795 "data/maps/Route110/scripts.pory"
	walk_up
# 796 "data/maps/Route110/scripts.pory"
	walk_up
# 797 "data/maps/Route110/scripts.pory"
	walk_up
# 798 "data/maps/Route110/scripts.pory"
	step_end
# 799 "data/maps/Route110/scripts.pory"

# 800 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit4:
# 801 "data/maps/Route110/scripts.pory"
	walk_up
# 802 "data/maps/Route110/scripts.pory"
	walk_up
# 803 "data/maps/Route110/scripts.pory"
	walk_up
# 804 "data/maps/Route110/scripts.pory"
	walk_up
# 805 "data/maps/Route110/scripts.pory"
	walk_up
# 806 "data/maps/Route110/scripts.pory"
	step_end
# 807 "data/maps/Route110/scripts.pory"

# 808 "data/maps/Route110/scripts.pory"
Route110_EventScript_Wally::
# 809 "data/maps/Route110/scripts.pory"
	lockall
# 810 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WallyRoute110Thinking, MSGBOX_DEFAULT
# 811 "data/maps/Route110/scripts.pory"
	closemessage
# 812 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 813 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
# 814 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 815 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
# 816 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 817 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_Delay48
# 818 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 819 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WallyLetsBattle, MSGBOX_DEFAULT
# 820 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_ROUTE_110, Route110_Text_WallyDefeated
# 821 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_AfterWallyBattle
# 822 "data/maps/Route110/scripts.pory"
	end
# 823 "data/maps/Route110/scripts.pory"

# 824 "data/maps/Route110/scripts.pory"
Route110_EventScript_AfterWallyBattle::
# 825 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WallyTimeToHeadBack, MSGBOX_DEFAULT
# 826 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_WallyExit
# 827 "data/maps/Route110/scripts.pory"
	end
# 828 "data/maps/Route110/scripts.pory"

# 829 "data/maps/Route110/scripts.pory"
Route110_EventScript_WallyExit::
# 830 "data/maps/Route110/scripts.pory"
	closemessage
# 831 "data/maps/Route110/scripts.pory"
	switch VAR_FACING
# 832 "data/maps/Route110/scripts.pory"
	case DIR_NORTH, Route110_EventScript_WallyExitFacingNorth
# 833 "data/maps/Route110/scripts.pory"
	case DIR_WEST, Route110_EventScript_WallyExitFacingEastOrWest
# 834 "data/maps/Route110/scripts.pory"
	case DIR_EAST, Route110_EventScript_WallyExitFacingEastOrWest
# 835 "data/maps/Route110/scripts.pory"
	case DIR_SOUTH, Route110_EventScript_WallyExitFacingNorth
# 836 "data/maps/Route110/scripts.pory"
	end
# 837 "data/maps/Route110/scripts.pory"

# 838 "data/maps/Route110/scripts.pory"
Route110_EventScript_WallyExitFacingNorth::
# 839 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_WALLY, Route110_Movement_WallyExitFacingNorth
# 840 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 841 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_WallyEnd
# 842 "data/maps/Route110/scripts.pory"
	end
# 843 "data/maps/Route110/scripts.pory"

# 844 "data/maps/Route110/scripts.pory"
Route110_EventScript_WallyExitFacingEastOrWest::
# 845 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_WALLY, Route110_Movement_WallyExitFacingEastWest
# 846 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 847 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_WallyEnd
# 848 "data/maps/Route110/scripts.pory"
	end
# 849 "data/maps/Route110/scripts.pory"

# 850 "data/maps/Route110/scripts.pory"
Route110_EventScript_WallyEnd::
# 851 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_WALLY
# 852 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 853 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 854 "data/maps/Route110/scripts.pory"
	releaseall
# 855 "data/maps/Route110/scripts.pory"
	end
# 856 "data/maps/Route110/scripts.pory"

# 857 "data/maps/Route110/scripts.pory"
Route110_Movement_WallyExitFacingNorth:
# 858 "data/maps/Route110/scripts.pory"
	walk_right
# 859 "data/maps/Route110/scripts.pory"
	walk_down
# 860 "data/maps/Route110/scripts.pory"
	walk_down
# 861 "data/maps/Route110/scripts.pory"
	walk_down
# 862 "data/maps/Route110/scripts.pory"
	walk_right
# 863 "data/maps/Route110/scripts.pory"
	walk_right
# 864 "data/maps/Route110/scripts.pory"
	walk_right
# 865 "data/maps/Route110/scripts.pory"
	walk_right
# 866 "data/maps/Route110/scripts.pory"
	walk_right
# 867 "data/maps/Route110/scripts.pory"
	walk_right
# 868 "data/maps/Route110/scripts.pory"
	walk_right
# 869 "data/maps/Route110/scripts.pory"
	walk_right
# 870 "data/maps/Route110/scripts.pory"
	walk_right
# 871 "data/maps/Route110/scripts.pory"
	walk_right
# 872 "data/maps/Route110/scripts.pory"
	step_end
# 873 "data/maps/Route110/scripts.pory"

# 874 "data/maps/Route110/scripts.pory"
Route110_Movement_WallyExitFacingEastWest:
# 875 "data/maps/Route110/scripts.pory"
	walk_down
# 876 "data/maps/Route110/scripts.pory"
	walk_down
# 877 "data/maps/Route110/scripts.pory"
	walk_down
# 878 "data/maps/Route110/scripts.pory"
	walk_right
# 879 "data/maps/Route110/scripts.pory"
	walk_right
# 880 "data/maps/Route110/scripts.pory"
	walk_right
# 881 "data/maps/Route110/scripts.pory"
	walk_right
# 882 "data/maps/Route110/scripts.pory"
	walk_right
# 883 "data/maps/Route110/scripts.pory"
	walk_right
# 884 "data/maps/Route110/scripts.pory"
	walk_right
# 885 "data/maps/Route110/scripts.pory"
	walk_right
# 886 "data/maps/Route110/scripts.pory"
	walk_right
# 887 "data/maps/Route110/scripts.pory"
	walk_right
# 888 "data/maps/Route110/scripts.pory"
	walk_right
# 889 "data/maps/Route110/scripts.pory"
	step_end
# 890 "data/maps/Route110/scripts.pory"

# 891 "data/maps/Route110/scripts.pory"
Route110_Text_WallyRoute110Thinking:
# 892 "data/maps/Route110/scripts.pory"
	.string "Wally: Hmm… Norman said I should try\n"
# 893 "data/maps/Route110/scripts.pory"
	.string "battling in here to get stronger, but\l"
# 894 "data/maps/Route110/scripts.pory"
	.string "will I even be able to hold my own?$"
# 895 "data/maps/Route110/scripts.pory"

# 896 "data/maps/Route110/scripts.pory"
Route110_Text_WallyLetsBattle:
# 897 "data/maps/Route110/scripts.pory"
	.string "Ahh!\p"
# 898 "data/maps/Route110/scripts.pory"
	.string "Geez, don't sneak up on me like that,\n"
# 899 "data/maps/Route110/scripts.pory"
	.string "{PLAYER}.\p"
# 900 "data/maps/Route110/scripts.pory"
	.string "I've gotten a lot stronger since our\n"
# 901 "data/maps/Route110/scripts.pory"
	.string "battle in Mauville!\p"
# 902 "data/maps/Route110/scripts.pory"
	.string "Norman, I mean um, your Dad, even gave\n"
# 903 "data/maps/Route110/scripts.pory"
	.string "me my own Mega Ring!\p"
# 904 "data/maps/Route110/scripts.pory"
	.string "Gardevoir and I have been working\n"
# 905 "data/maps/Route110/scripts.pory"
	.string "really hard…\p"
# 906 "data/maps/Route110/scripts.pory"
	.string "I've been here contemplating going into\n"
# 907 "data/maps/Route110/scripts.pory"
	.string "the Trick House for a while, but I'm\l"
# 908 "data/maps/Route110/scripts.pory"
	.string "still a little hesitant.\p"
# 909 "data/maps/Route110/scripts.pory"
	.string "I have an idea, let's battle out here,\n"
# 910 "data/maps/Route110/scripts.pory"
	.string "and the winner gets to go into the\l"
# 911 "data/maps/Route110/scripts.pory"
	.string "Trick House first!\p"
# 912 "data/maps/Route110/scripts.pory"
	.string "Ok, here I come!$"
# 913 "data/maps/Route110/scripts.pory"

# 914 "data/maps/Route110/scripts.pory"
Route110_Text_WallyDefeated:
# 915 "data/maps/Route110/scripts.pory"
	.string "Looks like I still wasn't strong\n"
# 916 "data/maps/Route110/scripts.pory"
	.string "enough…$"
# 917 "data/maps/Route110/scripts.pory"

# 918 "data/maps/Route110/scripts.pory"
Route110_Text_WallyTimeToHeadBack:
# 919 "data/maps/Route110/scripts.pory"
	.string "Great battle, {PLAYER}. Even though I\n"
# 920 "data/maps/Route110/scripts.pory"
	.string "lost to you again, I can feel myself\l"
# 921 "data/maps/Route110/scripts.pory"
	.string "getting stronger.\p"
# 922 "data/maps/Route110/scripts.pory"
	.string "You can go into the Trick House first\n"
# 923 "data/maps/Route110/scripts.pory"
	.string "since you won, I'll head off to train\l"
# 924 "data/maps/Route110/scripts.pory"
	.string "somewhere else before coming back.\p"
# 925 "data/maps/Route110/scripts.pory"
	.string "Watch your back, {PLAYER}, I'm going to\n"
# 926 "data/maps/Route110/scripts.pory"
	.string "keep training, and I'll catch up to you\l"
# 927 "data/maps/Route110/scripts.pory"
	.string "one day!$"
# 928 "data/maps/Route110/scripts.pory"

# 929 "data/maps/Route110/scripts.pory"
Route110_Text_WeCantTalkAboutAquaActivities:
# 930 "data/maps/Route110/scripts.pory"
	.string "Team Aqua's activities…\n"
# 931 "data/maps/Route110/scripts.pory"
	.string "We can't talk about them yet.$"
# 932 "data/maps/Route110/scripts.pory"

# 933 "data/maps/Route110/scripts.pory"
Route110_Text_KickUpARuckus:
# 934 "data/maps/Route110/scripts.pory"
	.string "I want to get going to Slateport and\n"
# 935 "data/maps/Route110/scripts.pory"
	.string "kick up a ruckus!$"
# 936 "data/maps/Route110/scripts.pory"

# 937 "data/maps/Route110/scripts.pory"
Route110_Text_MyFirstJobInAqua:
# 938 "data/maps/Route110/scripts.pory"
	.string "This is my first job after joining\n"
# 939 "data/maps/Route110/scripts.pory"
	.string "Team Aqua. It's a little scary.$"
# 940 "data/maps/Route110/scripts.pory"

# 941 "data/maps/Route110/scripts.pory"
Route110_Text_AquaActionsBringSmiles:
# 942 "data/maps/Route110/scripts.pory"
	.string "Team Aqua's actions should bring\n"
# 943 "data/maps/Route110/scripts.pory"
	.string "smiles to people's faces!$"
# 944 "data/maps/Route110/scripts.pory"

# 945 "data/maps/Route110/scripts.pory"
Route110_Text_MayLetsBattle:
# 946 "data/maps/Route110/scripts.pory"
	.string "May: Hi, {PLAYER}{KUN}, long time no see!\p"
# 947 "data/maps/Route110/scripts.pory"
	.string "While I was searching for other\n"
# 948 "data/maps/Route110/scripts.pory"
	.string "Pokémon, my Pokémon grew stronger.\p"
# 949 "data/maps/Route110/scripts.pory"
	.string "So…\n"
# 950 "data/maps/Route110/scripts.pory"
	.string "How about a little battle?$"
# 951 "data/maps/Route110/scripts.pory"

# 952 "data/maps/Route110/scripts.pory"
Route110_Text_MayDefeated:
# 953 "data/maps/Route110/scripts.pory"
	.string "Yikes!\n"
# 954 "data/maps/Route110/scripts.pory"
	.string "You're better than I expected!$"
# 955 "data/maps/Route110/scripts.pory"

# 956 "data/maps/Route110/scripts.pory"
Route110_Text_MayTakeThis:
# 957 "data/maps/Route110/scripts.pory"
	.string "May: {PLAYER}{KUN}, you've been busy\n"
# 958 "data/maps/Route110/scripts.pory"
	.string "training, too, haven't you?\p"
# 959 "data/maps/Route110/scripts.pory"
	.string "I think you deserve a reward!\n"
# 960 "data/maps/Route110/scripts.pory"
	.string "These are from me!\p"
# 961 "data/maps/Route110/scripts.pory"
	.string "I've got some things to help you\n"
# 962 "data/maps/Route110/scripts.pory"
	.string "on your journey.$"
# 963 "data/maps/Route110/scripts.pory"

# 964 "data/maps/Route110/scripts.pory"
Route110_Text_RivalExplainFlyHM:
# 965 "data/maps/Route110/scripts.pory"
	.string "As you can see, {COLOR GREEN}{SHADOW LIGHT_GREEN}I just gave you the\n"
# 966 "data/maps/Route110/scripts.pory"
	.string "HM02 Fly.\p"
# 967 "data/maps/Route110/scripts.pory"
	.string "Any Pokémon that can learn Fly should\n"
# 968 "data/maps/Route110/scripts.pory"
	.string "now have it in your party menu,{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} and the\l"
# 969 "data/maps/Route110/scripts.pory"
	.string "Badge requirement to use it has been\l"
# 970 "data/maps/Route110/scripts.pory"
	.string "removed! If you don't believe me, give\l"
# 971 "data/maps/Route110/scripts.pory"
	.string "it a try!$"
# 972 "data/maps/Route110/scripts.pory"

# 973 "data/maps/Route110/scripts.pory"
Route110_Text_RivalThatsNotAll::
# 974 "data/maps/Route110/scripts.pory"
	.string "That's not all I have for you.\n"
# 975 "data/maps/Route110/scripts.pory"
	.string "Here, take these as well.$"
# 976 "data/maps/Route110/scripts.pory"

# 977 "data/maps/Route110/scripts.pory"
Route110_Text_RivalExplainRestOfItems::
# 978 "data/maps/Route110/scripts.pory"
	.string "I just gave you the following Items:\n"
# 979 "data/maps/Route110/scripts.pory"
	.string "the Dowsing MCHN, the TMs for\l"
# 980 "data/maps/Route110/scripts.pory"
	.string "Fire Punch, Ice Punch, Thunder Punch,\l"
# 981 "data/maps/Route110/scripts.pory"
	.string "Fire Fang, Ice Fang, Thunder Fang,\l"
# 982 "data/maps/Route110/scripts.pory"
	.string "Psychic Fangs, and Poison Fang, some\l"
# 983 "data/maps/Route110/scripts.pory"
	.string "more types of Poké Balls, Shiny Stones,\l"
# 984 "data/maps/Route110/scripts.pory"
	.string "Ice Stones, Black Sludges, Flame Orbs,\l"
# 985 "data/maps/Route110/scripts.pory"
	.string "Toxic Orbs, Smoke Balls, Thick Clubs,\l"
# 986 "data/maps/Route110/scripts.pory"
	.string "Weakness Policies, Terrain Extenders,\l"
# 987 "data/maps/Route110/scripts.pory"
	.string "Shed Shells, Light Clays, and some\l"
# 988 "data/maps/Route110/scripts.pory"
	.string "Terrain Seeds.\p"
# 989 "data/maps/Route110/scripts.pory"
	.string "Whew, I think that's everything, you\n"
# 990 "data/maps/Route110/scripts.pory"
	.string "might want to take a look through your\l"
# 991 "data/maps/Route110/scripts.pory"
	.string "Bag pockets to see what you have now!\p"
# 992 "data/maps/Route110/scripts.pory"
	.string "I'll be going now, {PLAYER}, keep up the\n"
# 993 "data/maps/Route110/scripts.pory"
	.string "good work!$"
# 994 "data/maps/Route110/scripts.pory"

# 995 "data/maps/Route110/scripts.pory"

# 996 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanLetsBattle:
# 997 "data/maps/Route110/scripts.pory"
	.string "Brendan: Hey, {PLAYER}.\n"
# 998 "data/maps/Route110/scripts.pory"
	.string "So this is where you were.\l"
# 999 "data/maps/Route110/scripts.pory"
	.string "How's it going?\p"
# 1000 "data/maps/Route110/scripts.pory"
	.string "Have you been raising your Pokémon?\n"
# 1001 "data/maps/Route110/scripts.pory"
	.string "I'll check for you.$"
# 1002 "data/maps/Route110/scripts.pory"

# 1003 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanDefeated:
# 1004 "data/maps/Route110/scripts.pory"
	.string "Hmm…\n"
# 1005 "data/maps/Route110/scripts.pory"
	.string "You're pretty good.$"
# 1006 "data/maps/Route110/scripts.pory"

# 1007 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanTakeThis:
# 1008 "data/maps/Route110/scripts.pory"
	.string "Brendan: {PLAYER}, you've trained\n"
# 1009 "data/maps/Route110/scripts.pory"
	.string "without me noticing…\p"
# 1010 "data/maps/Route110/scripts.pory"
	.string "Good enough!\n"
# 1011 "data/maps/Route110/scripts.pory"
	.string "Here, take these,\p"
# 1012 "data/maps/Route110/scripts.pory"
	.string "I've got some things to help you\n"
# 1013 "data/maps/Route110/scripts.pory"
	.string "on your journey.$"
# 1014 "data/maps/Route110/scripts.pory"

# 1015 "data/maps/Route110/scripts.pory"
Route110_Text_RideBikeAtFullSpeed:
# 1016 "data/maps/Route110/scripts.pory"
	.string "Wouldn't it be great to ride a BIKE\n"
# 1017 "data/maps/Route110/scripts.pory"
	.string "at full speed on CYCLING ROAD?$"
# 1018 "data/maps/Route110/scripts.pory"

# 1019 "data/maps/Route110/scripts.pory"
Route110_Text_HairStreamsBehindMe:
# 1020 "data/maps/Route110/scripts.pory"
	.string "How do you like the way my raven-\n"
# 1021 "data/maps/Route110/scripts.pory"
	.string "colored hair streams behind me?\p"
# 1022 "data/maps/Route110/scripts.pory"
	.string "I grew my hair out just for that.$"
# 1023 "data/maps/Route110/scripts.pory"

# 1024 "data/maps/Route110/scripts.pory"
Route110_Text_YouGotBikeFromRydel:
# 1025 "data/maps/Route110/scripts.pory"
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
# 1026 "data/maps/Route110/scripts.pory"
	.string "Oh, it's glaringly obvious.\n"
# 1027 "data/maps/Route110/scripts.pory"
	.string "It says right on your bike…\p"
# 1028 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1029 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1030 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1031 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1032 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1033 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1034 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1035 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1036 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
# 1037 "data/maps/Route110/scripts.pory"
	.string "That name's everywhere.\p"
# 1038 "data/maps/Route110/scripts.pory"
	.string "You should ride it around all over\n"
# 1039 "data/maps/Route110/scripts.pory"
	.string "the place--it's good advertising!$"
# 1040 "data/maps/Route110/scripts.pory"

# 1041 "data/maps/Route110/scripts.pory"
Route110_Text_TwoRoads:
# 1042 "data/maps/Route110/scripts.pory"
	.string "The two roads, one above, one below…\p"
# 1043 "data/maps/Route110/scripts.pory"
	.string "A road each for people and Pokémon.\n"
# 1044 "data/maps/Route110/scripts.pory"
	.string "Perhaps that is right and fair.$"
# 1045 "data/maps/Route110/scripts.pory"

# 1046 "data/maps/Route110/scripts.pory"
Route110_Text_WalkOnTheLowRoad:
# 1047 "data/maps/Route110/scripts.pory"
	.string "I don't have a BIKE, so I'll take\n"
# 1048 "data/maps/Route110/scripts.pory"
	.string "a leisurely walk on the low road.$"
# 1049 "data/maps/Route110/scripts.pory"

# 1050 "data/maps/Route110/scripts.pory"
Route110_Text_BikeTechniques:
# 1051 "data/maps/Route110/scripts.pory"
	.string "Learning techniques will make BIKE\n"
# 1052 "data/maps/Route110/scripts.pory"
	.string "riding even more fun.\p"
# 1053 "data/maps/Route110/scripts.pory"
	.string "There are some places that you can\n"
# 1054 "data/maps/Route110/scripts.pory"
	.string "reach only by using a BIKE technique.$"
# 1055 "data/maps/Route110/scripts.pory"

# 1056 "data/maps/Route110/scripts.pory"
Route110_Text_WhichShouldIChoose:
# 1057 "data/maps/Route110/scripts.pory"
	.string "Which should I choose?\p"
# 1058 "data/maps/Route110/scripts.pory"
	.string "Make a beeline for MAUVILLE on\n"
# 1059 "data/maps/Route110/scripts.pory"
	.string "CYCLING ROAD, or take the low road\l"
# 1060 "data/maps/Route110/scripts.pory"
	.string "and look for Pokémon?$"
# 1061 "data/maps/Route110/scripts.pory"

# 1062 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingChallengeResultSummary:
# 1063 "data/maps/Route110/scripts.pory"
	.string "Number of collisions:\n"
# 1064 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_1}!\p"
# 1065 "data/maps/Route110/scripts.pory"
	.string "Total time:\n"
# 1066 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_2}!$"
# 1067 "data/maps/Route110/scripts.pory"

# 1068 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBest:
# 1069 "data/maps/Route110/scripts.pory"
	.string "Bravo! Splendid showing!\p"
# 1070 "data/maps/Route110/scripts.pory"
	.string "Your love of cycling comes from deep\n"
# 1071 "data/maps/Route110/scripts.pory"
	.string "within your heart.\l"
# 1072 "data/maps/Route110/scripts.pory"
	.string "You've shaken me to my very soul!$"
# 1073 "data/maps/Route110/scripts.pory"

# 1074 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionGood:
# 1075 "data/maps/Route110/scripts.pory"
	.string "Your technique is remarkable.\p"
# 1076 "data/maps/Route110/scripts.pory"
	.string "I suggest you speed up a bit while\n"
# 1077 "data/maps/Route110/scripts.pory"
	.string "still avoiding collisions.$"
# 1078 "data/maps/Route110/scripts.pory"

# 1079 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionOk:
# 1080 "data/maps/Route110/scripts.pory"
	.string "I would consider you a work in\n"
# 1081 "data/maps/Route110/scripts.pory"
	.string "progress.\p"
# 1082 "data/maps/Route110/scripts.pory"
	.string "Still, I hope you don't forget the\n"
# 1083 "data/maps/Route110/scripts.pory"
	.string "sheer pleasure of cycling.$"
# 1084 "data/maps/Route110/scripts.pory"

# 1085 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBad:
# 1086 "data/maps/Route110/scripts.pory"
	.string "My word… Your cycling skills border\n"
# 1087 "data/maps/Route110/scripts.pory"
	.string "on terrifying.\p"
# 1088 "data/maps/Route110/scripts.pory"
	.string "Most certainly, you need much more\n"
# 1089 "data/maps/Route110/scripts.pory"
	.string "practice riding.$"
# 1090 "data/maps/Route110/scripts.pory"

# 1091 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionWorst:
# 1092 "data/maps/Route110/scripts.pory"
	.string "…I am aghast…\p"
# 1093 "data/maps/Route110/scripts.pory"
	.string "You're perhaps not cut out for this\n"
# 1094 "data/maps/Route110/scripts.pory"
	.string "unfortunate cycling business.\p"
# 1095 "data/maps/Route110/scripts.pory"
	.string "You ought to give serious thought to\n"
# 1096 "data/maps/Route110/scripts.pory"
	.string "returning that BIKE to RYDEL.$"
# 1097 "data/maps/Route110/scripts.pory"

# 1098 "data/maps/Route110/scripts.pory"
Route110_Text_RatedForNumberOfCollisions:
# 1099 "data/maps/Route110/scripts.pory"
	.string "This is CYCLING ROAD.\p"
# 1100 "data/maps/Route110/scripts.pory"
	.string "If you were to ride from MAUVILLE to\n"
# 1101 "data/maps/Route110/scripts.pory"
	.string "Slateport on a MACH BIKE, you would\l"
# 1102 "data/maps/Route110/scripts.pory"
	.string "be rated for the number of collisions\l"
# 1103 "data/maps/Route110/scripts.pory"
	.string "and your total time.$"
# 1104 "data/maps/Route110/scripts.pory"

# 1105 "data/maps/Route110/scripts.pory"
Route110_Text_AlwaysAimHigher:
# 1106 "data/maps/Route110/scripts.pory"
	.string "Regardless of the results, I count on\n"
# 1107 "data/maps/Route110/scripts.pory"
	.string "seeing more challenges from you.\l"
# 1108 "data/maps/Route110/scripts.pory"
	.string "Always aim higher!$"
# 1109 "data/maps/Route110/scripts.pory"

# 1110 "data/maps/Route110/scripts.pory"
Route110_Text_AcroBikesDoNotQualify:
# 1111 "data/maps/Route110/scripts.pory"
	.string "On this CYCLING ROAD, those riding\n"
# 1112 "data/maps/Route110/scripts.pory"
	.string "MACH BIKES are rated for their number\l"
# 1113 "data/maps/Route110/scripts.pory"
	.string "of collisions and their total times.\p"
# 1114 "data/maps/Route110/scripts.pory"
	.string "ACRO BIKES do not qualify for rating.\n"
# 1115 "data/maps/Route110/scripts.pory"
	.string "They are easy to turn, so it's not fair.$"
# 1116 "data/maps/Route110/scripts.pory"

# 1117 "data/maps/Route110/scripts.pory"
Route110_Text_SlateportCitySign:
# 1118 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 1119 "data/maps/Route110/scripts.pory"
	.string "{DOWN_ARROW} Slateport City$"
# 1120 "data/maps/Route110/scripts.pory"

# 1121 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingRoadSign:
# 1122 "data/maps/Route110/scripts.pory"
	.string "SEASIDE CYCLING ROAD$"
# 1123 "data/maps/Route110/scripts.pory"

# 1124 "data/maps/Route110/scripts.pory"
Route110_Text_AquaWasHere:
# 1125 "data/maps/Route110/scripts.pory"
	.string "“Team Aqua was here!”\p"
# 1126 "data/maps/Route110/scripts.pory"
	.string "Someone painted that onto this sign,\n"
# 1127 "data/maps/Route110/scripts.pory"
	.string "but then someone else painted over it.\p"
# 1128 "data/maps/Route110/scripts.pory"
	.string "“Team Magma rules!” is what it\n"
# 1129 "data/maps/Route110/scripts.pory"
	.string "says now.$"
# 1130 "data/maps/Route110/scripts.pory"

# 1131 "data/maps/Route110/scripts.pory"
Route110_Text_Route103Sign:
# 1132 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 1133 "data/maps/Route110/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 103$"
# 1134 "data/maps/Route110/scripts.pory"

# 1135 "data/maps/Route110/scripts.pory"
Route110_Text_SeasideParkingSign:
# 1136 "data/maps/Route110/scripts.pory"
	.string "SEASIDE PARKING$"
# 1137 "data/maps/Route110/scripts.pory"

# 1138 "data/maps/Route110/scripts.pory"
Route110_Text_MauvilleCitySign:
# 1139 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 1140 "data/maps/Route110/scripts.pory"
	.string "{UP_ARROW} MAUVILLE CITY$"
# 1141 "data/maps/Route110/scripts.pory"

# 1142 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsPrlzSleep:
# 1143 "data/maps/Route110/scripts.pory"
	.string "Trainer Tips\p"
# 1144 "data/maps/Route110/scripts.pory"
	.string "You can press the “R” button while\n"
# 1145 "data/maps/Route110/scripts.pory"
	.string "choosing a move in battle to see\l"
# 1146 "data/maps/Route110/scripts.pory"
	.string "information about it.$"
# 1147 "data/maps/Route110/scripts.pory"

# 1148 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsRegisterItems:
# 1149 "data/maps/Route110/scripts.pory"
	.string "Trainer Tips\p"
# 1150 "data/maps/Route110/scripts.pory"
	.string "The Pokédex contains information\n"
# 1151 "data/maps/Route110/scripts.pory"
	.string "about a Pokémon's learnsets and\l"
# 1152 "data/maps/Route110/scripts.pory"
	.string "evolution methods.$"
# 1153 "data/maps/Route110/scripts.pory"

# 1154 "data/maps/Route110/scripts.pory"
Route110_Text_TrickHouseSign:
# 1155 "data/maps/Route110/scripts.pory"
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
# 1156 "data/maps/Route110/scripts.pory"
	.string "to reach the wondrous TRICK HOUSE.”$"
# 1157 "data/maps/Route110/scripts.pory"

# 1158 "data/maps/Route110/scripts.pory"
Route110_Text_BestRecord:
# 1159 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 1160 "data/maps/Route110/scripts.pory"
	.string "No. of collisions: {STR_VAR_1}\p"
# 1161 "data/maps/Route110/scripts.pory"
	.string "Elapsed time: {STR_VAR_2}$"
# 1162 "data/maps/Route110/scripts.pory"

# 1163 "data/maps/Route110/scripts.pory"
Route110_Text_ThereIsNoRecord:
# 1164 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 1165 "data/maps/Route110/scripts.pory"
	.string "No one seems to have taken the\n"
# 1166 "data/maps/Route110/scripts.pory"
	.string "challenge. There is no record…$"
# 1167 "data/maps/Route110/scripts.pory"

# 1168 "data/maps/Route110/scripts.pory"
Route110_Text_ImagineSeeingYouHere:
# 1169 "data/maps/Route110/scripts.pory"
	.string "Prof. Birch: Oh, {PLAYER}{KUN}!\n"
# 1170 "data/maps/Route110/scripts.pory"
	.string "Imagine seeing you here!\p"
# 1171 "data/maps/Route110/scripts.pory"
	.string "And where might my {RIVAL} be?$"
# 1172 "data/maps/Route110/scripts.pory"

# 1173 "data/maps/Route110/scripts.pory"
Route110_Text_HeardYouInstallMatchCall:
# 1174 "data/maps/Route110/scripts.pory"
	.string "Oh, I see!\n"
# 1175 "data/maps/Route110/scripts.pory"
	.string "You two are running separately.\l"
# 1176 "data/maps/Route110/scripts.pory"
	.string "Well, that's fine.\p"
# 1177 "data/maps/Route110/scripts.pory"
	.string "Oh, yes, I heard that your PokéNav\n"
# 1178 "data/maps/Route110/scripts.pory"
	.string "had the Match Call system installed.\p"
# 1179 "data/maps/Route110/scripts.pory"
	.string "Well, then, I should register you in\n"
# 1180 "data/maps/Route110/scripts.pory"
	.string "my PokéNav as well.\p"
# 1181 "data/maps/Route110/scripts.pory"
	.string "That way, even when we're apart,\n"
# 1182 "data/maps/Route110/scripts.pory"
	.string "I can rate your Pokédex anytime.\p"
# 1183 "data/maps/Route110/scripts.pory"
	.string "… … … … … …$"
# 1184 "data/maps/Route110/scripts.pory"

# 1185 "data/maps/Route110/scripts.pory"
Route110_Text_RegisteredBirchInPokenav:
# 1186 "data/maps/Route110/scripts.pory"
	.string "Registered Prof. Birch\n"
# 1187 "data/maps/Route110/scripts.pory"
	.string "in the PokéNav.$"
# 1188 "data/maps/Route110/scripts.pory"

# 1189 "data/maps/Route110/scripts.pory"
Route110_Text_KeepAnEyeOutForRival:
# 1190 "data/maps/Route110/scripts.pory"
	.string "Prof. Birch: {PLAYER}{KUN}…\p"
# 1191 "data/maps/Route110/scripts.pory"
	.string "Please keep an eye out for my {RIVAL}.\n"
# 1192 "data/maps/Route110/scripts.pory"
	.string "… … … … … …\p"
# 1193 "data/maps/Route110/scripts.pory"
	.string "Well, I had better get going.\n"
# 1194 "data/maps/Route110/scripts.pory"
	.string "See you again, {PLAYER}{KUN}!$"

Route110_Trigger_BlockTrickHouse::
# 1199 "data/maps/Route110/scripts.pory"
	lockall
# 1200 "data/maps/Route110/scripts.pory"
	msgbox TrickHouseMessage
# 1201 "data/maps/Route110/scripts.pory"
	waitmessage
# 1202 "data/maps/Route110/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, StopPlayer
# 1203 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 1204 "data/maps/Route110/scripts.pory"
	releaseall
	end


TrickHouseMessage::
# 1208 "data/maps/Route110/scripts.pory"
	.string "“Puzzles under construction,\n"
	.string "come back later” - The Trick Master$"
