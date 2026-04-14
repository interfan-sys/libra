/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:31:28 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/14 11:38:05 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node	*stack)
{
	while (stack)
	{
		printf("%d", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}
