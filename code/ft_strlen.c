/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:34:38 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/15 12:08:25 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s)

{
	unsigned int	len;
	const char		*ptr;

	ptr = s;
	len = 0;
	while (*ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}
