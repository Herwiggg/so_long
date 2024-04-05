/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:17:55 by almichel          #+#    #+#             */
/*   Updated: 2024/04/05 14:07:07 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_check_retour(char *dest)
{
	int		i;
	char	*new_tab;

	i = 0;
	while (dest[i] != '\0')
		i++;
	if (dest[i - 1] != '\n')
	{
		new_tab = malloc((ft_strlen(dest) + 2) * sizeof(char));
		if (!new_tab)
			return (NULL);
		i = 0;
		while (dest[i] != '\0')
		{
			new_tab[i] = dest[i];
			i++;
		}
		new_tab[i] = '\n';
		i++;
		new_tab[i] = '\0';
		free(dest);
		return (new_tab);
	}
	return (dest);
}

char	**ft_stock(char **dest, char *argv, int fd, int size)
{
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (size < 2)
	{
		write(1, "Error\n Map is not valid", 23);
		return (NULL);
	}
	dest = malloc((size + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest[size] = NULL;
	while (i < size)
	{
		dest[i] = get_next_line(fd);
		if (dest[0] == NULL)
			return (NULL);
		dest[i] = ft_check_retour(dest[i]);
		if (!dest)
			return (NULL);
		i++;
	}
	close(fd);
	return (dest);
}

char	**ft_read_and_stock(char *argv, t_data *data)
{
	int		size;
	char	*temp;
	int		fd;
	char	**dest;

	dest = NULL;
	size = 0;
	fd = open(argv, O_RDONLY);
	data->readed = read(fd, 0, 0);
	if (fd < 0 || data->readed < 0)
	{
		write(2, "Error\n", 6);
		close(fd);
		return (NULL);
	}
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		size++;
		free(temp);
	}
	close(fd);
	return (ft_stock(dest, argv, fd, size));
}
