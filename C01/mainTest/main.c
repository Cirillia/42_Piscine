#include <unistd.h>
#include <stdio.h>
#include "../ex00/ft_ft.c"
#include "../ex02/ft_swap.c"
#include "../ex03/ft_div_mod.c"
#include "../ex04/ft_ultimate_div_mod.c"
#include "../ex05/ft_putstr.c"
#include "../ex06/ft_strlen.c"
#include "../ex07/ft_rev_int_tab.c"
#include "../ex08/ft_sort_int_tab.c"

int main(void)
{
	int n = 0;

	printf("------------ex00:------------\n");
	printf("n's value is: %d\n", n);
	printf("n's reference is: %p\n", &n);
	ft_ft(&n);
	printf("After ex00 n's value is: %d\n", n);
	printf("After ex00 n's reference is: %p\n", &n);
	printf("\n\n");

	printf("------------ex02:------------\n");
	int i = 3, j = 10;
	int *p1 = &i, *p2 = &j;
	printf("Before swapping: i = %d, j = %d\n", i, j);
	ft_swap(p1, p2);
	printf("After swapping: i = %d, j = %d\n", i, j);
	printf("\n\n");

	printf("------------ex03:------------\n");
	int p, q;
	printf("Current a is %d, b is %d \n", i, j);
	ft_div_mod(i, j, &p, &q);
	printf("Quotient: %d, Remainder: %d \n", p, q);
	printf("\n\n");

	printf("------------ex04:------------\n");
	printf("Current a is %d, b is %d \n", i, j);
	printf("Before division: a = %d, b = %d \n", i, j);
	ft_ultimate_div_mod(&i, &j);
	printf("After division: a = %d, b = %d \n", i, j);
	printf("\n\n");

	printf("------------ex05:------------\n");
	ft_putstr("hello!");
	printf("\n\n");

	printf("------------ex06:------------\n");
	char str[] = "Hello!";
	printf("Length of the string: %d\n", ft_strlen(str));
	printf("\n\n");

	printf("------------ex07:------------\n");
	int arr[] = {1, 2, 3, 4, 5};
	int size = 5;

	printf("The current array is:");
	for(int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}

	ft_rev_int_tab(arr, size);
	printf("\n The reversed array is:");
	for(int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n\n");

	
	printf("------------ex08:------------\n");
	int n2 = 0;
	int arr2[] = {1,5,3,8,4,0,7,2,6,9};
	int size_of_arr = 10;
	ft_sort_int_tab(arr2, size_of_arr);
	while(n2 < 10)
	{
		printf("%d", arr2[n2]);
		n2++;
	}
}