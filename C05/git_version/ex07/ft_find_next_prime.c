/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:09:16 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/24 18:07:11 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
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
	//return (nb + 1);
	// should return next prime number
}
