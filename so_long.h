/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:39:57 by mmorue            #+#    #+#             */
/*   Updated: 2024/03/10 02:11:19 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TSIZE 64
# define WIDTH 1920
# define HEIGHT 1080
# include "./get_next_line/get_next_line.h"
# include "./libft42/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_coin {
	
	int	y;
	int	x;
	int	on_map;
}	t_coin;

typedef struct s_coord {

	int	y;
	int	x;
}	t_coord;

typedef struct s_data {

	char 	**map;
	void	*mlx;
	void	*mlx_wind;
	int		items;
	int		wall;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		collectible;
	t_coord		*wall_c;
	t_coord		player;
	t_coord		exit;
	t_coin		*collectible_c;
}	t_data;

/*---------Parsing-----------*/
char	**ft_read_and_stock(char *argv);
char	**ft_stock(char **dest, char *argv, int fd, int size);
char	*ft_check_retour(char *dest);

/*---------Check_map-----------*/
int		ft_check_ber(char *argv);
int		ft_is_a_valid_map(t_data *data);
int		ft_check_dimension(char **argv);
int		ft_check_rectangular(char **argv);
int		ft_check_wall(char **argv);
int		ft_check_elements(char **argv);
int 	ft_check_elements2(char **argv, int *x, int *y, int items, t_data *data);
int		pathfinding(char **tab, int y, int x, int items);

/*---------Utils-----------*/
int		ft_error_msg(char *str);
int 	ft_error_msg2(char *str, char **tab);
int    	ft_count_lines(char **str);
void	ft_display_map(t_data data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_count_height(char **map);
int		ft_count_len(char **map);
char 	**copy_double_tab(char **tab);
char	**ft_doublefree(char **tab, int k);
void	ft_stock_coords(t_data *data);
void	ft_malloc_struct(t_data *data);


#endif