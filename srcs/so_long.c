/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:17:29 by jefernan          #+#    #+#             */
/*   Updated: 2022/02/12 23:20:36 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game game;

	check_arg(argc, argv);
	game.map = open_file_map(argv[1]);	
}

int	check_arg(int argc, char *argv[])
{
	if (argc > 2)
		perror ("Many arguments. Use only the name of a map.");
	if (argc < 2)
		perror ("Map name with extension .ber is required");
	if (ft_strnstr(argv[1], ".ber") == NULL)
		perror ("Invalid map extension. Use .ber");
	return (0);
}