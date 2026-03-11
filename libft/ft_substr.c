/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:00:00 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/28 13:02:13 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	char	*buffer;
	size_t	l;

	if (!s)
	{
		return (NULL);
	}
	l = ft_strlen(s);
	if (start >= l)
	{
		return (ft_strdup(""));
	}
	if (start + len > l)
	{
		len = l - start;
	}
	buffer = malloc(len + 1);
	if (!buffer)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}
