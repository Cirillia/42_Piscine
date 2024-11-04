/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:45:55 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/18 13:50:50 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	char org[] = "Hello World!";
	char str2[10];

	ft_strncpy(str2, org, 1);
	printf("%s \n", str2);

	char org1[] = "Hello World!";
	char str1[10];

	strncpy(str1, org1, 1);
	printf("%s \n", str1);
}
