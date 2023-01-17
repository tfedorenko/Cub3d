/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:46:00 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 23:16:12 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	array_length(char **arr)
{
	int	out;

	out = 0;
	while (arr[out])
		out++;
	return (out);
}

static bool	inside_bounds(t_info *info, int x, int y)
{
	if (x < 0 || y < 0 || (x > ((int)ft_strlen(info->map[y]) - 1) \
			|| y > array_length(info->map)))
		return (false);
	return (true);
}

int	no_collision_up_and_down(t_info *info, int key)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 126 || key == 13)
	{
		x = (int)(info->pos_x + (MOVESPEED * 2) * info->dir_x);
		y = (int)(info->pos_y + (MOVESPEED * 2) * info->dir_y);
	}
	else if ((key == 125 || key == 1))
	{
		x = (int)(info->pos_x - (MOVESPEED * 2) * info->dir_x);
		y = (int)(info->pos_y - (MOVESPEED * 2) * info->dir_y);
	}
	if (inside_bounds(info, x, y) == false)
		return (0);
	if (info->map[y][x] == '1')
		return (0);
	return (1);
}

int	no_collision_right_and_left(t_info *info, int key)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	info->perp_dir_x = info->dir_y;
	info->perp_dir_y = info->dir_x * -1;
	if (key == 0)
	{
		x = (int)(info->pos_x + (MOVESPEED * 2) * info->perp_dir_x);
		y = (int)(info->pos_y + (MOVESPEED * 2) * info->perp_dir_y);
	}
	else if (key == 2)
	{
		x = (int)(info->pos_x - (MOVESPEED * 2) * info->perp_dir_x);
		y = (int)(info->pos_y - (MOVESPEED * 2) * info->perp_dir_y);
	}
	if (inside_bounds(info, x, y) == false)
		return (0);
	if (info->map[y][x] == '1')
		return (0);
	return (1);
}
