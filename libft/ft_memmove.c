/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:44:45 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/31 11:59:43 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)

{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s && d < s + n)
	{
		d += n - 1;
		s += n - 1;
		while (n > 0)
		{
			*d-- = *s--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}
