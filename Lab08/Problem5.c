#include <stdio.h>

void printGrid(int (*grid)[5]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int neighborRow = row + i;
            int neighborCol = col + j;

            if (neighborRow >= 0 && neighborRow < 5 && neighborCol >= 0 && neighborCol < 5) {
                count = count + (grid[neighborRow][neighborCol] & 1);
            }
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            int liveneighbors = countNeighbours(grid, r, c);
            int isAliveNow = grid[r][c] & 1;
            int livesnextgen = 0;

            if (isAliveNow) {
                if (liveneighbors == 2 || liveneighbors == 3) {
                    livesnextgen = 1;
                }
            } else {
                if (liveneighbors == 3) {
                    livesnextgen = 1;
                }
            }

            if (livesnextgen) {
                grid[r][c] |= 2; 
            }
        }
    }

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            grid[r][c] >>= 1;
        }
    }
}

int main() {
    int grid[5][5] = {0};

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    int generations;

    do{
        
        printf("Enter number of generations (0-50): ");
        scanf("%d", &generations);

        if (generations < 0 && generations > 50) {
            printf("Invalid number\n");
        }
    } while(generations<0||generations>50);

    printf("Generation 0:\n");
    printGrid(grid);

    for (int g = 1; g <= generations; g++) {
        nextGeneration(grid);
        printf("Generation %d:\n", g);
        printGrid(grid);
    }

    return 0;
}