/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalijono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:55:13 by nalijono          #+#    #+#             */
/*   Updated: 2024/03/09 19:50:52 by nalijono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void rush(int rows, int cols)
{
	if(rows <= 0 || cols <= 0 || 'a' <= rows <= 'z' || 'a' <= rows <= 'z')
		write(1, "Please give two absolute positive numbers", 41);	

	int my_row;
	int my_col;
	my_row = 1;

	while (my_row <= rows)
	    {
		    my_col = 1;
		    while (my_col <= cols)
		    {
			    if ((my_row == 1 && my_col == 1) || (my_row == rows && my_col == cols))
				    ft_putchar('A');
			    else if ((my_row == 1 && my_col == cols) || (my_row == rows && my_col == 1))
				    ft_putchar('C');
			    else if (my_row == rows || my_col == cols || my_row == 1 || my_col == 1)
				    ft_putchar('B');
			    else 
				    ft_putchar(' ');
			    my_col++;
		    }
		    ft_putchar('\n');
		    my_row++;
	    }

}
