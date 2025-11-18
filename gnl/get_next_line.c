/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:09 by agkicina          #+#    #+#             */
/*   Updated: 2025/11/18 13:20:16 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*f_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd)
{

	char	buffer[BUFFER_SIZE + 1];
	size_t	bytes_read;
	char	*line;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
	write(2, "Error\n", 6);
	return (NULL);
	}
	buffer[bytes_read] = '\0';
	line = malloc(bytes_read + 1);
	if (!line)
		return (NULL);
	line = f_strjoin(line, buffer);
	return (line);
}

int	main(void)
{
	int	fd;
	char *lines;
	
	fd = open("/nfs/homes/agkicina/test.txt", O_RDONLY);
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
