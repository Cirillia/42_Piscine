/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rush00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:55:13 by nalijono          #+#    #+#             */
/*   Updated: 2024/03/10 16:02:09 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	error_message(void)
{
	write(1, "Please give two absolute positive numbers", 41);
}

void	print_top_line(int cols)
{
	int	cur_col;

	ft_putchar('o');
	cur_col = 2;
	while (cols > 2 && cur_col < cols)
	{
		ft_putchar('-');
		cur_col++;
	}
	if (cols >= 3)
	{
		ft_putchar('o');
	}
}

void	print_middle_line(int cols)
{
	int	cur_col;

	ft_putchar('|');
	cur_col = 2;
	while (cols > 2 && cur_col < cols)
	{
		ft_putchar(' ');
		cur_col++;
	}
	if (cols >= 2)
	{
		ft_putchar('|');
	}
}

void	print_bottom_line(int cols)
{
	int	cur_col;

	ft_putchar('o');
	cur_col = 2;
	while (cols > 2 && cur_col < cols)
	{
		ft_putchar('-');
		cur_col++;
	}
	if (cols >= 2)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
}

void	rush(int rows, int cols)
{
	int	cur_row;

	if (rows <= 0 || cols <= 0)
	{
		error_message();
	}
	else if (rows >= 1)
	{
		print_top_line(cols);
		cur_row = 1;
		while (cur_row < rows -1)
		{
			ft_putchar('\n');
			print_middle_line(cols);
			cur_row++;
		}
		if (rows >= 2)
		{
			ft_putchar('\n');
			print_bottom_line(cols);
		}
	}
}
