/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:12:57 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/01 23:34:08 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start(t_game *game, t_maps *maps, char **map)
{
	maps->line = 0;
	while (map[maps->line])
		maps->line++;
	maps->count_p = 0;
	maps->count_e = 0;
	maps->count_c = 0;
	maps->col = ft_strlen(game->map[0]);
	game->pp_line = 0;
	game->pp_col = 0;
	game->win_height = maps->line * IMG_SIZE;
	game->win_width = ft_strlen(game->map[0]) * IMG_SIZE;
	game->img_width = IMG_SIZE;
	game->img_height = IMG_SIZE;
	game->player_moves = 0;
	game->collectibles = 0;
}
