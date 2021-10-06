#include "../include/lib_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *str)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while (str[i])
	{
		value += ft_putchar(str[i]);
		i++;
	}
	return (value);
}

int	ft_putnbrpos(long n)
{
	int value;

	value = 0;
	if (n < 0)
	{
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		value += ft_putchar(n + 48);
	}
	return (value);
}

int ft_putnbr(int n)
{
	int value;

	value = 0;
	if (n < 0)
	{
		value += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		value += ft_putchar(n + 48);
	}
	return (value);
}