/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:55:49 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 19:51:39 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	norminette function to output error and return a certain value
*/
static int	return_message(int error, char *msg)
{
	ft_putstr_fd(msg, 2);
	return (error);
}

static int	floor_check(size_t x, size_t y, char **map)
{
	if (map[y][x] != '0')
		return (0);
	if (x == 0)
		return (return_message(-1, "Make sure the map is closed 1\n"));
	if (allowed_char(map[y][x - 1]) == -1)
		return (return_message(-1, "Make sure the map is closed 2\n"));
	if (allowed_char(map[y][x + 1]) == -1)
		return (return_message(-1, "Make sure the map is closed 3\n"));
	if (y == 0)
		return (return_message(-1, "Make sure the map is closed 4\n"));
	if (allowed_char(map[y + 1][x]) == -1)
		return (return_message(-1, "Make sure the map is closed 5\n"));
	return (0);
}

int	valid_floor(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x] == ' ')
			x++;
		while (map[y][x])
		{
			if (floor_check(x, y, map) == -1)
			{
				printf("\nhere: %s \n ", map[y]);
				return (-1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static int	check_rows(char **map, size_t y, size_t x)
{
	int	connected;

	connected = 0;
	if (map[y + 1])
	{
		if (ft_strlen(map[y + 1]) >= x)
		{
			if (map[y + 1][x] != ' ' && map[y + 1][x] != '\0')
				connected++;
		}
	}
	if (y > 0)
	{
		if (ft_strlen(map[y - 1]) >= x)
		{
			if (map[y - 1][x] != ' ' && map[y - 1][x] != '\0')
				connected++;
		}
	}
	return (connected);
}

int	walls_connected(char **map, size_t y, size_t x)
{
	int	connected;

	connected = 0;
	if (map[y][x] != '1')
		return (1);
	connected += check_rows(map, y, x);
	if (x > 0)
	{
		if (map[y][x - 1] != ' ')
			connected++;
		if (map[y][x + 1] != ' ' && map[y][x + 1] != '\0')
			connected++;
	}
	return (connected);
}
