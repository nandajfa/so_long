/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:30:47 by jefernan          #+#    #+#             */
/*   Updated: 2022/03/02 15:17:17 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_print_flags(const char *format, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start (ap, format);
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			len += ft_print_flags(++format, ap);
			format++;
		}
		else
		{
			len += write (1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (len);
}

int	ft_print_flags(const char *format, va_list ap)
{
	char	c;

	if (*format == 'c')
	{
		c = (va_arg(ap, int));
		return (write(1, &c, 1));
	}
	else if (*format == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_print_d_i(va_arg(ap, int)));
	else if (*format == '%')
		return (write(1, format, 1));
	else
		return (0);
}
