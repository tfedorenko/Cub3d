/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_identifier_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:57:58 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 19:02:25 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_msg_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

/*
	skipping only spaces and
	returns the further index that has been incremented
*/
int	skip_whitespace(char *str, int position)
{
	while (str[position] == ' ')
	{
		position++;
		if (!str[position])
			break ;
	}
	return (position);
}

/*
	checking if there are unexpected characters
	in identifier substring
*/
int	check_valid_id(char *str)
{
	int	i;
	int	comma_count;

	comma_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			comma_count++;
			i++;
		}
		if ((ft_isdigit(str[i]) == 0 && str[i] != '\n') || comma_count > 2)
			return (-1);
		i++;
	}
	return (0);
}
