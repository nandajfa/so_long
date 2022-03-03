/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:04:43 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 23:30:52 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_right(t_game *game)
{
	if (game->map[game->pp_line][game->pp_col + 1] == 'E' \
	&& game->collectibles == 0)
	{
		ft_printf("You Win\n");
		ft_close(game);
	}
	else if (game->map[game->pp_line][game->pp_col + 1] == 'C')
		collect_right(game);
	else if (game->map[game->pp_line][game->pp_col + 1] == 'O')
	{
		ft_printf("GAME OVER!! You Lost\n");
		ft_close(game);
	}
	else if (game->map[game->pp_line][game->pp_col + 1] != '1' \
	&& game->map[game->pp_line][game->pp_col + 1] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_col++;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	game->player_moves++;
	ft_printf("%d\n", game->player_moves);
}

void	collect_right(t_game *game)
{
	game->map[game->pp_line][game->pp_col] = '0';
	game->collectibles--;
	game->pp_col++;
	game->map[game->pp_line][game->pp_col] = 'P';
}
