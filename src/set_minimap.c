/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:12 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 19:02:45 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_mlx_texture(t_info *info)
{
	int	width;
	int	heigth;

	info->p = mlx_xpm_file_to_image(info->mlx, RED, &width, &heigth);
	info->wall = mlx_xpm_file_to_image(info->mlx, GREY, &width, &heigth);
	info->ground = mlx_xpm_file_to_image(info->mlx, GREEN, &width, &heigth);
}
