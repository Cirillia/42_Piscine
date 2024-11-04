/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush1_pass.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruwang <ruwang@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:17:03 by ruwang            #+#    #+#             */
/*   Updated: 2024/03/17 21:45:11 by ruwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

int	check_view(int sequence[], int n, int clue)
{
	int	count;
	int	i;
	int	max_height;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < n)
	{
		if (sequence[i] > max_height)
		{
			count++;
			max_height = sequence[i];
		}
		i++;
	}
	return (count == clue);
}

int	check_column_validity(int grid[][4], int col, int row)
{
	int	column[4];
	int	r;
	int	i;
	int	j;

	r = 0;
	while (r <= row)
	{
		column[r] = grid[r][col];
		r++;
	}
	i = 0;
	while (i <= row)
	{
		j = i + 1;
		while (j <= row)
		{
			if (column[i] == column[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	swap(int array[], int i, int j)
{
	int	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int	permute_row(int grid[][4], int row, int clue_left, int clue_right,
		int start, int n, int clues[])
{
	int		reversed[4];
	bool	valid;

	if (start == n)
	{
		for (int i = 0; i < n; i++)
		{
			reversed[i] = grid[row][n - 1 - i];
		}
		if (check_view(grid[row], n, clue_left) && check_view(reversed, n,
				clue_right))
		{
			valid = 1;
			for (int col = 0; col < n; col++)
			{
				if (!check_column_validity(grid, col, row))
				{
					valid = false;
					break ;
				}
			}
			if (valid)
			{
				if (row == n - 1 || permute_row(grid, row + 1, clues[n * 2 + row
					+ 1], clues[n * 3 + row + 1], 0, n, clues))
				{
					return (1);
				}
			}
		}
		return (0);
	}
	for (int i = start; i < n; i++)
	{
		swap(grid[row], start, i);
		if (permute_row(grid, row, clue_left, clue_right, start + 1, n, clues))
		{
			return (1);
		}
		swap(grid[row], start, i);
	}
	return (0);
}

int	solve_skyscraper(int n, int clues[], int grid[][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			grid[i][j] = j + 1;
			j++;
		}
		i++;
	}
	if (permute_row(grid, 0, clues[n * 2], clues[n * 3], 0, n, clues))
	{
		return (1);
	}
	return (0);
}

void convert_numbers(const char *input, int *output, int max_size, int *num_Cvt) {
	int i = 0, number = 0;
	*num_Cvt = 0; 

   	for (; input[i] != '\0' && *num_Cvt < max_size; i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			number = number * 10 + (input[i] - '0');
		} else if (number > 0 || input[i] == ' ') {
			output[(*num_Cvt)++] = number;
			number = 0; 
        	}
    	}

	if (number != 0 && *num_Cvt < max_size) {
		output[(*num_Cvt)++] = number;
	}
}

int	main(int argc, char **argv)
{
	int		n;
	int		grid[4][4];
	bool	solution;
	int		i;
	int		j;
	char	*input = argv[1];
	int clues[16];
	int num_clues;
	
	if (argc < 2)
		return (1);
	convert_numbers(input, clues, 16, &num_clues);
	n = 4;
	solution = solve_skyscraper(n, clues, grid);
	if (solution)
	{
		i = 0;
		while (i < n)
		{
			j = 0;
			while (j < n)
			{
				printf("%d ", grid[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
	else
	{
		printf("No solution found.\n");
	}
	return (0);
}
