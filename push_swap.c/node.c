#include <stdio.h>
#include <stdlib.h>


typedef	struct	s_node{
	int	data;
	struct	s_node *next;
} t_node;

void	free_node(t_node *a);

int	main(int argc, char **argv)
{
	t_node *a;// we declared a pointer variable t_node *a in heap memory and after i have to malloc it!

	a = malloc(sizeof(t_node));//here i allocate the memory
	a->data = 42;
	a->next = malloc(sizeof(t_node));
	a->next->data = -42;// we use -> (arrow) to pointers
	a->next->next = malloc(sizeof(t_node));
	a->next->next->data = 84;
	a->next->next->next = NULL;
	t_node *p;
	p = a;// p points to Node a no need for & because both are pointers.
	while (p)// as long as p points to valid Node keep looping
	{
		printf("%d\n", p->data);// go to the Node p points-to (->) and read the data and print
		p = p->next;// points to the next Node in heap which dinamically allocated
	}
	free_node(a);
	return (0);
}
void	free_node(t_node *a)
{
	t_node *tmp;

	while(a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}