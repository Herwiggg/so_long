/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:18:38 by almichel          #+#    #+#             */
/*   Updated: 2024/03/27 22:21:14 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_collectible2(t_data *data, int y, int x, int sign)
{
	if (sign == 3)
	{
		data->collectible--;
		data->map[y][x + 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x + 1) * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else
	{
		data->collectible--;
		data->map[y + 1][x] = 'P';
		data->player.y = (y + 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
}

void	move_victory2(t_data *data, int y, int x, int sign)
{
	if (sign == 3)
	{
		data->map[y][x + 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x + 1) * 64;
		data->map[y][x] = '0';
		data->move++;
		data->flag = 2;
		ft_display_map(*data);
		ft_victory(data);
	}
	else
	{
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		data->player.y = (y + 1) * 64;
		data->player.x = x * 64;
		data->move++;
		data->flag = 0;
		ft_display_map(*data);
		ft_victory(data);
	}
}

void	move_empty2(t_data *data, int y, int x, int sign)
{
	if (sign == 3)
	{
		data->player.y = y * 64;
		data->player.x = (x + 1) * 64;
		data->map[y][x + 1] = 'P';
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else
	{
		data->map[y + 1][x] = 'P';
		data->player.y = (y + 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
}

void	move_campfire2(t_data *data, int y, int x, int sign)
{
	if (sign == 3)
	{
		data->map[y][x + 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x + 1) * 64;
		data->map[y][x] = '0';
	}
	else
	{
		data->map[y + 1][x] = 'P';
		data->player.y = (y + 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
	}
}
