/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:19:47 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/21 23:31:45 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	return (i > 1);
}

void	ft_putnb(int nb, char *base, int base_len)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnb(-(nb / base_len), base, base_len);
		ft_putchar(base[-(nb % base_len)]);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnb(nb, base, base_len);
	}
	else
	{
		if (nb >= base_len)
			ft_putnb(nb / base_len, base, base_len);
		ft_putchar(base[nb % base_len]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	if (check_base(base) == 1)
	{
		while (base[base_len])
			base_len++;
		ft_putnb(nbr, base, base_len);
	}
}

int	main(void)
{
	int n = 15;
	char *base = "0123456789abcdef";
	ft_putnbr_base(n, base);
}