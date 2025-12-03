/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:28:56 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/03 14:10:53 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcnlt.h>

char	*ft_strchr(const char *s, int	c)
{
	while (s != '\0')
		{
			if (*s == (char )c)
			{
				return ((char *)s);
			}
			s++;
		}
		if ((char )c == '\0')
			{
				return ((char *)s);
			}
			return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*newline;

	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while ((!ft_strchr(stash, '\n') && bytes > 0)
		if (bytes <= 0)
			return (NULL);

}

int	main(void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
