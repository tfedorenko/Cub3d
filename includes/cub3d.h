/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:03:37 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/09 17:06:42 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define WIDTH	640
# define HEIGHT 480

# define MOVESPEED 0.3
# define ROTATIONSPEED 0.2
# define TEXTURE_WIDTH 64
# define TEXTURE_HIGHT 64 

# define RED "./texture/red.xpm"
# define GREEN "./texture/blue.xpm"
# define GREY "./texture/grey.xpm"

typedef struct s_id
{
	int	number;
	int	r;
	int	g;
	int	b;
}	t_id;

typedef struct s_map
{
	size_t	x;
	int		y;
	int		start;
}	t_map;

typedef struct s_player
{
	size_t	x;
	size_t	y;
	int		count;
}	t_player;

typedef struct s_info	t_info;

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

typedef struct s_info
{
	char				**map;
	int					no;
	char				*north;
	int					so;
	char				*south;
	int					we;
	char				*west;
	int					ea;
	char				*east;
	char				view;
	void				*ground;
	void				*p;
	void				*wall;
	t_id				floor;
	t_id				ceiling;
	t_map				map_info;
	t_player			player;
	void				*mlx;
	void				*mlx_win;
	t_img_data			img_data;
	t_mlx				*mlx_data;
	t_player_position	*player_data;
	t_info				*info_data;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				perp_dir_x;
	double				perp_dir_y;
	t_img_data			img_texture;
	void				*snow_1;
	void				*snow_2;
	void				*snow_3;
}	t_info;

void	set_info_1(t_info *info);
void	set_info_2(t_info *info);
void	error_check(char *map_path, t_info *info);
void	exit_msg_error(char *str);
int		check_file(char *map_path);
int		check_id(char *map, t_info *info);
int		check_compass(char *map, t_info *info);
int		map_start(char *map, t_info *info);
int		check_map(char *map, t_info *info);
int		valid_map(char **map, t_info *info);
int		valid_floor(char **map);
int		valid_player(t_info *info);
size_t	double_arr_len(char **arr);
char	**create_map(char *map, int start, int y);
int		free_str_return(char *str, int value);
void	remove_new_lines(t_info *info);
int		find_identifier(char *str, t_info *info);
int		check_id(char *map, t_info *info);
int		set_identifier_ceiling(char *str, t_info *info);
int		set_identifier_floor(char *str, t_info *info);
int		check_valid_id(char *str);
int		set_rgb(char *str, t_id *rgb);
int		check_rgb(char **rgb, t_id *id);
int		set_compass_texture(char *str, t_info *info);
void	get_height(char	*map, t_info *info);
int		set_texture_north(char *removed, t_info *info);
int		set_texture_east(char *removed, t_info *info);
int		set_texture_south(char *removed, t_info *info);
int		set_texture_west(char *removed, t_info *info);
int		allowed_char(char character);
char	*remove_char_str(char *str, char c);
void	free_splits(char **splits);
int		count_splits(char **splits);
void	print_struct(t_info *info);
void	print_splits(char **splits);
void	free_struct(t_info *info);
void	init(t_info *info);
int		x_close(t_info *info);
int		deal_key(int key, t_info *info);
void	my_mlx_pixel_put(t_img_data *cub3d, int x, int y, int color);
void	draw_line(t_info *info, int x, t_img_data *img);
void	ray_handler(t_info *info, int i);
void	perform_dda(t_info *info);
void	raycaster(t_info *info);
void	render(t_img_data *img, t_info *info);
int		key_right(t_info *info);
int		key_left(t_info *info);
int		key_up(t_info *info);
int		key_down(t_info *info);
int		keyinput(int key, t_info *info);
void	init_start_position(t_info *info);
void	texturing(t_info *info);
int		get_pixel_color_2(t_info *info, int y);
void	key_a(t_info *info);
void	key_d(t_info *info);
void	rotate_right(t_info *info);
void	rotate_left(t_info *info);
int		cal_render(void *ptr);
void	init_start_position(t_info *info);
int		no_collision_up_and_down(t_info *info, int key);
int		no_collision_right_and_left(t_info *info, int key);
void	ray_handler_helper(t_info *info);
void	perform_dda_helper(t_info *info);
void	reset_info(t_info *info);
int		walls_connected(char **map, size_t y, size_t x);
int		valid_map_characters(char c);
int		cal_render(void *ptr);

#endif
