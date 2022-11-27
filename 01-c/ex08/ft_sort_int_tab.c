#include <stdio.h>

void swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void ft_sort_int_tab(int *tab, int size)
{
    int swap_count;
    int i;

    swap_count = 1;
    while (swap_count > 0)
    {
        i = 0;
        swap_count = 0;

        while (i <= size - 2)
        {
            if (tab[i] > tab[i + 1])
            {

                // printf("%i, %i\n", tab[i], tab[i + 1]);
                swap(&tab[i], &tab[i + 1]);
                swap_count++;
                // printf("%i, %i\n", tab[i], tab[i + 1]);
            }
            i++;
        }
    }
}
