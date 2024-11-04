/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:40:50 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/14 20:56:52 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
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
	char	*str1 = "Hello";
	char	*str2 = "Hello World!";
	char	*str3 = "123Hello";
	char	*str4 = "12345";
	char	*str5 = "";

	if (ft_str_is_numeric(str1)) 
	{
		printf("'%s' 1 \n", str1);
	} 
	else 
	{
		printf("'%s' 0 \n", str1);
	}
}
