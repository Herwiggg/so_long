/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:28:32 by almichel          #+#    #+#             */
/*   Updated: 2024/03/26 20:13:39 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player_top(t_data *data)
{
	int x;
	int y;

	y = data->player.y / 64;
	x = data->player.x / 64;
  
	if (data->map[y - 1][x] == 'C')
		{
			data->collectible--;
			data->map[y - 1][x] = 'P';
			data->player.y = (y - 1) * 64;
			data->player.x = x * 64;
			data->map[y][x] = '0';
			data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
		}
	else if (data->map[y - 1][x] == 'E' && data->collectible == 0)
		{
			data->map[y - 1][x] = 'P';
			data->map[y][x] = '0';
			data->player.y = (y - 1) * 64;
			data->player.x = x * 64;
			ft_display_map(*data);
			ft_exit(data);
		}
	else if (data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'P')
	{
		data->map[y - 1][x] = 'P';
		data->player.y = (y - 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else if(data->map[y - 1][x] == 'E' && data->collectible != 0)
	{
		data->map[y - 1][x] = 'P';
		data->player.y = (y - 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
	}
	else
		return;
	ft_display_map(*data);
}

void move_player_left(t_data *data)
{
	int x;
	int y;

	y = data->player.y / 64;
	x = data->player.x / 64;
  
	if (data->map[y][x - 1] == 'C')
		{
			data->collectible--;
			data->map[y][x - 1] = 'P';
			data->player.y = y * 64;
			data->player.x = (x - 1) * 64;
			data->map[y][x] = '0';
			data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
		}
	else if (data->map[y][x - 1] == 'E' && data->collectible == 0)
		{
			data->map[y][x - 1] = 'P';
			data->map[y][x] = '0';
			data->player.y = y * 64;
			data->player.x = (x - 1) * 64;
			ft_display_map(*data);
			ft_exit(data);
		}
	else if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'P')
	{
		data->map[y][x - 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x - 1) * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else if(data->map[y][x - 1] == 'E' && data->collectible != 0)
	{
		data->map[y][x - 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x - 1) * 64;
		data->map[y][x] = '0';
	}
	else
		return;
	ft_display_map(*data);
}

void move_player_right(t_data *data)
{
	int x;
	int y;

	y = data->player.y / 64;
	x = data->player.x / 64;
  
	if (data->map[y][x + 1] == 'C')
		{
			data->collectible--;
			data->map[y][x + 1] = 'P';
			data->player.y = y * 64;
			data->player.x = (x + 1) * 64;
			data->map[y][x] = '0';
			data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
		}
	else if (data->map[y][x + 1] == 'E' && data->collectible == 0)
		{
			data->map[y][x + 1] = 'P';
			data->player.y = y * 64;
			data->player.x = (x + 1) * 64;
			data->map[y][x] = '0';
			ft_display_map(*data);
			ft_exit(data);
		}
	else if (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'P')
	{
		data->player.y = y * 64;
		data->player.x = (x + 1) * 64;
		data->map[y][x + 1] = 'P';
		
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else if(data->map[y][x + 1] == 'E' && data->collectible != 0)
	{
		data->map[y][x + 1] = 'P';
		data->player.y = y * 64;
		data->player.x = (x + 1) * 64;
		data->map[y][x] = '0';
	}
	else	
		return;
	ft_display_map(*data);
}

void move_player_down(t_data *data)
{
	int x;
	int y;

	y = data->player.y / 64;
	x = data->player.x / 64;
  
	if (data->map[y + 1][x] == 'C')
		{
			data->collectible--;
			data->map[y + 1][x] = 'P';
			data->player.y = (y + 1) * 64;
			data->player.x = x * 64;
			data->map[y][x] = '0';
			data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
		}
	else if (data->map[y + 1][x] == 'E' && data->collectible == 0)
		{
			data->map[y + 1][x] = 'P';
			data->map[y][x] = '0';
			data->player.y = (y + 1) * 64;
			data->player.x = x * 64;
			ft_display_map(*data);
			ft_exit(data);
		}
	else if (data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'P')
	{
		data->map[y + 1][x] = 'P';
		data->player.y = (y + 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
		data->map[data->exit.y / 64][data->exit.x / 64] = 'E';
	}
	else if(data->map[y + 1][x] == 'E' && data->collectible != 0)
	{
		data->map[y + 1][x] = 'P';
		data->player.y = (y + 1) * 64;
		data->player.x = x * 64;
		data->map[y][x] = '0';
	}
	else
		return;
	ft_display_map(*data);
}
