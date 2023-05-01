#include <stdarg.h>
#include <stdio.h>

#include "ft_printf.h"

#include <limits.h>

int	ft_printflag(char flag, va_list args)
{
	if (flag == 'c')
		return ft_putchar(va_arg(args, int));
	if (flag == 's')
		return ft_putstr(va_arg(args, char*));
	if (flag == 'p')
		return ft_putptr(va_arg(args, int));
	if (flag == 'd' || flag == 'i')
		return ft_putnbr(va_arg(args, int));
	if (flag == 'u')
		return ft_putnbr_uns(va_arg(args, unsigned));
	if (flag == 'x')
		return ft_puthex(va_arg(args, int), 0);
	if (flag == 'X')
		return ft_puthex(va_arg(args, int), 1);
	if (flag == '%')
		return ft_putchar('%');
	return 0;
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	int		i;
	int		char_count;

	i = -1;
	va_start(args, format);
	char_count = 0;

	while(format[++i])
	{
		if (format[i] == '%')
			char_count += ft_printflag(format[++i], args);
		else
			char_count += ft_putchar(format[i]);
	}
	return (char_count);
}

int	main(void)
{
	char	*format;
	int X = -1;

	format ="%u \n";

	ft_printf("\nReturns : %d - %i  \n",
		printf(format, X, X,-1),
		ft_printf(format,X, X, -2)
	);
	// ft_puthex(256);
}
