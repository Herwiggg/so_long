/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:41:31 by almichel          #+#    #+#             */
/*   Updated: 2024/03/07 15:19:30 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    ft_count_lines(char **str)
{
    int    i;

    i = 0;
    while (str[i])
	{
		if (str[i][0] == '\n')
			break;
		i++;
	}
		
    return (i);
}

int	ft_error_msg(char *str)
{
	int	len;

	len = ft_strlen(str);
	write (2, str, len);
	return (-1);
}

int ft_error_msg2(char *str, char **tab)
{
	int	len;

	ft_doublefree(tab, ft_count_height(tab));
	len = ft_strlen(str);
	write (2, str, len);
	return (-1);
}
int	ft_count_len(char **map)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (map[i][j] && map[i][j] != '\n')
		j++;
	return (j);
}

int	ft_count_height(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		i++;
	}
	return (i);
}
