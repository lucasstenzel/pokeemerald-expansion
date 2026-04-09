# 1 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_MapScripts::
# 5 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_OnTransition:
# 10 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_PETALBURG_CITY
# 11 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 12 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
# 15 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 16 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 17 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 18 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 19 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 20 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
# 23 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
# 24 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 25 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 26 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
# 27 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
# 28 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 29 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 30 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_Woman::
# 31 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	lock
# 32 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 33 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
# 34 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	specialvar VAR_RESULT, IsStarterInParty
# 35 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
# 36 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 37 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 38 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 39 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
# 40 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
# 41 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
# 42 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
# 43 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 3, PetalburgCity_PokemonCenter_1F_EventScript_SayGibleType
# 44 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	release
# 45 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	end
# 46 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 47 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
# 48 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
# 49 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 50 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 51 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
# 52 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
# 53 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 54 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 55 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
# 56 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
# 57 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 58 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 59 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_EventScript_SayGibleType::
# 60 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	msgbox PetalburgCity_PokemonCenter_1F_Text_GibleIsDragonGroundType, MSGBOX_DEFAULT
# 61 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	return
# 62 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 63 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
# 64 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "That PC-based Pokémon Storage\n"
# 65 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "System…\p"
# 66 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Whoever made it must be some kind\n"
# 67 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "of a scientific wizard!$"
# 68 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 69 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
# 70 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "When my Pokémon ate an\n"
# 71 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "ORAN BERRY, it regained HP!$"
# 72 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 73 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
# 74 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "There are many types of Pokémon.\p"
# 75 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "All types have their strengths and\n"
# 76 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "weaknesses against other types.\p"
# 77 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Depending on the types of Pokémon,\n"
# 78 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "a battle could be easy or hard.$"
# 79 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 80 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
# 81 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TREECKO\n"
# 82 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a GRASS type.\p"
# 83 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the WATER and\n"
# 84 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "GROUND types.\p"
# 85 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against FIRE-type\n"
# 86 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Pokémon.$"
# 87 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 88 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
# 89 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your TORCHIC\n"
# 90 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a FIRE type.\p"
# 91 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the GRASS and\n"
# 92 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "BUG types.\p"
# 93 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against WATER-type\n"
# 94 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "Pokémon.$"
# 95 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 96 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
# 97 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your MUDKIP\n"
# 98 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a WATER type.\p"
# 99 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the FIRE type.\p"
# 100 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it's weak against GRASS-type\n"
# 101 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "and ELECTRIC-type Pokémon.$"
# 102 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"

# 103 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
PetalburgCity_PokemonCenter_1F_Text_GibleIsDragonGroundType:
# 104 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "For example, your GIBLE\n"
# 105 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "is a DRAGON and GROUND type.\p"
# 106 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "It's strong against the ELECTRIC type.\p"
# 107 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "But, it gets obliterated by\n"
# 108 "data/maps/PetalburgCity_PokemonCenter_1F/scripts.pory"
	.string "ICE-type Pokémon.$"
