/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:52:37 by nalijono          #+#    #+#             */
/*   Updated: 2024/03/10 15:54:56 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int rows, int cols);

int	main(void)
{
	rush(5, 5);
	rush(3, 1);
	rush(1, 1);
}
