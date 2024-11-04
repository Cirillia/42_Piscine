/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:42:59 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/24 10:55:26 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_sqrt(int nb)
{
	int	root;

	root = 1;
	if (nb > 0)
	{
		while (root * root <= nb)
		{
			if (root * root == nb)
			{
				return (root);
			}
			root++;
		}
	}
	return (0);	
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_sqrt(46341));
}