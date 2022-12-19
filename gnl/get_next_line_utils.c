/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:58:15 by dnguyen           #+#    #+#             */
/*   Updated: 2022/03/16 14:30:01 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoing(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	s3 = (char *)malloc(sizeof(char) * (ft_strleng(s1) + ft_strleng(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[j] != '\0')
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

size_t	ft_strleng(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchrg(char *src, int c)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (c == '\0')
		return ((char *)&src[ft_strleng(src)]);
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}
