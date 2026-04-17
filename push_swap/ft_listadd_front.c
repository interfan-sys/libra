/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:15:16 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/12 17:29:49 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
