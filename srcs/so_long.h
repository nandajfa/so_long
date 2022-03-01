/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:37:46 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/01 23:59:16 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# define IMG_FLOOR "assets/images/floor.xpm"
# define IMG_WALL "assets/images/wall.xpm"
# define IMG_COLLECT "assets/images/collect.xpm"
# define IMG_EXIT "assets/images/exit.xpm"
# define IMG_PLAYER "assets/images/player_s.xpm"

# define PLAYER_W "assets/images/player_w.xpm"
# define PLAYER_A "assets/images/player_l.xpm"
# define PLAYER_S "assets/images/player_s.xpm"
# define PLAYER_D "assets/images/player_r.xpm"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

# define IMG_SIZE 32

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
	char	**map;
	int		fd;
	int		win_width;
	int		win_height;
	int		player_moves;
	int		img_width;
	int		img_height;
	int		pp_col;
	int		pp_line;
	int		collectibles;
}			t_game;

typedef struct s_maps
{
	int	count_p;
	int	count_c;
	int	count_e;
	int	line;
	int	col;
}	t_maps;

int			check_arg(int argc, char *argv[]);
char		*open_file_map(char *map, int fd, t_game *game);
int			check_map(char	**map, t_maps	*maps, t_game *game);
void		start(t_game *game, t_maps *maps, char **map);
int			check_sprite(char	**map, t_maps *maps, t_game *game);
int			ft_close(t_game *game);
int			check_char(char	**map, t_game *game);
void		free_map(char **map);
void		ft_free(void **ptr);
void		start_game(t_game *game);
void		start_image(t_game *game);
int			put_image(t_game *game);
void		load_map(t_game *game, int x, int y);
void		free_images(t_game *game);
int			key_hook(int key, t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			put_image_update(t_game *game);
void		load_map_update(t_game *game, int x, int y);
void		message(char **map, t_maps *maps, t_game *game);
// FT_PRINTF //
int			ft_print_d_i(int nbr);
int			ft_print_ptr(unsigned long int ptr);
int			ft_print_str(char *str);
int			ft_print_unsigned(unsigned int nbr);
int			ft_print_hex(unsigned long int n, char *hexa);
int			ft_printf(const char *format, ...);

#endif