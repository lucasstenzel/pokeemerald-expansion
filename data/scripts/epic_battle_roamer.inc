EventScript_EpicBattleRoamerRelease::
	lockall
	clearflag FLAG_EPIC_BATTLE_ROAMER_PENDING
	pokenavcall Text_EpicBattleRoamerCall
	waitmessage
	delay 30
	closemessage
	releaseall
	end

Text_EpicBattleRoamerCall:
	.string "… … … … … …\p"
	.string "Yo {PLAYER},\p"
	.string "I just got word that a rare POKéMON\n"
	.string "was spotted roaming the region!\p"
	.string "It must have been drawn out by the\n"
	.string "intensity of that battle!\p"
	.string "Keep your eyes peeled out there!$"
