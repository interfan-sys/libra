/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:20:30 by agkicina          #+#    #+#             */
/*   Updated: 2025/11/13 15:19:54 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
