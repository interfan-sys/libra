/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:26:09 by agkicina          #+#    #+#             */
/*   Updated: 2025/11/28 13:57:33 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*f_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	f_strlen(const	char *s);

char	*ft_update_stash(char *old_stash)
{
	char	*new_stash;
	size_t	len;
	char	*new_line;
	size_t	i;

	new_line = ft_strchr(old_stash, '\n');
	if (!new_line)
	{
		free(old_stash);
		return (NULL);
	}
	len = f_strlen(new_line + 1);
	new_stash = malloc(sizeof(char) * (len + 1));
	if (!new_stash)
	{
		free(old_stash);
		return (NULL);
	}
	i = 0;
	new_line++;
	while (i < len)
	{
		new_stash[i] = new_line[i];
		i++;
	}
	new_stash[i] = '\0';
	free(old_stash);
	return (new_stash);
}


char	*ft_extract(char *s)
{
		int	i;
		int	j;
		char	*word;

		i = 0;
		while (*s && s[i] != '\n')
		i++;
		if (s[i] == '\n')
		i++;
		word = malloc(i + 1);
		if (!word)
			return (NULL);
		j = 0;
		while (j < i)
		{
			word[j] = s[j];
			j++;
		}
		word[j] = '\0';
		return (word);
}


char	*get_next_line(int fd)
{
	static	char	*stash;

	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && bytes > 0)/*if stash is empty read from fd, if stash exists but there is no newline read more, stop reading omly when stash has a newline or EOF (bytes <= 0)*/
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = f_strjoin(stash, buffer);
		if(!stash)
			return (NULL);
	}
		line = ft_extract(stash);
		stash = ft_update_stash(stash);
		return (line);
}

int	main(void)

{
	int	fd;
	char *line;
	
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
	write(1, line, strlen(line));
	free(line);
	}
	close(fd);
	return(0);
}
