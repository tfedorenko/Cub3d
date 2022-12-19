/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:10:13 by dnguyen           #+#    #+#             */
/*   Updated: 2022/10/19 18:31:30 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled. */
static int	get_length(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*intarray(char *string, unsigned int n, int len)
{
	while (n > 0)
	{
		string[len--] = 48 + (n % 10);
		n /= 10;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char			*string;
	int				len;
	unsigned int	number;

	len = get_length(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	string[len--] = '\0';
	if (n == 0)
		string[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		string[0] = '-';
	}
	else
	{
		number = n;
	}
	string = intarray(string, number, len);
	return (string);
}
