#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define N 4

int grid[N][N] = {0};
int clues[4 * N];

int checkClues(int position, int value, int grid[N][N]);
int solve(int grid[N][N], int position);
void printGrid(int grid[N][N]);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    // Parse input
    char *token = strtok(argv[1], " ");
    for (int i = 0; i < 4 * N && token != NULL; i++) {
        clues[i] = atoi(token);
        token = strtok(NULL, " ");
        if (clues[i] < 1 || clues[i] > N) {
            printf("Error\n");
            return 1;
        }
    }

    if (solve(grid, 0)) {
        printGrid(grid);
    } else {
        printf("Error\n");
    }

    return 0;
}

int checkClues(int position, int value, int grid[N][N]) {
    int row = position / N;
    int col = position % N;

    // Check against the clues (to be implemented)
    // You need to implement this function to check if placing 'value' at grid[row][col]
    // complies with the clues. You need to check the clues for the current row and column.

    return 1; // Return 1 if the placement is valid according to the clues, otherwise 0
}

int solve(int grid[N][N], int position) {
    if (position == N * N) {
        return 1; // Puzzle solved
    }

    int row = position / N;
    int col = position % N;

    for (int num = 1; num <= N; num++) {
        if (checkClues(position, num, grid)) {
            grid[row][col] = num;
            if (solve(grid, position + 1)) {
                return 1;
            }
            grid[row][col] = 0; // Backtrack
        }
    }

    return 0; // Trigger backtracking
}

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
