/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:28:26 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/03 16:13:42 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map(char	**map, t_maps *maps, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][maps->col - 1] != '1' || map[i][0] != '1'
				|| map[maps->line - 1][j] != '1' || map[0][j] != '1')
			{
				ft_printf("Error\nInvalid map: walls\n");
				free_map(map);
				free(game->map);
				exit (1);
			}	
			j++;
		}
		i++;
	}
	check_sprite(map, maps, game);
	game->collectibles = maps->count_c;
	check_char(map, game);
	return (0);
}

int	check_sprite(char	**map, t_maps *maps, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->pp_line = i;
				game->pp_col = j;
				maps->count_p++;
			}
			if (map[i][j] == 'E')
				maps->count_e++;
			if (map[i][j] == 'C')
				maps->count_c++;
			j++;
		}
		i++;
	}
	message(map, maps, game);
	return (0);
}

void	message(char	**map, t_maps *maps, t_game *game)
{
	if (maps->count_p != 1 || maps->count_e != 1 || maps->count_c == 0)
	{
		ft_printf("Error\nInvalid map: P-E-C\n");
		free_map(map);
		free(game->map);
		exit (1);
	}
}

int	check_char(char	**map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'O')
			{
				ft_printf("Error\nInvalid map: unknown character\n");
				free_map(map);
				free(game->map);
				exit (1);
			}	
			j++;
		}
		i++;
	}
	return (0);
}
