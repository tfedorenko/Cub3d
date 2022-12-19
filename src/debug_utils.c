#include "../includes/cub3d.h"

/*
	added @ symbol to check for null characters
*/
void print_struct(t_info *info)
{
	printf("RBG for ceiling %d , %d, %d\n", info->ceiling.r, info->ceiling.g, info->ceiling.b);
	printf("RBG for floor %d , %d, %d\n", info->floor.r, info->floor.g, info->floor.b);
	printf("Texture for north = %s@\n", info->north);
	printf("Texture for east = %s@\n", info->east);
	printf("Texture for south = %s@\n", info->south);
	printf("Texture for west = %s@\n", info->west);
}