/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:27:43 by agkicina          #+#    #+#             */
/*   Updated: 2025/12/07 13:43:00 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_update_stash(char *old_stash)
{
	char	*new_stash;
	size_t	len;
	char	*new_line_ptr;

	new_line_ptr = ft_strchr(old_stash, '\n');
	if (!new_line_ptr)
	{
		free(old_stash);
		return (NULL);
	}
	new_line_ptr++;
	len = ft_strlen(new_line_ptr);
	new_stash = malloc(sizeof(char) * (len + 1));
	if (!new_stash)
	{
		free(old_stash);
		return (NULL);
	}
	ft_strlcpy(new_stash, new_line_ptr, len + 1);
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

char	*read_fill_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free (stash);
		return (free(buffer), NULL);
	}
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash), free(buffer), (NULL));
		if (bytes == 0)
			return (free(buffer), stash);
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		free(buffer);
		buffer = malloc(BUFFER_SIZE + 1);
		if (!stash)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	static char		*stash[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	if (!stash[fd])
		return (NULL);
	stash[fd] = read_fill_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract(stash[fd]);
	stash[fd] = ft_update_stash(stash[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		write(1, line, ft_strlen(line));
// 		free (line);
// 	}
// 	close (fd);
// 	return (0);
// }
