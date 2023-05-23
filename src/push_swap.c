#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack *pile;

	pile = NULL;

	printf("Pushing to stack\n");
	init_stack(&pile, argc, argv);
	printf("Reading stack\n");
	read_stack(pile);
	printf("Freeing stack\n");
	free_stack(pile);
}