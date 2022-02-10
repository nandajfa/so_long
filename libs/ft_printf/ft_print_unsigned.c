/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:40:24 by jefernan          #+#    #+#             */
/*   Updated: 2021/12/09 17:06:38 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	char	*str;
	int		len;

	if (nbr == 0)
		return (write(1, "0", 1));
	len = 0;
	str = ft_uitoa(nbr);
	len = ft_print_str(str);
	free(str);
	return (len);
}
