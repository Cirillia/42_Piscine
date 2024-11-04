/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:51:54 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/22 12:33:34 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
		// nb * ( (nb-1) * ( nb -1 -1) .. * 1)
}

#include <stdio.h>
int	main(void)
{
	int n = 1;
	printf("%d", ft_recursive_factorial(n));
}