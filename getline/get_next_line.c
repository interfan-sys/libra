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

#include "get_next_line.h"

char	*ft_update_stash(char *old_stash)
{
	char	*new_stash;
	size_t	len;
	char	*new_line_ptr;
	size_t	i;

	new_line_ptr = ft_strchr(old_stash, '\n');
	if (!new_line_ptr)
	{
		free(old_stash);
		return (NULL);
	}
	new_line_ptr++;
	len = f_strlen(new_line_ptr);
	new_stash = malloc(sizeof(char) * (len + 1));
	if (!new_stash)
	{
		free(old_stash);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_stash[i] = new_line_ptr[i];
		i++;
	}
	new_stash[i] = '\0';
	free(old_stash);
	return (new_stash);
}

char	*ft_extract(char *s)
{
	size_t	i;
	size_t	j;
	char	*word;

	if (!s || s[0] == '\0')
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
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
	static	char	*stash = NULL;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = f_strdup("");
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			stash = (NULL);
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
	line = get_next_line(fd);
	write(1, line, f_strlen(line));
	free(line);
	write(1, "\n", 1);
	close(fd);
	return(0);
}
