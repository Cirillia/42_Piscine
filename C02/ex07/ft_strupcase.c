/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:29:17 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/13 20:57:20 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
    char str1[] = "hello world";
    char str2[] = "Hello, World!";
    char str3[] = "1234!@#$";

    printf("Original: %s, Uppercase: %s\n", str1, ft_strupcase(str1));
    printf("Original: %s, Uppercase: %s\n", str2, ft_strupcase(str2));
    printf("Original: %s, Uppercase: %s\n", str3, ft_strupcase(str3));
}
