#include "push_swap.h"

void push_stack(t_stack **head, int val)
{
	t_stack *new;
	t_stack *ptr;
	t_stack *prev;

	new = malloc(sizeof(t_stack));
	new->data = val;
	new->next = NULL;

	if (*head == NULL)
	{
		 *head = new;
		return ;
	}

	ptr = *head;
	while(ptr)
	{
		prev = ptr;
		if (ptr->data == val)
			raise_error();
		ptr = ptr->next;
	}
	prev->next = new;
}
void read_stack(t_stack *head)
{
	while(head)
	{
		printf("- %d\n", head->data);
		head = head->next;
	}
}

void free_stack(t_stack *head)
{
	t_stack *tmp;

	while(head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
