/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:54:46 by tfedoren          #+#    #+#             */
/*   Updated: 2023/01/05 18:54:51 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	allowed_char(char character)
{
	if (character == '1' || character == '0')
		return (0);
	if (character == 'N' || character == 'E' )
		return (0);
	if (character == 'S' || character == 'W')
		return (0);
	printf("This one @%c@", character);
	return (-1);
}
