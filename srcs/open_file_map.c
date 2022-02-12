/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:17:29 by jefernan          #+#    #+#             */
/*   Updated: 2022/02/12 23:19:56 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*open_file_map(char *map)
{
	int		fd;
	int		ret;
	char	*str = NULL;
	char	*temp;
	char	buffer[2];

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buffer, 1);
	while (ret)
	{
		buffer[rt] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str, buffer);
			free(str);
			str = temp;
		}
		rt = read(fd, buffer, 1);
	}
	close (fd);
	return (str);
}