/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:06 by almichel          #+#    #+#             */
/*   Updated: 2024/03/27 16:51:52 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_malloc_struct(t_data *data)
{
	data->collectible_c = malloc(data->collectible * sizeof(t_coin));
	if (!data->collectible_c)
		return (ft_error_msg2("Malloc error\n", data->map));
	data->wall_c = malloc(data->wall * sizeof(t_coord));
	if (!data->wall_c)
		return (ft_error_msg2("Malloc error\n", data->map));
	return (1);
}

void	ft_stock_coords(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '1')
			{
				data->wall_c[data->k].y = i * 64;
				data->wall_c[data->k].x = j * 64;
				data->k++;
			}
			else if (data->map[i][j] == 'C')
			{
				data->collectible_c[data->l].y = i * 64;
				data->collectible_c[data->l].x = j * 64;
				data->l++;
			}
			j++;
		}
		i++;
	}
}

void	ft_stock_coords2(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'E')
			{
				data->exit.y = i * 64;
				data->exit.x = j * 64;
			}
			else if (data->map[i][j] == 'P')
			{
				data->player.y = i * 64;
				data->player.x = j * 64;
			}
			j++;
		}
		i++;
	}
}
