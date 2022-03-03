/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:09:34 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 14:22:08 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_steps(t_game *game)
{
	char	*str;
	char	*join;
	char	*aux;

	aux = ft_strdup("MOVES: ");
	str = ft_itoa(game->player_moves);
	join = ft_strjoin(aux, str);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 35, 45, 0x000000FF, join);
	free(str);
	free(aux);
	free(join);
}
