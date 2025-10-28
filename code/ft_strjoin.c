/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:38:12 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/28 13:42:15 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	size_t	maxsize;
	size_t	total_len;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return(ft_strdup(s1));
	else if (s2 && !s1)
		return (ft_strdup(s2));
	maxsize = (size_t)-1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > maxsize - len2 - 1)
		return (NULL);
	total_len = len1 + len2 + 1;
	newstr = malloc(total_len);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	ft_strlcat(newstr, s2, total_len);
	return (newstr);
}
