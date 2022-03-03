/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:21:27 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/03 00:40:01 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	start_game(t_game *game)
{	
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width, \
		game->win_height, "So_long");
	start_image(game);
	put_image(game);
	put_enemy(game);
	mlx_hook(game->win_ptr, KEY_PRESS, 1L << 0, key_hook, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY, 0, ft_close, game);
	mlx_loop_hook(game->mlx_ptr, put_image, game);
//	mlx_loop_hook(game->mlx_ptr, animation, game);
	mlx_loop(game->mlx_ptr);
}

void	start_image(t_game *game)
{
	game->img_floor = mlx_xpm_file_to_image (game->mlx_ptr, IMG_FLOOR, \
		&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image (game->mlx_ptr, IMG_WALL, \
		&game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image (game->mlx_ptr, IMG_COLLECT, \
		&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image (game->mlx_ptr, IMG_EXIT, \
		&game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image (game->mlx_ptr, IMG_PLAYER, \
		&game->img_width, &game->img_height);
	game->img_enemie = mlx_xpm_file_to_image (game->mlx_ptr, IMG_ENEMIE, \
		&game->img_width, &game->img_height);
}
