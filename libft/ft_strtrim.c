/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:52:06 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/28 13:55:37 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static	int	is_in_set(char const *setstr, char c)

{
	while (*setstr)
	{
		if (*setstr == c)
		{
			return (1);
		}
		setstr++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)

{
	char			*copystr;
	char const		*start;
	char const		*end;
	size_t			len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = s1;
	while (*start && is_in_set(set, *start))
		start++;
	end = s1 + ft_strlen(s1);
	while (end > start && is_in_set(set, *(end - 1)))
		end--;
	len = end - start;
	copystr = (char *)malloc(len + 1);
	if (!copystr)
		return (NULL);
	ft_strlcpy(copystr, start, len + 1);
	return (copystr);
}
