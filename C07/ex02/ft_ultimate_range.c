/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:39:14 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/27 12:44:46 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*res;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	res = (int *)malloc(sizeof(int) * (max - min));
	if (!res)
		return (0);
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	*range = res;
	return (i);
}

#include <stdio.h>
int	main(void)
{
	int **range;
	int *arr = ft_ultimate_range(*range,-2,11);
	// for (int i = 0; i < 11 - (-2); i++) {
        //     printf("%d ", arr[i]);
        // }
	while (*arr != '\0')
	{
		printf("%d", *arr);
		arr++;
	}
}