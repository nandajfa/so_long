/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:17:29 by jefernan          #+#    #+#             */
/*   Updated: 2022/02/16 15:59:42 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**open_file_map(char *map, int fd)
{
	int		ret;
	char	*str;
	char	*temp;
	char	**str_ret;
	char	buffer[2];

	str = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buffer, 1);
	while (ret)
	{
		buffer[ret] = '\0';
		temp = ft_strjoin(str, buffer);
		free(str);
		str = temp;
		ret = read(fd, buffer, 1);
	}
	str_ret = ft_split(str, '\n');
	free(str);
	close (fd);
	return (str_ret);
}
