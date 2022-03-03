/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:02:34 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 23:53:47 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'O')
				enemy_animation(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
void enemy_animation(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] != '1')
	{
		game->map[i][j] = '0';
		game->map[i - 1][j] = 'O';
	} 
}