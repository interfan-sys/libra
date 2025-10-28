/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:41:59 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/24 19:40:49 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static	size_t	ft_nbrlen(long nbr)

{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)

{
	long	nbr;
	char	*str;
	size_t	len;

	nbr = (long )n;
	len = ft_nbrlen(nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
		nbr = -nbr;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nbr != 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
