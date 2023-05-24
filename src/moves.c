#include "push_swap.h"
void swap(t_stack **head)
{

	if (!*head || !(*head)->next)
		return;

	t_stack *top;
	t_stack *bot;

	top = *head;
	bot = top->next;

	top->next = bot->next;
	bot->next = top;
	*head = bot;


}

void sa()
{
	t_data *data;

	data = init_data();
	swap(&data->a_stack);
}

void sb()
{
	t_data *data;

	data = init_data();
	swap(&data->b_stack);
}

void ss()
{
	t_data *data;

	data = init_data();
	swap(&data->a_stack);
	swap(&data->b_stack);
}