/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:09 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/02 14:17:10 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*f_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	f_strlen(const	char *s);

char	*ft_update_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;

	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(f_strlen(stash + i) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		j++;
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_extract_word(char *s)
{
	int		i;
	char	*word;

	if (!s || *s == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\0' &&  s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		word[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		word[i] = '\n';
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;
	int			i;

	  if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		i = 0;
		while (i < BUFFER_SIZE +1)
			buffer[i++] = 0;
		//OR ft_memset(buffer, 0, BUFFER_SIZE +1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (stash);
			stash = (NULL);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = f_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_word(stash);
	stash = ft_update_stash(stash);
	return (line);
}

int	main(void)

{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		write(1, line, f_strlen(line));
		free(line);
	}
	close(fd);
	return(0);
}
