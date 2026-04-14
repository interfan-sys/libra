/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:05:18 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/14 14:35:13 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	ft_count_words(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_space(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_is_space(str[i]))
			i++;
	}
	return (count);
}

static char	*ft_extract_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static	void	free_split(char **res, int j)
{
	while (j >= 0)
		free(res[j--]);
	free(res);
}

char	**ft_split(const char *str)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_is_space(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !ft_is_space(str[i]))
			i++;
		res[j] = ft_extract_word(str, start, i);
		if (!res[j])
			return (free_split(res, j - 1), NULL);
		j++;
	}
	return (res[j] = NULL, res);
}
