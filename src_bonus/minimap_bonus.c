/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:57:37 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/06 13:31:29 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_bonus.h"

static int	loading(t_info *info, char *map, size_t x, int y)
{
	int	scalex;
	int	scaley;

	scalex = (x * 10) + 20;
	scaley = (y * 10) + 30;
	if (map[x] == info->view)
		mlx_put_image_to_window(info->mlx, info->mlx_win,
			info->ground, scalex, scaley);
	if (map[x] == '1')
		mlx_put_image_to_window(info->mlx, info->mlx_win,
			info->wall, scalex, scaley);
	if (map[x] == '0')
		mlx_put_image_to_window(info->mlx, info->mlx_win,
			info->ground, scalex, scaley);
	return (0);
}

int	minimap(t_info *info)
{
	size_t	x;
	int		y;

	x = 0;
	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (x < ft_strlen(info->map[y]))
		{
			loading(info, info->map[y], x, y);
			x++;
		}
		y++;
	}
	return (0);
}
