/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:56:12 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 19:00:31 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		printf("%s@\n", splits[i]);
		i++;
	}
}

/*
	added @ symbol to check for null characters
*/
void	print_struct(t_info *info)
{
	printf("RBG for ceiling %d , %d, %d\n", info->ceiling.r, \
		info->ceiling.g, info->ceiling.b);
	printf("RBG for floor %d , %d, %d\n", info->floor.r, \
		info->floor.g, info->floor.b);
	printf("Texture for north = %s@\n", info->north);
	printf("Texture for east = %s@\n", info->east);
	printf("Texture for south = %s@\n", info->south);
	printf("Texture for west = %s@\n", info->west);
	printf("\nThe map:\n");
	if (info->map)
		print_splits(info->map);
}
