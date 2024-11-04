/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:06:12 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/14 21:11:42 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int 	i;
	char	c;
	int 	new1;

	i = 0; 
	new1 = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (new1 == 1 && c >= 'a' && c <= 'z')
		{
			str[i] = str[i] - 32;
		}
		else if (new1 = 0, 'A' <= str[i] && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		
		if (c < '0' || '9' < c && c < 'A' || 'Z' < c && c < 'a' || 'z' < c)
		{
			new1 = 1;
		}
		else
		{
			new1 = 0;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
    char str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    printf("%s\n", ft_strcapitalize(str1));
}
