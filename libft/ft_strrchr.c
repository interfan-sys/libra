/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:09:36 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/27 13:14:48 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)

{
	char	ch;
	char	*str;
	char	*last_chr;

	str = (char *)s;
	ch = (char)c;
	last_chr = NULL;
	while (*str != '\0')
	{
		if (ch == (unsigned char )*str)
		{
			last_chr = str;
		}
		str++;
	}
	if (ch == '\0')
	{
		return (str);
	}
	return (last_chr);
}
