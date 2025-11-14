/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:09 by agkicina          #+#    #+#             */
/*   Updated: 2025/11/14 13:39:46 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd)

{
	static	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	size_t	i;
	char	*line = NULL;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		return (NULL);
	}
	i = 0;
	while (i < (size_t)bytes_read && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	size_t j = 0;
	while (j <= i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

int	main(void)

{
	int	fd;
	char *lines;
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	lines = get_next_line(fd);
	if (lines)
	write(1, lines, strlen(lines));
	free(lines);
	close(fd);
	return(0);
}
