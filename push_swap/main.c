#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	if (argc < 2 || !argv[1][0])
		return (0);
	a = init_stack_a(argc, argv);
	b = NULL;	
	check_duplicates(a);
	index_stack(&a);
	if (is_sorted(a))
		return (0);
	size = stack_size(a);
	if (size == 2)
		sort_two(&a);
	else
	radix_sort(&a, &b);
	print_stack(a);
	return (0);
}
