/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:21:55 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/28 19:08:17 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_specifier(va_list	args, char specifier)
{
	int	result;

	result = 0;
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (specifier == 'd' || specifier == 'i')
		return (result += ft_putnumber(va_arg(args, int)));
	if (specifier == 's')
		return (result += ft_putstr(va_arg(args, char *)));
	if (specifier == 'u')
		return (result += ft_unsigned_int(va_arg(args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (result += ft_printhex(va_arg(args, unsigned int), specifier));
	if (specifier == 'p')
		return (result += ft_printptr(va_arg(args, void *)));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_format_specifier(args, *format);
		}
		else
			count += ft_format_specifier(args, *format);
		format++;
	}
	va_end(args);
	return (count);
}
