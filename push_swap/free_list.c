/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:44:32 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/17 18:37:18 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *list)
{
	t_node	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
