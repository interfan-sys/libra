#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	if (argc == 2 && ft_is_empty(argv[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack_a(argc, argv);
	b = NULL;
	check_duplicates(a);
	index_stack(&a);
	if (is_sorted(a))
		return (0);
	size = stack_size(a);
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	return (0);
}
