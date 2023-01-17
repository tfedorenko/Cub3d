/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_identifier_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:57:49 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 18:57:52 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_identifier_floor(char *str, t_info *info)
{
	if (!str)
		return (-1);
	if (str[0] == 'F')
	{
		info->floor.number++;
		return (set_rgb(str, &info->floor));
	}
	return (-1);
}

int	set_identifier_ceiling(char *str, t_info *info)
{
	if (!str)
		return (-1);
	if (str[0] == 'C')
	{
		info->ceiling.number++;
		return (set_rgb(str, &info->ceiling));
	}
	return (-1);
}
