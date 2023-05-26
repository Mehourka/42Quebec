#include "push_swap.h"

static void	rot(t_stack **head)
{
	t_stack	*first_elem;
	t_stack	*ptr;

	if (!(*head) || !(*head)->next)
		return ;

	first_elem = (*head);
	(*head) = (*head)->next;
	first_elem->next = NULL;
	ptr = (*head);
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = first_elem;
}

void	ra(void)
{
	t_data	*data;

	data = init_data();
	rot(&data->a_stack);
}
void	rb(void)
{
	t_data	*data;

	data = init_data();
	rot(&data->b_stack);
}
void	rr(void)
{
	ra();
	rb();
}
