NewBirchsLab_MapScripts::
# 4 "data/maps/NewBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewBirchsLab_EventScript_BallDefault
# 5 "data/maps/NewBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NewBirchsLab_OnWarp
# 6 "data/maps/NewBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0


NewBirchsLab_EventScript_BallDefault::
# 10 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_STARTER_GEN, 0
# 11 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_UNUSED_0x40F8, 1
# 12 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_MONOTYPE_STARTER, 0
	return


NewBirchsLab_EventScript_Birch::
# 16 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 17 "data/maps/NewBirchsLab/scripts.pory"
	faceplayer
# 18 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_TOUCHED_BALLS, NewBirchsLab_EventScript_Birch_2
NewBirchsLab_EventScript_Birch_1:
# 26 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_USE_MONOTYPE_STARTERS, NewBirchsLab_EventScript_BirchMonotypeStarters
# 28 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_WATERSTARTER, NewBirchsLab_EventScript_Birch_7
NewBirchsLab_EventScript_Birch_6:
# 58 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SYS_POKEDEX_GET, NewBirchsLab_EventScript_Birch_19
# 64 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 65 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NewBirchsLab_EventScript_GoodbyePlayerFemale
# 66 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NewBirchsLab_EventScript_GoodbyePlayerMale
NewBirchsLab_EventScript_Birch_4:
# 70 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 71 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_Birch_2:
# 20 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 21 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NewBirchsLab_EventScript_WelcomePlayerFemale
# 22 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NewBirchsLab_EventScript_WelcomePlayerMale
# 23 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_TOUCHED_BALLS
	goto NewBirchsLab_EventScript_Birch_1

NewBirchsLab_EventScript_Birch_5:
# 29 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_ChangeStarters
# 30 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_0, 0
# 31 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_1, 1
# 32 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_2, 2
# 33 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_3, 3
# 34 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_4, 4
# 35 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_5, 5
# 36 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_6, 6
# 37 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_7, 7
# 38 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_8, 8
# 39 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_9, 9
# 40 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_10, MULTI_B_PRESSED
# 43 "data/maps/NewBirchsLab/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 45 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq NewBirchsLab_EventScript_Birch_15
# 49 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq NewBirchsLab_EventScript_Birch_16
NewBirchsLab_EventScript_Birch_14:
# 54 "data/maps/NewBirchsLab/scripts.pory"
	copyvar VAR_STARTER_GEN, VAR_RESULT
# 55 "data/maps/NewBirchsLab/scripts.pory"
	goto NewBirchsLab_EventScript_SayGenShowing
	goto NewBirchsLab_EventScript_Birch_4

NewBirchsLab_EventScript_Birch_7:
# 28 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GRASSSTARTER, NewBirchsLab_EventScript_Birch_9
	goto NewBirchsLab_EventScript_Birch_6

NewBirchsLab_EventScript_Birch_9:
# 28 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_FIRESTARTER, NewBirchsLab_EventScript_Birch_11
	goto NewBirchsLab_EventScript_Birch_6

NewBirchsLab_EventScript_Birch_11:
# 28 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GIBLESTARTER, NewBirchsLab_EventScript_Birch_5
	goto NewBirchsLab_EventScript_Birch_6

NewBirchsLab_EventScript_Birch_15:
# 47 "data/maps/NewBirchsLab/scripts.pory"
	goto NewBirchsLab_EventScript_SayGenShowing
	goto NewBirchsLab_EventScript_Birch_14

NewBirchsLab_EventScript_Birch_16:
# 51 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_STARTER_GEN, 3
# 52 "data/maps/NewBirchsLab/scripts.pory"
	goto NewBirchsLab_EventScript_AskChimchar
	goto NewBirchsLab_EventScript_Birch_14

NewBirchsLab_EventScript_Birch_19:
# 60 "data/maps/NewBirchsLab/scripts.pory"
	goto ProfBirch_EventScript_AskRatePokedex
	goto NewBirchsLab_EventScript_Birch_4


NewBirchsLab_EventScript_BirchMonotypeStarters::
# 76 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_WATERSTARTER, NewBirchsLab_EventScript_BirchMonotypeStarters_4
NewBirchsLab_EventScript_BirchMonotypeStarters_3:
# 107 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SYS_POKEDEX_GET, NewBirchsLab_EventScript_BirchMonotypeStarters_14
# 113 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 114 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NewBirchsLab_EventScript_GoodbyePlayerFemale
# 115 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NewBirchsLab_EventScript_GoodbyePlayerMale
NewBirchsLab_EventScript_BirchMonotypeStarters_1:
# 119 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 120 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_BirchMonotypeStarters_2:
# 77 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_ChangeStartersMonotypes
# 79 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_0, 0
# 80 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_1, 1
# 81 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_2, 2
# 82 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_3, 3
# 83 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_4, 4
# 84 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_5, 5
# 85 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_6, 6
# 86 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_7, 7
# 87 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_8, 8
# 88 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_9, 9
# 89 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_10, 10
# 90 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_11, 11
# 91 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_12, 12
# 92 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_13, 13
# 93 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_BirchMonotypeStarters_Text_14, 14
# 94 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_Birch_Text_10, MULTI_B_PRESSED
# 97 "data/maps/NewBirchsLab/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 99 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq NewBirchsLab_EventScript_BirchMonotypeStarters_12
NewBirchsLab_EventScript_BirchMonotypeStarters_11:
# 103 "data/maps/NewBirchsLab/scripts.pory"
	copyvar VAR_MONOTYPE_STARTER, VAR_RESULT
# 104 "data/maps/NewBirchsLab/scripts.pory"
	goto NewBirchsLab_EventScript_SayMonoShowing
	goto NewBirchsLab_EventScript_BirchMonotypeStarters_1

NewBirchsLab_EventScript_BirchMonotypeStarters_4:
# 76 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GRASSSTARTER, NewBirchsLab_EventScript_BirchMonotypeStarters_6
	goto NewBirchsLab_EventScript_BirchMonotypeStarters_3

NewBirchsLab_EventScript_BirchMonotypeStarters_6:
# 76 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_FIRESTARTER, NewBirchsLab_EventScript_BirchMonotypeStarters_8
	goto NewBirchsLab_EventScript_BirchMonotypeStarters_3

NewBirchsLab_EventScript_BirchMonotypeStarters_8:
# 76 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GIBLESTARTER, NewBirchsLab_EventScript_BirchMonotypeStarters_2
	goto NewBirchsLab_EventScript_BirchMonotypeStarters_3

NewBirchsLab_EventScript_BirchMonotypeStarters_12:
# 101 "data/maps/NewBirchsLab/scripts.pory"
	goto NewBirchsLab_EventScript_SayMonoShowing
	goto NewBirchsLab_EventScript_BirchMonotypeStarters_11

NewBirchsLab_EventScript_BirchMonotypeStarters_14:
# 109 "data/maps/NewBirchsLab/scripts.pory"
	goto ProfBirch_EventScript_AskRatePokedex
	goto NewBirchsLab_EventScript_BirchMonotypeStarters_1


NewBirchsLab_EventScript_SayGenShowing::
# 125 "data/maps/NewBirchsLab/scripts.pory"
	switch VAR_STARTER_GEN
# 127 "data/maps/NewBirchsLab/scripts.pory"
	case 0, NewBirchsLab_EventScript_SayGenShowing_3
# 129 "data/maps/NewBirchsLab/scripts.pory"
	case 1, NewBirchsLab_EventScript_SayGenShowing_4
# 131 "data/maps/NewBirchsLab/scripts.pory"
	case 2, NewBirchsLab_EventScript_SayGenShowing_5
# 133 "data/maps/NewBirchsLab/scripts.pory"
	case 3, NewBirchsLab_EventScript_SayGenShowing_6
# 135 "data/maps/NewBirchsLab/scripts.pory"
	case 4, NewBirchsLab_EventScript_SayGenShowing_7
# 137 "data/maps/NewBirchsLab/scripts.pory"
	case 5, NewBirchsLab_EventScript_SayGenShowing_8
# 139 "data/maps/NewBirchsLab/scripts.pory"
	case 6, NewBirchsLab_EventScript_SayGenShowing_9
# 141 "data/maps/NewBirchsLab/scripts.pory"
	case 7, NewBirchsLab_EventScript_SayGenShowing_10
# 143 "data/maps/NewBirchsLab/scripts.pory"
	case 8, NewBirchsLab_EventScript_SayGenShowing_11
# 146 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_9
NewBirchsLab_EventScript_SayGenShowing_1:
# 148 "data/maps/NewBirchsLab/scripts.pory"
	release
	end

NewBirchsLab_EventScript_SayGenShowing_3:
# 128 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_0
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_4:
# 130 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_1
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_5:
# 132 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_2
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_6:
# 134 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_3
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_7:
# 136 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_4
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_8:
# 138 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_5
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_9:
# 140 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_6
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_10:
# 142 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_7
	goto NewBirchsLab_EventScript_SayGenShowing_1

NewBirchsLab_EventScript_SayGenShowing_11:
# 144 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayGenShowing_Text_8
	goto NewBirchsLab_EventScript_SayGenShowing_1


NewBirchsLab_EventScript_AskChimchar::
# 153 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_0
# 154 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIMCHAR, 10, 3
# 155 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_1
# 156 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 157 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_AskChimchar_Text_2, 0
# 158 "data/maps/NewBirchsLab/scripts.pory"
	dynmultipush NewBirchsLab_EventScript_AskChimchar_Text_3, 1
# 159 "data/maps/NewBirchsLab/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 161 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq NewBirchsLab_EventScript_AskChimchar_1
# 210 "data/maps/NewBirchsLab/scripts.pory"
	goto NewBirchsLab_EventScript_SayGenShowing
	return

NewBirchsLab_EventScript_AskChimchar_1:
# 162 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_4
# 163 "data/maps/NewBirchsLab/scripts.pory"
	givemon SPECIES_GIBLE, 5
# 165 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_AskChimchar_5
# 172 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_AskChimchar_6
# 180 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_6
NewBirchsLab_EventScript_AskChimchar_4:
# 183 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 184 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_STARTER_MON, 3
# 186 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 187 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 188 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 189 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 190 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 191 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 192 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 193 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 194 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 195 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 196 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 198 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBirchsLab_EventScript_AskChimchar_11
NewBirchsLab_EventScript_AskChimchar_10:
# 205 "data/maps/NewBirchsLab/scripts.pory"
	release
	end

NewBirchsLab_EventScript_AskChimchar_5:
# 166 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 167 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_5
# 168 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 169 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_GIBLESTARTER
# 170 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto NewBirchsLab_EventScript_AskChimchar_4

NewBirchsLab_EventScript_AskChimchar_6:
# 173 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 174 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_5
# 175 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 176 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_GIBLESTARTER
# 177 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto NewBirchsLab_EventScript_AskChimchar_4

NewBirchsLab_EventScript_AskChimchar_11:
# 201 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 202 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NewBirchsLab_EventScript_RivalSprigatitoGoodbyePlayerFemale
# 203 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NewBirchsLab_EventScript_RivalSprigatitoGoodbyePlayerMale
	goto NewBirchsLab_EventScript_AskChimchar_10


NewBirchsLab_EventScript_SayMonoShowing::
# 215 "data/maps/NewBirchsLab/scripts.pory"
	switch VAR_MONOTYPE_STARTER
# 217 "data/maps/NewBirchsLab/scripts.pory"
	case 0, NewBirchsLab_EventScript_SayMonoShowing_3
# 219 "data/maps/NewBirchsLab/scripts.pory"
	case 1, NewBirchsLab_EventScript_SayMonoShowing_4
# 221 "data/maps/NewBirchsLab/scripts.pory"
	case 2, NewBirchsLab_EventScript_SayMonoShowing_5
# 223 "data/maps/NewBirchsLab/scripts.pory"
	case 3, NewBirchsLab_EventScript_SayMonoShowing_6
# 225 "data/maps/NewBirchsLab/scripts.pory"
	case 4, NewBirchsLab_EventScript_SayMonoShowing_7
# 227 "data/maps/NewBirchsLab/scripts.pory"
	case 5, NewBirchsLab_EventScript_SayMonoShowing_8
# 229 "data/maps/NewBirchsLab/scripts.pory"
	case 6, NewBirchsLab_EventScript_SayMonoShowing_9
# 231 "data/maps/NewBirchsLab/scripts.pory"
	case 7, NewBirchsLab_EventScript_SayMonoShowing_10
# 233 "data/maps/NewBirchsLab/scripts.pory"
	case 8, NewBirchsLab_EventScript_SayMonoShowing_11
# 235 "data/maps/NewBirchsLab/scripts.pory"
	case 9, NewBirchsLab_EventScript_SayMonoShowing_12
# 237 "data/maps/NewBirchsLab/scripts.pory"
	case 10, NewBirchsLab_EventScript_SayMonoShowing_13
# 239 "data/maps/NewBirchsLab/scripts.pory"
	case 11, NewBirchsLab_EventScript_SayMonoShowing_14
# 241 "data/maps/NewBirchsLab/scripts.pory"
	case 12, NewBirchsLab_EventScript_SayMonoShowing_15
# 243 "data/maps/NewBirchsLab/scripts.pory"
	case 13, NewBirchsLab_EventScript_SayMonoShowing_16
# 245 "data/maps/NewBirchsLab/scripts.pory"
	case 14, NewBirchsLab_EventScript_SayMonoShowing_17
# 248 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_13
NewBirchsLab_EventScript_SayMonoShowing_1:
# 250 "data/maps/NewBirchsLab/scripts.pory"
	release
	end

NewBirchsLab_EventScript_SayMonoShowing_3:
# 218 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_0
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_4:
# 220 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_1
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_5:
# 222 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_2
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_6:
# 224 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_3
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_7:
# 226 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_4
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_8:
# 228 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_5
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_9:
# 230 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_6
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_10:
# 232 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_7
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_11:
# 234 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_8
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_12:
# 236 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_9
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_13:
# 238 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_10
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_14:
# 240 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_11
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_15:
# 242 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_12
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_16:
# 244 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_13
	goto NewBirchsLab_EventScript_SayMonoShowing_1

NewBirchsLab_EventScript_SayMonoShowing_17:
# 246 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_SayMonoShowing_Text_14
	goto NewBirchsLab_EventScript_SayMonoShowing_1


NewBirchsLab_EventScript_PokeballOne::
# 255 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 256 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH, NewBirchsLab_EventScript_PokeballOne_2
# 259 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_TOUCHED_BALLS, NewBirchsLab_EventScript_PokeballOne_3
# 263 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_WATERSTARTER, NewBirchsLab_EventScript_PokeballOne_6
NewBirchsLab_EventScript_PokeballOne_5:
# 273 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_1
NewBirchsLab_EventScript_PokeballOne_1:
# 275 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 276 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_PokeballOne_2:
# 257 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotYet
	goto NewBirchsLab_EventScript_PokeballOne_1

NewBirchsLab_EventScript_PokeballOne_3:
# 261 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_0
	goto NewBirchsLab_EventScript_PokeballOne_1

NewBirchsLab_EventScript_PokeballOne_4:
# 264 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_HandleGrassStarterChoice
# 265 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBirchsLab_EventScript_PokeballOne_15
	goto NewBirchsLab_EventScript_PokeballOne_1

NewBirchsLab_EventScript_PokeballOne_6:
# 263 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GRASSSTARTER, NewBirchsLab_EventScript_PokeballOne_8
	goto NewBirchsLab_EventScript_PokeballOne_5

NewBirchsLab_EventScript_PokeballOne_8:
# 263 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_FIRESTARTER, NewBirchsLab_EventScript_PokeballOne_10
	goto NewBirchsLab_EventScript_PokeballOne_5

NewBirchsLab_EventScript_PokeballOne_10:
# 263 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GIBLESTARTER, NewBirchsLab_EventScript_PokeballOne_4
	goto NewBirchsLab_EventScript_PokeballOne_5

NewBirchsLab_EventScript_PokeballOne_15:
# 267 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 268 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NewBirchsLab_EventScript_RivalTorchicGoodbyePlayerFemale
# 269 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NewBirchsLab_EventScript_RivalTorchicGoodbyePlayerMale
	goto NewBirchsLab_EventScript_PokeballOne_1


NewBirchsLab_EventScript_HandleGrassStarterChoice::
# 281 "data/maps/NewBirchsLab/scripts.pory"
	bufferstarterinfo STR_VAR_1, 0
# 282 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic VAR_0x8006, 10, 3
# 283 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_0, MSGBOX_YESNO
# 284 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_HandleGrassStarterChoice_1
# 324 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 325 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_HandleGrassStarterChoice_1:
# 285 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_GiveStarter
# 287 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_HandleGrassStarterChoice_5
# 295 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_HandleGrassStarterChoice_6
# 304 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 305 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_6
NewBirchsLab_EventScript_HandleGrassStarterChoice_4:
# 308 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 309 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 311 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 312 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 313 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 314 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 315 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 316 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 317 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 318 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 319 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 320 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 321 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	return

NewBirchsLab_EventScript_HandleGrassStarterChoice_5:
# 288 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 289 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_1
# 290 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 291 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 292 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_GRASSSTARTER
# 293 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto NewBirchsLab_EventScript_HandleGrassStarterChoice_4

NewBirchsLab_EventScript_HandleGrassStarterChoice_6:
# 296 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 297 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_1
# 298 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 299 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 1
# 300 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_GRASSSTARTER
# 301 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto NewBirchsLab_EventScript_HandleGrassStarterChoice_4


NewBirchsLab_EventScript_PokeballTwo::
# 331 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 332 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH, NewBirchsLab_EventScript_PokeballTwo_2
# 335 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_TOUCHED_BALLS, NewBirchsLab_EventScript_PokeballTwo_3
# 339 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_WATERSTARTER, NewBirchsLab_EventScript_PokeballTwo_6
NewBirchsLab_EventScript_PokeballTwo_5:
# 349 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_1
NewBirchsLab_EventScript_PokeballTwo_1:
# 351 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 352 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_PokeballTwo_2:
# 333 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotYet
	goto NewBirchsLab_EventScript_PokeballTwo_1

NewBirchsLab_EventScript_PokeballTwo_3:
# 337 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_0
	goto NewBirchsLab_EventScript_PokeballTwo_1

NewBirchsLab_EventScript_PokeballTwo_4:
# 340 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_HandleFireStarterChoice
# 341 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBirchsLab_EventScript_PokeballTwo_15
	goto NewBirchsLab_EventScript_PokeballTwo_1

NewBirchsLab_EventScript_PokeballTwo_6:
# 339 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GRASSSTARTER, NewBirchsLab_EventScript_PokeballTwo_8
	goto NewBirchsLab_EventScript_PokeballTwo_5

NewBirchsLab_EventScript_PokeballTwo_8:
# 339 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_FIRESTARTER, NewBirchsLab_EventScript_PokeballTwo_10
	goto NewBirchsLab_EventScript_PokeballTwo_5

NewBirchsLab_EventScript_PokeballTwo_10:
# 339 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GIBLESTARTER, NewBirchsLab_EventScript_PokeballTwo_4
	goto NewBirchsLab_EventScript_PokeballTwo_5

NewBirchsLab_EventScript_PokeballTwo_15:
# 343 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 344 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NewBirchsLab_EventScript_RivalMudkipGoodbyePlayerFemale
# 345 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NewBirchsLab_EventScript_RivalMudkipGoodbyePlayerMale
	goto NewBirchsLab_EventScript_PokeballTwo_1


NewBirchsLab_EventScript_HandleFireStarterChoice::
# 357 "data/maps/NewBirchsLab/scripts.pory"
	bufferstarterinfo STR_VAR_1, 1
# 358 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic VAR_0x8006, 10, 3
# 359 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_0, MSGBOX_YESNO
# 360 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_HandleFireStarterChoice_1
# 400 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 401 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_HandleFireStarterChoice_1:
# 361 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_GiveStarter
# 363 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_HandleFireStarterChoice_5
# 371 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_HandleFireStarterChoice_6
# 380 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 381 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_6
NewBirchsLab_EventScript_HandleFireStarterChoice_4:
# 384 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 385 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 387 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 388 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 389 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 390 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 391 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 392 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 393 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 394 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 395 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 396 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 397 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	return

NewBirchsLab_EventScript_HandleFireStarterChoice_5:
# 364 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 365 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_1
# 366 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 367 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 368 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_FIRESTARTER
# 369 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto NewBirchsLab_EventScript_HandleFireStarterChoice_4

NewBirchsLab_EventScript_HandleFireStarterChoice_6:
# 372 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 373 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_1
# 374 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 375 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 2
# 376 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_FIRESTARTER
# 377 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto NewBirchsLab_EventScript_HandleFireStarterChoice_4


NewBirchsLab_EventScript_PokeballThree::
# 407 "data/maps/NewBirchsLab/scripts.pory"
	lockall
# 408 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH, NewBirchsLab_EventScript_PokeballThree_2
# 411 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_TOUCHED_BALLS, NewBirchsLab_EventScript_PokeballThree_3
# 415 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_WATERSTARTER, NewBirchsLab_EventScript_PokeballThree_6
NewBirchsLab_EventScript_PokeballThree_5:
# 426 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_1
NewBirchsLab_EventScript_PokeballThree_1:
# 428 "data/maps/NewBirchsLab/scripts.pory"
	waitmessage
# 429 "data/maps/NewBirchsLab/scripts.pory"
	releaseall
	end

NewBirchsLab_EventScript_PokeballThree_2:
# 409 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotYet
	goto NewBirchsLab_EventScript_PokeballThree_1

NewBirchsLab_EventScript_PokeballThree_3:
# 413 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_PokeballOne_Text_0
	goto NewBirchsLab_EventScript_PokeballThree_1

NewBirchsLab_EventScript_PokeballThree_4:
# 416 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_EventScript_HandleWaterStarterChoice
# 417 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, NewBirchsLab_EventScript_PokeballThree_15
	goto NewBirchsLab_EventScript_PokeballThree_1

NewBirchsLab_EventScript_PokeballThree_6:
# 415 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GRASSSTARTER, NewBirchsLab_EventScript_PokeballThree_8
	goto NewBirchsLab_EventScript_PokeballThree_5

NewBirchsLab_EventScript_PokeballThree_8:
# 415 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_FIRESTARTER, NewBirchsLab_EventScript_PokeballThree_10
	goto NewBirchsLab_EventScript_PokeballThree_5

NewBirchsLab_EventScript_PokeballThree_10:
# 415 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_unset FLAG_CHOSE_GIBLESTARTER, NewBirchsLab_EventScript_PokeballThree_4
	goto NewBirchsLab_EventScript_PokeballThree_5

NewBirchsLab_EventScript_PokeballThree_15:
# 420 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 421 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, NewBirchsLab_EventScript_RivalTreeckoGoodbyePlayerFemale
# 422 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, NewBirchsLab_EventScript_RivalTreeckoGoodbyePlayerMale
	goto NewBirchsLab_EventScript_PokeballThree_1


NewBirchsLab_EventScript_HandleWaterStarterChoice::
# 434 "data/maps/NewBirchsLab/scripts.pory"
	bufferstarterinfo STR_VAR_1, 2
# 435 "data/maps/NewBirchsLab/scripts.pory"
	showmonpic VAR_0x8006, 10, 3
# 436 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_0, MSGBOX_YESNO
# 437 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NewBirchsLab_EventScript_HandleWaterStarterChoice_1
# 477 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 478 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_NotChosen
	return

NewBirchsLab_EventScript_HandleWaterStarterChoice_1:
# 438 "data/maps/NewBirchsLab/scripts.pory"
	call NewBirchsLab_GiveStarter
# 440 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchsLab_EventScript_HandleWaterStarterChoice_5
# 448 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchsLab_EventScript_HandleWaterStarterChoice_6
# 457 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 458 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_AskChimchar_Text_6
NewBirchsLab_EventScript_HandleWaterStarterChoice_4:
# 461 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 462 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 464 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 465 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 466 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 467 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 468 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 469 "data/maps/NewBirchsLab/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 470 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 471 "data/maps/NewBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 472 "data/maps/NewBirchsLab/scripts.pory"
	checkplayergender
# 473 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 474 "data/maps/NewBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	return

NewBirchsLab_EventScript_HandleWaterStarterChoice_5:
# 441 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 442 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_1
# 443 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 444 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 445 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_WATERSTARTER
# 446 "data/maps/NewBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto NewBirchsLab_EventScript_HandleWaterStarterChoice_4

NewBirchsLab_EventScript_HandleWaterStarterChoice_6:
# 449 "data/maps/NewBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 450 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_1
# 451 "data/maps/NewBirchsLab/scripts.pory"
	waitfanfare
# 452 "data/maps/NewBirchsLab/scripts.pory"
	removeobject 3
# 453 "data/maps/NewBirchsLab/scripts.pory"
	setflag FLAG_CHOSE_WATERSTARTER
# 454 "data/maps/NewBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto NewBirchsLab_EventScript_HandleWaterStarterChoice_4


NewBirchsLab_GiveStarter::
# 484 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_USE_MONOTYPE_STARTERS, NewBirchsLab_GiveStarter_2
# 497 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SHINY_STARTERS, NewBirchsLab_GiveStarter_8
# 503 "data/maps/NewBirchsLab/scripts.pory"
	givemonrandom VAR_0x8006, 5
NewBirchsLab_GiveStarter_1:
	return

NewBirchsLab_GiveStarter_2:
# 486 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_SHINY_STARTERS, NewBirchsLab_GiveStarter_5
# 492 "data/maps/NewBirchsLab/scripts.pory"
	givemon VAR_0x8006, 5
	goto NewBirchsLab_GiveStarter_1

NewBirchsLab_GiveStarter_5:
# 488 "data/maps/NewBirchsLab/scripts.pory"
	givemon VAR_0x8006, 5, isShiny = TRUE
	goto NewBirchsLab_GiveStarter_1

NewBirchsLab_GiveStarter_8:
# 499 "data/maps/NewBirchsLab/scripts.pory"
	givemonrandom VAR_0x8006, 5, isShiny = TRUE
	goto NewBirchsLab_GiveStarter_1


NewBirchsLab_EventScript_WelcomePlayerMale::
# 511 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_USE_MONOTYPE_STARTERS, NewBirchsLab_EventScript_WelcomePlayerMale_2
# 518 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_WelcomePlayerMale
NewBirchsLab_EventScript_WelcomePlayerMale_1:
	return

NewBirchsLab_EventScript_WelcomePlayerMale_2:
# 513 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_WelcomePlayerMaleMonotype
	goto NewBirchsLab_EventScript_WelcomePlayerMale_1


NewBirchsLab_EventScript_WelcomePlayerFemale::
# 524 "data/maps/NewBirchsLab/scripts.pory"
	goto_if_set FLAG_USE_MONOTYPE_STARTERS, NewBirchsLab_EventScript_WelcomePlayerFemale_2
# 531 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_WelcomePlayerFemale
NewBirchsLab_EventScript_WelcomePlayerFemale_1:
	return

NewBirchsLab_EventScript_WelcomePlayerFemale_2:
# 526 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_WelcomePlayerFemaleMonotype
	goto NewBirchsLab_EventScript_WelcomePlayerFemale_1


NewBirchsLab_EventScript_GoodbyePlayerMale::
# 537 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerMale
	return


NewBirchsLab_EventScript_GoodbyePlayerFemale::
# 542 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerFemale
	return


NewBirchsLab_EventScript_RivalTreeckoGoodbyePlayerMale::
# 547 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterTreeckoPlayerMale
# 548 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerMale
# 549 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NewBirchsLab_EventScript_RivalTreeckoGoodbyePlayerFemale::
# 554 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterTreeckoPlayerFemale
# 555 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerFemale
# 556 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NewBirchsLab_EventScript_RivalMudkipGoodbyePlayerMale::
# 561 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterMudkipPlayerMale
# 562 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerMale
# 563 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NewBirchsLab_EventScript_RivalMudkipGoodbyePlayerFemale::
# 568 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterMudkipPlayerFemale
# 569 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerFemale
# 570 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NewBirchsLab_EventScript_RivalTorchicGoodbyePlayerMale::
# 575 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterTorchicPlayerMale
# 576 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerMale
# 577 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NewBirchsLab_EventScript_RivalTorchicGoodbyePlayerFemale::
# 582 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterTorchicPlayerFemale
# 583 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerFemale
# 584 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NewBirchsLab_EventScript_RivalSprigatitoGoodbyePlayerMale::
# 589 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterSprigatitoPlayerMale
# 590 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerMale
# 591 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NewBirchsLab_EventScript_RivalSprigatitoGoodbyePlayerFemale::
# 596 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_RivalStarterSprigatitoPlayerFemale
# 597 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NewBirchsLab_Route103PlayerFemale
# 598 "data/maps/NewBirchsLab/scripts.pory"
	callnative UpdateFollowingPokemon
	return


NicknamePartyMon::
# 605 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 606 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 607 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 608 "data/maps/NewBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 609 "data/maps/NewBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 616 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 617 "data/maps/NewBirchsLab/scripts.pory"
	hidemonpic
# 618 "data/maps/NewBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 621 "data/maps/NewBirchsLab/scripts.pory"
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
# 619 "data/maps/NewBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


NewBirchsLab_EventScript_Birch_Text_0:
# 30 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 1$"

NewBirchsLab_EventScript_Birch_Text_1:
# 31 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 2$"

NewBirchsLab_EventScript_Birch_Text_2:
# 32 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 3$"

NewBirchsLab_EventScript_Birch_Text_3:
# 33 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 4$"

NewBirchsLab_EventScript_Birch_Text_4:
# 34 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 5$"

NewBirchsLab_EventScript_Birch_Text_5:
# 35 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 6$"

NewBirchsLab_EventScript_Birch_Text_6:
# 36 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 7$"

NewBirchsLab_EventScript_Birch_Text_7:
# 37 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 8$"

NewBirchsLab_EventScript_Birch_Text_8:
# 38 "data/maps/NewBirchsLab/scripts.pory"
	.string "Gen 9$"

NewBirchsLab_EventScript_Birch_Text_9:
# 39 "data/maps/NewBirchsLab/scripts.pory"
	.string "I don't like any of these.$"

NewBirchsLab_EventScript_Birch_Text_10:
# 40 "data/maps/NewBirchsLab/scripts.pory"
	.string "Cancel$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_0:
# 79 "data/maps/NewBirchsLab/scripts.pory"
	.string "Fighting$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_1:
# 80 "data/maps/NewBirchsLab/scripts.pory"
	.string "Flying$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_2:
# 81 "data/maps/NewBirchsLab/scripts.pory"
	.string "Poison$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_3:
# 82 "data/maps/NewBirchsLab/scripts.pory"
	.string "Ground$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_4:
# 83 "data/maps/NewBirchsLab/scripts.pory"
	.string "Rock$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_5:
# 84 "data/maps/NewBirchsLab/scripts.pory"
	.string "Bug$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_6:
# 85 "data/maps/NewBirchsLab/scripts.pory"
	.string "Ghost$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_7:
# 86 "data/maps/NewBirchsLab/scripts.pory"
	.string "Steel$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_8:
# 87 "data/maps/NewBirchsLab/scripts.pory"
	.string "Electric$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_9:
# 88 "data/maps/NewBirchsLab/scripts.pory"
	.string "Psychic$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_10:
# 89 "data/maps/NewBirchsLab/scripts.pory"
	.string "Ice$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_11:
# 90 "data/maps/NewBirchsLab/scripts.pory"
	.string "Dragon$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_12:
# 91 "data/maps/NewBirchsLab/scripts.pory"
	.string "Dark$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_13:
# 92 "data/maps/NewBirchsLab/scripts.pory"
	.string "Normal$"

NewBirchsLab_EventScript_BirchMonotypeStarters_Text_14:
# 93 "data/maps/NewBirchsLab/scripts.pory"
	.string "Fairy$"

NewBirchsLab_EventScript_SayGenShowing_Text_0:
# 128 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 1.$"

NewBirchsLab_EventScript_SayGenShowing_Text_1:
# 130 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 2.$"

NewBirchsLab_EventScript_SayGenShowing_Text_2:
# 132 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 3.$"

NewBirchsLab_EventScript_SayGenShowing_Text_3:
# 134 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 4.$"

NewBirchsLab_EventScript_SayGenShowing_Text_4:
# 136 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 5.$"

NewBirchsLab_EventScript_SayGenShowing_Text_5:
# 138 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 6.$"

NewBirchsLab_EventScript_SayGenShowing_Text_6:
# 140 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 7.$"

NewBirchsLab_EventScript_SayGenShowing_Text_7:
# 142 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 8.$"

NewBirchsLab_EventScript_SayGenShowing_Text_8:
# 144 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing starters for Gen 9.$"

NewBirchsLab_EventScript_SayGenShowing_Text_9:
# 146 "data/maps/NewBirchsLab/scripts.pory"
	.string "Now showing starters.$"

NewBirchsLab_EventScript_AskChimchar_Text_0:
# 153 "data/maps/NewBirchsLab/scripts.pory"
	.string "Really?$"

NewBirchsLab_EventScript_AskChimchar_Text_1:
# 155 "data/maps/NewBirchsLab/scripts.pory"
	.string "...not even this guy?$"

NewBirchsLab_EventScript_AskChimchar_Text_2:
# 157 "data/maps/NewBirchsLab/scripts.pory"
	.string "Okay fine, I'll pick a starter.$"

NewBirchsLab_EventScript_AskChimchar_Text_3:
# 158 "data/maps/NewBirchsLab/scripts.pory"
	.string "Hate him.$"

NewBirchsLab_EventScript_AskChimchar_Text_4:
# 162 "data/maps/NewBirchsLab/scripts.pory"
	.string "You ungrateful child. Take this.$"

NewBirchsLab_EventScript_AskChimchar_Text_5:
# 167 "data/maps/NewBirchsLab/scripts.pory"
	.string "{PLAYER} received the Gible!$"

NewBirchsLab_EventScript_AskChimchar_Text_6:
# 180 "data/maps/NewBirchsLab/scripts.pory"
	.string "No More Room$"

NewBirchsLab_EventScript_SayMonoShowing_Text_0:
# 218 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Fighting-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_1:
# 220 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Flying-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_2:
# 222 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Poison-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_3:
# 224 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Ground-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_4:
# 226 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Rock-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_5:
# 228 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Bug-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_6:
# 230 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Ghost-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_7:
# 232 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Steel-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_8:
# 234 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Electric-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_9:
# 236 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Psychic-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_10:
# 238 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Ice-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_11:
# 240 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Dragon-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_12:
# 242 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Dark-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_13:
# 244 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Normal-type starters.$"

NewBirchsLab_EventScript_SayMonoShowing_Text_14:
# 246 "data/maps/NewBirchsLab/scripts.pory"
	.string "Showing Fairy-type starters.$"

NewBirchsLab_EventScript_PokeballOne_Text_0:
# 261 "data/maps/NewBirchsLab/scripts.pory"
	.string "Ask Professor Birch about this!$"

NewBirchsLab_EventScript_PokeballOne_Text_1:
# 273 "data/maps/NewBirchsLab/scripts.pory"
	.string "Better not get greedy!$"

NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_0:
# 283 "data/maps/NewBirchsLab/scripts.pory"
	.string "Do you want to choose {STR_VAR_1}?$"

NewBirchsLab_EventScript_HandleGrassStarterChoice_Text_1:
# 289 "data/maps/NewBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}!$"

NicknamePartyMon_Text_0:
# 605 "data/maps/NewBirchsLab/scripts.pory"
	.string "Give a nickname?$"

NicknameBoxMon_Text_0:
# 621 "data/maps/NewBirchsLab/scripts.pory"
	.string "Transferred to PC.$"

NewBirchsLab_NotChosen::
# 624 "data/maps/NewBirchsLab/scripts.pory"
	.string "You did not choose this Pokemon.$"

NewBirchsLab_NotYet::
# 628 "data/maps/NewBirchsLab/scripts.pory"
	.string "Better not touch these yet!\p"
	.string "Maybe you should talk to {RIVAL}.$"

NewBirchsLab_WelcomePlayerMale::
# 633 "data/maps/NewBirchsLab/scripts.pory"
	.string "Hello there! I'm Prof. Birch, and you\n"
	.string "must be {PLAYER}. You just missed\l"
	.string "{RIVAL}, she stopped by and grabbed\l"
	.string "one of my Starter Pokémon and then\l"
	.string "rushed out of here.\p"
	.string "I told her to be on the lookout for a\n"
	.string "trainer named {PLAYER}, who just moved\l"
	.string "into the house next door!\p"
	.string "I hope the two of you can be friends\n"
	.string "who can start a new Pokémon journey\l"
	.string "together.\p"
	.string "How about this, I'll give you one of\n"
	.string "these Starter Pokémon, and then if you\l"
	.string "can beat {RIVAL} with your Pokémon,\l"
	.string "come back and I'll give you a Pokédex!\p"
	.string "I'll tell you which Starter she chose\n"
	.string "after you pick yours, it wouldn't be\l"
	.string "fair if you knew before you picked!\p"
	.string "I can let you choose from any\n"
	.string "Generation of Starter Pokémon, just\l"
	.string "ask me if you want to change them.$"

NewBirchsLab_WelcomePlayerFemale::
# 657 "data/maps/NewBirchsLab/scripts.pory"
	.string "Hello there! I'm Prof. Birch, and you\n"
	.string "must be {PLAYER}. You just missed\l"
	.string "{RIVAL}, he stopped by and grabbed\l"
	.string "one of my Starter Pokémon and then\l"
	.string "rushed out of here.\p"
	.string "I told him to be on the lookout for a\n"
	.string "trainer named {PLAYER}, who just moved\l"
	.string "into the house next door!\p"
	.string "I hope the two of you can be friends\n"
	.string "who can start a new Pokémon journey\l"
	.string "together.\p"
	.string "How about this, I'll give you one of\n"
	.string "these Starter Pokémon, and then if you\l"
	.string "can beat {RIVAL} with your Pokémon,\l"
	.string "come back and I'll give you a Pokédex!\p"
	.string "I'll tell you which Starter he chose\n"
	.string "after you pick yours, it wouldn't be\l"
	.string "fair if you knew before you picked!\p"
	.string "I can let you choose from any\n"
	.string "Generation of Starter Pokémon, just\l"
	.string "ask me if you want to change them.$"

NewBirchsLab_WelcomePlayerMaleMonotype::
# 681 "data/maps/NewBirchsLab/scripts.pory"
	.string "Hello there! I'm Prof. Birch, and you\n"
	.string "must be {PLAYER}. You just missed\l"
	.string "{RIVAL}, she stopped by and grabbed\l"
	.string "one of my Starter Pokémon and then\l"
	.string "rushed out of here.\p"
	.string "I told her to be on the lookout for a\n"
	.string "trainer named {PLAYER}, who just moved\l"
	.string "into the house next door!\p"
	.string "I hope the two of you can be friends\n"
	.string "who can start a new Pokémon journey\l"
	.string "together.\p"
	.string "How about this, I'll give you one of\n"
	.string "these Starter Pokémon, and then if you\l"
	.string "can beat {RIVAL} with your Pokémon,\l"
	.string "come back and I'll give you a Pokédex!\p"
	.string "I'll tell you which Starter she chose\n"
	.string "after you pick yours, it wouldn't be\l"
	.string "fair if you knew before you picked!\p"
	.string "I can let you choose from any\n"
	.string "Type of Starter Pokémon, just\l"
	.string "ask me if you want to change them.$"

NewBirchsLab_WelcomePlayerFemaleMonotype::
# 705 "data/maps/NewBirchsLab/scripts.pory"
	.string "Hello there! I'm Prof. Birch, and you\n"
	.string "must be {PLAYER}. You just missed\l"
	.string "{RIVAL}, he stopped by and grabbed\l"
	.string "one of my Starter Pokémon and then\l"
	.string "rushed out of here.\p"
	.string "I told him to be on the lookout for a\n"
	.string "trainer named {PLAYER}, who just moved\l"
	.string "into the house next door!\p"
	.string "I hope the two of you can be friends\n"
	.string "who can start a new Pokémon journey\l"
	.string "together.\p"
	.string "How about this, I'll give you one of\n"
	.string "these Starter Pokémon, and then if you\l"
	.string "can beat {RIVAL} with your Pokémon,\l"
	.string "come back and I'll give you a Pokédex!\p"
	.string "I'll tell you which Starter he chose\n"
	.string "after you pick yours, it wouldn't be\l"
	.string "fair if you knew before you picked!\p"
	.string "I can let you choose from any\n"
	.string "Type of Starter Pokémon, just\l"
	.string "ask me if you want to change them.$"

NewBirchsLab_Route103PlayerMale::
# 729 "data/maps/NewBirchsLab/scripts.pory"
	.string "{RIVAL} yelled she was heading to\n"
	.string "Route 103 as she ran out the door,\l"
	.string "perhaps you should look for her there.$"

NewBirchsLab_Route103PlayerFemale::
# 736 "data/maps/NewBirchsLab/scripts.pory"
	.string "{RIVAL} yelled he was heading to\n"
	.string "Route 103 as he ran out the door,\l"
	.string "perhaps you should look for him there.$"

NewBirchsLab_RivalStarterTreeckoPlayerMale::
# 743 "data/maps/NewBirchsLab/scripts.pory"
	.string "A great choice, but also an unlucky one!\n"
	.string "{RIVAL} chose a Treecko as\l"
	.string "her Starter!$"

NewBirchsLab_RivalStarterTreeckoPlayerFemale::
# 750 "data/maps/NewBirchsLab/scripts.pory"
	.string "A great choice, but also an unlucky one!\n"
	.string "{RIVAL} chose a Treecko as\l"
	.string "his Starter!$"

NewBirchsLab_RivalStarterMudkipPlayerMale::
# 757 "data/maps/NewBirchsLab/scripts.pory"
	.string "A great choice, but also an unlucky one!\n"
	.string "{RIVAL} chose a Mudkip as\l"
	.string "her Starter!$"

NewBirchsLab_RivalStarterMudkipPlayerFemale::
# 764 "data/maps/NewBirchsLab/scripts.pory"
	.string "A great choice, but also an unlucky one!\n"
	.string "{RIVAL} chose a Mudkip as\l"
	.string "his Starter!$"

NewBirchsLab_RivalStarterTorchicPlayerMale::
# 771 "data/maps/NewBirchsLab/scripts.pory"
	.string "A great choice, but also an unlucky one!\n"
	.string "{RIVAL} chose a Torchic as\l"
	.string "her Starter!$"

NewBirchsLab_RivalStarterTorchicPlayerFemale::
# 778 "data/maps/NewBirchsLab/scripts.pory"
	.string "A great choice, but also an unlucky one!\n"
	.string "{RIVAL} chose a Torchic as\l"
	.string "his Starter!$"

NewBirchsLab_RivalStarterSprigatitoPlayerMale::
# 785 "data/maps/NewBirchsLab/scripts.pory"
	.string "Yeah, {RIVAL} chose a Sprigatito as\l"
	.string "her Starter. Good Luck.$"

NewBirchsLab_RivalStarterSprigatitoPlayerFemale::
# 791 "data/maps/NewBirchsLab/scripts.pory"
	.string "Yeah, {RIVAL} chose a Sprigatito as\l"
	.string "his Starter. Good Luck.$"

NewBirchsLab_ChangeStarters::
# 797 "data/maps/NewBirchsLab/scripts.pory"
	.string "Which Generation of Starters would you\n"
	.string "like to see? You can change\l"
	.string "Generations as many times as you want.$"

NewBirchsLab_ChangeStartersMonotypes::
# 803 "data/maps/NewBirchsLab/scripts.pory"
	.string "Which Type of Starters would you\n"
	.string "like to see? You can change\l"
	.string "Types as many times as you want.$"
