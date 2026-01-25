#include <stdio.h>
#include <stdlib.h>



typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

void    free_node(t_node *a);

void	push(int value)
{
    t_node  *head;
    t_node  *tmp;
    head = malloc(sizeof(t_node));
    head->data = value;
    head->next = NULL;
    head = head->next;//You first connect the new node to the existing list, and only then move the head pointer so the list starts at the new node.
    while(tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    free_node(tmp);
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
int main(int argc, char **argv)
{
    push(10);
    push(20);
    return(0);
}