/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/05 16:28:37 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	ft_doublefree(data->map, ft_count_height(data->map));
	free(data->collectible_c);
	free(data->wall_c);
	//mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_wind);
	mlx_destroy_display(data->mlx);
	free(data->img);
	free(data->mlx);
	exit(EXIT_FAILURE);
}

int	ft_victory(t_data *data)
{
	ft_doublefree(data->map, ft_count_height(data->map));
	free(data->collectible_c);
	free(data->wall_c);
//	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_wind);
	mlx_destroy_display(data->mlx);
	write(1, "Victory ! Well done ;)\n", 24);
	free(data->img);
	free(data->mlx);
	exit(EXIT_FAILURE);
}
