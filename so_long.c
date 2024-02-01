/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:30:52 by almichel          #+#    #+#             */
/*   Updated: 2024/02/01 02:06:26 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_a_valid_map(char **map)
{
	if (map[0] == NULL)
		return (-1);
	if (ft_check_dimension(map) == -1)
		return (-1);
	if (ft_check_rectangular(map) == -1)
		return (-1);
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
	{
		write(2, "Error\n", 6);
		write(2, "Map is not valid\n", 17);
		return (-1);
	}
}
