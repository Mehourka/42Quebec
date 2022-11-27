	#include <unistd.h>

void ft_print_combn(int n)
{
	char comb[10];
	// int i;
	// int j;

	// Initialize the array
	comb[0] = '0';
	// i = 0;
	while (comb[0] <= '9' - (n - 1))
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '9')
		{
			write(1, comb, n);
			write(1, ", ", 2);
			comb[1]++;
		}
		comb[0]++;
		// 	if (comb[i] == '9')
		// 	{
		// 		comb[i - 1]++;
		// 		comb[i] = comb[i - 1] + 1;
		// 	}
		// 	while (comb[i] <= '9')
		// 	{
		// 		write(1, &comb[i], 1);
		// 		if (comb[0] < '9' - n + 1)
		// 			write(1, ", ", 2);
		// 		comb[i]++;

		// 	}
		// 	i++;
		// }
	}
}
