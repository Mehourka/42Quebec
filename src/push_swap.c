#include "push_swap.h"
#include <stdio.h>

int main(void)
{
	t_stack *pile;

	pile = NULL;

	printf("Pushing to stack\n");
	for (int i = 0; i < 10; i++)
		push_stack(&pile, i);
	printf("Reading stack\n");
	read_stack(pile);
	printf("Freeing stack\n");
	free_stack(pile);
}