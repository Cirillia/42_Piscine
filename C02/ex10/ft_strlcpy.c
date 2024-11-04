/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:00:13 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/14 21:13:52 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int	count;

	i = 0;
	count = 0;
	while (src[count])
	{
		count++;		
	}

	if (size < 1)
	{
		return (count);
	}

	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

int main(void)
{
	char org[] = "Hello World";
	char str2[15];
	//ft_strlcpy(str2, org, 9);
	printf("%d \n", ft_strlcpy(str2, org, 10));
	printf("%s \n", str2);
}
