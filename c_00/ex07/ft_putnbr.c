#include <unistd.h>
#include <stdio.h>
void ft_putnbr(int nb);

int main()
{
    int x = 10;
    ft_putnbr(42);
    write(1, "\n", 1);
    ft_putnbr(-120);
    write(1, "\n", 1);
    // ft_putnbr(0);
    // write(1, "\n", 1);
}

void ft_putnbr(int nb)
{
    char str[12];
    int n = (nb > 0) ? nb : -nb;
    int c = 0;
    while (n > 0)
    {
        printf("%c", n % 10 + '0');
        str[c] = n % 10 + '0';
        n = n / 10;
        c++;
    }

    if (n < 0)
    {
        str[c] = '-';
        c++;
    }

    write(1, str, c);
    // for (int i = c; c >= 0; c--)
    // {
    //     printf("%i", str[i]);
    //     write(1, &str[i], 1);
    // }
}