/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/02 16:57:49 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' || argv[i
			- 4] != '.' || i <= 4)
	{
		write(2, "Error\n", 6);
		write(2, "File is not a .ber\n", 19);
		return (-1);
	}
	return (1);
}

int	ft_check_dimension(char **argv)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	temp = ft_strlen(argv[i]);
	while (argv[i])
	{
		len = ft_strlen(argv[i]);
		if (len != temp)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_rectangular(char **argv)
{
	int	len_long;
	int	len_large;
	int	i;
	int	j;

	len_large = 0;
	i = 0;
	len_long = ft_strlen(argv[0]) - 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			j++;
		len_large++;
		i++;
	}
	if (len_large != len_long)
		return (1);
	return (-1);
}

int	ft_check_wall(char **argv)
{
	int	len_double;
	int	i;
	int	len_line;

	len_line = ft_strlen(argv[0]);
	i = 0;
	len_double = ft_count_lines(argv);
	if (ft_check_wall2(argv) == -1)
		return (-1);
	while (argv[len_double - 1][i] != '\n' && argv[len_double - 1][i])
	{
		if (argv[len_double - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] != '1' || argv[i][len_line - 2] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_wall2(char **argv)
{
	int	i;

	i = 0;
	while (argv[0][i] != '\n' && argv[0][i])
	{
		if (argv[0][i] != '1')
			return (-1);
		i++;
	}
	return (1);
}
