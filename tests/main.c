#include "ft_printf.h"

void check_printf(char *format, void **arg)
{
	int 	a, b;
	a = ft_printf(format, arg);
	puts("\nm:");
	b = printf(format, arg);
	puts("\nc:");

	printf("My: %d C: %d\n\n", a, b);
}

int main(void)
{
	int p1 = 2422;
	double p2 = 2343.43322;
	char c = '4';

	ft_printf("m: %p\n", &p1);
	printf("C: %p\n\n", &p1);
	
	ft_printf("m: %p\n", &p2);
	printf("C: %p\n\n", &p2);
	
	ft_printf("m: %p\n", &c);
	printf("C: %p\n\n", &c);
	//check_printf("%p", &p2);
	//check_printf("%p", &c);

	
	return (0);
}
