/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:41:31 by almichel          #+#    #+#             */
/*   Updated: 2024/02/02 01:26:56 by almichel         ###   ########.fr       */
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
