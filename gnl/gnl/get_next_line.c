/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:28:56 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/03 13:06:59 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcnlt.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*newline;
	int	i;
	
	i = 0;
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	while ((!ft_strchr(stash, '\n') && buffer[i] != '\0') && bytes > 0)
		i++;
		if (bytes <= 0)
			return (NULL);

}

int	main(void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
