/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:19:42 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/29 14:34:47 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex_ptr(unsigned long n);

int	ft_printptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	count += ft_printhex_ptr((unsigned long)ptr);
	return (count);
}

int	ft_printhex_ptr(unsigned long n)
{
	int		result;
	char	*base;

	result = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		result += ft_printhex_ptr(n / 16);
	result++;
	write(1, &base[n % 16], 1);
	return (result);
}
