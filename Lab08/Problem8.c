#include <stdio.h>

void computeTotals(int (*marks)[3], int rows, int totals[]) {
    for (int r = 0; r < rows; r++) {
        int rowSum = 0;
        for (int c = 0; c < 3; c++) {
            rowSum = rowSum + *(*(marks + r) + c);
        }
        *(totals + r) = rowSum;
    }
}

int findTopper(const int *totals, int rows) {
    int maxIndex = 0;
    int maxTotal = *totals; 

    for (int i = 1; i < rows; i++) {
        if (*(totals + i) > maxTotal) {
            maxTotal = *(totals + i);
            maxIndex = i; 
        }
    }
    return maxIndex;
}

int main() {
    int marks[3][3];
    int totals[3] = {0}; 
    int rows = 3;

    for (int i = 0; i < rows; i++) {
        printf("Enter marks for Student %d (3 subjects): ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    computeTotals(marks, rows, totals);

    for (int i = 0; i < rows; i++) {
        printf("Total for Student %d: %d\n", i + 1, totals[i]);
    }

    int topperIndex = findTopper(totals, rows);

    printf("Student %d is the topper with total %d\n", topperIndex + 1, totals[topperIndex]);

    return 0;
}




