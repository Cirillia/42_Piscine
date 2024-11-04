/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:09:16 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/24 13:32:41 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fine_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (2);
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (nb);
		else
			i++;
	}
	// return (nb + 1);
	// need to return next prime number
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_fine_next_prime(97));
}