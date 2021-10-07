/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:20:52 by vsavilov          #+#    #+#             */
/*   Updated: 2021/10/07 19:20:33 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *str)
{
	int	i;
	int	value;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	value = 0;
	while (str[i])
	{
		value += ft_putchar(str[i]);
		i++;
	}
	return (value);
}

int	ft_putnbr(int n, int check)
{
	static int	value;

	if (check == 0)
		value = 0;
	if (n == -2147483648)
	{
		value += ft_putchar('-');
		value += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		value += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, 1);
		ft_putnbr(n % 10, 1);
	}
	else
	{
		value += ft_putchar(n + 48);
	}
	return (value);
}

int ft_putnbrpos(unsigned int n, int check)
{
	static int value;

	if (check == 0)
		value = 0;
	if (n >= 10)
	{
		ft_putnbrpos(n / 10, 1);
		ft_putnbrpos(n % 10, 1);
	}
	else
		value += ft_putchar(n + 48);
	return (value);
}

int	ft_putnbrhex_mem(unsigned long n, int check, int uplow)
{
	static int	value;

	if (check == 0)
		value = 0;
	if (n >= 16)
	{
		ft_putnbrhex_mem(n / 16, 1, uplow);
		ft_putnbrhex_mem(n % 16, 1, uplow);
	}
	else
		value += ft_putchar_hex(n, uplow);
	return (value);
}
