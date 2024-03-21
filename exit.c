/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:45 by almichel          #+#    #+#             */
/*   Updated: 2024/02/02 01:33:51 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_exit(t_data *data)
{
    ft_doublefree(data->map, ft_count_height(data->map));
    free(data->collectible_c);
    free(data->wall_c);
    mlx_destroy_window(data->mlx, data->mlx_wind);
    return (EXIT_FAILURE);
}
