/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:30:52 by almichel          #+#    #+#             */
/*   Updated: 2024/01/31 02:33:43 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/*
int	ft_check_rectangular(char *argv)
{
	int	i;
	int	j;
	int	stack_long;
	int	stack_short;

	stack_short = 0;
	stack_long = 0;
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i] != '\n')
			j++;
		stack_long = j;
		stack_short = i + stack_short;
		i++;
	}
	return (1);
}*/

int	ft_check_ber(char *argv)
{
	int	i;

	i = ft_strlen(argv);

	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' || argv[i - 4] != '.')
	{
		write(2, "file is not a .ber\n",19);
			return (-1);
	}
	return (1);
}

char	**ft_stock(char **dest, char *argv, int fd, int size)
{
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	dest = malloc((size + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = get_next_line(fd);
		if (dest == NULL)
			break;
		i++;
	}
	close(fd);
	return (dest);
}

char	**ft_read_and_stock(char *argv)
{
	int size;
	char *temp;
	int	fd;
	char **dest;

	dest = NULL;
	size = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break;
		size++;
		free(temp);
	}
	close(fd);
	return (dest = ft_stock(dest, argv, fd, size));
}

int	main(int argc, char **argv)
{
	int	fd;
	char	**map;
	
	if (argc < 2 || ft_check_ber(argv[1]) == -1)
		return (-1);
	map = ft_read_and_stock(argv[1]);
	if (!(map))
		return (-1);
}
