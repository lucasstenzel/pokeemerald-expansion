# 1 "data/maps/EverGrandeCity/scripts.pory"

# 2 "data/maps/EverGrandeCity/scripts.pory"
.set LOCALID_VOLKNER, 3
# 3 "data/maps/EverGrandeCity/scripts.pory"

# 4 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_MapScripts::
# 5 "data/maps/EverGrandeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
# 6 "data/maps/EverGrandeCity/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity/scripts.pory"

# 8 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_OnTransition:
# 9 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 10 "data/maps/EverGrandeCity/scripts.pory"
	call_if_unset FLAG_BEAT_BOTH_RIVALS, Common_EventScript_SetupRivalGfxId
# 11 "data/maps/EverGrandeCity/scripts.pory"
	end
# 12 "data/maps/EverGrandeCity/scripts.pory"

# 13 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadSign::
# 14 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
# 15 "data/maps/EverGrandeCity/scripts.pory"
	end
# 16 "data/maps/EverGrandeCity/scripts.pory"

# 17 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_CitySign::
# 18 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
# 19 "data/maps/EverGrandeCity/scripts.pory"
	end
# 20 "data/maps/EverGrandeCity/scripts.pory"

# 21 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_PokemonLeagueSign::
# 22 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
# 23 "data/maps/EverGrandeCity/scripts.pory"
	end
# 24 "data/maps/EverGrandeCity/scripts.pory"

# 25 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_Rival::
# 26 "data/maps/EverGrandeCity/scripts.pory"
	lock
# 27 "data/maps/EverGrandeCity/scripts.pory"
	faceplayer
# 28 "data/maps/EverGrandeCity/scripts.pory"
	checkplayergender
# 29 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_EventScript_May
# 30 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_EventScript_Brendan
# 31 "data/maps/EverGrandeCity/scripts.pory"
	end
# 32 "data/maps/EverGrandeCity/scripts.pory"

# 33 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_May::
# 34 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_EVERGRANDE_CITY_BEAT_RIVAL, EverGrandeCity_EventScript_BeatRivalNotDawn
# 35 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_MayAskToBattleAgain
# 36 "data/maps/EverGrandeCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_MayAskToBattle
# 37 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_DeclineMayBattle
# 38 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 39 "data/maps/EverGrandeCity/scripts.pory"
	switch VAR_STARTER_MON
# 40 "data/maps/EverGrandeCity/scripts.pory"
	case 0, EverGrandeCity_EventScript_BattleMayTreecko
# 41 "data/maps/EverGrandeCity/scripts.pory"
	case 1, EverGrandeCity_EventScript_BattleMayTorchic
# 42 "data/maps/EverGrandeCity/scripts.pory"
	case 2, EverGrandeCity_EventScript_BattleMayMudkip
# 43 "data/maps/EverGrandeCity/scripts.pory"
	case 3, EverGrandeCity_EventScript_BattleMayGible
# 44 "data/maps/EverGrandeCity/scripts.pory"
	end
# 45 "data/maps/EverGrandeCity/scripts.pory"

# 46 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_MayAskToBattleAgain::
# 47 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_MayBattleMe, MSGBOX_YESNO
# 48 "data/maps/EverGrandeCity/scripts.pory"
	return
# 49 "data/maps/EverGrandeCity/scripts.pory"

# 50 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_MayAskToBattle::
# 51 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 52 "data/maps/EverGrandeCity/scripts.pory"
	return
# 53 "data/maps/EverGrandeCity/scripts.pory"

# 54 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_DeclineMayBattle::
# 55 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE
# 56 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 57 "data/maps/EverGrandeCity/scripts.pory"
	release
# 58 "data/maps/EverGrandeCity/scripts.pory"
	end
# 59 "data/maps/EverGrandeCity/scripts.pory"

# 60 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleMayTreecko::
# 61 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_EVERGRANDE_TREECKO, EverGrandeCity_Text_MayDefeat
# 62 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedMay
# 63 "data/maps/EverGrandeCity/scripts.pory"
	end
# 64 "data/maps/EverGrandeCity/scripts.pory"

# 65 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleMayTorchic::
# 66 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_EVERGRANDE_TORCHIC, EverGrandeCity_Text_MayDefeat
# 67 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedMay
# 68 "data/maps/EverGrandeCity/scripts.pory"
	end
# 69 "data/maps/EverGrandeCity/scripts.pory"

# 70 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleMayMudkip::
# 71 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_EVERGRANDE_MUDKIP, EverGrandeCity_Text_MayDefeat
# 72 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedMay
# 73 "data/maps/EverGrandeCity/scripts.pory"
	end
# 74 "data/maps/EverGrandeCity/scripts.pory"

# 75 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleMayGible::
# 76 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_EVERGRANDE_GIBLE, EverGrandeCity_Text_MayDefeat
# 77 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedMay
# 78 "data/maps/EverGrandeCity/scripts.pory"
	end
# 79 "data/maps/EverGrandeCity/scripts.pory"

# 80 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_DefeatedMay::
# 81 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_EVERGRANDE_CITY_BEAT_RIVAL
# 82 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_BEAT_DAWN_EVERGRANDE, EverGrandeCity_EventScript_RivalsFlyAway
# 83 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CanYouBeatDawn, MSGBOX_DEFAULT
# 84 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
# 85 "data/maps/EverGrandeCity/scripts.pory"
	end
# 86 "data/maps/EverGrandeCity/scripts.pory"

# 87 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_Brendan::
# 88 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_EVERGRANDE_CITY_BEAT_RIVAL, EverGrandeCity_EventScript_BeatRivalNotDawn
# 89 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_BrendanAskToBattleAgain
# 90 "data/maps/EverGrandeCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_BrendanAskToBattle
# 91 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_DeclineBrendanBattle
# 92 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 93 "data/maps/EverGrandeCity/scripts.pory"
	switch VAR_STARTER_MON
# 94 "data/maps/EverGrandeCity/scripts.pory"
	case 0, EverGrandeCity_EventScript_BattleBrendanTreecko
# 95 "data/maps/EverGrandeCity/scripts.pory"
	case 1, EverGrandeCity_EventScript_BattleBrendanTorchic
# 96 "data/maps/EverGrandeCity/scripts.pory"
	case 2, EverGrandeCity_EventScript_BattleBrendanMudkip
# 97 "data/maps/EverGrandeCity/scripts.pory"
	case 3, EverGrandeCity_EventScript_BattleBrendanGible
# 98 "data/maps/EverGrandeCity/scripts.pory"
	end
# 99 "data/maps/EverGrandeCity/scripts.pory"

# 100 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BrendanAskToBattleAgain::
# 101 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 102 "data/maps/EverGrandeCity/scripts.pory"
	return
# 103 "data/maps/EverGrandeCity/scripts.pory"

# 104 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BrendanAskToBattle::
# 105 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 106 "data/maps/EverGrandeCity/scripts.pory"
	return
# 107 "data/maps/EverGrandeCity/scripts.pory"

# 108 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_DeclineBrendanBattle::
# 109 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE
# 110 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 111 "data/maps/EverGrandeCity/scripts.pory"
	release
# 112 "data/maps/EverGrandeCity/scripts.pory"
	end
# 113 "data/maps/EverGrandeCity/scripts.pory"

# 114 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleBrendanTreecko::
# 115 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_EVERGRANDE_TREECKO, EverGrandeCity_Text_BrendanDefeat
# 116 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedBrendan
# 117 "data/maps/EverGrandeCity/scripts.pory"
	end
# 118 "data/maps/EverGrandeCity/scripts.pory"

# 119 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleBrendanTorchic::
# 120 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_EVERGRANDE_TORCHIC, EverGrandeCity_Text_BrendanDefeat
# 121 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedBrendan
# 122 "data/maps/EverGrandeCity/scripts.pory"
	end
# 123 "data/maps/EverGrandeCity/scripts.pory"

# 124 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleBrendanMudkip::
# 125 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_EVERGRANDE_MUDKIP, EverGrandeCity_Text_BrendanDefeat
# 126 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedBrendan
# 127 "data/maps/EverGrandeCity/scripts.pory"
	end
# 128 "data/maps/EverGrandeCity/scripts.pory"

# 129 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BattleBrendanGible::
# 130 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_EVERGRANDE_GIBLE, EverGrandeCity_Text_BrendanDefeat
# 131 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DefeatedBrendan
# 132 "data/maps/EverGrandeCity/scripts.pory"
	end
# 133 "data/maps/EverGrandeCity/scripts.pory"

# 134 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_DefeatedBrendan::
# 135 "data/maps/EverGrandeCity/scripts.pory"
    setflag FLAG_EVERGRANDE_CITY_BEAT_RIVAL
# 136 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_BEAT_DAWN_EVERGRANDE, EverGrandeCity_EventScript_RivalsFlyAway
# 137 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CanYouBeatDawn, MSGBOX_DEFAULT
# 138 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
# 139 "data/maps/EverGrandeCity/scripts.pory"
	end
# 140 "data/maps/EverGrandeCity/scripts.pory"

# 141 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_BeatRivalNotDawn::
# 142 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_NotMovingUntilDawn, MSGBOX_DEFAULT
# 143 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
# 144 "data/maps/EverGrandeCity/scripts.pory"
	end
# 145 "data/maps/EverGrandeCity/scripts.pory"

# 146 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_RivalFlyAway::
# 147 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
# 148 "data/maps/EverGrandeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 149 "data/maps/EverGrandeCity/scripts.pory"
	waitmovement 0
# 150 "data/maps/EverGrandeCity/scripts.pory"
	delay 50
# 151 "data/maps/EverGrandeCity/scripts.pory"
	setfieldeffectargument 0, 1
# 152 "data/maps/EverGrandeCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 153 "data/maps/EverGrandeCity/scripts.pory"
	delay 15
# 154 "data/maps/EverGrandeCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 155 "data/maps/EverGrandeCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 156 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 157 "data/maps/EverGrandeCity/scripts.pory"
	release
# 158 "data/maps/EverGrandeCity/scripts.pory"
	end
# 159 "data/maps/EverGrandeCity/scripts.pory"

# 160 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_SetVisitedEverGrande::
# 161 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 162 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 163 "data/maps/EverGrandeCity/scripts.pory"
	end
# 164 "data/maps/EverGrandeCity/scripts.pory"

# 165 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_MomRoamerCall::
# 166 "data/maps/EverGrandeCity/scripts.pory"
	lockall
# 167 "data/maps/EverGrandeCity/scripts.pory"
	pokenavcall MatchCall_Text_MomRoamers
# 168 "data/maps/EverGrandeCity/scripts.pory"
	waitmessage
# 169 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
# 170 "data/maps/EverGrandeCity/scripts.pory"
	special InitRoamer
# 171 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_ROAMER_MATCH_CALL
# 172 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
# 173 "data/maps/EverGrandeCity/scripts.pory"
	end
# 174 "data/maps/EverGrandeCity/scripts.pory"

# 175 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_MayShoppingLetsBattle:
# 176 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}! Dawn told me about\n"
# 177 "data/maps/EverGrandeCity/scripts.pory"
	.string "everything that happened with Team\l"
# 178 "data/maps/EverGrandeCity/scripts.pory"
	.string "Aqua, Team Magma, and Drake!\p"
# 179 "data/maps/EverGrandeCity/scripts.pory"
	.string "I can't believe what he did, but I'm\n"
# 180 "data/maps/EverGrandeCity/scripts.pory"
	.string "more impressed with how you were able\l"
# 181 "data/maps/EverGrandeCity/scripts.pory"
	.string "to stop all of them by yourself!\p"
# 182 "data/maps/EverGrandeCity/scripts.pory"
	.string "It feels silly to even say this, but we\n"
# 183 "data/maps/EverGrandeCity/scripts.pory"
	.string "wanted to give you one final test\l"
# 184 "data/maps/EverGrandeCity/scripts.pory"
	.string "before you head into Victory Road!\l"
# 185 "data/maps/EverGrandeCity/scripts.pory"
	.string "We are rivals after all!\p"
# 186 "data/maps/EverGrandeCity/scripts.pory"
	.string "Don't worry, we won't make you fight us\n"
# 187 "data/maps/EverGrandeCity/scripts.pory"
	.string "both at once. But you will have to beat\l"
# 188 "data/maps/EverGrandeCity/scripts.pory"
	.string "us both to get through! So…\p"
# 189 "data/maps/EverGrandeCity/scripts.pory"
	.string "What do you say to one last battle?$"
# 190 "data/maps/EverGrandeCity/scripts.pory"

# 191 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_MayNotRaisingPokemon:
# 192 "data/maps/EverGrandeCity/scripts.pory"
	.string "Oh, alright then. But just so you know,\n"
# 193 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'm not going anywhere until you beat\l"
# 194 "data/maps/EverGrandeCity/scripts.pory"
	.string "Dawn and me!$"
# 195 "data/maps/EverGrandeCity/scripts.pory"

# 196 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_MayBattleMe:
# 197 "data/maps/EverGrandeCity/scripts.pory"
	.string "Come on, battle with me one more time!\n"
# 198 "data/maps/EverGrandeCity/scripts.pory"
	.string "What do you say?$"
# 199 "data/maps/EverGrandeCity/scripts.pory"

# 200 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_MayWontBeBeaten:
# 201 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'll show you how strong I've become!$"
# 202 "data/maps/EverGrandeCity/scripts.pory"

# 203 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_MayDefeat:
# 204 "data/maps/EverGrandeCity/scripts.pory"
	.string "… … … … … … … …\p"
# 205 "data/maps/EverGrandeCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 206 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}{KUN}, on Route 103.\p"
# 207 "data/maps/EverGrandeCity/scripts.pory"
	.string "That battle helped you become this\n"
# 208 "data/maps/EverGrandeCity/scripts.pory"
	.string "strong, didn't it?$"
# 209 "data/maps/EverGrandeCity/scripts.pory"

# 210 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_MayGoingBackToLittleroot:
# 211 "data/maps/EverGrandeCity/scripts.pory"
	.string "Anyway, I'm thinking of going back to\n"
# 212 "data/maps/EverGrandeCity/scripts.pory"
	.string "Littleroot soon.\p"
# 213 "data/maps/EverGrandeCity/scripts.pory"
	.string "I've caught a decent group of Pokémon,\n"
# 214 "data/maps/EverGrandeCity/scripts.pory"
	.string "and my Pokédex is coming along, so\l"
# 215 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'm going home to show my dad.\p"
# 216 "data/maps/EverGrandeCity/scripts.pory"
	.string "Like Dawn said, you've got this,\n"
# 217 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}. I know you're strong enough\l"
# 218 "data/maps/EverGrandeCity/scripts.pory"
	.string "to become the Champion!\p"
# 219 "data/maps/EverGrandeCity/scripts.pory"
	.string "Oh, and one more thing. When we first\n"
# 220 "data/maps/EverGrandeCity/scripts.pory"
	.string "got here, we saw Wally walking into\l"
# 221 "data/maps/EverGrandeCity/scripts.pory"
	.string "Victory Road.\p"
# 222 "data/maps/EverGrandeCity/scripts.pory"
	.string "He looked really determined, he was\n"
# 223 "data/maps/EverGrandeCity/scripts.pory"
	.string "almost like a different person from\l"
# 224 "data/maps/EverGrandeCity/scripts.pory"
	.string "that timid kid you beat in Mauville…\p"
# 225 "data/maps/EverGrandeCity/scripts.pory"
	.string "Just thought I'd give you a heads up!\n"
# 226 "data/maps/EverGrandeCity/scripts.pory"
	.string "Anyway, take care, {PLAYER}, I'm sure\l"
# 227 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'll see you again soon!$"
# 228 "data/maps/EverGrandeCity/scripts.pory"

# 229 "data/maps/EverGrandeCity/scripts.pory"

# 230 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_RivalTakeKubfu:
# 231 "data/maps/EverGrandeCity/scripts.pory"
	.string "Here, {PLAYER}, I have one final gift\n"
# 232 "data/maps/EverGrandeCity/scripts.pory"
	.string "as well before I head out.$"
# 233 "data/maps/EverGrandeCity/scripts.pory"

# 234 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_BrendanShoppingLetsBattle:
# 235 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}! Dawn told me about\n"
# 236 "data/maps/EverGrandeCity/scripts.pory"
	.string "everything that happened with Team\l"
# 237 "data/maps/EverGrandeCity/scripts.pory"
	.string "Aqua, Team Magma, and Drake!\p"
# 238 "data/maps/EverGrandeCity/scripts.pory"
	.string "I can't believe what he did, but I'm\n"
# 239 "data/maps/EverGrandeCity/scripts.pory"
	.string "more impressed with how you were able\l"
# 240 "data/maps/EverGrandeCity/scripts.pory"
	.string "to stop all of them by yourself!\p"
# 241 "data/maps/EverGrandeCity/scripts.pory"
	.string "It feels silly to even say this, but we\n"
# 242 "data/maps/EverGrandeCity/scripts.pory"
	.string "wanted to give you one final test\l"
# 243 "data/maps/EverGrandeCity/scripts.pory"
	.string "before you head into Victory Road!\l"
# 244 "data/maps/EverGrandeCity/scripts.pory"
	.string "We are rivals after all!\p"
# 245 "data/maps/EverGrandeCity/scripts.pory"
	.string "Don't worry, we won't make you fight us\n"
# 246 "data/maps/EverGrandeCity/scripts.pory"
	.string "both at once. But you will have to beat\l"
# 247 "data/maps/EverGrandeCity/scripts.pory"
	.string "us both to get through! So…\p"
# 248 "data/maps/EverGrandeCity/scripts.pory"
	.string "What do you say to one last battle?$"
# 249 "data/maps/EverGrandeCity/scripts.pory"

# 250 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_BrendanNoConfidence:
# 251 "data/maps/EverGrandeCity/scripts.pory"
	.string "If you say so, but I'm not going\n"
# 252 "data/maps/EverGrandeCity/scripts.pory"
	.string "anywhere until we battle!$"
# 253 "data/maps/EverGrandeCity/scripts.pory"

# 254 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_BrendanBattleMe:
# 255 "data/maps/EverGrandeCity/scripts.pory"
	.string "Come on, {PLAYER}. I'm really going to\n"
# 256 "data/maps/EverGrandeCity/scripts.pory"
	.string "beat you this time!\l"
# 257 "data/maps/EverGrandeCity/scripts.pory"
	.string "What do you say?$"
# 258 "data/maps/EverGrandeCity/scripts.pory"

# 259 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_BrendanWontBeBeaten:
# 260 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'll show you how strong I've become!$"
# 261 "data/maps/EverGrandeCity/scripts.pory"

# 262 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_BrendanDefeat:
# 263 "data/maps/EverGrandeCity/scripts.pory"
	.string "… … … … … … … …\p"
# 264 "data/maps/EverGrandeCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 265 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}{KUN}, on Route 103.\p"
# 266 "data/maps/EverGrandeCity/scripts.pory"
	.string "That battle helped you become this\n"
# 267 "data/maps/EverGrandeCity/scripts.pory"
	.string "strong, didn't it?$"
# 268 "data/maps/EverGrandeCity/scripts.pory"

# 269 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_BrendanGoingBackToLittleroot:
# 270 "data/maps/EverGrandeCity/scripts.pory"
	.string "Anyway, I…\n"
# 271 "data/maps/EverGrandeCity/scripts.pory"
	.string "I plan on going home to Littleroot.\p"
# 272 "data/maps/EverGrandeCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 273 "data/maps/EverGrandeCity/scripts.pory"
	.string "Pokédex. It's coming together pretty\l"
# 274 "data/maps/EverGrandeCity/scripts.pory"
	.string "decently, so I should go show him.\p"
# 275 "data/maps/EverGrandeCity/scripts.pory"
	.string "Like Dawn said, you've got this,\n"
# 276 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}. I know you're strong enough\l"
# 277 "data/maps/EverGrandeCity/scripts.pory"
	.string "to become the Champion!\p"
# 278 "data/maps/EverGrandeCity/scripts.pory"
	.string "Oh, and one more thing. When we first\n"
# 279 "data/maps/EverGrandeCity/scripts.pory"
	.string "got here, we saw Wally walking into\l"
# 280 "data/maps/EverGrandeCity/scripts.pory"
	.string "Victory Road.\p"
# 281 "data/maps/EverGrandeCity/scripts.pory"
	.string "He looked really determined, he was\n"
# 282 "data/maps/EverGrandeCity/scripts.pory"
	.string "almost like a different person from\l"
# 283 "data/maps/EverGrandeCity/scripts.pory"
	.string "that timid kid you beat in Mauville…\p"
# 284 "data/maps/EverGrandeCity/scripts.pory"
	.string "Just thought I'd give you a heads up!\n"
# 285 "data/maps/EverGrandeCity/scripts.pory"
	.string "Anyway, take care, {PLAYER}, I'm sure\l"
# 286 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'll see you again soon!$"
# 287 "data/maps/EverGrandeCity/scripts.pory"

# 288 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringVictoryRoad:
# 289 "data/maps/EverGrandeCity/scripts.pory"
	.string "Entering Victory Road$"
# 290 "data/maps/EverGrandeCity/scripts.pory"

# 291 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringPokemonLeague:
# 292 "data/maps/EverGrandeCity/scripts.pory"
	.string "Entering Pokémon League\n"
# 293 "data/maps/EverGrandeCity/scripts.pory"
	.string "Center Gate$"
# 294 "data/maps/EverGrandeCity/scripts.pory"

# 295 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_CitySign:
# 296 "data/maps/EverGrandeCity/scripts.pory"
	.string "Ever Grande City\p"
# 297 "data/maps/EverGrandeCity/scripts.pory"
	.string "“The paradise of flowers, the sea,\n"
# 298 "data/maps/EverGrandeCity/scripts.pory"
	.string "and Pokémon.”$"

EverGrandeCity_EventScript_Dawn::
# 303 "data/maps/EverGrandeCity/scripts.pory"
	lockall
# 304 "data/maps/EverGrandeCity/scripts.pory"
	applymovement 2, Common_Movement_FacePlayer
# 305 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_BEAT_DAWN_EVERGRANDE, EverGrandeCity_EventScript_BeatDawnNotRival
# 306 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_DECLINED_DAWN_EVERGRANDE, EverGrandeCity_EventScript_DawnRequestBattleAgain
# 307 "data/maps/EverGrandeCity/scripts.pory"
	msgbox Dawn_GreetingEvergrande, MSGBOX_YESNO
# 308 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_BattleDawnPrompt
	end


EverGrandeCity_EventScript_DawnRequestBattleAgain::
# 313 "data/maps/EverGrandeCity/scripts.pory"
	msgbox ReadyYetFinal, MSGBOX_YESNO
# 314 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_BattleDawnPrompt
	end


EverGrandeCity_EventScript_BattleDawnPrompt::
# 319 "data/maps/EverGrandeCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, EverGrandeCity_EventScript_BattleDawn
# 320 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_DeclineDawnBattle
# 321 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
	end


EverGrandeCity_EventScript_DeclineDawnBattle::
# 326 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_DECLINED_DAWN_EVERGRANDE
# 327 "data/maps/EverGrandeCity/scripts.pory"
	msgbox ComeBackWhenReadyFinal, MSGBOX_DEFAULT
# 328 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


EverGrandeCity_EventScript_BattleDawn::
# 333 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_BattleDawn_Text_0, MSGBOX_DEFAULT
# 334 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_DAWN_EVERGRANDE, Dawn_OutroEvergrande
# 335 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_DawnDefeated
	return


EverGrandeCity_EventScript_DawnDefeated::
# 341 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_BEAT_DAWN_EVERGRANDE
# 342 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_EVERGRANDE_CITY_BEAT_RIVAL, EverGrandeCity_EventScript_RivalsFlyAway
# 343 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CanYouBeatRival, MSGBOX_DEFAULT
# 344 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end


EverGrandeCity_EventScript_BeatDawnNotRival::
# 349 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_NotMovingUntilRival, MSGBOX_DEFAULT
# 350 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end


EverGrandeCity_EventScript_RivalsFlyAway::
# 356 "data/maps/EverGrandeCity/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
# 357 "data/maps/EverGrandeCity/scripts.pory"
	waitmovement 0
# 358 "data/maps/EverGrandeCity/scripts.pory"
	msgbox DawnFarewell, MSGBOX_DEFAULT
# 359 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_TM_DRACO_METEOR
# 360 "data/maps/EverGrandeCity/scripts.pory"
	msgbox DawnFarewell2, MSGBOX_DEFAULT
# 361 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
# 362 "data/maps/EverGrandeCity/scripts.pory"
	delay 30
# 363 "data/maps/EverGrandeCity/scripts.pory"
	setfieldeffectargument 0, 1
# 364 "data/maps/EverGrandeCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 365 "data/maps/EverGrandeCity/scripts.pory"
	delay 15
# 366 "data/maps/EverGrandeCity/scripts.pory"
	removeobject 2
# 367 "data/maps/EverGrandeCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 368 "data/maps/EverGrandeCity/scripts.pory"
	delay 15
# 369 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_RivalFarewellStart
# 370 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end


EverGrandeCity_EventScript_RivalFarewellStart::
# 375 "data/maps/EverGrandeCity/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
# 376 "data/maps/EverGrandeCity/scripts.pory"
	waitmovement 0
# 377 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_RivalTakeKubfu, MSGBOX_DEFAULT
# 378 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
# 379 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_RivalGiveKubfu
# 380 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end


EverGrandeCity_EventScript_MayFarewell::
# 385 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 386 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
# 387 "data/maps/EverGrandeCity/scripts.pory"
	delay 30
# 388 "data/maps/EverGrandeCity/scripts.pory"
	setfieldeffectargument 0, 1
# 389 "data/maps/EverGrandeCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 390 "data/maps/EverGrandeCity/scripts.pory"
	delay 15
# 391 "data/maps/EverGrandeCity/scripts.pory"
	removeobject 1
# 392 "data/maps/EverGrandeCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 393 "data/maps/EverGrandeCity/scripts.pory"
	delay 15
# 394 "data/maps/EverGrandeCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 395 "data/maps/EverGrandeCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 396 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 397 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_BEAT_BOTH_RIVALS
# 398 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end


EverGrandeCity_EventScript_BrendanFarewell::
# 403 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 404 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
# 405 "data/maps/EverGrandeCity/scripts.pory"
	delay 30
# 406 "data/maps/EverGrandeCity/scripts.pory"
	setfieldeffectargument 0, 1
# 407 "data/maps/EverGrandeCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 408 "data/maps/EverGrandeCity/scripts.pory"
	delay 15
# 409 "data/maps/EverGrandeCity/scripts.pory"
	removeobject 1
# 410 "data/maps/EverGrandeCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 411 "data/maps/EverGrandeCity/scripts.pory"
	delay 15
# 412 "data/maps/EverGrandeCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 413 "data/maps/EverGrandeCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 414 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 415 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_BEAT_BOTH_RIVALS
# 416 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end


EverGrandeCity_EventScript_RivalGiveKubfu::
# 421 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KUBFU
# 422 "data/maps/EverGrandeCity/scripts.pory"
	givemonrandom SPECIES_KUBFU, 40
# 423 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, EverGrandeCity_EventScript_ReceiveKubfuParty
# 424 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, EverGrandeCity_EventScript_ReceiveKubfuPC
# 425 "data/maps/EverGrandeCity/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 426 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


EverGrandeCity_EventScript_ReceiveKubfuParty::
# 431 "data/maps/EverGrandeCity/scripts.pory"
	call EverGrandeCity_EventScript_ReceivedKubfuFanfare
# 432 "data/maps/EverGrandeCity/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 433 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_ExplainKubfu
# 434 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 435 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 436 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_ExplainKubfu
	end


EverGrandeCity_EventScript_ReceiveKubfuPC::
# 442 "data/maps/EverGrandeCity/scripts.pory"
	call EverGrandeCity_EventScript_ReceivedKubfuFanfare
# 443 "data/maps/EverGrandeCity/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 444 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_SendKubfuToPC
# 445 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 446 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_SendKubfuToPC
	end


EverGrandeCity_EventScript_SendKubfuToPC::
# 452 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_TransferredToPC
# 453 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_ExplainKubfu
	end


EverGrandeCity_EventScript_ReceivedKubfuFanfare::
# 459 "data/maps/EverGrandeCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 460 "data/maps/EverGrandeCity/scripts.pory"
	message EverGrandeCity_Text_PlayerReceivedKubfu
# 461 "data/maps/EverGrandeCity/scripts.pory"
	waitmessage
# 462 "data/maps/EverGrandeCity/scripts.pory"
	waitfanfare
# 463 "data/maps/EverGrandeCity/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KUBFU
	return


EverGrandeCity_EventScript_ExplainKubfu::
# 469 "data/maps/EverGrandeCity/scripts.pory"
	msgbox Rival_ExplainKubfu, MSGBOX_DEFAULT
# 470 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_RECEIVED_KUBFU
# 471 "data/maps/EverGrandeCity/scripts.pory"
	checkplayergender
# 472 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_EventScript_MayFarewell
# 473 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_EventScript_BrendanFarewell
# 474 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


EverGrandeCity_EventScript_Volkner::
# 565 "data/maps/EverGrandeCity/scripts.pory"
	lockall
# 566 "data/maps/EverGrandeCity/scripts.pory"
	applymovement LOCALID_VOLKNER, Common_Movement_FacePlayer
# 567 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_defeated TRAINER_VOLKNER, EverGrandeCity_EventScript_VolknerDefeated
# 568 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_TEMP_1, EverGrandeCity_EventScript_VolknerRequestBattleAgain
# 569 "data/maps/EverGrandeCity/scripts.pory"
	msgbox Volkner_Greeting, MSGBOX_YESNO
# 570 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_BattleVolknerPrompt
	end


EverGrandeCity_EventScript_VolknerRequestBattleAgain::
# 575 "data/maps/EverGrandeCity/scripts.pory"
	msgbox Volkner_ReadyYet, MSGBOX_YESNO
# 576 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_BattleVolknerPrompt
	end


EverGrandeCity_EventScript_BattleVolknerPrompt::
# 581 "data/maps/EverGrandeCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, EverGrandeCity_EventScript_BattleVolkner
# 582 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_DeclineVolknerBattle
# 583 "data/maps/EverGrandeCity/scripts.pory"
	closemessage
	end


EverGrandeCity_EventScript_DeclineVolknerBattle::
# 588 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_TEMP_1
# 589 "data/maps/EverGrandeCity/scripts.pory"
	msgbox Volkner_ComeBackWhenReady, MSGBOX_DEFAULT
# 590 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


EverGrandeCity_EventScript_BattleVolkner::
# 595 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_EventScript_BattleVolkner_Text_0, MSGBOX_DEFAULT
# 596 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_no_intro TRAINER_VOLKNER, Volkner_Outro
# 597 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_TM_RISING_VOLTAGE
# 598 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_TM_SUPERCELL_SLAM
# 599 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_EJECT_BUTTON
# 600 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_VolknerGiveZeraora
	return


EverGrandeCity_EventScript_VolknerDefeated::
# 606 "data/maps/EverGrandeCity/scripts.pory"
	msgbox PostBattle_Volkner, MSGBOX_DEFAULT
# 607 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end


EverGrandeCity_EventScript_VolknerGiveZeraora::
# 612 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZERAORA
# 613 "data/maps/EverGrandeCity/scripts.pory"
	givemonrandom SPECIES_ZERAORA, 50
# 614 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, EverGrandeCity_EventScript_ReceiveZeraoraParty
# 615 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, EverGrandeCity_EventScript_ReceiveZeraoraPC
# 616 "data/maps/EverGrandeCity/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 617 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


EverGrandeCity_EventScript_ReceiveZeraoraParty::
# 622 "data/maps/EverGrandeCity/scripts.pory"
	call EverGrandeCity_EventScript_ReceivedZeraoraFanfare
# 623 "data/maps/EverGrandeCity/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 624 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_ExplainZeraora
# 625 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 626 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 627 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_ExplainZeraora
	end


EverGrandeCity_EventScript_ReceiveZeraoraPC::
# 633 "data/maps/EverGrandeCity/scripts.pory"
	call EverGrandeCity_EventScript_ReceivedZeraoraFanfare
# 634 "data/maps/EverGrandeCity/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 635 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_SendZeraoraToPC
# 636 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 637 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_SendZeraoraToPC
	end


EverGrandeCity_EventScript_SendZeraoraToPC::
# 643 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_TransferredToPC
# 644 "data/maps/EverGrandeCity/scripts.pory"
	goto EverGrandeCity_EventScript_ExplainZeraora
	end


EverGrandeCity_EventScript_ReceivedZeraoraFanfare::
# 650 "data/maps/EverGrandeCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 651 "data/maps/EverGrandeCity/scripts.pory"
	message EverGrandeCity_Text_PlayerReceivedZeraora
# 652 "data/maps/EverGrandeCity/scripts.pory"
	waitmessage
# 653 "data/maps/EverGrandeCity/scripts.pory"
	waitfanfare
# 654 "data/maps/EverGrandeCity/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZERAORA
	return


EverGrandeCity_EventScript_ExplainZeraora::
# 660 "data/maps/EverGrandeCity/scripts.pory"
	msgbox Volkner_ExplainZeraora, MSGBOX_DEFAULT
# 661 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


EverGrandeCity_EventScript_BattleDawn_Text_0:
# 333 "data/maps/EverGrandeCity/scripts.pory"
	.string "Let's do this, one last time!$"

EverGrandeCity_EventScript_BattleVolkner_Text_0:
# 595 "data/maps/EverGrandeCity/scripts.pory"
	.string "This is going to be electric!$"

EverGrandeCity_Text_PlayerReceivedKubfu::
# 478 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER} received Kubfu!$"

Rival_ExplainKubfu::
# 482 "data/maps/EverGrandeCity/scripts.pory"
	.string "Kubfu can evolve in 2 different ways.\n"
	.string "You can use a Dusk Stone to evolve it\l"
	.string "into the Single-Strike form, like I have,\l"
	.string "or you can use a Water Stone to evolve\l"
	.string "it into the Rapid-Strike form.\p"
	.string "Both are quite powerful.$"

Dawn_GreetingEvergrande::
# 492 "data/maps/EverGrandeCity/scripts.pory"
	.string "Hey, {PLAYER}! After everything that\n"
	.string "happened in Sootopolis, I called up\l"
	.string "{RIVAL}, and we decided to meet up here\l"
	.string "and wait for you.\p"
	.string "You've beaten us both a number of\n"
	.string "times, but we agreed that we can't just\l"
	.string "let you through to Victory Road\l"
	.string "without one more battle for each of us!\p"
	.string "Don't worry, we won't make you fight us\n"
	.string "both at once. But you will have to beat\l"
	.string "us both to get through!\p"
	.string "So what do you say, ready to have our\n"
	.string "final battle?$"

ReadyYetFinal::
# 508 "data/maps/EverGrandeCity/scripts.pory"
	.string "Ready for our final battle now?$"

ComeBackWhenReadyFinal::
# 512 "data/maps/EverGrandeCity/scripts.pory"
	.string "Come back when you're ready, I'll be\n"
	.string "here!$"

Dawn_OutroEvergrande::
# 517 "data/maps/EverGrandeCity/scripts.pory"
	.string "Looks like you passed my final test\n"
	.string "with flying colors, {PLAYER}.\p"
	.string "Not that there was ever any doubt, but\n"
	.string "you're definitely ready for the\l"
	.string "Pokémon League.$"

EverGrandeCity_Text_CanYouBeatRival::
# 525 "data/maps/EverGrandeCity/scripts.pory"
	.string "Thanks for one last great battle,\n"
	.string "{PLAYER}. But I'm not going anywhere\l"
	.string "until you beat {RIVAL} too!$"

EverGrandeCity_Text_NotMovingUntilRival::
# 532 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'm not going anywhere until\n"
	.string "you beat {RIVAL} too!$"

EverGrandeCity_Text_CanYouBeatDawn::
# 537 "data/maps/EverGrandeCity/scripts.pory"
	.string "That was a great battle, {PLAYER}, but\n"
	.string "can you beat Dawn too?$"

EverGrandeCity_Text_NotMovingUntilDawn::
# 542 "data/maps/EverGrandeCity/scripts.pory"
	.string "I'm not going anywhere until\n"
	.string "you beat Dawn too!$"

DawnFarewell::
# 547 "data/maps/EverGrandeCity/scripts.pory"
	.string "Dawn: Well, {PLAYER}, neither of us were\n"
	.string "a match for you once again.\p"
	.string "I have one more TM I can give you to\n"
	.string "help, I hope you can use it against\l"
	.string "against the Elite Four when you make it\l"
	.string "there.$"

DawnFarewell2::
# 556 "data/maps/EverGrandeCity/scripts.pory"
	.string "Become the Champion, {PLAYER}, I know\n"
	.string "you can do it!\p"
	.string "So long, my friend, until next time!$"

Volkner_Greeting::
# 665 "data/maps/EverGrandeCity/scripts.pory"
	.string "Wow, another trainer showed up here. It\n"
	.string "gets pretty boring being the strongest\l"
	.string "Gym Leader in a given region…\p"
	.string "… … … … … …\p"
	.string "How would I know? Well, my name's\n"
	.string "Volkner, and I'm the 8th Gym Leader in\l"
	.string "the Sinnoh region.\p"
	.string "Usually, the weak trainers get weeded\n"
	.string "out before they can make it to me.\p"
	.string "But you're now the fourth strong-\n"
	.string "looking trainer I've seen come through\l"
	.string "here, it's really got me itching for a\l"
	.string "battle. So, will you battle me?$"

Volkner_ReadyYet::
# 681 "data/maps/EverGrandeCity/scripts.pory"
	.string "Ready to battle me yet?$"

Volkner_ComeBackWhenReady::
# 685 "data/maps/EverGrandeCity/scripts.pory"
	.string "How boring, I was hoping you'd be\n"
	.string "different than the average trainer.$"

EverGrandeCity_Text_PlayerReceivedZeraora::
# 690 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER} received Zeraora!$"

Volkner_ExplainZeraora::
# 694 "data/maps/EverGrandeCity/scripts.pory"
	.string "Zeraora is definitely a favorite of\n"
	.string "mine. His electrifying fists light up\l"
	.string "any battle!\p"
	.string "I hope you raise it well!$"

Volkner_Outro::
# 701 "data/maps/EverGrandeCity/scripts.pory"
	.string "Ha! Wow, the trainers here are way\n"
	.string "stronger than in Sinnoh, how exciting!$"

PostBattle_Volkner::
# 707 "data/maps/EverGrandeCity/scripts.pory"
	.string "I think I'll just stay here and wait for\n"
	.string "more strong trainers, someone else can\l"
	.string "run my Gym for all I care.$"
