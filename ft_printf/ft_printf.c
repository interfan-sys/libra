/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:21:55 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/29 14:44:31 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_specifier(va_list	args, char specifier)
{
	int		count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnumber(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_unsigned_int(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_format_specifier(args, *format);
			format++;
		}
		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
