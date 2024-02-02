/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_valid_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:33:27 by almichel          #+#    #+#             */
/*   Updated: 2024/02/02 01:33:55 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_elements2(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] != '\n')
		{
			if (argv[i][j] == '0' || argv[i][j] == '1' || argv[i][j] == 'E' || argv[i][j] == 'C' || argv[i][j] == 'P')
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}
