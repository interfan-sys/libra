/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:29:12 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/08 11:21:25 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

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

char	*ft_strdup(const char *s)

{
	char	*buffer;
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	copy = malloc(len + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	buffer = copy;
	while (*s)
	{
		*buffer++ = *s++;
	}
	*buffer = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > SIZE_MAX - len2 - 1)
		return (NULL);
	newstr = malloc(len1 + len2 + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	ft_strlcpy(newstr + len1, s2, len2 + 1);
	return (newstr);
}
