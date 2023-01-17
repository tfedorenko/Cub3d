/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:13:29 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 19:57:51 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->mlx_img_addr + (y * img_data->line_len + x * \
		(img_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	rgb_to_hex(t_id *color_from_parsing)
{
	int	color;

	color = (color_from_parsing->r << 16 | color_from_parsing->g << 8 | \
		color_from_parsing->b << 0);
	return (color);
}

static void	drawing_wall(t_info *info, int x, t_img_data *img)
{
	int		i;
	int		color_from_texture;
	double	texture_y;
	double	step;

	i = 0;
	step = 1.0 * TEXTURE_HIGHT / (HEIGHT / info->perp_wall_dist);
	texture_y = (info->draw_start - HEIGHT / 2.0 + \
			(HEIGHT / info->perp_wall_dist) / 2.0) * step;
	while (i < info->draw_end - info->draw_start)
	{
		color_from_texture = get_pixel_color_2(info, (int)texture_y);
		my_mlx_pixel_put(img, x, info->draw_start + i, color_from_texture);
		texture_y += step;
		i++;
	}
}

void	draw_line(t_info *info, int x, t_img_data *img)
{
	int		i;

	i = 0;
	while (i < info->draw_start)
	{
		my_mlx_pixel_put(img, x, i, rgb_to_hex(&info->ceiling));
		i++;
	}
	drawing_wall(info, x, img);
	i = 1;
	while (i < HEIGHT - info->draw_end)
	{
		my_mlx_pixel_put(img, x, i + info->draw_end, rgb_to_hex(&info->floor));
		i++;
	}
}
