/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:45:28 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/10 12:17:46 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_recursion(int depth)
{
	depth--;
}

void	ft_print_combn(int n)
{
	int	i;

	i = 0;
	ft_putchar(',');
	ft_putchar(' ');
}

int	main(void)
{
	ft_print_combn(2);
}
