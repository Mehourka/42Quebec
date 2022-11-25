#include <stdio.h>

void ft_swap(int *a, int *b)
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
    int swap;
    
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
                ft_swap(&tab[i], &tab[i + 1]);
                swap_count++;
                // printf("%i, %i\n", tab[i], tab[i + 1]);
            }
            i++;   
        }
    }
}

// /*
#include <stdio.h>
#include <unistd.h>
void print_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int size = 5;
    int arr[5] = {6, 10, 8, 2, 4};
    // int arr[3] = {2, 1, 3};
    print_arr(arr, size);
    ft_sort_int_tab(arr, size);

    print_arr(arr, size);
}

// */c print
