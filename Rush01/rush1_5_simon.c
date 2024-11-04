#include <stdbool.h>
#include <stdio.h>

bool	check_view(int sequence[], int n, int clue)
{
	int	count;
	int	i;

	count = 0;
	int max_height = 0;
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

bool	check_column_validity(int grid[][4], int col, int row)
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
			{
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

void	swap(int array[], int i, int j)
{
	int	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

bool	permute_row(int grid[][4], int row, int clue_left, int clue_right,
			int start, int n, int clues[]);

bool	solve_skyscraper(int n, int clues[], int grid[][4])
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
		return (true);
	}
	return (false);
}

bool	permute_row(int grid[][4], int row, int clue_left, int clue_right,
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
			valid = true;
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
					return (true);
				}
			}
		}
		return (false);
	}
	for (int i = start; i < n; i++)
	{
		swap(grid[row], start, i);
		if (permute_row(grid, row, clue_left, clue_right, start + 1, n, clues))
		{
			return (true);
		}
		swap(grid[row], start, i);
	}
	return (false);
}

void convertToNumbers(const char *input, int *output, int maxOutputSize, int *numConverted) {
    int i = 0, number = 0;
    *numConverted = 0; // Number of integers converted

    // Iterate over each character in the string
    for (; input[i] != '\0' && *numConverted < maxOutputSize; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            // Convert character digit to integer and accumulate
            number = number * 10 + (input[i] - '0');
        } else if (number > 0 || input[i] == ' ') {
            // Number is completed, save it
            output[(*numConverted)++] = number;
            number = 0; // Reset number for the next iteration
        }
        // If the character is not a digit or space, you can handle it as an error or ignore
    }

    // Catch any number that might be at the end of the string
    if (number != 0 && *numConverted < maxOutputSize) {
        output[(*numConverted)++] = number;
    }
}

int	main(void)
{
	int		n;
	int		grid[4][4];
	bool	solution;
	int		i;
	int		j;
	const char input[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int clues[16];
	int numClues;

    	convertToNumbers(input, clues, 16, &numClues);

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



