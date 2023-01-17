/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:55:03 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/09 17:16:36 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_compass(char *map, t_info *info)
{
	int		file;
	char	*str;

	file = open(map, O_RDONLY);
	str = get_next_line(file);
	while (str)
	{
		if (set_compass_texture(str, info) == -1)
		{
			free(str);
			close(file);
			return (-1);
		}
		str = get_next_line(file);
	}
	free(str);
	close(file);
	return (0);
}

static int	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	set_compass_texture_helper(t_info *info, char *removed, int error)
{
	if (removed[0] == 'N' && removed[1] == 'O')
		error = set_texture_north(removed, info);
	if (removed[0] == 'E' && removed[1] == 'A')
		error = set_texture_east(removed, info);
	if (removed[0] == 'S' && removed[1] == 'O')
		error = set_texture_south(removed, info);
	if (removed[0] == 'W' && removed[1] == 'E')
		error = set_texture_west(removed, info);
	return (error);
}

int	set_compass_texture(char *str, t_info *info)
{
	int		error;
	char	*removed;

	error = 0;
	if (only_space(str) == 1)
		return (0);
	removed = remove_char_str(str, ' ');
	if (removed[0] == '\0')
	{
		free(removed);
		return (0);
	}
	error = set_compass_texture_helper(info, removed, error);
	if (error == -1)
	{
		free (removed);
		ft_putstr_fd("Error: textures not set correct\n", 2);
		return (-1);
	}
	free(removed);
	return (0);
}
