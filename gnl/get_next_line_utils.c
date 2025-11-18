/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:20:30 by agkicina          #+#    #+#             */
/*   Updated: 2025/11/17 14:23:05 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	f_strlen(const char *s)
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

char	*f_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	size_t	maxsize;
	size_t	total_len;
	
	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (f_strdup(s1));
	else if (!s1 && s2)
		return (f_strdup(s2));
	maxsize = (size_t)-1;
	len1 = f_strlen(s1);
	len2 = f_strlen(s2);
	if (len1 > maxsize - len2 - 1)
		return (NULL);
	total_len = len1 + len2 + 1;
	newstr = malloc(total_len);
	if (!newstr)
		return (NULL);
	f_strlcpy(newstr, s1, len1 + 1);
	f_strlcat(newstr, s2, total_len);
	return (newstr);
}
