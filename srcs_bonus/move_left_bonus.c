/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:05:51 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/03 23:15:53 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_game *game)
{
	if (game->map[game->pp_line][game->pp_col - 1] == 'E' \
	&& game->collectibles == 0)
	{
		ft_printf("You Win!!\n");
		ft_close(game);
	}
	else if (game->map[game->pp_line][game->pp_col - 1] == 'C')
		collect_left(game);
	else if (game->map[game->pp_line][game->pp_col - 1] == 'O')
	{
		ft_printf("GAME OVER!! You Lost\n");
		ft_close(game);
	}
	else if (game->map[game->pp_line][game->pp_col - 1] != '1' \
	&& game->map[game->pp_line][game->pp_col - 1] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_col--;
		game->map[game->pp_line][game->pp_col] = 'P';
		game->player_moves++;
	}
}

void	collect_left(t_game *game)
{
	game->player_moves++;
	game->map[game->pp_line][game->pp_col] = '0';
	game->collectibles--;
	game->pp_col--;
	game->map[game->pp_line][game->pp_col] = 'P';
}