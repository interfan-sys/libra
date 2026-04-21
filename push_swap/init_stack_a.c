/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:24:22 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/17 18:41:36 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*error_exit(char **argv, t_node *a, int is_split)
{
	if (is_split)
		free_split(argv);
	free_list(a);
	return (write(2, "Error\n", 6), NULL);
}

static	char	**string_input(char *str)
{
	char	**split;

	split = NULL;
	split = ft_split(str);
	if (!split || !split[0])
	{
		return (write(2, "Error\n", 6), NULL);
	}
	return (split);
}

static t_node	*fill_stack(char **argv, int i, int is_split)
{
	t_node	*a;
	t_node	*new;
	long	num;

	a = NULL;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (error_exit(argv, a, is_split));
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (error_exit(argv, a, is_split));
		new = ft_lstnew((int)num);
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}

t_node	*init_stack_a(int argc, char **argv)
{
	t_node	*a;
	int		i;
	int		is_split;

	i = 0;
	is_split = 0;
	if (argc == 2)
	{
		argv = string_input(argv[1]);
		if (!argv)
			return (NULL);
		is_split = 1;
	}
	else
		i = 1;
	a = fill_stack(argv, i, is_split);
	if (!a)
		return (NULL);
	if (is_split)
		free_split(argv);
	check_duplicates(a);
	return (a);
}
