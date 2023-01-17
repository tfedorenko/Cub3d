/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_nl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:01:31 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/09 17:20:45 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**realloc_map(char **map, size_t y, size_t nl)
{
	char	**realloc;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (y < 3)
		return (NULL);
	realloc = malloc(sizeof(char *) * (y - nl + 1));
	while (map[i][0] == '\n')
			i++;
	while (map[i])
	{
		if (map[i][0] == '\n')
			return (NULL);
		realloc[j] = remove_char_str(map[i], '\n');
		i++;
		j++;
	}
	realloc[j] = NULL;
	return (realloc);
}

void	remove_new_lines(t_info *info)
{
	size_t	y;
	size_t	nl;

	y = 0;
	nl = 0;
	while (info->map[y])
	{	
		if (info->map[y][0] == '\n')
			nl++;
		y++;
	}
	info->map = realloc_map(info->map, y, nl);
}
