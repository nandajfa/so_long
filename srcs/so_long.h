/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:37:46 by jefernan          #+#    #+#             */
/*   Updated: 2022/02/11 21:48:26 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/ft_printf/ft_printf.h"

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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
}			t_data;

typedef struct s_map
{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		col;
	int		row;
}			t_map;

typedef struct s_player
{
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	int		player_move;
}			t_player;

typedef struct s_sprite
{
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*img_player;
	int		img_width;
	int		img_height;
}			t_sprite;

typedef struct s_game
{
	t_data *data;
	t_map	*map;
	t_player	*player;
	t_sprite	*sprite;
	int		x;
	int		y;	
}			t_game;

