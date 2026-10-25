#include <stdio.h>

void swapValues(int *p1, int *p2) {
    int temp; 

    temp = *p1; 
    *p1 = *p2;  
    *p2 = temp; 
}

int main() {
    int priceA, priceB;

    printf("Enter price A: ");
    scanf("%d", &priceA);
    printf("Enter price B: ");
    scanf("%d", &priceB);

    printf("Before swap: A = %d, B = %d\n", priceA, priceB);

    swapValues(&priceA, &priceB);

    printf("After swap: A = %d, B = %d\n", priceA, priceB);

    return 0;
}
