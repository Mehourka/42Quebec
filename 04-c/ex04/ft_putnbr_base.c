#include <unistd.h>

int validate_base(char *base)
{
	//check that base is at least size 2 and of unique characters != +/-
	// returns the base (size) as int
	int size;
	int i;
	int j;

	size = 0;
	while(base[size])
		size++;
	if (size <= 1)
		return (0);

	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
	i++;
	}
	return (size);
}

#include<stdio.h>
void rec_putnbr_base(int nbr, char *base_str, int base_int)
{
	int mod;

	mod = nbr % base_int;
	if (nbr >= base_int)
	{
		rec_putnbr_base(nbr / base_int, base_str, base_int);
	}
	write(1, &base_str[mod], 1);
}

void ft_putnbr_base(int nbr, char *base)
{
	int base_int;

	base_int = validate_base(base);
	if (base_int)
	{
		rec_putnbr_base(nbr, base, base_int);
	}
}



int main(void)
{
	// char *bin = "01";
	// char *hexa = "0123456789abcdef";
	// char *octa = "01234567";
	// char *err1 = "0";
	// char *err2 = "11";
	// char *err3 = "12+";

	ft_putnbr_base(13, "poneyvif");

}
