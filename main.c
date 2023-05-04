#include "get_next_line.h"
#include <stdio.h> // printf()
#include <fcntl.h> // open()


char **init_tab(int n)
{
	int i;
	char **new_tab;

	i = 0;
	new_tab = (char **) malloc(n * sizeof(char *));
	while (i < n)
	{
		new_tab[i++] = NULL;
	}
	return new_tab;
}
void print_lines(char **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
		puts(tab[i++]);
}

void free_tab(char **tab, int n)
{
	int i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}

int main(void)
{
	int fd;
	char **lines;
	int i;
	int reps = 1;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	lines = init_tab(reps);
	while(i < reps)
	{
		lines[i] = get_next_line(fd);
		i++;
	}
	print_lines(lines, reps);
	free_tab(lines, reps);
}
