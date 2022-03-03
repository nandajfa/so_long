/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:05:44 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 23:36:55 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			load_map(game, i, j);
			j++;
		}
		i++;
	}
	put_steps(game);
	return (0);
}

void	load_map(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, \
			y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, \
			y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img_collect, y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, \
			y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, \
			y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map[x][y] == 'O')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_enemie, \
			y * IMG_SIZE, x * IMG_SIZE);
}
