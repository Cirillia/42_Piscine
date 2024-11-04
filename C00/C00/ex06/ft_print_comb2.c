/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:24:55 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/10 11:47:30 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_digit(int i)
{
	if (i < 10)
	{
		ft_putchar('0');
		ft_putchar('0' + i);
	}
	else
	{
		ft_putchar('0' + i / 10);
		ft_putchar('0' + i % 10);
	}
}

void	ft_print_comb2(void)
{
	int	n;
	int	m;

	n = 0;
	while (n <= 98)
	{
		m = n + 1;
		while (m <= 99)
		{
			ft_digit(n);
			ft_putchar(' ');
			ft_digit(m);
			if (n != 98 || m != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			m++;
		}
		n++;
	}
}
