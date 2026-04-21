/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:37:11 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/14 14:00:46 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*stack_to_array(t_node *a)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * stack_size(a));
	i = 0;
	while (a)
	{
		arr[i++] = a->nbr;
		a = a->next;
	}
	return (arr);
}

static	void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static	int	get_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	index_stack(t_node **a)
{
	int		*arr;
	int		size;
	t_node	*tmp;

	size = stack_size(*a);
	arr = stack_to_array(*a);
	sort_array(arr, size);
	tmp = *a;
	while (tmp)
	{
		tmp->nbr = get_index(arr, size, tmp->nbr);
		tmp = tmp->next;
	}
	free(arr);
}
