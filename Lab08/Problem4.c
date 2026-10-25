#include <stdio.h>

float averageSteps(int *steps, int n) {
    float sum = 0.0; 

    for (int i = 0; i < n; i++) {
        sum = sum + *(steps + i); 
    }
    return sum / n;
}

int countGoalDays(int *steps, int n, int goal) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (*(steps + i) >= goal) { 
            count++;
        }
    }
    return count;
}

int main() {
    int steps[7];
    int days = 7;
    int goal = 8000;

    for (int i = 0; i < days; i++) {
        printf("Enter steps for day %d: ", i + 1);
        scanf("%d", &steps[i]);
    }

    float avg = averageSteps(steps, days);
    int count = countGoalDays(steps, days, goal);

    printf("Average steps: %.2f\n", avg);
    printf("Days goal reached (%d or more): %d\n", goal, count);

    return 0;
}
