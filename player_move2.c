/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:07:42 by almichel          #+#    #+#             */
/*   Updated: 2024/03/27 22:28:13 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_collectible1(t_data *data, int y, int x, int sign)
{
	if (sign == 0)
	{
		data->collectible--;
		data->map[y - 1][x] = 'P';
		data->player.y = (y - 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else
	{
		data->collectible--;
		data->map[y][x - 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x - 1) * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
}

void	move_victory1(t_data *data, int y, int x, int sign)
{
	if (sign == 0)
	{
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
		data->player.y = (y - 1) * 64;
		data->player.x = x * 64;
		data->move++;
		data->flag = 1;
		ft_display_map(*data);
		ft_victory(data);
	}
	else
	{
		data->map[y][x - 1] = 'P';
		data->map[y][x] = '0';
		data->player.y = y * 64;
		data->player.x = (x - 1) * 64;
		data->move++;
		data->flag = 3;
		ft_display_map(*data);
		ft_victory(data);
	}
}

void	move_empty1(t_data *data, int y, int x, int sign)
{
	if (sign == 0)
	{
		data->map[y - 1][x] = 'P';
		data->player.y = (y - 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else
	{
		data->map[y][x - 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x - 1) * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
}

void	move_campfire1(t_data *data, int y, int x, int sign)
{
	if (sign == 0)
	{
		data->map[y - 1][x] = 'P';
		data->player.y = (y - 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
	}
	else
	{
		data->map[y][x - 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x - 1) * 64;
		data->map[y][x] = '0';
	}
}
