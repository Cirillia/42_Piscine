def check_view(sequence, clue):
    count, max_height = 0, 0
    for height in sequence:
        if height > max_height:
            count += 1
            max_height = height
    return count == clue

def check_column_validity(grid, col, row):
    column = [grid[r][col] for r in range(row + 1)]
    return len(column) == len(set(column))

def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

def permute_row(grid, row, clue_left, clue_right, start, n):
    if start == n:
        if check_view(grid[row], clue_left) and check_view(grid[row][::-1], clue_right):
            if all(check_column_validity(grid, col, row) for col in range(n)):
                if row == n - 1 or permute_row(grid, row + 1, clues[n * 2 + row + 1], clues[n * 3 + row + 1], 0, n):
                    return True
        return False

    for i in range(start, n):
        swap(grid[row], start, i)
        if permute_row(grid, row, clue_left, clue_right, start + 1, n):
            return True
        swap(grid[row], start, i)  # backtrack
    return False

def solve_skyscraper(n, clues):
    grid = [list(range(1, n + 1)) for _ in range(n)]  # Initialize grid
    if permute_row(grid, 0, clues[n * 2], clues[n * 3], 0, n):
        return grid
    return None

# Define the size of the grid and the clues
n = 4
clues = [3, 2, 1, 2, 2, 2, 4, 1, 2, 2, 1, 4, 1, 2, 3, 2]  # Top, Bottom, Left, Right clues

solution = solve_skyscraper(n, clues)
if solution:
    for row in solution:
        print(row)
else:
    print("No solution found.")
