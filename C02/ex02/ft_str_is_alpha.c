/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:24:40 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/14 20:53:38 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z' || 'A' <= str[i] && str[i] <= 'Z')
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
	char	*str1 = "HelloWorld";
	char	*str2 = "Hello World!";
	char	*str3 = "abcXYZ";
	char	*str4 = "12345";
	char	*str5 = "";

	if (ft_str_is_alpha(str1)) 
	{
		printf("'%s' 1 \n", str1);
	} 
	else 
	{
		printf("'%s' 0 \n", str1);
	}
}
