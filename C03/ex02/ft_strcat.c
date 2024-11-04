/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:39:29 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/18 12:39:06 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char dest1[10] = "abc";
	char dest2[10] = "1234";
	char dest3[5] = "";
	printf("%s \n", ft_strcat(dest1, "def"));
	printf("%s \n", ft_strcat(dest2, "hello"));
	printf("%s \n", ft_strcat(dest3, "aabb"));
}