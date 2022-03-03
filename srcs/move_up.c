/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:38:28 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/03 23:42:50 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->pp_line - 1][game->pp_col] == 'E' \
	&& game->collectibles == 0)
	{
		ft_printf("You win!!");
		ft_close(game);
	}
	else if (game->map[game->pp_line - 1][game->pp_col] == 'C')
		collect_up(game);
	else if (game->map[game->pp_line - 1][game->pp_col] != '1' \
	&& game->map[game->pp_line - 1][game->pp_col] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_line--;
		game->map[game->pp_line][game->pp_col] = 'P';
		game->player_moves++;
		ft_printf("%d\n", game->player_moves);
	}
}

void	collect_up(t_game *game)
{
	game->player_moves++;
	game->map[game->pp_line][game->pp_col] = '0';
	game->collectibles--;
	game->pp_line--;
	game->map[game->pp_line][game->pp_col] = 'P';
	ft_printf("%d\n", game->player_moves);
}