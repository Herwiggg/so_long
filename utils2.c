/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:41:31 by almichel          #+#    #+#             */
/*   Updated: 2024/04/07 03:46:07 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_double_tab(char **tab)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc((ft_count_height(tab) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	map[ft_count_height(tab)] = NULL;
	while (i < ft_count_height(tab))
	{
		map[i] = ft_strdup(tab[i]);
		i++;
	}
	return (map);
}

char	**ft_doublefree(char **tab, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		free(tab[i]);
	free(tab);
	return (NULL);
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
