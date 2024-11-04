import itertools

def check_view(sequence, clue):
    count, max_height = 0, 0
    for height in sequence:
        if height > max_height:
            count += 1
            max_height = height
    return count == clue

def check_column_validity(grid, col):
    column = [grid[row][col] for row in range(len(grid))]
    return len(column) == len(set(column))

def permute_row(grid, row, clues):
    n = len(grid)
    if row == n:
        # If all rows are filled, check column validity
        #while(col < range):
        return all(check_column_validity(grid, col) for col in range(n))

    for perm in itertools.permutations(grid[row]):
        grid[row] = list(perm)
        # Check if the current row permutation matches the left and right clues
        if check_view(grid[row], clues[n * 2 + row]) and check_view(grid[row][::-1], clues[n * 3 + row]):
            # If valid, move to the next row
            if permute_row(grid, row + 1, clues):
                return True
    return False

def solve_skyscraper(n, clues):
    # Initialize grid with numbers 1 through n
    grid = [[1,2,3,4], [1,2,3,4], [1,2,3,4], [1,2,3,4]]
    # Start permutation from the first row
    if permute_row(grid, 0, clues):
        return grid
    return None

# Define the size of the grid and the clues
n = 4
clues = [3, 2, 1, 2, 1, 2, 3, 2, 2, 2, 4, 1, 2, 2, 1, 4]  # Top, Bottom, Left, Right clues

solution = solve_skyscraper(n, clues)
if solution:
    for row in solution:
        print(row)
else:
    print("No solution found.")
