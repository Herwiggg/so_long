/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:30:52 by almichel          #+#    #+#             */
/*   Updated: 2024/04/02 17:43:28 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_a_valid_map2(t_data *data)
{
	int	items;

	if (ft_check_elements(data->map, data) == -1)
		return (ft_error_msg("Error\nBad ressources\n"));
	if (ft_check_elements2(data->map, data) == -1)
		return (ft_error_msg("Error\nBad ressources\n"));
	collect_nbr_item(data->map, data);
	data->tab = copy_double_tab(data->map);
	items = data->items;
	if (pathfinding(data->tab, data->y, data->x, &items) == 0)
		return (ft_error_msg2("Error\nNo path found\n", data->tab));
	ft_doublefree(data->tab, ft_count_height(data->tab));
	return (1);
}

int	ft_is_a_valid_map(t_data *data)
{
	if (data->map[0] == NULL)
		return (ft_error_msg("Error\nMap is empty\n"));
	if (ft_check_dimension(data->map) == -1)
		return (ft_error_msg("Error\nMap is not valid\n"));
	if (ft_check_rectangular(data->map) == -1)
		return (ft_error_msg("Error\nMap is not rectangular\n"));
	if (ft_check_wall(data->map) == -1)
		return (ft_error_msg("Error\nMap is not surrounded by walls\n"));
	if (ft_is_a_valid_map2(data) == -1)
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = NULL;
	ft_bzero(&data, sizeof(t_data));
	if (argc < 2 || ft_check_ber(argv[1]) == -1)
		return (-1);
	data.map = ft_read_and_stock(argv[1], &data);
	if (data.map == NULL)
		return (-1);
	if (ft_is_a_valid_map(&data) == -1)
		return (-1);
	if (ft_malloc_struct(&data) == -1)
		return (-1);
	ft_stock_coords(&data);
	ft_stock_coords2(&data);
	ft_mlx_init(&data);
	ft_display_map(data);
	mlx_hook(data.mlx_wind, 2, (1L << 0), ft_handle_input, &data);
	mlx_hook(data.mlx_wind, 17, (1L << 0), ft_exit, &data);
	mlx_loop(data.mlx);
}
