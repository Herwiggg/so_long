/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:54:08 by almichel          #+#    #+#             */
/*   Updated: 2024/04/07 03:26:37 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_data *data)
{
	data->img.floor = "./xpm/empty.xpm";
	data->img.wall = "./xpm/wall.xpm";
	data->img.collect = "./xpm/coin1.xpm";
	data->img.player = "./xpm/player1.xpm";
	data->img.exit = "./xpm/exit.xpm";
	data->img.player_top = "./xpm/playertop.xpm";
	data->img.player_right = "./xpm/playerright.xpm";
	data->img.player_left = "./xpm/playerleft.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx, data->img.wall,
			&(data->img_width), &(data->img_height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx, data->img.floor,
			&(data->img_width), &(data->img_height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx, data->img.exit,
			&(data->img_width), &(data->img_height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx,
			data->img.collect, &(data->img_width), &(data->img_height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx,
			data->img.player, &(data->img_width), &(data->img_height));
	data->img.img_player_top = mlx_xpm_file_to_image(data->mlx,
			data->img.player_top, &(data->img_width), &(data->img_height));
	data->img.img_player_right = mlx_xpm_file_to_image(data->mlx,
			data->img.player_right, &(data->img_width), &(data->img_height));
	data->img.img_player_left = mlx_xpm_file_to_image(data->mlx,
			data->img.player_left, &(data->img_width), &(data->img_height));
}

void	ft_image_to_wind(t_data data, int *_y, int *_x, void *img)
{
	data.addr = mlx_get_data_addr(img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data.mlx, data.mlx_wind, img, *_x, *_y);
}


void	ft_display_map2(t_data data, int y, int x)
{
	while (data.map[y][x] != '\n' && data.map[y][x])
	{
		if (data.map[y][x] == '1')
			ft_image_to_wind(data, &data._y, &data._x, data.img.img_wall);
		else if (data.map[y][x] == '0')
			ft_image_to_wind(data, &data._y, &data._x, data.img.img_floor);
		else if (data.map[y][x] == 'C')
			ft_image_to_wind(data, &data._y, &data._x, data.img.img_collect);
		else if (data.map[y][x] == 'E')
			ft_image_to_wind(data, &data._y, &data._x, data.img.img_exit);
		else if (data.map[y][x] == 'P')
		{
			if (image_player(&data) == 0)
				ft_image_to_wind(data, &data._y, &data._x, data.img.img_player);
		}	
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
	if (data->move == 0)
		phrase = ft_strjoin("Movement : ", move);
	else 
		phrase = ft_strjoin("Movements : ", move);
	mlx_string_put(data->mlx, data->mlx_wind, 40, 20, 99999, phrase);
	write(1, phrase, ft_strlen(phrase));
	write(1, "\n", 1);
	data->move = data->move + 1;
	free(move);
	free(phrase);
}

int		image_player(t_data *data)
{
	if (data->flag == 1)
		ft_image_to_wind(*data, &data->_y, &data->_x, data->img.img_player_top);
	else if (data->flag == 2)
		ft_image_to_wind(*data, &data->_y, &data->_x, data->img.img_player_right);
	else if (data->flag == 3)
		ft_image_to_wind(*data, &data->_y, &data->_x, data->img.img_player_left);
	else if (data->flag == 0)
		return (0);
	return (1);
}
