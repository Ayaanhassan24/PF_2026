#include <stdio.h>

int isValidMark(int m) {
    if (m >= 0 && m <= 100) {
        return 1;
    }
    return 0;
}

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i]; 
        }
        if (arr[i] > *max) {
            *max = arr[i]; 
        }
    }
}

int main() {
    int marks[5];
    int size = 5;
    int lowest, highest;

    for (int i = 0; i < size; i++) {
        int check=0;
        do{
            printf("Enter mark %d: ", i + 1);
            scanf("%d", &marks[i]);

            if (isValidMark(marks[i])) {
                check=1;
            } else {
                printf("Invalid mark, enter again\n");
                check=0;
            }
        }while(check==0);
    }

    findMinMax(marks, size, &lowest, &highest);

    printf("Lowest mark: %d\n", lowest);
    printf("Highest mark: %d\n", highest);

    return 0;
}