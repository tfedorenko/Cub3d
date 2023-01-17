/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:44:48 by dnguyen           #+#    #+#             */
/*   Updated: 2022/12/28 14:39:02 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a pointer to a null-terminated byte string, 
which is a duplicate of the string pointed to by str1. 
The returned pointer must be passed to free to avoid a memory leak*/
char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;

	if (!src)
		return (NULL);
	str = (char *)malloc(sizeof(char*) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/* int main(void)
{
    const char *s1 = "String";
    char *s2 = ft_strdup(s1);
    printf("Value of = %i" , strcmp(s1, s2));
    free(s2);
}*/