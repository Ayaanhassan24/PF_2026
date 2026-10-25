#include <stdio.h>

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int isEven(int x) {
    return x % 2 == 0;
}

int isPositive(int x) {
    return x > 0;
}

void applyToArray(int *arr, int n, int (*fn)(int)) {
    for (int i = 0; i < n; i++) {
        *(arr + i) = fn(*(arr + i));
    }
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pred(*(arr + i))) {
            count++;
        }
    }
    return count;
}

void printGeneric(void *data, char type, int n) {
    if (type == 'i') {
        int *intPtr = (int *)data;
        for (int i = 0; i < n; i++) {
            printf("%d ", *(intPtr + i));
        }
        printf("\n");
    } 
    else if (type == 'f') {
        float *floatPtr = (float *)data;
        for (int i = 0; i < n; i++) {
            printf("%.2f ", *(floatPtr + i));
        }
        printf("\n");
    } 
    else if (type == 'c') {
        char *charPtr = (char *)data;
        for (int i = 0; i < n; i++) {
            printf("%c ", *(charPtr + i));
        }
        printf("\n");
    } 
    else {
        printf("Invalid type '%c' for printGeneric\n", type);
    }
}


int main() {
    int arr[] = {3, -2, 8, -5, 6};
    int n;

    do {
        printf("Enter n (1-50): ");
        scanf("%d", &n);
    }while(n<1||n>50);

    printf("Original: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, negate);
    printf("After negate: ");
    printGeneric(arr, 'i', n);

    int posCount = countIf(arr, n, isPositive);
    printf("Positive values after negate: %d\n", posCount);

    int evenCount = countIf(arr, n, isEven);
    printf("Even values after negate: %d\n", evenCount);

    float floatArr[] = {1.50, 2.25};
    printf("Float print (type f): ");
    printGeneric(floatArr, 'f', 2);

    printGeneric(arr, 'x', n);

    return 0;
}
