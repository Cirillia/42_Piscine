#include <stdio.h>
#include <stdlib.h>

void print_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_view(int *sequence, int size, int clue) {
    int count = 0, max_height = 0;
    for (int i = 0; i < size; i++) {
        if (sequence[i] > max_height) {
            count++;
            max_height = sequence[i];
        }
    }
    return count == clue;
}

int check_column_validity(int **grid, int col, int row, int n) {
    for (int i = 0; i <= row; i++) {
        for (int j = i + 1; j <= row; j++) {
            if (grid[i][col] == grid[j][col]) {
                return 0;  // Duplicate found
            }
        }
    }
    return 1;  // No duplicates
}

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int permute_row(int **grid, int row, int clue_left, int clue_right, int start, int n, int *clues) {
    if (start == n) {
        if (check_view(grid[row], n, clue_left) && check_view(grid[row], n, clue_right)) {
            for (int col = 0; col < n; col++) {
                if (!check_column_validity(grid, col, row, n)) {
                    return 0;
                }
            }
            if (row == n - 1 || permute_row(grid, row + 1, clues[n * 2 + row + 1], clues[n * 3 + row + 1], 0, n, clues)) {
                return 1;
            }
        }
        return 0;
    }

    for (int i = start; i < n; i++) {
        swap(grid[row], start, i);
        printf("After swapping elements at indices %d and %d in row %d:\n", start, i, row);
        print_grid(grid, n);
        if (permute_row(grid, row, clue_left, clue_right, start + 1, n, clues)) {
            return 1;
        }
        swap(grid[row], start, i);  // backtrack
    }
    return 0;
}

int **solve_skyscraper(int n, int *clues) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = j + 1;
        }
    }

    if (permute_row(grid, 0, clues[n * 2], clues[n * 3], 0, n, clues)) {
        return grid;
    } else {
        for (int i = 0; i < n; i++) {
            free(grid[i]);
        }
        free(grid);
        return NULL;
    }
}

int main() {
    int n = 4;
    int clues[] = {3, 2, 1, 2, 2, 2, 4, 1, 2, 2, 1, 4, 1, 2, 3, 2};  // Top, Bottom, Left, Right clues

    int **solution = solve_skyscraper(n, clues);
    if (solution) {
        printf("Solution found:\n");
        print_grid(solution, n);
        for (int i = 0; i < n; i++) {
            free(solution[i]);
        }
        free(solution);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
