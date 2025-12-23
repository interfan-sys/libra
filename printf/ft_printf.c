/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:21:55 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/22 13:28:55 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_putchar_i(*format);
		}
		else
			count += ft_format_specifier(args, *format);
		format++;
	}
	va_end(args);
	return (count);
}
