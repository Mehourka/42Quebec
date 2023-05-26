#include "push_swap.h"
#include <stdio.h>

void print_stacks()
{
	t_data *data;

	data = init_data();

	t_stack *a_stack = data->a_stack;
	t_stack *b_stack = data->b_stack;

	char *a;
	char *b;

	printf("\n A     B\n");
	printf(" _______\n");
	while(a_stack || b_stack)
	{
		if(a_stack)
		{
			a = ft_itoa(a_stack->val);
			a_stack = a_stack->next;
		} else
			a = ft_strdup("_");

		if(b_stack)
		{
			b = ft_itoa(b_stack->val);
			b_stack = b_stack->next;
		} else
			b = ft_strdup("_");
			
		printf(" %s --- %s\n",a , b);
		free(a);
		free(b);
	}
	printf("\n\n");
}

void read_stack(t_stack *head)
{
	while(head)
	{
		printf("- %d\n", head->val);
		head = head->next;
	}
}