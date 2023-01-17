/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:47 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 18:58:50 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

int	count_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
		i++;
	return (i);
}

int	char_count_in_str(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

/*
	 allocates memory and returns the string without the given character
	the length is length of str minus characters found in string + 1
*/
char	*remove_char_str(char *str, char c)
{
	int		len;
	int		i;
	int		j;
	char	*removed;

	if (!str || !c)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(str) - char_count_in_str(str, c);
	if (len == 0)
		return (NULL);
	removed = malloc((sizeof(char) * len) + 1);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		removed[j] = str[i];
		i++;
		j++;
	}
	removed[j] = '\0';
	return (removed);
}

void	free_struct(t_info *info)
{
	if (info->north)
		free(info->north);
	if (info->east)
		free(info->east);
	if (info->south)
		free(info->south);
	if (info->west)
		free(info->west);
	if (info->map)
		free_splits(info->map);
}
