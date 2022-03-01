/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:22:45 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/01 23:25:37 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game->map);
	free(game->map);
	exit (0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_free((void *)&map[i]);
		i++;
	}
	ft_free((void *)&map[i]);
}

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_floor);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_collect);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
}
