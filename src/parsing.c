#include "push_swap.h"
void init_stack(t_stack **stack, int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
		stack_arg(stack, argv[i]);
}

void stack_arg(t_stack **head, char *arg)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(arg, ' ');

	while(tab[i])
	{
		// Add int check
		// Add unique check
		push_stack(head, ft_atoi(tab[i]));
		i++;
	}
	ft_free_tab(tab);

}