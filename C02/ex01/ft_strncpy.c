/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:45:55 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/18 20:59:36 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

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

#include <string.h>
int main(void)
{
	char *org3 = "Hello World!";
	char str3[5];
	char *org1 = "Hello World!";
	char str1[5];
	char safe[100];


	strncpy(str3, org3, 9);
	printf("%s \n", str3);

	*ft_strncpy(str1, org1, 9);
	printf("%s \n", str1);


}
