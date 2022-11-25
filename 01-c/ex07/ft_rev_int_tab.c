void ft_rev_int_tab(int *tab, int size)
{
    int c;
    int i;

    i = 0;
    while (i <= size / 2)
    {
        c = tab[(size - 1) - i];
        tab[(size - 1) - i] = tab[i];
        tab[i] = c;
        i++;
    }
}


/*
#include <stdio.h>
int main(void)
{   
    int size = 5;
    int arr[5] = {2, 4, 6, 8, 10};

    printf("%i\n", arr[5 - 1 - 0]);

    ft_rev_int_tab(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("\n");
}
*/