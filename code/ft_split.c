/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:42:17 by agkicina          #+#    #+#             */
/*   Updated: 2025/10/23 17:20:45 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static	void	free_split(char	**array)

{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static	int	ft_words(char const *s, char c)

{
	int	count_words;
	int	in_word;

	count_words = 0;
	in_word = 0;
	while (*s && *s == c)
		s++;
	while (*s != '\0')
	{
		if (*s != c && in_word == 0)
		{
			count_words++;
			in_word = 1;
		}
		else if (*s == c && in_word == 1)
		{
			in_word = 0;
		}
		s++;
	}
	return (count_words);
}

static	char	*ft_extract(char const *s, char c)

{
	char const	*start;
	char		*string;
	size_t		len;
	size_t		i;

	start = s;
	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = start[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)

{
	char	**array;
	size_t	i;
	size_t	strings;

	if (!s)
		return (NULL);
	strings = ft_words(s, c);
	array = malloc(sizeof(char *) * (strings + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < strings)
	{
		while (*s == c)
			s++;
		array[i] = ft_extract(s, c);
		if (!array[i])
		{
			free_split(array);
			return (NULL);
		}
		s = s + ft_strlen(array[i++]);
	}
	(array[i] = NULL);
	return (array);
}
