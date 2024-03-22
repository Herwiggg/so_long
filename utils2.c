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

char **copy_double_tab(char **tab)
{
	char **map;
	int		i;

	i = 0;
	map = malloc((ft_count_height(tab) + 1)* sizeof(char *));
	if (!map)
		return (NULL);
	map[ft_count_height(tab)] = '\0';
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