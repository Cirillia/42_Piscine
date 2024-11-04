#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*int assign_certain_values()
{

}*/

void	print_grid(int **arr)
{
	int	i;
	int	j;
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

int **initialise_grid()
{
	int	**grid;
	int	i;
	int	j;
	int	row;
	int	col;
	int	value;

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
	print_grid(grid);
	return grid;

	j = 0;
	while (j < 4)
	{
		free(grid[j]);
		j++;
	}
	free(grid);
}

void	check_grid(char arr, char **arr1)
{
	int	counter;
	int	highest;
	int	i;
	int	row;
	int	col;
	
	i = 0;
	
}

int	main(void)
{
	initialise_grid();
}
