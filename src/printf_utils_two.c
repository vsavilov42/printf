#include "../include/lib_printf.h"

int	ft_putnbrhex_mem(long n, int check, int uplow)
{
	static int value;
	
	if (check == 0)
		value = 2;
	if (n >= 16)
	{
		ft_putnbrhex_mem(n / 16, 1, uplow);
		ft_putnbrhex_mem(n % 16, 1, uplow);
	}
	else
	{
		value += ft_putchar_hex(n, uplow);
	}
	return (value);
}

int	ft_putchar_hex(int c, int uplow)
{
	int value;
	char *hex;
	char *HEX;

	value = 0;
	hex = "0123456789abcdef";
	HEX = "0123456789ABCDEF";
	if (c > 16)
		c = c % 16;
	if (uplow == 1)
		value += ft_putchar(hex[c]);
	if (uplow == 2)
		value += ft_putchar(HEX[c]);
	return (value);
}
