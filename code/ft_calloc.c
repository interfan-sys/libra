/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:43:12 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/13 12:02:16 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)

{
	size_t	total_size;
	char	*buffer;

	total_size = ((size_t)-1);
	if (nmemb == 0 || size == 0)
	{
		return (malloc(1));
	}
	if (nmemb != 0 && size > total_size / nmemb)
	{
		return (NULL);
	}
	buffer = malloc(nmemb * size);
	if (!buffer)
	{
		return (NULL);
	}
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
