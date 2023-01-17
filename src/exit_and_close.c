/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:59:59 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/06 16:38:56 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	x_close(t_info *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	free(info);
	exit(0);
}

/*  key 53 = esc;
	key 126 or 13 = w or arrow up
	key 125 or 1 = s or arrow down
	key 0 = a
	key 2 = d
	key 123 = arrow left
	key 124 = arrow right*/
static void	key_w(t_info *info)
{
	info->pos_y += MOVESPEED * info->dir_y;
	info->pos_x += MOVESPEED * info->dir_x;
}

static void	key_s(t_info *info)
{
	info->pos_x -= MOVESPEED * info->dir_x;
	info->pos_y -= MOVESPEED * info->dir_y;
}

static void	deal_moves(int key, t_info *info)
{
	if ((key == 126 || key == 13) && no_collision_up_and_down(info, key))
	{
		key_w(info);
		cal_render(info);
	}
	else if ((key == 125 || key == 1) && no_collision_up_and_down(info, key))
	{	
		key_s(info);
		cal_render(info);
	}
	else if (key == 0 && no_collision_right_and_left(info, key))
	{	
		key_a(info);
		cal_render(info);
	}
	else if (key == 2 && no_collision_right_and_left(info, key))
	{
		key_d(info);
		cal_render(info);
	}
}

int	deal_key(int key, t_info *info)
{
	info->perp_dir_x = info->dir_y;
	info->perp_dir_y = info->dir_x * -1;
	if (key == 53)
	{
		mlx_destroy_window(info->mlx, info->mlx_win);
		free(info);
		exit(1);
	}
	else if (key == 126 || key == 13 || key == 125 || key == 1 || \
		key == 0 || key == 2)
	{
		deal_moves(key, info);
	}
	else if (key == 123)
	{	
		rotate_left(info);
		cal_render(info);
	}
	else if (key == 124)
	{	
		rotate_right(info);
		cal_render(info);
	}
	return (0);
}
