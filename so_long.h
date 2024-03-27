/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:39:57 by mmorue            #+#    #+#             */
/*   Updated: 2024/03/27 22:18:11 by almichel         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

typedef struct s_coin
{
	int		y;
	int		x;
	int		on_map;
}			t_coin;

typedef struct s_coord
{
	int		y;
	int		x;
}			t_coord;

typedef struct s_data
{
	char	**map;
	char	**tab;
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
	int		move;
	int		k;
	int		l;
	int		flag;
	int		readed;
	int		e;
	int		c;
	int		p;
	int		y;
	int		x;
	int		_x;
	int		_y;
	t_coord	*wall_c;
	t_coord	player;
	t_coord	exit;
	t_coin	*collectible_c;
}			t_data;

/*---------Parsing-----------*/
char		**ft_read_and_stock(char *argv, t_data *data);
char		**ft_stock(char **dest, char *argv, int fd, int size);
char		*ft_check_retour(char *dest);

/*---------Check_map-----------*/
int			ft_check_ber(char *argv);
int			ft_is_a_valid_map(t_data *data);
int			ft_check_dimension(char **argv);
int			ft_check_rectangular(char **argv);
int			ft_check_wall(char **argv);
int			ft_check_wall2(char **argv);
int			ft_check_elements(char **argv, t_data *data);
int			ft_check_elements2(char **argv, t_data *data);
int			pathfinding(char **tab, int y, int x, int items);
void		collect_nbr_item(char **argv, int items);

/*---------MLX-----------*/
void		ft_display_map(t_data data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_handle_input(int keysym, t_data *data);
int			ft_exit(t_data *data);
void		ft_mlx_init(t_data *data);
void		ft_print_movements(t_data *data);
int			ft_victory(t_data *data);
void		ft_image_to_wind(t_data data, int *size_y, int *size_x);
void		ft_display_map2(t_data data, int y, int x);

/*---------Player moves-----------*/
int			ft_check_above(t_data *data);
int			ft_check_down(t_data *data);
int			ft_check_right(t_data *data);
int			ft_check_left(t_data *data);
void		move_player_top(t_data *data);
void		move_player_left(t_data *data);
void		move_player_right(t_data *data);
void		move_player_down(t_data *data);
char		*image_player(t_data *data);
void		move_collectible1(t_data *data, int y, int x, int sign);
void		move_victory1(t_data *data, int y, int x, int sign);
void		move_empty1(t_data *data, int y, int x, int sign);
void		move_campfire1(t_data *data, int y, int x, int sign);
void		move_collectible2(t_data *data, int y, int x, int sign);
void		move_victory2(t_data *data, int y, int x, int sign);
void		move_empty2(t_data *data, int y, int x, int sign);
void		move_campfire2(t_data *data, int y, int x, int sign);

/*---------Utils-----------*/
int			ft_error_msg(char *str);
int			ft_error_msg2(char *str, char **tab);
int			ft_count_lines(char **str);
int			ft_count_height(char **map);
int			ft_count_len(char **map);
char		**copy_double_tab(char **tab);
char		**ft_doublefree(char **tab, int k);
void		ft_stock_coords(t_data *data);
void		ft_stock_coords2(t_data *data);
int			ft_malloc_struct(t_data *data);

#endif