#include <unistd.h>
#include <stdlib.h>

#define N 4

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int check_view(int *sequence, int clue) {
    int count = 0, max_height = 0;
    for (int i = 0; i < N; ++i) {
        if (sequence[i] > max_height) {
            max_height = sequence[i];
            ++count;
        }
    }
    return count == clue;
}

int check_columns(int **grid) {
    for (int col = 0; col < N; ++col) {
        int seen[N + 1] = {0};
        for (int row = 0; row < N; ++row) {
            if (seen[grid[row][col]]) {
                return 0;
            }
            seen[grid[row][col]] = 1;
        }
    }
    return 1;
}

void print_grid(int **grid) {
    char buffer[3]; // 2 digits and a space or newline
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            buffer[0] = '0' + grid[i][j];
            buffer[1] = ' ';
            buffer[2] = '\0';
            write(1, buffer, 2);
        }
        write(1, "\n", 1);
    }
}

int permute_and_check(int **grid, int row, int *clues, int start) {
    if (start == N) {
        if (row == 0 || check_columns(grid)) {
            if (check_view(grid[row], clues[2 * N + row]) && check_view(grid[row], clues[3 * N + row])) {
                if (row == N - 1 || permute_and_check(grid, row + 1, clues, 0)) {
                    return 1;
                }
            }
        }
        return 0;
    }

    for (int i = start; i < N; i++) {
        swap(&grid[row][start], &grid[row][i]);
        if (permute_and_check(grid, row, clues, start + 1)) {
            return 1;
        }
        //write(1, "rec", 3);
        swap(&grid[row][start], &grid[row][i]); // backtrack
    }

    return 0;
}

int main() {
    int *grid[N];
    for (int i = 0; i < N; i++) {
        grid[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = j + 1; // Initial population of grid
        }
    }

    int clues[] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2}; // top, bottom, left, right

    if (permute_and_check(grid, 0, clues, 0)) {
        print_grid(grid);
    } else {
        write(1, "No solution found.\n", 19);
    }

    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    return 0;
}
