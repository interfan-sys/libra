/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:26:48 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/17 17:15:40 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push_swap(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	if (argc == 2 && only_spaces(argv[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack_a(argc, argv);
	b = NULL;
	check_duplicates(a);
	index_stack(&a);
	if (is_sorted(a))
		return (0);
	size = stack_size(a);
	push_swap(&a, &b, size);
	free_list(a);
	return (0);
}
