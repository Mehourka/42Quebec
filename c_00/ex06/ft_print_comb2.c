#include <unistd.h>
#include <stdio.h>

void format(int n);
void ft_print_comb2(void);

int main(void)
{
    ft_print_comb2();
    // format(22);
}

void ft_print_comb2(void)
{
    for (int i = 0; i <= 3; i++)
    {
        if (i != 0)
        {
            write(1, ", ", 2);
        }
        format(i);
    }
}

void format(int n)
{
    char str[5];
    for (int i = 4; i >= 0; i--)
    {
        if (i == 2)
        {
            str[i] = ' ';
        }
        else
        {
            str[i] = n % 10 + '0';
            n /= 10;
        }
    }
    write(1, str, 5);
}