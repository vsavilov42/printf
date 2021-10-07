#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

# define HEX "0123456789abcdef"
# define UPHEX "0123456789ABCDEF"

/*struct t_form {
	int i;
};
struct t_form = {0};*/

int		ft_printf(const char *form, ...);
int		ft_putchar(int c);
int		ft_str(char *str);
int		ft_putnbr(int n, int check);
int		formatfunct(char form, va_list arg);
int		printmem(void *memory);
int		ft_putnbrhex_mem(unsigned long n, int check, int uplow);
int		ft_putchar_hex(int c, int uplow);
int		ft_putnbrpos(unsigned int n, int check);
int		ft_putnbrhex(unsigned int n, int check, int uplow);

#endif
