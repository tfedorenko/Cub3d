#!/bin/bash
YELLOW=$'\e[101;33m'
GREEN=$'\e[0;32m'
RED=$'\e[38;5;196m'
NC=$'\e[0m'


	echo -e "${RED}============Testing the map============"
	echo "Rules:"
	echo "1. The file / error in the file"
	echo "2. Error message from the program"
	echo "3. If it exists, an error message from leaks-atExit${NC}"
	echo
	echo "${YELLOW}----------Wrong file name----------${NC}"
	echo 
	echo "wrong_name.cu"
	./cub3d maps/wrong_name.cu --leaks-atExit
	echo 
	echo "wrong_name_cubb"
	./cub3d maps/wrong_name_cubb --leaks-atExit
	echo 
	echo "${YELLOW}---------Missing textures---------${NC}"
	echo
	echo "Missing NO "
	./cub3d maps/missing_textures_1.cub --leaks-atExit
	echo
	echo "Missing EA "
	./cub3d maps/missing_textures_2.cub --leaks-atExit
	echo
	echo "Missing WE "
	./cub3d maps/missing_textures_3.cub --leaks-atExit
	echo
	echo "Missing SO "
	./cub3d maps/missing_textures_4.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Missing identifier---------${NC}"
	echo
	echo "Missing ceiling"
	./cub3d maps/missing_id_1.cub --leaks-atExit
	echo
	echo "Missing floor"
	./cub3d maps/missing_id_2.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Wrong identifier---------${NC}"
	echo
	echo "C 3,5,1,3"
	./cub3d maps/wrong_id_1.cub --leaks-atExit
	echo
	echo "comma after F0,0,0,"
	./cub3d maps/wrong_id_2.cub --leaks-atExit
	echo
	echo "two commas no value F0,0,,"
	./cub3d maps/wrong_id_3.cub --leaks-atExit
	echo
	echo "missing value F0,0"
	./cub3d maps/wrong_id_4.cub --leaks-atExit
	echo
	echo "F 0,0,3,2"
	./cub3d maps/wrong_id_5.cub --leaks-atExit
	echo
	echo "C a,5,1"
	./cub3d maps/wrong_id_6.cub --leaks-atExit
	echo
	echo "${YELLOW}---------identifier wrong value---------${NC}"
	echo "Number invalid value F0,0,-1"
	./cub3d maps/scope_id_1.cub --leaks-atExit
	echo
	echo "Number invalid value C 255,2147483648,1"
	./cub3d maps/scope_id_2.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Missing map---------${NC}"
	echo "No map after identifier"
	./cub3d maps/missing_map.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Unclosed map---------${NC}"
	echo "Unclosed upper border"
	./cub3d maps/unclosed_map_1.cub --leaks-atExit
	echo
	echo "Unclosed corner"
	./cub3d maps/unclosed_map_2.cub --leaks-atExit
	echo
	echo "Unclosed corner 2"
	./cub3d maps/unclosed_map_3.cub --leaks-atExit
	echo
	echo "Unclosed bottom border"
	./cub3d maps/unclosed_map_4.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Wrong player---------${NC}"
	echo "No player"
	./cub3d maps/wrong_player_1.cub --leaks-atExit
	echo
	echo "Two players"
	./cub3d maps/wrong_player_2.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Wall outside of the map---------${NC}"
	echo "Wall outside of the map"
	./cub3d maps/wall_outside.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Map between identifier---------${NC}"
	echo "Map is before identifier"
	./cub3d maps/map_inbetween_1.cub --leaks-atExit
	echo
	echo "Map is between textures"
	./cub3d maps/map_inbetween_2.cub --leaks-atExit
	echo
	echo "Map is between colors"
	./cub3d maps/map_inbetween_3.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Random character inbetween--------${NC}"
	echo "Random character between color information"
	./cub3d maps/random_character_1.cub --leaks-atExit
	echo
	echo "Random character before rgb value"
	./cub3d maps/random_character_2.cub --leaks-atExit
	echo
	echo "Random character inside the map"
	./cub3d maps/random_character_3.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Multiple identifier--------${NC}"
	echo "Multiple NO texture identifier"
	./cub3d maps/multiple_identifiers_1.cub --leaks-atExit
	echo
	echo "Multiple colors identifiers"
	./cub3d maps/multiple_identifiers_2.cub --leaks-atExit
	echo
	echo "Multiple texture and colors identifiers"
	./cub3d maps/multiple_identifiers_3.cub --leaks-atExit
	echo
	echo "${YELLOW}---------Multiple maps--------${NC}"
	echo "Multiple maps vertical"
	./cub3d maps/multiple_maps_1.cub --leaks-atExit
	echo
	echo "Multiple maps vertical and horizontal"
	./cub3d maps/multiple_maps_2.cub --leaks-atExit
	echo
	echo "${YELLOW}---------empty file--------${NC}"
	echo
	echo "empty file"
	./cub3d maps/empty.cub --leaks-atExit
	echo
	echo "${YELLOW}---------This file lel--------${NC}"
	echo "Z error"
	./cub3d maps/z.cub --leaks-atExit
	echo
