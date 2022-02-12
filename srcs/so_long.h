/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:37:46 by jefernan          #+#    #+#             */
/*   Updated: 2022/02/12 23:20:55 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# define IMG_FLOOR "assets/images/floor.xpm"
# define IMG_WALL "assets/images/wall.xpm"
# define IMG_COLLECT "assets/images/collect.xpm"
# define IMG_EXIT "assets/images/exit.xpm"
# define IMG_PLAYER "assets/images/mario_s.xpm"

# define PLAYER_W "assets/images/mario_w.xpm"
# define PLAYER_A "assets/images/mario_l.xpm"
# define PLAYER_S "assets/images/mario_s.xpm"
# define PLAYER_D "assets/images/mario_r.xpm"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_ESC 65307
# define KEY_Q 113

# define SPRITE_SIZE 64

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*img_player;
	char	*map;
	int		width;
	int		height;
	int		col;
	int		row;
	int		win_width;
	int		win_height;
	int		player_move;
	int		img_width;
	int		img_height;
	int		x;
	int		y;	
}			t_game;

int	check_arg(int argc, char *argv[]);
char	*open_file_map(char *map);


#endif