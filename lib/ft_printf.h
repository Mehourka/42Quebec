#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_numlen_dec(long num);
int	ft_putnbr(int n);
int ft_putnbr_uns(unsigned n);
int	ft_putnbr_base(unsigned long n, char*);
int ft_puthex(unsigned long, int);
int	ft_putptr(unsigned long n);
int	ft_printf(const char* format, ...);
int	ft_numlen_hex(unsigned long num);

#endif
