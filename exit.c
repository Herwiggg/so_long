/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:45 by almichel          #+#    #+#             */
/*   Updated: 2024/03/27 02:48:25 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_exit(t_data *data)
{
    ft_doublefree(data->map, ft_count_height(data->map));
    free(data->collectible_c);
    free(data->wall_c);
    mlx_destroy_window(data->mlx, data->mlx_wind);
    exit (EXIT_FAILURE);
}

int ft_victory(t_data *data)
{
    printf("Victory ! Well done :)\n");
    ft_doublefree(data->map, ft_count_height(data->map));
    free(data->collectible_c);
    free(data->wall_c);
    mlx_destroy_window(data->mlx, data->mlx_wind);
    exit (EXIT_FAILURE);
}