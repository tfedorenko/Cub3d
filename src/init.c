#include "../includes/cub3d.h"

// void init_img(t_img_data *img_data, t_mlx *mlx_data)
// {
 

//   // img_data->line_len = 0;
//   // img_data->bits_per_pixel = 0;
//   // img_data->img_ptr = NULL;

// 	img_data->img_ptr = mlx_new_image(mlx_data->mlx, 1920, 1080);
//   img_data->mlx_img_addr = mlx_get_data_addr(&img_data->img_ptr, &img_data->bits_per_pixel, &img_data->line_len, &img_data->endian);

// }

void	init(t_cub3d *cub3d)
{

  
  // Stuff for raycasting  
	cub3d->posX =22;
	cub3d->posY =12;
	cub3d->dirX =-1;
	cub3d->dirY =0;
	cub3d->planeX =0;
	cub3d->planeY =0.66;

  cub3d->time = 0; 
  cub3d->oldTime = 0;

	cub3d->mapX = (int)cub3d->posX;
  cub3d->mapY = (int)cub3d->posY;

  

  // cub3d->sideDistX = 0;
  // cub3d->sideDistY = 0;

  // cub3d->deltaDistX = 0;
  // cub3d->deltaDistY = 0;
  
  cub3d->hit = 0;
  // cub3d->side = 0;

  cub3d->perpWallDist = 0;
  cub3d->lineHeight = 0;
  cub3d->drawStart = 0;
  cub3d->drawEnd = 0;
	cub3d->def_color = 0xffffff;
 

	
  
	// printf("******Inside init******\n");



}
