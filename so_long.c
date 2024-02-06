/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:30:52 by almichel          #+#    #+#             */
/*   Updated: 2024/02/06 01:02:39 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_a_valid_map(char **map)
{
	int	items;
	int	x;
	int	y;

	x = 0;
	y = 0;
	items = 0;
	if (map[0] == NULL)
		return (ft_error_msg("Error\nMap is empty\n"));
	if (ft_check_dimension(map) == -1)
		return (ft_error_msg("Error\nMap is not valid\n"));
	if (ft_check_rectangular(map) == -1)
		return (ft_error_msg("Error\nMap is not rectangular\n"));
	if (ft_check_wall(map) == -1)
		return (ft_error_msg("Error\nMap is not surrounded by walls\n"));
	if (ft_check_elements(map) == -1)
		return (ft_error_msg("Error\nBad ressources\n"));
	if (ft_check_elements2(map, &y, &x, &items) == -1)
		return (ft_error_msg("Error\nBad ressources\n"));
	if (pathfinding(map, y, x, &items) == 0)
		return (ft_error_msg("Error\nNo path found\n"));
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc < 2 || ft_check_ber(argv[1]) == -1)
		return (-1);
	map = ft_read_and_stock(argv[1]);
	if (map == NULL)
		return (-1);
	if (ft_is_a_valid_map(map) == -1)
		return (-1);
}
