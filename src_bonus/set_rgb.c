/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:24 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 18:58:28 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	checks if the identifier C or F has been set or called already.
*/
int	set_rgb(char *str, t_id *id)
{
	char	*setup;
	char	**rgb;

	if (id->number > 2)
		return (-1);
	setup = ft_substr(str, 1, ft_strlen(str));
	if (check_valid_id(setup) == -1)
	{
		free (setup);
		return (-1);
	}
	rgb = ft_split(setup, ',');
	if (check_rgb(rgb, id) == -1)
	{
		free_splits(rgb);
		free(setup);
		return (-1);
	}
	free_splits(rgb);
	free(setup);
	return (0);
}

/*
	simple check if the numbers are being set correctly
*/
int	check_rgb(char **rgb, t_id *id)
{
	if (count_splits(rgb) != 3)
		return (-1);
	id->r = ft_atoi(rgb[0]);
	id->g = ft_atoi(rgb[1]);
	id->b = ft_atoi(rgb[2]);
	if (id->r > 255 || id->g > 255 || id->b > 255)
		return (-1);
	if (id->r < 0 || id->g < 0 || id->b < 0)
		return (-1);
	return (0);
}
