#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*top;
	t_stack	*bot;

	if (!*head || !(*head)->next)
		return ;
	top = *head;
	bot = top->next;
	top->next = bot->next;
	bot->next = top;
	*head = bot;
}

void	sa(void)
{
	t_data	*data;

	data = init_data();
	swap(&data->a_stack);
}

void	sb(void)
{
	t_data	*data;

	data = init_data();
	swap(&data->b_stack);
}

void	ss(void)
{
	sa();
	sb();
}