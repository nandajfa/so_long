/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:42:54 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 23:18:02 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				enemy_place(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	enemy_place(t_game *game, int i, int j)
{
	if (game->map[i][j - 1] == '0')
		game->map[i][j - 1] = 'O';
}