#include "../includes/cub3d.h"

int	find_identifier(char *str, t_info *info)
{
	int		error;
	char	*removed;

	error = 0;
	removed = NULL;
	removed = remove_char_str(str, ' ');
	if(!removed)
		return (0);
	if (removed[0] == 'C')
		error =	set_identifier_ceiling(removed, info);
	if (removed[0] == 'F')
		error =	set_identifier_floor(removed, info);
	if (removed)
		free(removed);
	if (error == -1)
	{
		ft_putstr_fd("Please make sure the identifier are correct!\n", 2);
		return (-1);
	}
	return (0);
}

/*
	looking for identifier of ceiling and floor
	throwing error if multiple identifier or
	unexpected characters
*/
int	check_id(char *map, t_info *info)
{
	int		file;
	char	*str;

	file = open(map, O_RDONLY);
	str = get_next_line(file);
	if (!str)
	{
		close(file);
		exit_msg_error("Error: Empty file ayyyy\n");
	}
	while(str)
	{
		if(find_identifier(str, info) == -1)
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
