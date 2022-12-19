#include "../includes/cub3d.h"

int	set_identifier_floor(char *str, t_info *info)
{
	if (!str)
		return (-1);
	if (str[0] == 'F')
	{
		info->floor.number++;
		return (set_rgb(str, &info->floor));
	}
	return (-1);
}

int	set_identifier_ceiling(char *str, t_info *info)
{
	if (!str)
		return (-1);
	if (str[0] =='C')
	{
		info->ceiling.number++;
		return (set_rgb(str, &info->ceiling));
	}
	return (-1);
}


/* void	set_compass_texture(char *str, t_info *info, char compass, int pos)
{
	if (compass == 'N')
	{
		info->no++;
		open();
	}
	if (compass == 'E')
		check_east(str, info, pos);
	if (compass == 'S')
		check_south(str, info, pos);
	if (compass == 'W')
		check_west(str, info, pos);
} */