/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:59:03 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 23:14:37 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	player_position(int y, char *str, t_info *info)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == 'N' || str[x] == 'E' || str[x] == 'S' || str[x] == 'W')
		{
			info->player.count++;
			info->view = str[x];
			info->player.x = x;
			info->player.y = y;
			return (0);
		}
		if (info->player.count > 1)
			return (-1);
		x++;
	}
	return (0);
}

int	valid_player(t_info *info)
{
	int		y;

	y = 0;
	while (info->map[y])
	{
		if (player_position(y, info->map[y], info) == -1)
			return (-1);
		y++;
	}
	if (info->player.count < 1)
		return (-1);
	return (0);
}
