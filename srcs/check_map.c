/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:28:26 by jefernan          #+#    #+#             */
/*   Updated: 2022/02/17 02:23:53 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_map(char	**map, t_maps	*maps)
{
	int	i;
	int	j;

	maps->row = 0;
	maps->col = ft_strlen(map[0]);
	while (map[maps->row])
		maps->row++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][maps->col - 1] != '1' || map[i][0] != '1' 
				|| map[maps->row - 1][j] != '1' || map[0][j] != '1')
			{
				write (1, "Error\nInvalid map\n", 20);
				return (1);
			}	
			j++;
		}
		i++;
	}
	init_map(maps);
	check_sprite(map, maps);
	check_char(map);
	printf("%d\n%d\n", maps->col, maps->row);
	printf("%d\n%d\n", j, i);
	return (0);
}

void	init_map(t_maps *maps)
{
	maps->count_p = 0;
	maps->count_e = 0;
	maps->count_c = 0;
}


int	check_sprite(char	**map, t_maps *maps)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				maps->count_p++;
			if (map[i][j] == 'E')
				maps->count_e++;
			if (map[i][j] == 'C')
				maps->count_c++;
			j++;
		}
		i++;
	}
	printf("%d\n%d\n%d\n", maps->count_p, maps->count_e, maps->count_c);
	if (maps->count_p != 1 || maps->count_e != 1 || maps->count_c == 0)
	{
		write (1, "Error\nInvalid map: no PEC\n", 26);
		return (1);
	}
	return (0);
}

int	check_char(char	**map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')	
			{
				printf("%d\n%d\n", i, j);
				write (1, "Error\nInvalid map: unknown character\n", 39);
				return (1);
			}	
			j++;
		}
		i++;
	}
	
	return (0);
}