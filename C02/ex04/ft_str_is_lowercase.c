/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:47:28 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/13 13:06:54 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	char	*str1 = "Hello!";
	char	*str2 = "hello world";
	char	*str3 = "123Hello";
	char	*str4 = "12345";
	char	*str5 = "";

	if (ft_str_is_lowercase(str1)) 
	{
		printf("'%s' 1 \n", str1);
	} 
	else 
	{
		printf("'%s' 0 \n", str1);
	}
}
