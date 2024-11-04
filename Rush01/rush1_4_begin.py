def check_view(buildings, view):
    max_height = 0
    visible_count = 0
    for height in buildings:
        if height > max_height:
            visible_count += 1
            max_height = height
    return visible_count == view

def is_valid_solution(grid, clues):
    n = len(grid)

    # 检查行的视线条件
    for i in range(n):
        # 检查左边视线
        if clues[8 + i] != 0 and not check_view(grid[i], clues[8 + i]):
            return False
        # 检查右边视线
        if clues[12 + i] != 0 and not check_view(grid[i][::-1], clues[12 + i]):
            return False

    # 检查列的视线条件
    for i in range(n):
        col = [grid[j][i] for j in range(n)]
        # 检查上边视线
        if clues[i] != 0 and not check_view(col, clues[i]):
            return False
        # 检查下边视线
        if clues[4 + i] != 0 and not check_view(col[::-1], clues[4 + i]):
            return False

    return True

def solve_skyscraper(grid, clues, row=0):
    n = len(grid)

    if row == n:
        # 所有行都满足条件，检查列是否有重复数字
        if any(len(set(grid[row][col] for row in range(n))) != n for col in range(n)):
            return False
        return is_valid_solution(grid, clues)

    for i in range(n):
        for j in range(i + 1, n):
            grid[row][i], grid[row][j] = grid[row][j], grid[row][i]
            if is_valid_solution(grid, clues) and solve_skyscraper(grid, clues, row + 1):
                return True
            grid[row][i], grid[row][j] = grid[row][j], grid[row][i]  # 回溯

    return False

# 初始化网格和线索
grid = [[1, 2, 3, 4] for _ in range(4)]
clues = [3, 2, 1, 2, 1, 2, 3, 2, 2, 2, 4, 1, 2, 2, 1, 4]  # 使用提供的线索

if solve_skyscraper(grid, clues):
    solution = grid
else:
    solution = "No solution found."

solution
