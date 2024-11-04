/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:48:22 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/18 20:27:19 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dl;
	unsigned int	sl;
	unsigned int	i;

	dl = 0;
	sl = 0;
	i = 0;
	while (dest[dl] != '\0')
	{
		dl++;
	}
	while (src[sl] != '\0')
	{
		sl++;
	}
	if (size <= dl)
		return (sl + size);
	while (src[i] != '\0' && (dl + i) < size - 1)
	{
		dest[dl + i] = src[i];
		i++;
	}
	dest[dl + i] = '\0';
	return (sl + dl);
}
