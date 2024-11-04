/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:45 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/21 21:33:55 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] == s2[n] && s1[n] != '\0')
	{
		n++;
	}
	if (s1[n] == s2[n])
		return (0);
	else
		return (s1[n] - s2[n]);
}

int	main(void)
{
	printf("%d", ft_strcmp("1nbfasdf","5"));
	printf("%d", ft_strcmp("1","5"));
	printf("%d", ft_strcmp("aaa","aaabbcc"));
}
