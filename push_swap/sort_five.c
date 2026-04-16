/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:09:27 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/15 12:21:38 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	find_min(t_node *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (a->nbr < min)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		while ((*a)->nbr != find_min(*a))
			ra(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
