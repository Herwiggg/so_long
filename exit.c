/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/07 02:18:33 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	ft_doublefree(data->map, ft_count_height(data->map));
	free(data->collectible_c);
	free(data->wall_c);
	mlx_destroy_image(data->mlx, data->img.img_wall);
	mlx_destroy_image(data->mlx, data->img.img_floor);
	mlx_destroy_image(data->mlx, data->img.img_collect);
	mlx_destroy_image(data->mlx, data->img.img_player);
	mlx_destroy_image(data->mlx, data->img.img_exit);
	mlx_destroy_image(data->mlx, data->img.img_player_top);
	mlx_destroy_image(data->mlx, data->img.img_player_right);
	mlx_destroy_image(data->mlx, data->img.img_player_left);
	mlx_destroy_window(data->mlx, data->mlx_wind);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_FAILURE);
}

int	ft_victory(t_data *data)
{
	ft_doublefree(data->map, ft_count_height(data->map));
	free(data->collectible_c);
	free(data->wall_c);
	mlx_destroy_image(data->mlx, data->img.img_wall);
	mlx_destroy_image(data->mlx, data->img.img_floor);
	mlx_destroy_image(data->mlx, data->img.img_collect);
	mlx_destroy_image(data->mlx, data->img.img_player);
	mlx_destroy_image(data->mlx, data->img.img_exit);
	mlx_destroy_image(data->mlx, data->img.img_player_top);
	mlx_destroy_image(data->mlx, data->img.img_player_right);
	mlx_destroy_image(data->mlx, data->img.img_player_left);
	mlx_destroy_window(data->mlx, data->mlx_wind);
	mlx_destroy_display(data->mlx);
	write(1, "Victory ! Well done ;)\n", 24);
	free(data->mlx);
	exit(EXIT_FAILURE);
}
