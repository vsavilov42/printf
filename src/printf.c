/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:18:36 by vsavilov          #+#    #+#             */
/*   Updated: 2021/10/07 19:20:35 by vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *form, ...)
{
	int		i;
	va_list	arg;
	int value;

	i = 0;
	value = 0;
	va_start(arg, form);
	while (form[i] != '\0')
	{
		if (form[i] == '%')
		{
			i++;
			value += formatfunct(form[i], arg);
		}
		else
			value += ft_putchar(form[i]);
		i++;
	}
	va_end(arg);
	return (value);
}

int	formatfunct(char form, va_list arg)
{
	int	value;

	value = 0;
	if (form == 'c')
		value += ft_putchar(va_arg(arg, int));
	else if (form == 's')
		value += ft_str(va_arg(arg, char *));
	else if (form == 'p')
		value += printmem(va_arg(arg, void *));
	else if (form == 'd' || form == 'i')
		value += ft_putnbr(va_arg(arg, int), 0);
	else if (form == 'u')
		value += ft_putnbrpos(va_arg(arg, unsigned int), 0);
	else if (form == 'x')
		value += ft_putnbrhex(va_arg(arg, unsigned int), 0, 1);
	else if (form == 'X')
		value += ft_putnbrhex(va_arg(arg, unsigned int), 0, 2);
	else
		value += ft_putchar(form);
	return (value);
}

int	printmem(void *memory)
{
	unsigned long	memoryhex;
	int				value;

	memoryhex = (uintptr_t)memory;
	value = 0;
	value += write(1, "0x", 2);
	value += ft_putnbrhex_mem(memoryhex, 0, 1);
	return (value);
}

int	ft_putchar_hex(int c, int uplow)
{
	int		value;

	value = 0;
	if (c > 16)
		c = c % 16;
	if (uplow == 1)
		value += ft_putchar(HEX[c]);
	if (uplow == 2)
		value += ft_putchar(UPHEX[c]);
	return (value);
}

int	ft_putnbrhex(unsigned int n, int check, int uplow)
{
	static int	value;

	if (check == 0)
		value = 0;
	if (n >= 16)
	{
		ft_putnbrhex(n / 16, 1, uplow);
		ft_putnbrhex(n % 16, 1, uplow);
	}
	else
		value += ft_putchar_hex(n, uplow);
	return (value);
}
