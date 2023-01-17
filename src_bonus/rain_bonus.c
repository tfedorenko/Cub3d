/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rain_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:38:46 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/09 16:38:49 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	rain(t_info *info)
{
	static int	drops;

	drops++;
	if ((drops % 4420) < 10)
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->snow_1, 0, 0);
	else if ((drops % 4420) < 20 && (drops % 4420) > 10)
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->snow_2, 0, 0);
	else if ((drops % 4420) < 30 && (drops % 4420) > 20)
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->snow_3, 0, 0);
	else if ((drops % 4420) < 40 && (drops % 4420) > 30)
	{
		drops = 0;
	}
	return (0);
}

int	cal_render(void *ptr)
{
	t_info	*info;

	info = (t_info *) ptr;
	mlx_clear_window(info->mlx, info->mlx_win);
	info->img_data.img_ptr = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img_data.mlx_img_addr = mlx_get_data_addr(info->img_data.img_ptr, \
		&info->img_data.bits_per_pixel, &info->img_data.line_len, \
			&info->img_data.endian);
	render(&info->img_data, info);
	return (0);
}

void	render(t_img_data *img, t_info *info)
{
	raycaster(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, img->img_ptr, 0, 0);
}
