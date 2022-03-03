/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:05:18 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 23:30:47 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_down(t_game *game)
{
	if (game->map[game->pp_line + 1][game->pp_col] == 'E' \
	&& game->collectibles == 0)
	{
		ft_printf("You Win\n");
		ft_close(game);
	}	
	else if (game->map[game->pp_line + 1][game->pp_col] == 'C')
		collect_down(game);
	else if (game->map[game->pp_line + 1][game->pp_col] == 'O')
	{
		ft_printf("GAME OVER!! You Lost\n");
		ft_close(game);
	}
	else if (game->map[game->pp_line + 1][game->pp_col] != '1' \
	&& game->map[game->pp_line + 1][game->pp_col] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_line++;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	game->player_moves++;
	ft_printf("%d\n", game->player_moves);
}

void	collect_down(t_game *game)
{
	game->map[game->pp_line][game->pp_col] = '0';
	game->collectibles--;
	game->pp_line++;
	game->map[game->pp_line][game->pp_col] = 'P';
}