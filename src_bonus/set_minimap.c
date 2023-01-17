/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:12 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/06 20:27:04 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	set_mlx_texture(t_info *info)
{
	int	width;
	int	heigth;

	info->p = mlx_xpm_file_to_image(info->mlx, RED, &width, &heigth);
	info->wall = mlx_xpm_file_to_image(info->mlx, GREY, &width, &heigth);
	info->ground = mlx_xpm_file_to_image(info->mlx, GREEN, &width, &heigth);
	info->snow_1 = mlx_xpm_file_to_image(info->mlx, SNOW_1, &width, &heigth);
	info->snow_2 = mlx_xpm_file_to_image(info->mlx, SNOW_2, &width, &heigth);
	info->snow_3 = mlx_xpm_file_to_image(info->mlx, SNOW_3, &width, &heigth);
}
