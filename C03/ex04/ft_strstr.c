/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:44:29 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/19 19:14:02 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;
	
		i = 0;
		if (to_find[0] == '\0')
			return (str);
		while (str[i] != '\0')
		{
			n = 0;
			while (str[i + n] == to_find[n])
			{
				if (to_find[n + 1] == '\0')
				{
					return (str + i);
				}
				n++;
			}
			i++;
		}
		return (0);
	}


int main(void)
{
	char s[] = "ababcedffa";
	char aim[] = "abc";

	printf("%s", ft_strstr(s, aim));
}