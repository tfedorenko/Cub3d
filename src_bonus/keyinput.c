/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:56:47 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 21:31:54 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_right(t_info *info)
{
	if (info->map[info->player.y][info->player.x + 1] != '1')
	{
		info->map[info->player.y][info->player.x] = '0';
		info->map[info->player.y][info->player.x + 1] = info->view;
		info->player.x++;
	}
	return (0);
}

int	key_left(t_info *info)
{
	if (info->map[info->player.y][info->player.x - 1] != '1')
	{
		info->map[info->player.y][info->player.x] = '0';
		info->map[info->player.y][info->player.x - 1] = info->view;
		info->player.x--;
	}
	return (0);
}

int	key_down(t_info *info)
{
	if (info->map[info->player.y + 1][info->player.x] != '1')
	{
		info->map[info->player.y][info->player.x] = '0';
		info->map[info->player.y + 1][info->player.x] = info->view;
		info->player.y++;
	}
	return (0);
}

int	key_up(t_info *info)
{
	if (info->map[info->player.y - 1][info->player.x] != '1')
	{
		info->map[info->player.y][info->player.x] = '0';
		info->map[info->player.y - 1][info->player.x] = info->view;
		info->player.y--;
	}
	return (0);
}

/* int	keyinput(int key, t_info *info)
{
	if (key == RIGHT)
		key_right(info);
	else if (key == LEFT)
		key_left(info);
	else if (key == DOWN)
		key_down(info);
	else if (key == UP)
		key_up(info);
	else if (key == ESC)
		exit(1);
	return (0);
} */
