#include <unistd.h>
#include "../ex00/ft_putchar.c"
#include "../ex01/ft_print_alphabet.c"
#include "../ex02/ft_print_reverse_alphabet.c"
#include "../ex03/ft_print_numbers.c"
#include "../ex04/ft_is_negative.c"
// #include "../ex05/ft_print_comb.c"
// #include "../ex06/ft_print_comb2.c"
// #include "../ex07/ft_putnbr.c"



int main(void){
	ft_putchar('h');
	write( 1, "\n\n", 2);
	ft_print_alphabet();
	write( 1, "\n\n", 2);
	ft_print_reverse_alphabet();
	write( 1, "\n\n", 2);
	ft_print_numbers();
	write( 1, "\n\n", 2);
	ft_is_negative(5);
	write( 1, "\n\n", 2);
	// ft_print_comb();
	// write( 1, "\n\n", 2);
	// ft_print_comb2();
	//  write( 1, "\n\n", 2);
	// ft_putnbr(4242);
	// write( 1, "\n", 2);
	// ft_putnbr(0);
	// write( 1, "\n", 2);
	// ft_putnbr(-4242);
	// write( 1, "\n\n", 2);


}