#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	check_columns(int rows_checked, int **grid)
{
	// this function will check if the columns contain repeating values
	// it uses rows_checked param to check only rows we have assigned permutations
	int	list[4];
	int	i;
	int	col;
	int	k;
	
	i = 0;
	while (i < rows_checked)
	{
		col = 0;
		while (col < 4)
		{
			k = 0;
			while (k < i)
			{
				if (list[k] == grid[i][col])
					return (1);
				k++;
			}
			list[col] = grid[i][col];
			col++;
		}
		i++;
	}
	return (0);
}

int	check_leftrows(char clue, int *arr)
{
	int	counter;
	int	highest;
	int	col;
	
	col = 0;
	counter = 1;
	highest = 1;
	while(col < 3)
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
	while(col > 0)
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

