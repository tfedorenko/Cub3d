/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:13:29 by tfedoren          #+#    #+#             */
/*   Updated: 2022/12/19 16:04:30 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->mlx_img_addr + (y * img_data->line_len + x * (img_data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(t_cub3d *cub3d, int x, int color, t_img_data *img)
{
	int i;
	i = 0;
	while (i < cub3d->drawStart)
	{
		my_mlx_pixel_put(img, x, i, cub3d->def_color);
		i++;
	}
	i = 0;
	while (i < cub3d->drawEnd - cub3d->drawStart)
	{
		my_mlx_pixel_put(img, x, cub3d->drawStart + i, color);
		i++;
	}
	if(color || x || img || cub3d){}
	i = 0;
	while (i < HEIGHT - cub3d->drawEnd)
	{
		my_mlx_pixel_put(img, x, i + cub3d->drawEnd, 0xE433FF); //pink
		i++;
	}

}

void ray_handler(t_cub3d *cub3d, int i)
{
	cub3d->cameraX = 2 * i / ((double)WIDTH - 1);
	cub3d->cameraX = 2 * i / ((double)WIDTH - 1);
	cub3d->rayDirX = cub3d->dirX + cub3d->planeX * cub3d->cameraX;
	cub3d->rayDirY = cub3d->dirY + cub3d->planeY * cub3d->cameraX;
	cub3d->mapX = (int)cub3d->posX;
	cub3d->mapY = (int)cub3d->posY;
	if (cub3d->rayDirX == 0)
		cub3d->deltaDistX = 1e30;
	else 
		cub3d->deltaDistX = fabs(1 / cub3d->rayDirX);
	if (cub3d->rayDirY == 0)
		cub3d->deltaDistY = 1e30;
	else 
		cub3d->deltaDistY = fabs(1 / cub3d->rayDirY);
	cub3d->hit = 0;
	if (cub3d->rayDirX < 0)
	{
		cub3d->stepX = -1;
		cub3d->sideDistX = (cub3d->posX - cub3d->mapX) * cub3d->deltaDistX;
	}
	else
	{
		cub3d->stepX = 1;
		cub3d->sideDistX = (cub3d->mapX + 1.0 - cub3d->posX) * cub3d->deltaDistX;
	}
	if (cub3d->rayDirY < 0)
	{
		cub3d->stepY = -1;
		cub3d->sideDistY = (cub3d->posY - cub3d->mapY) * cub3d->deltaDistY;
	}
	else
	{
		cub3d->stepY = 1;
		cub3d->sideDistY = (cub3d->mapY + 1.0 - cub3d->posY) * cub3d->deltaDistY;
	}
	cub3d->hit = 0;
}

void perform_DDA(t_cub3d *cub3d, int map[24][24])
{
	while (cub3d->hit == 0)
	{
		if(cub3d->sideDistX < cub3d->deltaDistY)
		{
			cub3d->sideDistX +=cub3d->deltaDistX;
			cub3d->mapX += cub3d->stepX;
			cub3d->side = 0;
		}
		else
		{
			cub3d->sideDistY +=cub3d->deltaDistY;
			cub3d->mapY += cub3d->stepY;
			cub3d->side = 1;
		}
		if (map[cub3d->mapY][cub3d->mapX] > 0)
			cub3d->hit = 1;
	}
	if (cub3d->side == 0)
	{
		cub3d->perpWallDist = cub3d->sideDistX - cub3d->deltaDistX;
	}
	else
		cub3d->perpWallDist = cub3d->sideDistY - cub3d->deltaDistY;
	if (cub3d->perpWallDist == 0)
		cub3d->perpWallDist = 1;
}

// void normalize(t_cub3d *cub3d)
// {
// 	double v;
// 	double f;

// 	v = sqrt(cub3d->planeX * cub3d->planeX + cub3d->planeY * cub3d->planeY);
// 	f = 0.66 / v;
// 	cub3d->planeX *= f;
// 	cub3d->planeX *= f;
// }

// void player_position(t_cub3d *cub3d, int map[24][24])
// {
	
// }

