#include "../includes/cub3d.h"

/* 
->making sure every variable is being set properly and used only once in the map_file
->because rgb is unsigned, negative numbers are not possible and used for error_check.
*/
// void	set_info(t_info *info)
// {
// 	info->ceiling.number = 0;
// 	info->ceiling.r = -1;
// 	info->ceiling.g = -1;
// 	info->ceiling.b = -1;
// 	info->floor.number = 0;
// 	info->floor.r = -1;
// 	info->floor.g = -1;
// 	info->floor.b = -1;
// 	info->no = 0;
// 	info->north = NULL;
// 	info->ea = 0;
// 	info->east = NULL;
// 	info->so = 0;
// 	info->south = NULL;
// 	info->we = 0;
// 	info->west = NULL;
// }

void	set_info(t_cub3d *cub3d)
{
	cub3d->info_data->ceiling.number = 0;
	printf("******Am I inside set_info?******\n");
	cub3d->info_data->ceiling.r = -1;
	cub3d->info_data->ceiling.g = -1;
	cub3d->info_data->ceiling.b = -1;
	cub3d->info_data->floor.number = 0;
	cub3d->info_data->floor.r = -1;
	cub3d->info_data->floor.g = -1;
	cub3d->info_data->floor.b = -1;
	cub3d->info_data->no = 0;
	cub3d->info_data->north = NULL;
	cub3d->info_data->ea = 0;
	cub3d->info_data->east = NULL;
	cub3d->info_data->so = 0;
	cub3d->info_data->south = NULL;
	cub3d->info_data->we = 0;
	cub3d->info_data->west = NULL;
}