/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:09:54 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/28 17:32:31 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_unsigned_int(unsigned int n)
{
	int		result;
	char	c;

	result = 0;
	if (n > 9)
		result += ft_unsignedint(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	result++;
	return (result);
}
