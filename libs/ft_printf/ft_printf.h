/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:30:51 by jefernan          #+#    #+#             */
/*   Updated: 2021/12/09 17:16:21 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_print_str(char *str);
int	ft_print_d_i(int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_hex(unsigned long int n, char *hexa);
int	ft_print_ptr(unsigned long int ptr);

#endif
