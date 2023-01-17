/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:56:33 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 20:06:42 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init(t_info *info)
{
	info->pos_x = info->player.x;
	info->pos_y = info->player.y;
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	info->side_dist_x = 0;
	info->side_dist_y = 0;
	info->hit = 0;
	info->perp_wall_dist = 0;
	info->line_height = 0;
	info->draw_start = 0;
	info->draw_end = 0;
}

void	init_start_position(t_info *info)
{
	if (info->map[info->player.y][info->player.x] == 'N')
	{
		info->dir_x = 0;
		info->dir_y = -1;
	}
	if (info->map[info->player.y][info->player.x] == 'S')
	{
		info->dir_x = 0;
		info->dir_y = 1;
	}
	if (info->map[info->player.y][info->player.x] == 'W')
	{
		info->dir_x = -1;
		info->dir_y = 0;
	}
	if (info->map[info->player.y][info->player.x] == 'E')
	{
		info->dir_x = 1;
		info->dir_y = 0;
	}
	info->perp_dir_x = info->dir_y;
	info->perp_dir_y = info->dir_x * -1;
	info->plane_x = info->perp_dir_x;
	info->plane_y = info->perp_dir_y * 0.66;
}

/*
	reset of identifiers for proper check inbetween.
*/
void	reset_info(t_info *info)
{
	info->ceiling.number = 0;
	info->floor.number = 0;
	info->no = 0;
	info->ea = 0;
	info->so = 0;
	info->we = 0;
}
