#include "../includes/cub3d.h"

/*
	checking if the file name ends with .cub
*/
void	check_name(char *map_name)
{
	int	len_name;

	len_name = ft_strlen(map_name);
	if (len_name <= 4)
		exit_msg_error("Error invalid map name\n");
	if (map_name[len_name - 4] != '.' || map_name[len_name - 3] != 'c' 
			|| map_name[len_name - 2] != 'u' || map_name[len_name - 1] != 'b')
		exit_msg_error("Error invalid map name\n");
}

/*
	pre-check if the file exist
*/
int	check_file(char *map_path)
{
	int	file;

	file = open(map_path, O_RDONLY);
	if (file == -1)
	{
		perror(map_path);
		return (-1);
	}
	close(file);
	return (0);
}

void	error_check(char *map, t_info *info)
{
	check_name(map);
	if (check_file(map) == -1)
		exit (1);
	if (check_id(map, info) == -1)
		exit (1);
	if (check_compass(map,info) == -1)
		exit (1);
}