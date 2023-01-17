/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:57:19 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/06 10:32:17 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (argc < 2)
		exit_msg_error("Error: Map argument is wrong.\n");
	set_info_1(info);
	error_check(argv[1], info);
	init(info);
	init_start_position(info);
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, WIDTH, HEIGHT, \
		"Our amazing project");
	cal_render(info);
	mlx_hook(info->mlx_win, 2, 0, deal_key, info);
	mlx_hook(info->mlx_win, 17, 0, x_close, info);
	mlx_loop(info->mlx);
	return (0);
}

void	render(t_img_data *img, t_info *info)
{
	raycaster(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, img->img_ptr, 0, 0);
}

double	smth(double target, double possible, double number)
{
	if (target + possible > number && target - possible < number)
		return (target);
	return (number);
}

void	raycaster(t_info *info)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ray_handler(info, i);
		perform_dda(info);
		info->perp_wall_dist = smth(0, 0.001, info->perp_wall_dist);
		if (info->perp_wall_dist == 0)
			info->draw_end = HEIGHT;
		else
			info->line_height = (int)(HEIGHT / info->perp_wall_dist);
		info->draw_start = (-info->line_height / 2 + HEIGHT / 2);
		if (info->draw_start < 0)
			info->draw_start = 0;
		info->draw_end = info->line_height / 2 + HEIGHT / 2;
		if (info->draw_end >= HEIGHT)
			info->draw_end = HEIGHT - 1;
		texturing(info);
		draw_line(info, WIDTH - i - 1, &info->img_data);
		i++;
	}
}
