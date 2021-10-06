#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

/*struct t_form {
	int i;
};
struct t_form = {0};*/

int		ft_printf(const char *form, ...);
int		ft_putchar(char c);
int		ft_str(char *str);
int		ft_putnbrpos(long n);
int		ft_putnbr(int n);
int		formatfunct(char form, va_list arg);
int		printmem(void *memory);
int		ft_putnbrhex_mem(long n, int check, int uplow);
int		ft_putchar_hex(int c, int uplow);

#endif
