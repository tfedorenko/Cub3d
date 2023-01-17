/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:55:41 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 23:15:28 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	map_characters(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (valid_map_characters(map[y][x]) == -1)
			{
				ft_putstr_fd("Error: invalid character found in map\n", 2);
				return (-1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static int	valid_walls(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (walls_connected(map, y, x) < 1)
			{
				ft_putstr_fd("Error: Walls not correct\n", 2);
				printf("walls wrong here %s with x = %zu\n", map[y], x);
				return (-1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/*
	checking for valid characters in the map.
	valid characters are: 1, 0 , N, E, S, W
	1 -> wall (has to be connected to atleast another wall)
	0 -> floor (surrounded by walls)
	N,E,S,W -> Player (only one allowed)
*/
int	valid_map(char **map, t_info *info)
{
	if (!info->map)
		return (-1);
	if (map_characters(map) == -1)
		return (-1);
	if (valid_floor(map) == -1)
		return (-1);
	if (valid_walls(map) == -1)
		return (-1);
	if (valid_player(info) == -1)
		return (-1);
	return (0);
}

int	valid_map_characters(char c)
{
	int	error;

	error = -1;
	if (c == '0' || c == '1' || c == ' ')
		error = 0;
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		error = 0;
	if (c == '\n')
		error = 0;
	return (error);
}
