/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnguyen <dnguyen@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:17:24 by dnguyen           #+#    #+#             */
/*   Updated: 2022/03/16 14:30:39 by dnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//this function allocates a buffer to store the length of the BUFFER_SIZE
//check will receive the number of written bytes in the read file
//returns the string from the file
static char	*readfile(int fd, char *str)
{
	int		size;
	char	*buffer;

	size = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (!ft_strchrg(str, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		str = ft_strjoing(str, buffer);
	}
	free(buffer);
	return (str);
}

//checking for a new line
static char	*readline(char *str)
{
	int		index1;
	char	*buffer;

	if (*str == '\0')
		return (NULL);
	index1 = 0;
	while (str[index1] && str[index1] != '\n')
		index1++;
	buffer = (char *) malloc(sizeof(char) * index1 + 2);
	if (!buffer)
		return (NULL);
	index1 = 0;
	while (str[index1] && str[index1] != '\n')
	{
		buffer[index1] = str[index1];
		index1++;
	}
	if (str[index1] == '\n')
	{
		buffer[index1] = '\n';
		index1++;
	}
	buffer[index1] = '\0';
	return (buffer);
}

//updates the static variable
static char	*rest(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	buff = (char *) malloc(sizeof(char) * (ft_strleng(str) - i + 1));
	if (!buff)
		return (NULL);
	i++;
	while (str[i])
	{
		buff[j++] = str[i];
		i++;
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = readfile(fd, str);
	if (!str)
		return (NULL);
	line = readline(str);
	str = rest(str);
	return (line);
}
