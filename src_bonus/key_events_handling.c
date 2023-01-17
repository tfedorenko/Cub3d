/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:32:53 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 18:34:09 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;
	double	old_perp_dir_x;

	old_plane_x = info->plane_x;
	old_dir_x = info->dir_x;
	old_perp_dir_x = info->perp_dir_x;
	info->dir_x = info->dir_x * cos(-ROTATIONSPEED) - \
		info->dir_y * sin(-ROTATIONSPEED);
	info->dir_y = old_dir_x * sin(-ROTATIONSPEED) + \
		info->dir_y * cos(-ROTATIONSPEED);
	info->plane_x = info->plane_x * cos(-ROTATIONSPEED) - \
		info->plane_y * sin(-ROTATIONSPEED);
	info->plane_y = old_plane_x * sin(-ROTATIONSPEED) + \
		info->plane_y * cos(-ROTATIONSPEED);
	info->perp_dir_x = info->perp_dir_x * cos(-ROTATIONSPEED) - \
		info->perp_dir_y * sin(-ROTATIONSPEED);
	info->perp_dir_y = old_perp_dir_x * sin(-ROTATIONSPEED) + \
		info->perp_dir_y * cos(-ROTATIONSPEED);
}

void	rotate_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;
	double	old_perp_dir_x;

	old_plane_x = info->plane_x;
	old_dir_x = info->dir_x;
	old_perp_dir_x = info->perp_dir_x;
	info->dir_x = info->dir_x * cos(ROTATIONSPEED) - \
		info->dir_y * sin(ROTATIONSPEED);
	info->dir_y = old_dir_x * sin(ROTATIONSPEED) + \
		info->dir_y * cos(ROTATIONSPEED);
	info->plane_x = info->plane_x * cos(ROTATIONSPEED) - \
		info->plane_y * sin(ROTATIONSPEED);
	info->plane_y = old_plane_x * sin(ROTATIONSPEED) + \
		info->plane_y * cos(ROTATIONSPEED);
	info->perp_dir_x = info->perp_dir_x * cos(ROTATIONSPEED) - \
		info->perp_dir_y * sin(ROTATIONSPEED);
	info->perp_dir_y = old_perp_dir_x * sin(ROTATIONSPEED) + \
		info->perp_dir_y * cos(ROTATIONSPEED);
}

void	key_a(t_info *info)
{
	info->pos_x += MOVESPEED * info->perp_dir_x;
	info->pos_y += MOVESPEED * info->perp_dir_y;
}

void	key_d(t_info *info)
{
	info->pos_x -= MOVESPEED * info->perp_dir_x;
	info->pos_y -= MOVESPEED * info->perp_dir_y;
}
