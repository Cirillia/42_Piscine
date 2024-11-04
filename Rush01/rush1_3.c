#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check_view(int *sequence, int clue) {
    int count = 0, max_height = 0;
    for (int i = 0; i < clue; i++) {
        int height = sequence[i];
        if (height > max_height) {
            count += 1;
            max_height = height;
        }
    }
    return count == clue;
}

bool check_column_validity(int **grid, int col, int row) {
    int *column = malloc((row + 1) * sizeof(int));
    for (int r = 0; r <= row; r++) {
        column[r] = grid[r][col];
    }
    bool validity = true;
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j <= row; j++) {
            if (column[i] == column[j]) {
                validity = false;
                break;
            }
        }
        if (!validity) {
            break;
        }
    }
    free(column);
    return validity;
}

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

bool permute_row(int **grid, int row, int clue_left, int clue_right, int start, int n, int *clues) {
    if (start == n) {
        if (check_view(grid[row], clue_left) && check_view(grid[row][3], clue_right)) {
            bool validity = true;
            for (int col = 0; col < n; col++) {
                if (!check_column_validity(grid, col, row)) {
                    validity = false;
                    break;
                }
            }
            if (row == n - 1 || permute_row(grid, row + 1, clues[n * 2 + row + 1], clues[n * 3 + row + 1], 0, n, clues)) {
                return true;
            }
        }
        return false;
    }
    for (int i = start; i < n; i++) {
        swap(grid[row], start, i);
        if (permute_row(grid, row, clue_left, clue_right, start + 1, n, clues)) {
            return true;
        }
        swap(grid[row], start, i);
    }
    return false;
}

int **solve_skyscraper(int n, int *clues) {
    int **grid = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = j + 1;
        }
    }
    if (permute_row(grid, 0, clues[n * 2], clues[n * 3], 0, n, clues)) {
        return grid;
    }
    return NULL;
}

int main() {
    int n = 4;
    int clues[] = {3, 2, 1, 2, 2, 2, 4, 1, 2, 2, 1, 4, 1, 2, 3, 2};
    int **solution = solve_skyscraper(n, clues);
    if (solution) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", solution[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
    return 0;
}

