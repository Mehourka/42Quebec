#include <stdio.h>
#include <unistd.h>
//gcc -Wall -Wextra -Werror ./*.c ../main.c && ./a.out

void ft_ft(int *nbr) __attribute__((weak));
void ft_ultimate_ft(int *********nbr) __attribute__((weak));
void ft_swap(int *a, int *b) __attribute__((weak));
void ft_div_mod(int a, int b, int *div, int *mod) __attribute__((weak));
void ft_ultimate_div_mod(int *a, int *b) __attribute__((weak));
void ft_putstr(char *str) __attribute__((weak));
int ft_strlen(char *str) __attribute__((weak));
void ft_rev_int_tab(int *tab, int size) __attribute__((weak));
// void ft_print_combn(int n) __attribute__((weak));
int main(void)
{
	// Exercice 0
	if (ft_ft)
	{
		int i;
		ft_ft(&i);
		printf("Expected : 42\nOutput : %i", i);
	}

	// // Exercice 1
	if (ft_ultimate_ft)
	{
		int a = 0;
		int *a1 = &a;
		int **a2 = &a1;
		int ***a3 = &a2;
		int ****a4 = &a3;
		int *****a5 = &a4;
		int ******a6 = &a5;
		int *******a7 = &a6;
		int ********a8 = &a7;
		int *********a9 = &a8;

		ft_ultimate_ft(a9);
		printf("Expect : 42\nOutput : %i\n", a);
	}

	// // Exercice 2
	if (ft_swap)
	{
		int a = 'b';
		int b = 'a';

		ft_swap(&a, &b);
		printf("Expect : a-b\nOutput : %c-%c\n", a, b);
	}

	// // Exercice 3
	if (ft_div_mod)
	{
		int a = 42;
		int b = 24;
		int div, mod;

		ft_div_mod(a, b, &div, &mod);
		printf("Expect : div=1 mod=18\nOutput : div=%i mod=%i\n", div, mod);
	}

	// // Exercice 4
	if (ft_ultimate_div_mod)
	{
		int a = 42;
		int b = 24;

		ft_ultimate_div_mod(&a, &b);
		printf("Expect : div=1 mod=18\nOutput : div=%i mod=%i\n", a, b);
	}

	// // Exercice 5
	if (ft_putstr)
		ft_putstr("Exercice 5 : OK\n");

	// // Exercice 6
	if (ft_strlen)
	{
		ft_strlen("Four");
		printf("Expect : 0, 4, 2\nOutput : %i, %i, %i\n",
		 ft_strlen(""), ft_strlen("Four"), ft_strlen("42"));
	}

	// // Exercice 7
	if (ft_rev_int_tab)
	{
		int even[4] = {7, 6, 5, 4};
		int odds[3] = {3, 2, 1};


		ft_rev_int_tab(even, 4);
		ft_rev_int_tab(odds, 3);

		printf("Expect : 123 4567\nOutput : ");
		for (int i = 0; i < 3; i++)
		{
			printf("%i", odds[i]);
		}
		printf(" ");
		for (int i = 0; i < 4; i++)
		{
			printf("%i", even[i]);
		}
		printf("\n");


	}

	// // Exercice 8
	// if (ft_print_combn)
	// 	ft_print_combn(2);
}
