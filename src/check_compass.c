#include "../includes/cub3d.h"

int	check_compass(char *map, t_info *info)
{
	int		file;
	char	*str;

	file = open(map, O_RDONLY);
	str = get_next_line(file);
	while(str)
	{
		if(set_compass_texture(str, info) == -1)
		{
			free(str);
			close(file);
			return (-1);
		}
		if(str)
			free(str);
		str = get_next_line(file);
	}
	free(str);
	close(file);
	return (0);
}

int	set_compass_texture(char *str, t_info *info)
{
	int		error;
	char	*removed;

	error = 0;
	removed = remove_char_str(str, ' ');

	if (removed[0] == 'N' && removed[1] == 'O')
		error = set_texture_north(removed, info);
 	if (removed[0] == 'E' && removed[1] == 'A')
		error = set_texture_east(removed, info);
 	if (removed[0] == 'S' && removed[1] == 'O')
		error = set_texture_south(removed, info);
 	if (removed[0] == 'W' && removed[1] == 'E')
		error = set_texture_west(removed, info);
	if(error == -1)
	{
		free (removed);
		ft_putstr_fd("Error: textures not set correct\n", 2);
		return (-1);
	}
	free(removed);
	return (0);
}
