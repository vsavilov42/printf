#include "../include/lib_printf.h"

int ft_printf(const char *form, ...)
{
	int i;
	char *str;
	va_list arg;

	i = 0;
	str = NULL;
	va_start(arg, form);
	while(form[i])
	{
		if(form[i] == '%')
		{
			i++;
			formatfunct(form[i], arg); //func cond
			i++;
		}
		ft_putchar(form[i]);
		i++;
	}
	va_end(arg);
	return (0);
}

int	formatfunct(char form, va_list arg)
{
	int i;

	i = 0;
	if (form == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (form == 's')
		i += ft_str(va_arg(arg, char *));
	else if (form == 'p')
		i += printmem(va_arg(arg, void *));//imprime direccion de memoria del punt (u int ptr)
	else if (form == 'd' || form == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (form == 'u')
		i += ft_putnbrpos(va_arg(arg, long));
	else if (form == 'x')
		i += ft_putnbrhex_mem(va_arg(arg, int), 0, 1);
	else if (form == 'X')
		i += ft_putnbrhex_mem(va_arg(arg, int), 0, 2);
	else
		i += ft_putchar(form);
	return (i);
}

int	printmem(void *memory)
{
	unsigned long memoryhex;
	int value;

	memoryhex = (uintptr_t)memory;
	value = 0;
	write(1, "0x", 2);
	value += ft_putnbrhex_mem(memoryhex, 0, 1);
	return (value);
}
