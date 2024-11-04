
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	check_upcols(char arr, char **arr)
{
	int	counter;
	int	highest;
	int	i;
	int	row;
	int	col;
	
	col = 0;
	while(col < 3)
	{
		i = 0;
		row = 0;
		counter = 1;
		highest = 1;
		while(row < 3)
		{
			if (arr[row + 1][col] > arr[row][col])
			{
				counter++;
				highest = arr[row + 1][col];
			}
			row++;
		}
		if (counter != arr[i])
			return (1);
		col++;
		i++;
	}
	return (0);
}

int	check_downcols(char arr, char **arr)
{
	int	counter;
	int	highest;
	int	i;
	int	row;
	int	col;
	
	col = 0;
	while(col < 3)
	{
		i = 4;
		row = 3;
		counter = 1;
		highest = 1;
		while(row > 0)
		{
			if (arr[row - 1][col] > arr[row][col])
			{
				counter++;
				highest = arr[row - 1][col];
			}
			row--;
		}
		if (counter != arr[i])
			return (2);
		col++;
		i++;
	}
	return (0);
}
int	check_leftrows(char arr, char **arr)
{
	int	counter;
	int	highest;
	int	i;
	int	row;
	int	col;
	
	row = 0;
	while(row < 3)
	{
		i = 8;
		col = 0;
		counter = 1;
		highest = 1;
		while(col < 3)
		{
			if (arr[row][col + 1] > arr[row][col])
			{
				counter++;
				highest = arr[row][col + 1];
			}
			col++;
		}
		if (counter != arr[i])
			return (3);
		row++;
	}
	return (0);
}

int	check_rightrows(char arr, char **arr)
{
	int	counter;
	int	highest;
	int	i;
	int	row;
	int	col;
	
	row = 0;
	while(row < 3)
	{
		i = 12;
		col = 3;
		counter = 1;
		highest = 1;
		while(col > 0)
		{
			if (arr[row][col - 1] > arr[row][col])
			{
				counter++;
				highest = arr[row][col - 1];
			}
			col--;
		}
		if (counter != arr[i])
			return (4);
		row++;
	}
	return (0);
}

int	check_grid(char arr, char **arr)
{
	if (check_upcols(arr, **arr) == 1)
		return (1);
	else if (check_downcols(arr, **arr) == 2)
		return (2);
	else if (check_leftrows(arr, **arr) == 3)
		return (3);
	else if (check_rightrows(arr, **arr))
		return (4);
	else
		return (0);
}
