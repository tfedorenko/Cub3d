/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:56:20 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/09 17:23:22 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	checking if the file name ends with .cub
	42 made me a monster, I do everything manually :((
*/
void	check_name(char *map_name)
{
	int	len_name;

	len_name = ft_strlen(map_name);
	if (len_name <= 4)
		exit_msg_error("Error invalid map name\n");
	if (map_name[len_name - 4] != '.' || map_name[len_name - 3] != 'c'
		|| map_name[len_name - 2] != 'u' || map_name[len_name - 1] != 'b')
		exit_msg_error("Error invalid map name\n");
}

/*
	pre-check if the file exist
*/
int	check_file(char *map_path)
{
	int	file;

	file = open(map_path, O_RDONLY);
	if (file == -1)
	{
		perror(map_path);
		return (-1);
	}
	close(file);
	return (0);
}

void	error_check(char *map, t_info *info)
{
	check_name(map);
	if (check_file(map) == -1)
		exit (1);
	if (check_id(map, info) == -1)
		exit (1);
	if (check_compass(map, info) == -1)
		exit (1);
	if (map_start(map, info) == -1)
	{
		free_struct(info);
		exit(1);
	}
	get_height(map, info);
	info->map = create_map(map, info->map_info.start, info->map_info.y);
	remove_new_lines(info);
	if (valid_map(info->map, info) == -1)
	{
		ft_putstr_fd("The map is not correct\n", 2);
		free_struct(info);
		exit(1);
	}
}
