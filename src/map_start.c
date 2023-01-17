/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:57:27 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/09 17:27:23 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**create_map(char *map, int start, int y)
{
	int		fd;
	char	*str;
	char	**new_map;

	new_map = NULL;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	new_map = malloc(sizeof(char *) * (y + 1 - start));
	while (start > 0)
	{
		str = get_next_line(fd);
		start--;
	}
	while (str)
	{
		new_map[start] = ft_strdup(str);
		str = get_next_line(fd);
		start++;
	}
	new_map[start] = NULL;
	free(str);
	close(fd);
	return (new_map);
}

/*
	if there are unexpected characters before the identifiers are
	set return value is -1
*/
static int	inbetween_check(char *str)
{
	char	*removed;

	removed = remove_char_str(str, ' ');
	if (removed[0] == 'C' || removed[0] == 'F')
		return (free_str_return(removed, 0));
	if (removed[0] == 'N' && removed[1] == 'O')
		return (free_str_return(removed, 0));
	if (removed[0] == 'E' && removed[1] == 'A')
		return (free_str_return(removed, 0));
	if (removed[0] == 'S' && removed[1] == 'O')
		return (free_str_return(removed, 0));
	if (removed[0] == 'W' && removed[1] == 'E')
		return (free_str_return(removed, 0));
	if (removed[0] == '\n')
		return (free_str_return(removed, 0));
	return (free_str_return(removed, -1));
}

/*
	now we check that there is nothing inbetween the identifier
 */
static int	id_check(char *str, t_info *info)
{
	int	check;

	check = 0;
	if (inbetween_check(str) == -1)
		return (-1);
	find_identifier(str, info);
	set_compass_texture(str, info);
	if (info->no == 1 && info->ea == 1)
		check++;
	if (info->so == 1 && info->we == 1)
		check++;
	if (info->ceiling.number == 1 && info->floor.number == 1)
		check++;
	if (check == 3)
		return (1);
	return (0);
}

int	map_start_helper(int fd, char *str)
{
	ft_putstr_fd("Error: invalid characters between identifier\n", 2);
	free(str);
	close(fd);
	return (-1);
}

int	map_start(char *map, t_info *info)
{
	int		fd;
	char	*str;
	int		start;

	start = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	reset_info(info);
	while (str)
	{
		start++;
		if (id_check(str, info) != 0)
			break ;
		str = get_next_line(fd);
	}
	if (id_check(str, info) == -1)
		return (map_start_helper(fd, str));
	free(str);
	close(fd);
	info->map_info.start = start;
	return (0);
}
