#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*int assign_certain_values()
{

}*/

int     check_columns(int rows_checked, int **grid);

int	check_leftrows(char clue, int *arr);

int	check_rightrows(char clue, int *arr);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

int **allocate_grid()
{
	int	**grid;
	int	i;
		
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
	return grid;
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


void	swap(int *a, int *b) 
{
	int	temp = *a;
	*a = *b;
	*b = temp;
}

int	permute_row(int *row, int clue, int start, char *clues)
{
	int 	i;
	int	end;
	
	end = 3;
	if (start == end) 
		return (1);
	if (check_leftrows(clues[clue], row) && 
		check_rightrows(clues[clue + 8], row))
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

int main(int argc, char **argv)
{
	int 	**grid;
	int	row;
	char	clues[32];
	char	clue;

	ft_strcpy(clues, argv[1]);
	if (argc > 2)
		return (1);

	grid = allocate_grid();
	
	if (!grid) {
    		fprintf(stderr, "Failed to allocate memory for the grid.\n");
	   	return 1;
	}
	initialise_grid(grid);

	row = 0;
	while (row < 4)
	{
		clue = 16 + (2 *row);
		if (permute_row(grid[row], clue, 0, clues) == 0 &&
		check_columns(row, grid) == 0)
		{
			row++;
			permute_row(grid[row], clue, 0, clues);
		}
		else
		{
			row--;
			permute_row(grid[row], clue, 0, clues);
		}
	}
	print_grid(grid);
	free_grid_mem(grid);

} 

