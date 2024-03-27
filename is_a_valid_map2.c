/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:33:27 by almichel          #+#    #+#             */
/*   Updated: 2024/03/27 19:55:41 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_nbr_item(char **argv, int items)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] != '\n')
		{
			if (argv[i][j] == 'C' || argv[i][j] == 'E')
				items++;
			j++;
		}
		i++;
	}
}

int	ft_check_elements2(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] != '\n')
		{
			if (argv[i][j] == '1')
				data->wall += 1;
			else if (argv[i][j] == 'C')
				data->collectible += 1;
			else if (argv[i][j] == 'P')
			{
				data->y = i;
				data->x = j;
			}
			else if (argv[i][j] != '0' && argv[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_elements(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'E')
				data->e++;
			if (argv[i][j] == 'C')
				data->c++;
			if (argv[i][j] == 'P')
				data->p++;
			j++;
		}
		i++;
	}
	if (data->e == 1 && data->p == 1 && data->c > 0)
		return (1);
	return (-1);
}

int	pathfinding(char **map, int y, int x, int items)
{
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C' || map[y][x] == 'E')
		items -= 1;
	map[y][x] = '1';
	pathfinding(map, y - 1, x, items);
	pathfinding(map, y + 1, x, items);
	pathfinding(map, y, x - 1, items);
	pathfinding(map, y, x + 1, items);
	if (items == 0)
		return (1);
	return (0);
}
