/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:35:32 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/26 18:22:39 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	res = (int *)malloc(sizeof(int) * (max - min));
	if (!res)
		return (NULL);
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}

#include <stdio.h>
int	main(void)
{
	int *arr = ft_range(-2,11);
	// for (int i = 0; i < 11 - (-2); i++) {
        //     printf("%d ", arr[i]);
        // }
	while (*arr != '\0')
	{
		printf("%d", *arr);
		arr++;
	}
}