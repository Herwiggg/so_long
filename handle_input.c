/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:45 by almichel          #+#    #+#             */
/*   Updated: 2024/03/26 16:14:18 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_handle_input(int keysym, t_data *data)
{
  if (keysym == KEY_Q || keysym == KEY_ESC)
    ft_exit(data);
  if ((keysym == KEY_UP || keysym == KEY_W) && ft_check_above(data) == 0)
    printf("nothing\n");
  if ((keysym == KEY_LEFT || keysym == KEY_A) && ft_check_left(data) == 0)
		printf("nothing\n");
	if ((keysym == KEY_RIGHT || keysym == KEY_D) && ft_check_right(data) == 0)
		printf("nothing\n");
	if ((keysym == KEY_DOWN || keysym == KEY_S) && ft_check_down(data) == 0)
		printf("nothing\n");
	return (0);
}

int ft_check_above(t_data *data)
{
  int x;
  int y;

  y = data->player.y / 64;
  x = data->player.x / 64;

  if (data->map[y - 1][x] == '1')
    return (-1);
  return (0);
}

int ft_check_down(t_data *data)
{
  int x;
  int y;

  y = data->player.y / 64;
  x = data->player.x / 64;

  if (data->map[y + 1][x] == '1')
    return (-1);
  return (0);
}

int ft_check_right(t_data *data)
{
  int x;
  int y;

  y = data->player.y / 64;
  x = data->player.x / 64;

  if (data->map[y][x + 1] == '1')
    return (-1);
  return (0);
}

int ft_check_left(t_data *data)
{
  int x;
  int y;

  y = data->player.y / 64;
  x = data->player.x / 64;
  
  if (data->map[y][x - 1] == '1')
    return (-1);
  return (0);
}
