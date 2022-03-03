/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:33:09 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/03 23:43:07 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	if (game->map[game->pp_line][game->pp_col + 1] == 'E' \
	&& game->collectibles == 0)
	{
		ft_printf("You win!!");
		ft_close(game);
	}
	else if (game->map[game->pp_line][game->pp_col + 1] == 'C')
		collect_right(game);
	else if (game->map[game->pp_line][game->pp_col + 1] != '1' \
	&& game->map[game->pp_line][game->pp_col + 1] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_col++;
		game->map[game->pp_line][game->pp_col] = 'P';
		game->player_moves++;
		ft_printf("%d\n", game->player_moves);
	}
}

void	collect_right(t_game *game)
{
	game->player_moves++;
	game->map[game->pp_line][game->pp_col] = '0';
	game->collectibles--;
	game->pp_col++;
	game->map[game->pp_line][game->pp_col] = 'P';
	ft_printf("%d\n", game->player_moves);
}