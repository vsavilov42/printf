#include "../ft_printf.h"
#include <limits.h>

int main()
{
	/*int a;
	int b;
	a = ft_printf("MY: %s %d", "pacojones", 1023);
	b = printf("MY: %s %d", "pacojones", 1023);*/
	ft_printf("1 %c\n", 50);	
	printf("1 %c\n", 50);	
	ft_printf("2 %s\n", "abc");
	printf("2 %s\n", "abc");
	ft_printf("3 %p\n", "123");
	printf("3 %p\n", "123");
	ft_printf("4 %d\n", 123);
	printf("4 %d\n", 123);
	ft_printf("5 %i\n", 123);
	printf("5 %i\n", 123);
	ft_printf("6 %u\n", 123);
	printf("6 %u\n", 123);
	ft_printf("7 %x\n", 123);
	printf("7 %x\n", 123);
	ft_printf("8 %X\n", 123);	
	printf("8 %X\n", 123);
	printf("9 %%");
	ft_printf("9 %%\n");	
	//printf("OG RET %d\n MY RET %d\n", b, a);
	return (0);
}
