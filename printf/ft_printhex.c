/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:22:10 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/22 13:05:08 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printhex(unsigned long num, char specifier)
{
	const char	*base;
	int			result;

	result = 0;
	if (specifier == 'x')
		base = "0123456789abcdef";
	else if (specifier == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	if (num >= 16)
		result += ft_printhex(num / 16, specifier);
	write(1, &base[num % 16], 1);
	result++;
	return (result);
}
