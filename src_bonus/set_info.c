/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:48:29 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 19:02:37 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
->making sure every variable is being set properly and used only 
	once in the map_file
->because rgb is unsigned, negative numbers are not possible and used 
	for error_check.
*/
void	set_info_1(t_info *info)
{
	info->ceiling.number = 0;
	info->ceiling.r = -1;
	info->ceiling.g = -1;
	info->ceiling.b = -1;
	info->floor.number = 0;
	info->floor.r = -1;
	info->floor.g = -1;
	info->floor.b = -1;
	info->no = 0;
	info->north = NULL;
	info->ea = 0;
	info->east = NULL;
	info->so = 0;
	info->south = NULL;
	info->we = 0;
	info->west = NULL;
	set_info_2(info);
	init(info);
}

void	set_info_2(t_info *info)
{
	info->map = NULL;
	info->player.count = 0;
	info->player.x = 0;
	info->player.y = 0;
}
