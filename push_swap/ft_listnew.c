/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:26:35 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/12 18:30:03 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "push_swap.h"

	t_node	*ft_lstnew(int value)
	{
		t_node	*new_node;

		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->nbr = value;
		new_node->next = NULL;
		return (new_node);
	}
