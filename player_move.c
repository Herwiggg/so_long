/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:28:32 by almichel          #+#    #+#             */
/*   Updated: 2024/03/27 22:21:39 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_top(t_data *data)
{
	int	x;
	int	y;
	int	sign;

	sign = 0;
	y = data->player.y / 64;
	x = data->player.x / 64;
	if (data->map[y - 1][x] == 'C')
		move_collectible1(data, y, x, sign);
	else if (data->map[y - 1][x] == 'E' && data->collectible == 0)
		move_victory1(data, y, x, sign);
	else if (data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'P')
		move_empty1(data, y, x, sign);
	else if (data->map[y - 1][x] == 'E' && data->collectible != 0)
		move_campfire1(data, y, x, sign);
	else
		return ;
	data->move++;
	data->flag = 1;
	ft_display_map(*data);
}

void	move_player_left(t_data *data)
{
	int	x;
	int	y;
	int	sign;

	sign = 1;
	y = data->player.y / 64;
	x = data->player.x / 64;
	if (data->map[y][x - 1] == 'C')
		move_collectible1(data, y, x, sign);
	else if (data->map[y][x - 1] == 'E' && data->collectible == 0)
		move_victory1(data, y, x, sign);
	else if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'P')
		move_empty1(data, y, x, sign);
	else if (data->map[y][x - 1] == 'E' && data->collectible != 0)
		move_campfire1(data, y, x, sign);
	else
		return ;
	data->move++;
	data->flag = 3;
	ft_display_map(*data);
}

void	move_player_right(t_data *data)
{
	int	x;
	int	y;
	int	sign;

	sign = 3;
	y = data->player.y / 64;
	x = data->player.x / 64;
	if (data->map[y][x + 1] == 'C')
		move_collectible2(data, y, x, sign);
	else if (data->map[y][x + 1] == 'E' && data->collectible == 0)
		move_victory2(data, y, x, sign);
	else if (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'P')
		move_empty2(data, y, x, sign);
	else if (data->map[y][x + 1] == 'E' && data->collectible != 0)
		move_campfire2(data, y, x, sign);
	else
		return ;
	data->move++;
	data->flag = 2;
	ft_display_map(*data);
}

void	move_player_down(t_data *data)
{
	int	x;
	int	y;
	int	sign;

	sign = 4;
	y = data->player.y / 64;
	x = data->player.x / 64;
	if (data->map[y + 1][x] == 'C')
		move_collectible2(data, y, x, sign);
	else if (data->map[y + 1][x] == 'E' && data->collectible == 0)
		move_victory2(data, y, x, sign);
	else if (data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'P')
		move_empty2(data, y, x, sign);
	else if (data->map[y + 1][x] == 'E' && data->collectible != 0)
		move_campfire2(data, y, x, sign);
	else
		return ;
	data->move++;
	data->flag = 0;
	ft_display_map(*data);
}
