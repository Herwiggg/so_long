/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:06 by almichel          #+#    #+#             */
/*   Updated: 2024/03/09 00:26:48 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_malloc_struct(t_data data)
{
	
	data.collectible_c = malloc(data.collectible * sizeof(t_coin));
	data.wall_c = malloc(data.wall * sizeof(t_coord));

}
