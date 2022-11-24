#include <unistd.h>
#include <stdio.h>

void ft_print_comb(void);

int main(void)
{
    ft_print_comb();
}

void ft_print_comb(void)
{
    char espace = ' ';
    int i = '0';
    int j, k;

    while (i <= '9')
    {
        j = i + 1;
        while (j <= '9')
        {
            k = j + 1;
            while (k <= '9')
            {
                write(1, &i, 1);
                write(1, &j, 1);
                write(1, &k, 1);
                write(1, &espace, 1);
                k++;
            }
            j++;
        }
        i++;
    }
}