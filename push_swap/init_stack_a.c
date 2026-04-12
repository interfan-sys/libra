/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:24:22 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/12 18:33:59 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_stack_a(int argc, char **argv)
{
	t_node	*a;
	t_node	*new;
	int		i;
	int		value;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new = ft_lstnew(value);
		ft_lstadd_back(&a, new);
		i++;
	}
	check_duplicates(a);
	return (a);
}
