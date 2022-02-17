/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:17:29 by jefernan          #+#    #+#             */
/*   Updated: 2022/02/17 02:24:31 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_game	game;
	t_maps	maps;

	check_arg(argc, argv);
	game.map = open_file_map(argv[1], game.fd);
	printf("%s\n", *game.map);
	check_map(game.map, &maps);

	
	free(game.map);
}

int	check_arg(int argc, char *argv[])
{
	char	*str;
	int		len;

	if (argc != 2)
	{
		write(1, "Error\nInvalid number of arguments.\n", 37);
		exit (1);
	}
	else
	{
		len = 0;
		str = ft_strrchr(argv[1], '.');
		if (str)
		{
			len = ft_strlen(str);
			if (!ft_memcmp(str, ".ber", len))
				return (0);
		}
		write(1, "Error\nInvalid map extension. Use .ber\n", 40);
		exit(1);
	}
	return (0);
}
