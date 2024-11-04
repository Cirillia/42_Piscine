/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:29:17 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/13 21:02:01 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
    char str1[] = "HELLO WORLD";
    char str2[] = "Hello, World!";
    char str3[] = "1234!@#$CCccCC";

    printf("Original: %s, Lowercase: %s\n", str1, ft_strlowcase(str1));
    printf("Original: %s, Lowercase: %s\n", str2, ft_strlowcase(str2));
    printf("Original: %s, Lowercase: %s\n", str3, ft_strlowcase(str3));
}
