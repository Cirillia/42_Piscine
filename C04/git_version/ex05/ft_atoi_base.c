/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:05 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/21 22:34:49 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	parse_sign_and_whitespace(char *str, int *symbol)
{
	int	i;

	i = 0;
	*symbol = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*symbol *= -1;
		i++;
	}
	return (i);
}

int	convert_to_base(char *str, char *base, int i, int symbol)
{
	int	val;
	int	res;
	int	base_len;

	val = 0;
	res = 0;
	base_len = check_base(base);
	if (!base_len)
		return (0);
	val = get_value(str[i], base);
	while (val != -1)
	{
		res = res * base_len + val;
		i++;
		val = get_value(str[i], base);
	}
	return (res * symbol);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	symbol;
	int	res;

	if (!check_base(base))
		return (0);
	i = parse_sign_and_whitespace(str, &symbol);
	res = convert_to_base(str, base, i, symbol);
	return (res);
}
