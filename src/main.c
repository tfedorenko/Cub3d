#include "../includes/cub3d.h"

int map[mapWidth][mapHeight]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	
int loop_render(void *ptr)
{
	t_cub3d *cub3d = (t_cub3d *) ptr;
	mlx_clear_window(cub3d->mlx, cub3d->mlx_win);
	cub3d->img_data.img_ptr = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	cub3d->img_data.mlx_img_addr = mlx_get_data_addr(cub3d->img_data.img_ptr, &cub3d->img_data.bits_per_pixel, &cub3d->img_data.line_len,
						&cub3d->img_data.endian);
	render(cub3d, &cub3d->img_data,  map);
	return 0;
}

int	main(int argc, char **argv)
{
	t_cub3d *cub3d;

	(void)argv;
	(void)argc;
	cub3d = malloc(sizeof(t_cub3d));
	init(cub3d);
	cub3d->mlx = mlx_init();
	cub3d->mlx_win = mlx_new_window(cub3d->mlx, WIDTH, HEIGHT, "Our amazing project");
	mlx_loop_hook(cub3d->mlx, loop_render, cub3d);
	mlx_key_hook(cub3d->mlx_win, deal_key, cub3d);
	mlx_hook(cub3d->mlx_win, 2, 0, deal_key, cub3d);
	mlx_hook(cub3d->mlx_win, 17, 0, x_close, cub3d);
	mlx_loop(cub3d->mlx);	
	return (0);
}


void render(t_cub3d *cub3d, t_img_data *img, int map[24][24])
{
	raycaster(cub3d, map);
	mlx_put_image_to_window(cub3d->mlx, cub3d->mlx_win, img->img_ptr, 0, 0);
}


void raycaster(t_cub3d *cub3d, int map[24][24])
{
	int i;
	i = 0;
	while(i++ < WIDTH)
	{
		ray_handler(cub3d, i / 4);
		perform_DDA(cub3d, map);
		cub3d->lineHeight = (int)(HEIGHT / cub3d->perpWallDist);
		cub3d->drawStart = (-cub3d->lineHeight / 2 + HEIGHT / 2);
		if (cub3d->drawStart < 0)
			cub3d->drawStart = 0;
		cub3d->drawEnd = cub3d->lineHeight / 2 + HEIGHT / 2;
		if (cub3d->drawEnd >= HEIGHT)
			cub3d->drawEnd = HEIGHT -1;
		draw_line(cub3d, WIDTH - i - 1, 0x000000FF, &cub3d->img_data);
	}
}
