/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:11:53 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/28 18:17:06 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnumber(int n)
{
	char			c;
	unsigned int	num;
	int				count;

	num = 0;
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;
	if (num > 9)
	{
		count += ft_putnumber(num / 10);
	}
	c = num % 10 + '0';
	count++;
	write(1, &c, 1);
	return (count);
}
/*
int	main(void)

{
	int	x;
	x = -2147483648;
	ft_putnumber(x);
	return (0);
}*/
