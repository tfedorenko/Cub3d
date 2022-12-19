#include "../includes/cub3d.h"

int	x_close(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->mlx_win);
	// free(cub3d);
	exit(0);
}

int	deal_key(int key, t_cub3d *cub3d, int map[24][24])
{
	double oldDirX;
	double oldPlaneX;

	oldPlaneX = cub3d->planeX;
	oldDirX = cub3d->dirX;

	if (key == 53) // esc
	{
		mlx_destroy_window(cub3d->mlx, cub3d->mlx_win);
		exit(1);
	}
	if(key == 126) // key up
	{
		if(!(map[(int)(cub3d->posX + cub3d->dirX * moveSpeed)][(int)(cub3d->posY + cub3d->dirY * moveSpeed)]) && !map_borders(cub3d))
		{
			cub3d->posY += moveSpeed * cub3d->dirY;
			printf("Am I here? cub3d->posY = %i\n", (int)cub3d->posY);
			cub3d->posX += moveSpeed * cub3d->dirX;
			printf("Am I here? cub3d->posX = %i\n", (int)cub3d->posX);
		}
		// if
		// {
			
		// }
	}

	if(key == 125) // key down
	{	
		if(!(map[(int)(cub3d->posX - cub3d->dirX *moveSpeed)][(int)(cub3d->posY - cub3d->dirY * moveSpeed)]) && !map_borders(cub3d))
		{
			cub3d->posX -= moveSpeed * cub3d->dirX;
			cub3d->posY -= moveSpeed * cub3d->dirY;

		}
		// if(!(map[(int)(cub3d->posX)][(int)(cub3d->posY - cub3d->dirY * moveSpeed)]) && !map_borders(cub3d))
	}

	if(key == 123) // key right
	{	
		cub3d->dirX = cub3d->dirX * cos(-rotSpeed) - cub3d->dirY * sin(-rotSpeed);
		cub3d->dirY = oldDirX * sin(-rotSpeed) + cub3d->dirY * cos(-rotSpeed);

		cub3d->planeX = cub3d->planeX * cos(-rotSpeed) - cub3d->planeY * sin(-rotSpeed);
		cub3d->planeY = oldPlaneX * sin(-rotSpeed) + cub3d->planeY * cos(-rotSpeed);
	}

	if(key == 124) // key right
	{	
		cub3d->dirX = cub3d->dirX * cos(rotSpeed) - cub3d->dirY * sin(rotSpeed);
		cub3d->dirY = oldDirX * sin(rotSpeed) + cub3d->dirY * cos(rotSpeed);
		cub3d->planeX = cub3d->planeX * cos(rotSpeed) - cub3d->planeY * sin(rotSpeed);
		cub3d->planeY = oldPlaneX * sin(rotSpeed) + cub3d->planeY * cos(rotSpeed);
	}

	return (0);

}

int map_borders(t_cub3d *cub3d)
{
	if ((cub3d->posX + moveSpeed * cub3d->dirX > 0) && (cub3d->posY + moveSpeed * cub3d->dirY  > 0) && (cub3d->posX + moveSpeed * cub3d->dirX < mapWidth) && (cub3d->posY + moveSpeed * cub3d->dirY < mapHeight))
		return (0);
	return (1);
} 
