/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:24:39 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 16:13:24 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
