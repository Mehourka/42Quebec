#include <stdio.h>

void ft_print_comb(void) __attribute__((weak));
void ft_putnbr(int nb) __attribute__((weak));

int main(void)
{
    // test Ex5
    if (ft_print_comb)
        ft_print_comb();
    

    // test Ex7
    if (ft_putnbr)
        printf("It works !!");
}