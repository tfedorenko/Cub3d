/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:36 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 18:58:38 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_texture_north(char *str, t_info *info)
{
	char	*texture;

	texture = ft_substr(str, 2, ft_strlen(str) - 3);
	if (check_file(texture) == -1)
	{
		free(texture);
		return (-1);
	}
	info->no++;
	if (info->no > 1)
	{
		free(texture);
		ft_putstr_fd("NO texture not correct\n", 2);
		return (-1);
	}
	info->north = texture;
	return (0);
}

int	set_texture_east(char *str, t_info *info)
{
	char	*texture;

	info->ea++;
	texture = ft_substr(str, 2, ft_strlen(str) - 3);
	if (check_file(texture) == -1 || info->ea > 1)
	{
		ft_putstr_fd("EA texture not correct\n", 2);
		free(texture);
		return (-1);
	}
	info->east = texture;
	return (0);
}

int	set_texture_south(char *str, t_info *info)
{
	char	*texture;

	info->so++;
	texture = ft_substr(str, 2, ft_strlen(str) - 3);
	if (check_file(texture) == -1 || info->so > 1)
	{
		ft_putstr_fd("SO texture not correct\n", 2);
		free(texture);
		return (-1);
	}
	info->south = texture;
	return (0);
}

int	set_texture_west(char *str, t_info *info)
{
	char	*texture;

	info->we++;
	texture = ft_substr(str, 2, ft_strlen(str) - 3);
	if (check_file(texture) == -1 || info->we > 1)
	{
		ft_putstr_fd("WE texture not correct\n", 2);
		free(texture);
		return (-1);
	}
	info->west = texture;
	return (0);
}
