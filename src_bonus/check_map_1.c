/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:55:23 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 23:12:28 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/* 
	checking on how long the file is
*/
int	get_file_height(char *map)
{
	int		fd;
	char	*str;
	int		height;

	height = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		height++;
	}
	free(str);
	return (height);
}

/*
	start marks the starting row where we copy the 2D array for the map.
	-2 in line 35 because I subtract 2 NULL-terminating characters
*/
static void	map_copy_helper(t_info *info, char *str, int fd, int start)
{
	info->map[start] = NULL;
	free(str);
	close(fd);
}

static int	map_copy(char *map, t_info *info, int start)
{
	int		fd;
	char	*str;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	info->map_info.y = info->map_info.start - start - 2;
	info->map = malloc(sizeof(char *) * (info->map_info.y + 1));
	while (start > 0)
	{
		free(str);
		str = get_next_line(fd);
		start--;
	}
	while (str)
	{
		info->map[start] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
		start++;
	}
	map_copy_helper(info, str, fd, start);
	if (valid_map(info->map, info) == -1)
		return (-1);
	return (0);
}

/*
	checks the file until a wall is being found as first character
*/
int	check_map(char *map, t_info *info)
{
	int		fd;
	int		start;
	char	*str;
	char	*tmp;

	start = 1;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	tmp = remove_char_str(str, ' ');
	while (tmp[0] != '1')
	{
		start++;
		free(tmp);
		str = get_next_line(fd);
		tmp = remove_char_str(str, ' ');
	}
	free(str);
	free(tmp);
	if (map_copy(map, info, start) == -1)
		return (-1);
	return (0);
}
