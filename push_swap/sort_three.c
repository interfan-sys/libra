/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 11:31:20 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/15 11:53:23 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if (first < second && second < third)
		return ;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
		return ;
	}
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
