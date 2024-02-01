/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:10:12 by almichel          #+#    #+#             */
/*   Updated: 2024/01/31 20:50:01 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft42/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*---------Parsing-----------*/
char	**ft_read_and_stock(char *argv);
char	**ft_stock(char **dest, char *argv, int fd, int size);
char	*ft_check_retour(char *dest);

/*---------Check_map-----------*/
int		ft_check_ber(char *argv);
int		ft_is_a_valid_map(char **map);
int		ft_check_dimension(char **argv);
int		ft_check_rectangular(char **argv);
#endif