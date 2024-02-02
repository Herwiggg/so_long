/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:30:52 by almichel          #+#    #+#             */
/*   Updated: 2024/02/02 01:34:34 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_a_valid_map(char **map)
{
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
	if (ft_check_elements2(map) == -1)
		return (ft_error_msg("Error\nBad ressources\n"));
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
