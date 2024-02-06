/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:33:27 by almichel          #+#    #+#             */
/*   Updated: 2024/02/06 01:09:14 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_elements2(char **argv, int *y, int *x, int *items)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] != '\n')
		{
			if (argv[i][j] == '0' || argv[i][j] == '1')
				j++;
			else if (argv[i][j] == 'C' || argv[i][j] == 'E')
				{
					*items += 1;
					j++;
				}
			else if (argv[i][j] == 'P')
			{
				*y = i;
				*x = j;
				j++;
			}
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	pathfinding(char **tab, int y, int x, int *items)
{

	if (tab[y][x] == '1')
		return (0);
	if (tab[y][x] == 'C' || tab[y][x] == 'E')
		*items -= 1;
	tab[y][x] = '1';
	pathfinding(tab, y - 1, x, items);
	pathfinding(tab, y + 1, x, items);
	pathfinding(tab, y, x - 1, items);
	pathfinding(tab, y, x + 1, items);
	if (*items == 0)
		return (1);
	return (0);
}
