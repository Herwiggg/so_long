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

void	ft_malloc_struct(t_data *data)
{
	
	data->collectible_c = malloc(data->collectible * sizeof(t_coin));
	data->wall_c = malloc(data->wall * sizeof(t_coord));

}

void	ft_stock_coords(t_data *data)
{
	int	i;
	int	j;
	int k;
	int	l;

	ft_malloc_struct(data);
	l = 0;
	k = 0;
	i = 0;

	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '1')
			{
				data->wall_c[k].y = i * 64;
				data->wall_c[k].x = j * 64;
				k++;
			}
			else if (data->map[i][j] == 'C')
			{
				data->collectible_c[l].y = i * 64;
				data->collectible_c[l].x = j * 64;
				l++;
			}
			else if (data->map[i][j] == 'E')
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


