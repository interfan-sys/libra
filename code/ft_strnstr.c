/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:14:54 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/27 13:35:51 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)

{
	char	*str;
	char	*substr;
	size_t	i;
	size_t	j;

	str = (char *)s1;
	substr = (char *)s2;
	i = 0;
	if (*substr == '\0')
		return (str);
	while (i < n && str[i])
	{
		j = 0;
		while (substr[j] && (i + j) < n && str[i + j] == substr[j])
		{
			j++;
		}
		if (substr[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
