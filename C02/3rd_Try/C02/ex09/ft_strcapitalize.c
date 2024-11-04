/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:06:12 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/14 19:25:43 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		new1;
	char	c;

	new1 = 1;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (new1 == 1 && c >= 'a' && c <= 'z')
			str[i] = str[i] - 32;
		else if (new1 == 0 && 'A' <= c && c <= 'Z')
			str[i] = str[i] + 32;
		if (c < '0' || ('9' < c && c < 'A')
			|| ('Z' < c && c < 'a') || 'z' < c)
			new1 = 1;
		else
			new1 = 0;
		i++;
	}
	return (str);
}
