/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:03 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/12 21:42:05 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	temp;

	n = 0;
	while (n < size / 2)
	{
		temp = tab[n];
		tab[n] = tab[size - 1 - n];
		tab[size - 1 - n] = temp;
		n++;
	}
}
