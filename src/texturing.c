/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:02:12 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:24 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	texturing(t_info *info)
{
	int		width;
	int		height;
	char	*texture_file;

	if (info->ray_dir_y < 0 && info->side == 1)
		texture_file = info->north;
	if (info->ray_dir_y > 0 && info->side == 1)
		texture_file = info->south;
	if (info->ray_dir_x > 0 && info->side == 0)
		texture_file = info->east;
	if (info->ray_dir_x < 0 && info->side == 0)
		texture_file = info->west;
	info->img_texture.img_ptr = mlx_new_image(info->mlx, \
		TEXTURE_WIDTH, TEXTURE_HIGHT);
	info->img_texture.img_ptr = mlx_xpm_file_to_image(info->mlx, \
		texture_file, &width, &height);
	info->img_texture.mlx_img_addr = \
		mlx_get_data_addr(info->img_texture.img_ptr, \
			&info->img_texture.bits_per_pixel, &info->img_texture.line_len, \
				&info->img_texture.endian);
}

int	get_pixel_color_2(t_info *info, int y)
{
	char	*dst;
	double	wall_x;
	int		texture_x;

	if (info->side == 0)
		wall_x = info->pos_y + info->perp_wall_dist * info->ray_dir_y;
	else
		wall_x = info->pos_x + info->perp_wall_dist * info->ray_dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if (info->side == 0 && info->ray_dir_x > 0)
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	if (info->side == 0 && info->ray_dir_y < 0)
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	if (texture_x > TEXTURE_WIDTH)
		texture_x = texture_x % TEXTURE_WIDTH;
	if (y > TEXTURE_HIGHT)
		y = y % TEXTURE_HIGHT;
	if (y < 0)
		y = 0;
	dst = info->img_texture.mlx_img_addr + y * info->img_texture.line_len + \
		texture_x * (info->img_texture.bits_per_pixel / 8);
	return (*(int *)dst);
}
