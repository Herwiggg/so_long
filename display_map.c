#include "so_long.h"

void	ft_display_map(t_data data)
{
	int y;
	int	x;

	x = 0;
	y = 0;
	int size_x;
	int size_y;
	size_x = 0;
	size_y = 0;
	while (data.map[y])
	{
		size_x = 0;
		 x = 0 ;
		 while (data.map[y][x] != '\n' && data.map[y][x])
		 {
			if (data.map[y][x] == '1')
				data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/wall.xpm", &data.img_width, &data.img_height);
			else if (data.map[y][x] == '0')
				data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/empty.xpm", &data.img_width, &data.img_height);
			else if (data.map[y][x] == 'C')
				data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/coin1.xpm", &data.img_width, &data.img_height);
			else if (data.map[y][x] == 'E')
				data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/exit.xpm", &data.img_width, &data.img_height);
			else if (data.map[y][x] == 'P')	
					data.img = mlx_xpm_file_to_image(data.mlx, "./xpm/player1.xpm", &data.img_width, &data.img_height);
			data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
			my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
			mlx_put_image_to_window(data.mlx, data.mlx_wind, data.img, size_x, size_y);
			size_x = size_x + 64;
			x++;
		 }
		 size_y = size_y + 64;
		 y++;
	}
	int i = 0;
	while (data.map[i])
		printf("%s\n", data.map[i++]);
	
	printf("-----------------------\n");
}
