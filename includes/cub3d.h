#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include <stdbool.h>

# define WIDTH 640
# define HEIGHT 480
# define mapWidth 24
# define mapHeight 24

# define moveSpeed 0.5
# define rotSpeed 0.1

typedef struct s_id t_id;

typedef struct	s_id
{
	int	number;
	int	r;
	int	g;
	int	b;
}	t_id;

typedef struct	s_map
{
	size_t	length;
	int		height;
}	t_map;

typedef struct	s_info
{
	char		**map;
	int			no;
	char		*north;
	int			so;
	char		*south;
	int			we;
	char		*west;
	int			ea;
	char		*east;
	t_id		floor;
	t_id		ceiling;
}	t_info;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*mlx_img_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;

}	t_mlx;

typedef struct s_player_position
{
	float	px;
	float	py;
}	t_player_position;

typedef struct s_cub3d
{
	void		*mlx;
	void		*mlx_win;
	t_img_data img_data;
	t_mlx *mlx_data;
	t_player_position *player_data;
	t_info *info_data;

	int map[24][24];
	int def_color;

	double posX;
	double posY;

	double dirX;
	double dirY;

	double planeX;
	double planeY;

	double time;
	double oldTime;

	double cameraX;
	double rayDirX;
	double rayDirY;

	int mapX;
	int mapY;

	double sideDistX;
	double sideDistY;

	double deltaDistX;
	double deltaDistY;

	double perpWallDist;

	int stepX;
	int stepY;

	int hit;
	int side;

	int lineHeight;

	int drawStart;
	int drawEnd;
} t_cub3d;

void	set_info(t_cub3d *cub3d);	
void	error_check(char *map_path, t_info *info);
void	exit_msg_error(char *str);
int		check_file(char *map_path);
int		check_id(char *map, t_info *info);
int		check_compass(char *map, t_info *info);
/* identifier */
int		find_identifier(char *str, t_info *info);
int		check_id(char *map, t_info *info);
int		set_identifier_rgb(char *str, t_info *info);
int		set_identifier_ceiling(char *str, t_info *info);
int		set_identifier_floor(char *str, t_info *info);
int		check_valid_id(char *str);
int		set_rgb(char *str, t_id *rgb);
int		check_rgb(char **rgb, t_id *id);
int		set_compass_texture(char *str, t_info *info);
int		skip_whitespaces(char *str, int position);
/* texture */
int		set_texture_north(char *removed, t_info *info);
int		set_texture_east(char *removed, t_info *info);
int		set_texture_south(char *removed, t_info *info);
int		set_texture_west(char *removed, t_info *info);
/* utils */
char	*remove_char_str(char *str, char c);
void	free_splits(char **splits);
int		count_splits(char **splits);
void	print_struct(t_info *info);
void	free_struct(t_info *info);
/* window */
void	init(t_cub3d *data);
int		x_close(t_cub3d *data);
int		deal_key(int key, t_cub3d *data, int map[24][24]);
void	my_mlx_pixel_put(t_img_data *cub3d, int x, int y, int color);
void	draw_line(t_cub3d *cub3d, int x, int color, t_img_data *img);
void	ray_handler(t_cub3d *cub3d, int i);
void	perform_DDA(t_cub3d *cub3d, int map[24][24]);
void	raycaster(t_cub3d *cub3d, int map[24][24]);
void	render(t_cub3d *cub3d, t_img_data *img, int map[24][24]);
int		map_borders(t_cub3d *cub3d);
void	draw_minimap(int map[24][24], t_img_data *img);
void render_minimap(t_cub3d *cub3d, t_img_data *img, int map[24][24]);

#endif
