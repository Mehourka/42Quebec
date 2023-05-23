#include "push_swap.h"

void raise_error()
{
	t_data *data;

	data = init_data();
	// TODO : Free memory here
	// free ft_split tabs.
	printf("Error\n");
	exit(1);
}

void	init_stack(t_stack **stack, int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
		stack_arg(stack, argv[i]);
}

/*
Returns 
	0 : if str represents valid int
	1 : otherwise
*/
int	int_check(char *nb)
{
	int i;

	i = 0;
	while(nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (1);
		i++;
	}
	return (0);
}


void	stack_arg(t_stack **head, char *arg)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split(arg, ' ');

	while(tab[i])
	{
		// Add int check
		if (int_check(tab[i]) != 0)
		{
			ft_free_tab(tab);
			raise_error();
		}
		// Add unique check
		push_stack(head, ft_atoi(tab[i]));
		i++;
	}
	ft_free_tab(tab);
}