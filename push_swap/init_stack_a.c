/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:24:22 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/16 14:57:58 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_stack_a(int argc, char **argv)
{
    t_node  *a;
    t_node  *new;
    char    **split;
    int     i;

    a = NULL;
    split = NULL;
    if (argc == 2)
    {
        split = ft_split(argv[1]);
        if (!split || !split[0])
            return (write(2, "Error\n", 6), NULL);
        argv = split;
        i = 0;
    }
    else
        i = 1;
    while (argv[i])
    {
        if (!is_number(argv[i]))
            return (write(2, "Error\n", 6), NULL);
        new = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(&a, new);
        i++;
    }
    check_duplicates(a);
    return (a);
}
