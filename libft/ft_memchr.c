/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:12:59 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/31 11:28:11 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*str == chr)
		{
			return ((void *)str);
		}
		str++;
		n--;
	}
	return (NULL);
}
