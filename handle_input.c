/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:19:45 by almichel          #+#    #+#             */
/*   Updated: 2024/02/02 01:33:51 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_handle_input(int keysym, t_data *data)
{
  if (keysym == KEY_Q || keysym == KEY_ESC)
    ft_exit(data);
	return (0);
}