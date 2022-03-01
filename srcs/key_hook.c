/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:24:39 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/01 22:34:08 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC || key == KEY_Q)
		ft_close(game);
	else if (key == KEY_W || key == KEY_UP)
		move_up(game);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(game);
	return (0);
}

void	move_up(t_game *game)
{
	if (game->map[game->pp_line - 1][game->pp_col] == 'E' \
	&& game->collectibles == 0)
		ft_close(game);
	else if (game->map[game->pp_line - 1][game->pp_col] == 'C')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->collectibles--;
		game->pp_line--;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	else if (game->map[game->pp_line - 1][game->pp_col] != '1' \
	&& game->map[game->pp_line - 1][game->pp_col] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_line--;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	game->player_moves++;
	put_image(game);
	ft_printf("%d\n", game->player_moves);
}

void	move_down(t_game *game)
{
	if (game->map[game->pp_line + 1][game->pp_col] == 'E' \
	&& game->collectibles == 0)
		ft_close(game);
	else if (game->map[game->pp_line + 1][game->pp_col] == 'C')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->collectibles--;
		game->pp_line++;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	else if (game->map[game->pp_line + 1][game->pp_col] != '1' \
	&& game->map[game->pp_line + 1][game->pp_col] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_line++;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	game->player_moves++;
	put_image(game);
	ft_printf("%d\n", game->player_moves);
}

void	move_left(t_game *game)
{
	if (game->map[game->pp_line][game->pp_col - 1] == 'E' \
	&& game->collectibles == 0)
		ft_close(game);
	else if (game->map[game->pp_line][game->pp_col - 1] == 'C')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->collectibles--;
		game->pp_col--;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	else if (game->map[game->pp_line][game->pp_col - 1] != '1' \
	&& game->map[game->pp_line][game->pp_col - 1] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_col--;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	game->player_moves++;
	put_image(game);
	ft_printf("%d\n", game->player_moves);
}

void	move_right(t_game *game)
{
	if (game->map[game->pp_line][game->pp_col + 1] == 'E' \
	&& game->collectibles == 0)
		ft_close(game);
	else if (game->map[game->pp_line][game->pp_col + 1] == 'C')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->collectibles--;
		game->pp_col++;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	else if (game->map[game->pp_line][game->pp_col + 1] != '1' \
	&& game->map[game->pp_line][game->pp_col + 1] != 'E')
	{
		game->map[game->pp_line][game->pp_col] = '0';
		game->pp_col++;
		game->map[game->pp_line][game->pp_col] = 'P';
	}
	game->player_moves++;
	put_image(game);
	ft_printf("%d\n", game->player_moves);
}
