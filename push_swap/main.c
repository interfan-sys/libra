#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*tmp;

	a = NULL;
	if (argc < 2 || !argv[1][0])
		return (0);
	a = init_stack_a(argc, argv);
	tmp = a;

	while (tmp)
	{
		printf("%d, ", tmp->nbr);
		tmp = tmp->next;
	}
	return (0);
}
