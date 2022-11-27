#include <stdio.h>

void ft_putchar(char c) __attribute__((weak));
void ft_print_alphabet(void) __attribute__((weak));
void ft_print_reverse_alphabet(void) __attribute__((weak));
void ft_print_numbers(void) __attribute__((weak));
void ft_is_negative(int n) __attribute__((weak));
void ft_print_comb(void) __attribute__((weak));
void ft_print_comb2(void) __attribute__((weak));
void ft_putnbr(int nb) __attribute__((weak));
void ft_print_combn(int n) __attribute__((weak));

int main(void)
{
	// Exercice 0
	if (ft_putchar)
		ft_putchar('G');

	// Exercice 1
	if (ft_print_alphabet)
		ft_print_alphabet();

	// Exercice 2
	if (ft_print_reverse_alphabet)
		ft_print_reverse_alphabet();

	// Exercice 3
	if (ft_print_numbers)
		ft_print_numbers();

	// Exercice 4
	if (ft_is_negative)
	{
		printf("Expected : NP\nOutput : ");
		ft_is_negative(-42);
		ft_is_negative(0);
	}

	// Exercice 5
	if (ft_print_comb)
		ft_print_comb();

	// Exercice 6
	if (ft_print_comb2)
		ft_print_comb2();

	// Exercice 7
	if (ft_putnbr)
	{
		ft_putnbr(0); printf("\n");
		ft_putnbr(42); printf("\n");
		ft_putnbr(-42); printf("\n");
		ft_putnbr(2147483647); printf("\n");
		ft_putnbr(-2147483647); printf("\n");
	}

	// Exercice 8
	if (ft_print_combn)
		ft_print_combn(2);
}
