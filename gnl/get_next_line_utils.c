/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:20:30 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/02 12:19:34 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char const *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

size_t	f_strlen(const char *s)
{
	unsigned int	len;
	const char		*ptr;

	if (!s)
		return(0);
	ptr = s;
	len = 0;
	while (*ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}

size_t	f_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = f_strlen(src);
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

size_t	f_strlcat(char *dest, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	tlen;
	size_t	i;

	if (!dest || !src)
		return (0);
	slen = f_strlen(src);
	dlen = f_strlen(dest);
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

char	*f_strdup(const char *s)

{
	char	*buffer;
	char	*copy;
	size_t	len;

	len = f_strlen(s);
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

char	*f_strjoin(char *s1, char *s2)
{
	char    *newstr;
	size_t  len1;
	size_t  len2;
	size_t  i;
	size_t  j;

    if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = f_strlen(s1);
	len2 = f_strlen(s2);
	if (len1 + len2 + 1 < len1 || len1 + len2 + 1 < len2)
	{
		free(s1);
		return (NULL);
	}
	newstr = malloc(len1 + len2 + 1);
	if (!newstr)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < len1)
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
    free(s1);
    return (newstr);
}
