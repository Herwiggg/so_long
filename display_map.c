/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:54:08 by almichel          #+#    #+#             */
/*   Updated: 2024/04/05 16:30:53 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_to_wind(t_data data, int *_y, int *_x)
{
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data.mlx, data.mlx_wind, data.img, *_x, *_y);
	free(data.img);
}

void	ft_display_map2(t_data data, int y, int x)
{
	while (data.map[y][x] != '\n' && data.map[y][x])
	{
		if (data.map[y][x] == '1')
			data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/wall.xpm",
					&data.img_width, &data.img_height);
		else if (data.map[y][x] == '0')
			data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/empty.xpm",
					&data.img_width, &data.img_height);
		else if (data.map[y][x] == 'C')
			data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/coin1.xpm",
					&data.img_width, &data.img_height);
		else if (data.map[y][x] == 'E')
			data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/exit.xpm",
					&data.img_width, &data.img_height);
		else if (data.map[y][x] == 'P')
			data.img = mlx_xpm_file_to_image(data.mlx, image_player(&data),
					&data.img_width, &data.img_height);
		ft_image_to_wind(data, &data._y, &data._x);
		data._x = data._x + 64;
		x++;
	}
}

void	ft_display_map(t_data data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (data.map[y])
	{
		data._x = 0;
		x = 0;
		ft_display_map2(data, y, x);
		data._y = data._y + 64;
		y++;
	}
	ft_print_movements(&data);
}

void	ft_print_movements(t_data *data)
{
	char	*move;
	char	*phrase;

	move = ft_itoa(data->move);
	phrase = ft_strjoin("Movements : ", move);
	mlx_string_put(data->mlx, data->mlx_wind, 40, 20, 99999, phrase);
	data->move = data->move + 1;
	free(move);
	free(phrase);
}

char	*image_player(t_data *data)
{
	if (data->flag == 0)
		return ("./xpm/player1.xpm");
	else if (data->flag == 1)
		return ("./xpm/playertop.xpm");
	else if (data->flag == 2)
		return ("./xpm/playerright.xpm");
	else
		return ("./xpm/playerleft.xpm");
}
