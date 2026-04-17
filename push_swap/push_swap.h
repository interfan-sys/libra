/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:15:48 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/17 18:26:08 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
}	t_node;
t_node	*ft_lstnew(int value);
t_node	*init_stack_a(int argc, char **argv);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	check_duplicates(t_node *a);
long	ft_atoi(const char *str);
char	**ft_split(const char *str);
void	sa(t_node **a);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	print_stack(t_node	*stack);
int		stack_size(t_node *a);
void	ra(t_node **a);
void	rra(t_node **a);
int		is_sorted(t_node *a);
void	index_stack(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
int		only_spaces(char *str);
int		is_number(char *str);
void	free_list(t_node *list);
int		ft_is_space(char c);
void	free_split(char **split);
void	sort_two(t_node **a);

#endif
