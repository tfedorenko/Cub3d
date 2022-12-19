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
int	skip_whitespace(char *str , int position)
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

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ',' && str[i] != '\n')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}