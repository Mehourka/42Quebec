#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*new_src;

	if (!*src)
		return ;
	new_src = (*src)->next;
	(*src)->next = (*dest);
	*dest = *src;
	*src = new_src;
}

void	pa(void)
{
	t_data	*data;

	data = init_data();
	push(&data->b_stack, &data->a_stack);
}

void	pb(void)
{
	t_data	*data;

	data = init_data();
	push(&data->a_stack, &data->b_stack);
}