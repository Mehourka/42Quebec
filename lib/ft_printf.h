#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_numlen_dec(long num);
int	ft_putnbr(int n);
int ft_putnbr_uns(unsigned n);
int	ft_putnbr_base(long n, char*);
int ft_puthex(int, int);
int	ft_putptr(int n);
int	ft_printf(char *format, ...);

#endif
