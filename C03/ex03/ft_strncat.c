/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:48:22 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/18 13:28:07 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

int main(void)
{
	char dest1[10] = "abc";
	char dest2[10] = "1234";
	char dest3[10] = "";
	
	printf("%s \n", ft_strncat(dest1, "def", 20));
	printf("%s \n", ft_strncat(dest2, "hello", 3));
	printf("%s \n", ft_strncat(dest3, "aabb", 8));
}