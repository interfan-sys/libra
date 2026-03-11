/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:27:00 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/15 12:30:26 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)

{
	size_t	slen;
	size_t	dlen;
	size_t	tlen;
	size_t	i;

	if (!dest || !src)
		return (0);
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (dlen >= size)
		return (size + slen);
	tlen = size - dlen - 1;
	i = 0;
	while (i < tlen && src[i] != '\0')
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
