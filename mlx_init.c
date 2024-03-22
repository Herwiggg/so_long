/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:06 by almichel          #+#    #+#             */
/*   Updated: 2024/03/10 02:11:24 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_doublefree(data->map, ft_count_height(data->map));
    	free(data->collectible_c);
    	free(data->wall_c);
		exit (EXIT_FAILURE);
	}
	data->mlx_wind = mlx_new_window(data->mlx, ft_count_len(data->map) * 64, ft_count_height(data->map) * 64, "MLX42");
	if (data->mlx_wind == NULL)
	{
		ft_doublefree(data->map, ft_count_height(data->map));
    	free(data->collectible_c);
    	free(data->wall_c);
		exit (EXIT_FAILURE);
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
