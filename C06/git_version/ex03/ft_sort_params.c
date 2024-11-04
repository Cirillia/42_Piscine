/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:45:20 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/24 17:56:34 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	j = 1;
	while (j < argc)
	{
		i = 1;
		while (i + 1 < argc)
		{
			if (ft_strcmp (argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	ft_print_params(argc, argv);
}
