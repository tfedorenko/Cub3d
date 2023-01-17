/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handling_and_dda.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:20:46 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 18:24:16 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_handler_helper(t_info *info)
{
	if (info->ray_dir_x < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (info->pos_x - info->map_x) * info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - info->pos_x) * \
			info->delta_dist_x;
	}
	if (info->ray_dir_y < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (info->pos_y - info->map_y) * info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - info->pos_y) * \
			info->delta_dist_y;
	}
}

void	ray_handler(t_info *info, int i)
{
	info->camera_x = 2 * i / (double)WIDTH - 1;
	info->ray_dir_x = info->dir_x + info->plane_x * info->camera_x;
	info->ray_dir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	if (info->ray_dir_x == 0)
		info->delta_dist_x = 1e30;
	else
		info->delta_dist_x = fabs(1 / info->ray_dir_x);
	if (info->ray_dir_y == 0)
		info->delta_dist_y = 1e30;
	else
		info->delta_dist_y = fabs(1 / info->ray_dir_y);
	info->hit = 0;
	ray_handler_helper(info);
	info->hit = 0;
}

void	perform_dda_helper(t_info *info)
{
	if (info->side_dist_x < info->side_dist_y)
	{
		info->side_dist_x += info->delta_dist_x;
		info->map_x += info->step_x;
		info->side = 0;
	}
	else
	{
		info->side_dist_y += info->delta_dist_y;
		info->map_y += info->step_y;
		info->side = 1;
	}
	if (info->map[info->map_y][info->map_x] == '1')
		info->hit = 1;
}

void	perform_dda(t_info *info)
{
	while (info->hit == 0)
		perform_dda_helper(info);
	if (info->side == 0)
		info->perp_wall_dist = info->side_dist_x - info->delta_dist_x;
	else
		info->perp_wall_dist = info->side_dist_y - info->delta_dist_y;
	if (info->perp_wall_dist == 0)
		info->perp_wall_dist = 1;
}
