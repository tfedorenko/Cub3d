/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:54 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 19:02:53 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" 

size_t	double_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		printf("reading : %s\n", arr[i]);
		i++;
	}
	return (i);
}

void	get_height(char *map, t_info *info)
{
	int		fd;
	int		count;
	char	*str;

	count = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		count++;
	}
	free(str);
	close(fd);
	info->map_info.y = count;
}

/* frees the parameter str and returns value */
int	free_str_return(char *str, int value)
{
	free(str);
	return (value);
}
