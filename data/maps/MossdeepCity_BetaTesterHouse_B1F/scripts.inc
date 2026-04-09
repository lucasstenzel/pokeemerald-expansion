# 1 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"

# 2 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
.set LOCALID_JENKINS, 1
# 3 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
.set LOCALID_SNAKE, 2
# 4 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"

# 5 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
MossdeepCity_BetaTesterHouse_B1F_MapScripts::
# 6 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.byte 0

MossdeepCity_BetaTesterHouse_B1F_EventScript_Jenkins::
# 10 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	trainerbattle_single TRAINER_JENKINS, Jenkins_Intro, Jenkins_Outro, MossdeepCity_BetaTesterHouse_B1F_EventScript_JenkinsDefeated
# 11 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	msgbox PostBattle_Jenkins, MSGBOX_AUTOCLOSE
	end


MossdeepCity_BetaTesterHouse_B1F_EventScript_JenkinsDefeated::
# 16 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	msgbox Jenkins_RewardText, MSGBOX_DEFAULT
# 17 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	giveitem ITEM_GARCHOMPITE
# 18 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	msgbox PostBattle_Jenkins, MSGBOX_DEFAULT
# 19 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	release
	end


MossdeepCity_BetaTesterHouse_B1F_EventScript_Snake::
# 29 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	trainerbattle_single TRAINER_SNAKE, Snake_Intro, Snake_Outro, MossdeepCity_BetaTesterHouse_B1F_EventScript_SnakeDefeated
# 30 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	msgbox PostBattle_Snake, MSGBOX_AUTOCLOSE
	end


MossdeepCity_BetaTesterHouse_B1F_EventScript_SnakeDefeated::
# 35 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	setflag FLAG_SNAKE_DEFEATED
# 36 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	msgbox PostBattle_Snake, MSGBOX_DEFAULT
# 37 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	release
	end


Jenkins_RewardText::
# 23 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.string "Not bad! Here, I'll share\n"
	.string "some of my loot with you.$"

Jenkins_Intro::
# 41 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.string "Alright Chumps, let's do this.\n"
	.string "LEEROOOOOOOOOOOY...$"

Jenkins_Outro::
# 46 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.string "Now you can finally play the game.$"

PostBattle_Jenkins::
# 50 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.string "You can thank Bruce for that.$"

Snake_Intro::
# 54 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.string "Kept you waiting, huh?$"

Snake_Outro::
# 58 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.string "Surprised you've made it this far.$"

PostBattle_Snake::
# 62 "data/maps/MossdeepCity_BetaTesterHouse_B1F/scripts.pory"
	.string "I'll let you in on a secret. Deep in the\n"
	.string "North-East area of the Safari Zone, there's\l"
	.string "a smashable rock in a nook. There's a\l"
	.string "hidden staircase behind it.$"
