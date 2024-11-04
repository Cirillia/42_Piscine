/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:55:30 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/17 23:04:53 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_columns(int rows_checked, int **grid) {
    int list[4];
    int i, col, k;

    for (col = 0; col < 4; col++) {
        // Initialize list with invalid grid values (assuming grid values are positive)
        for (i = 0; i < 4; i++) {
            list[i] = -1;
        }

        for (i = 0; i < rows_checked; i++) {
            for (k = 0; k < 4; k++) {
                // Check if the current grid value is already in the list
                if (list[k] == grid[i][col]) {
                    return 1;  // Duplicate found
                }
                // If list[k] is an uninitialized slot, use it to store the current grid value
                if (list[k] == -1) {
                    list[k] = grid[i][col];
                    break;
                }
            }
        }
    }
    return 0;  // No duplicates found
}

int	check_leftrows(char clue, int *arr)
{
	int	counter;
	int	highest;
	int	col;

	col = 0;
	counter = 1;
	highest = 1;
	while (col < 3)
	{
		if (arr[col + 1] > arr[col])
		{
			counter++;
			highest = arr[col + 1];
		}
		col++;
	}
	if (counter != (clue - '0'))
		return (1);
	return (0);
}

int	check_rightrows(char clue, int *arr)
{
	int	counter;
	int	highest;
	int	col;

	col = 3;
	counter = 1;
	highest = 1;
	while (col > 0)
	{
		if (arr[col - 1] > arr[col])
		{
			counter++;
			highest = arr[col - 1];
		}
		col--;
	}
	if (counter != (clue - '0'))
		return (1);
	return (0);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	permute_row(int *row, int clue, int start, char *clues)
{
	int	i;
	int	end;

	end = 3;
	if (start == end)
		return (1);
	if (check_leftrows(clues[clue], row)
		&& check_rightrows(clues[clue + 8], row))
		return (0);
	i = start;
	while (i < end)
	{
		swap(&row[start], &row[i]);
		permute_row(row, clue, start + 1, clues);
		swap(&row[start], &row[i]);
		i++;
	}
	return (1);
}
