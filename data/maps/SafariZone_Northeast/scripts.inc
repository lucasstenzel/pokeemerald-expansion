# 1 "data/maps/SafariZone_Northeast/scripts.pory"

# 2 "data/maps/SafariZone_Northeast/scripts.pory"
SafariZone_Northeast_MapScripts::
# 3 "data/maps/SafariZone_Northeast/scripts.pory"
	.byte 0
# 4 "data/maps/SafariZone_Northeast/scripts.pory"

# 5 "data/maps/SafariZone_Northeast/scripts.pory"
SafariZone_Northeast_EventScript_SecretWall::
# 6 "data/maps/SafariZone_Northeast/scripts.pory"
	lock
# 7 "data/maps/SafariZone_Northeast/scripts.pory"
	faceplayer
# 8 "data/maps/SafariZone_Northeast/scripts.pory"
	msgbox SafariZone_Northeast_Text_CrackInWall, MSGBOX_YESNO
# 9 "data/maps/SafariZone_Northeast/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SafariZone_Northeast_EventScript_SecretWallDecline
# 10 "data/maps/SafariZone_Northeast/scripts.pory"
	@ Exit Safari Mode before warping
# 11 "data/maps/SafariZone_Northeast/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 1
# 12 "data/maps/SafariZone_Northeast/scripts.pory"
	special ExitSafariMode
# 13 "data/maps/SafariZone_Northeast/scripts.pory"
	playse SE_EXIT
# 14 "data/maps/SafariZone_Northeast/scripts.pory"
	waitse
# 15 "data/maps/SafariZone_Northeast/scripts.pory"
	warp MAP_TURNBACK_CAVE_ENTRANCE, 11, 20
# 16 "data/maps/SafariZone_Northeast/scripts.pory"
	waitstate
# 17 "data/maps/SafariZone_Northeast/scripts.pory"
	release
# 18 "data/maps/SafariZone_Northeast/scripts.pory"
	end
# 19 "data/maps/SafariZone_Northeast/scripts.pory"

# 20 "data/maps/SafariZone_Northeast/scripts.pory"
SafariZone_Northeast_EventScript_SecretWallDecline::
# 21 "data/maps/SafariZone_Northeast/scripts.pory"
	release
# 22 "data/maps/SafariZone_Northeast/scripts.pory"
	end
# 23 "data/maps/SafariZone_Northeast/scripts.pory"

# 24 "data/maps/SafariZone_Northeast/scripts.pory"
SafariZone_Northeast_Text_CrackInWall:
# 25 "data/maps/SafariZone_Northeast/scripts.pory"
	.string "You notice a crack in the wall...\n"
# 26 "data/maps/SafariZone_Northeast/scripts.pory"
	.string "Would you like to try to slip through?$"
