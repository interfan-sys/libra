/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agkicina <agkicina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:15:48 by agkicina          #+#    #+#             */
/*   Updated: 2026/04/12 20:24:40 by agkicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
}	t_node;
t_node	*ft_lstnew(int	value);
t_node	*init_stack_a(int argc, char **argv);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	check_duplicates(t_node *a);
int		ft_atoi(const char *str);
char	**ft_split(const char *str);
void	sa(t_node **a);

#endif
