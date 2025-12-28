/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:19:42 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/22 13:26:10 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printptr(void *ptr)
{
	int	count;

	count = 0;
	write(1, "0x", 2);
	count += 2;
	if (!ptr)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	count += ft_printhex((unsigned long)ptr, 'x');
	return (count);
}
