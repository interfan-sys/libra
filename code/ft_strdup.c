/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:08:53 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/13 14:41:26 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

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
