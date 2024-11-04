/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalijono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:55:13 by nalijono          #+#    #+#             */
/*   Updated: 2024/03/10 13:18:26 by nalijono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	error_message ()
{
	write(1, "Please give two absolute positive numbers", 41);
}

void	print_top_line (int cols)
{
	ft_putchar('A');
	int	cur_col;
	cur_col = 2;
	while ( cols > 2 && cur_col < cols)
	{
		ft_putchar('B');
		cur_col++;	
	}
	if (cols >= 2)
	{
		ft_putchar('C');
		ft_putchar('\n');
	}
}

void	print_middle_line (int cols)
{
	ft_putchar('B');
	int	cur_col;
	cur_col = 2;
	while (cols > 2 && cur_col < cols)
	{
		ft_putchar(' ');	
		cur_col++;
	}
	if (cols >= 2)
	{
		ft_putchar('B');
		ft_putchar('\n');
	}
}

void	print_bottom_line (int cols)
{
	ft_putchar('C');
	int	cur_col;
	cur_col = 2;
	while (cols > 2 && cur_col < cols)
	{
		ft_putchar('B');
		cur_col++;	
	}
	if (cols >= 2)
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
}

void	rush (int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		error_message();
	}
	else if (rows >= 1)
	{
		print_top_line(cols);
		int	cur_row;
		cur_row = 1;
		while (rows > cur_row && cur_row < rows)
		{
			print_middle_line(cols);
			cur_row++;
		}
		print_bottom_line(cols);
	}
}
