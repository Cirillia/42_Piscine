#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_grid(int **arr)
{
	int		i;
	int		j;
	char	digit;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			digit = arr[i][j] + '0';
			write(1, &digit, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	**allocate_grid(void)
{
	int	i;
	int	**grid;

	grid = malloc(sizeof(int *) * 4);
	if (!grid)
		return (0);
	i = 0;
	while (i < 4)
	{
		grid[i] = malloc(sizeof(int) * 4);
		if (!grid[i])
			return (0);
		i++;
	}
	return (grid);
}

void	free_grid_mem(int **grid)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		free(grid[j]);
		j++;
	}
	free(grid);
}

int	**initialise_grid(int **grid)
{
	int	row;
	int	col;
	int	value;

	row = 0;
	while (row < 4)
	{
		col = 0;
		value = 1;
		while (col < 4)
		{
			grid[row][col] = value;
			value++;
			col++;
		}
		row++;
	}
	return (grid);
}

int main()
{
	int **grid;

	grid = allocate_grid();
	initialise_grid(grid);
	print_grid(grid);
	free_grid_mem(grid);
	return 0;
}

