/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:09 by agkicina          #+#    #+#             */
/*   Updated: 2025/11/12 13:23:27 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(void)

{
	int	fd;
	char	buffer[33];
	ssize_t	bytes_read;
	ssize_t	i;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1)
	{
		write(2, "Error\n", 6);
		close(fd);
		return (1);
	}
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
	i++;
	}
	write(1, buffer, i);
	close(fd);
	return(0);
}
