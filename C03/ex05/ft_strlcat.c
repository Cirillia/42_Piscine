/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:48:22 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/18 22:26:03 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dl;
	unsigned int	sl;
	unsigned int	i;

	dl = 0;
	sl = 0;
	i = 0;
	while (dest[dl] != '\0')
	{
		dl++;
	}
	while (src[sl] != '\0')
	{
		sl++;
	}
	while (src[i] != '\0' && (dl + i) < size - 1)
	{
		dest[dl + i] = src[i];
		i++;
	}
	if (size <= dl)
		return (sl + size);
	dest[dl + i] = '\0';
	return (sl + dl);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest1[] = "12345";
	char	*dest2;
	char	src1[] = "hello";
	char	*src2;

	dest2 = "12345";
	src2 = "hello";
	printf("%s %d \n", dest2, strlcat(dest2, src2, 7));
	printf("%s %d \n", dest1, ft_strlcat(dest1, src1, 7));
}
