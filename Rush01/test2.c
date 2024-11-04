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
			if (arr[col + 1] > highest)
			{
				counter++;
				highest = arr[col + 1];
			}
		}
		col++;
	}
	if (counter != (clue - '0'))
		return (1);
	return (0);
}

int main(){
	
}