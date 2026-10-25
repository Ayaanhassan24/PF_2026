#include <stdio.h>

int add(int a, int b, int *result) {
    *result = a + b;
    return 1;
}

int subtract(int a, int b, int *result) {
    *result = a - b;
    return 1;
}

int multiply(int a, int b, int *result) {
    *result = a * b;
    return 1;
}

int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0; 
    }
    *result = a / b;
    return 1; 
}

int main() {
    int (*ops[])(int, int, int *) = {add, subtract, multiply, divide};

    const char *opNames[] = {"Add", "Subtract", "Multiply", "Divide"};

    int choice;
    int a, b, answer;

    do {
        printf("Choice (1-5): ");
        scanf("%d",&choice);
        if(choice<1||choice>5){
            printf("Invalid choice\n");
        }

        if (choice == 5) {
            printf("Goodbye.\n");
            break;
        }

        printf("Enter a and b: ");
        scanf("%d %d", &a, &b);

        int index = choice - 1;

        if (ops[index](a, b, &answer)) {
            printf("%s result: %d\n", opNames[index], answer);
        } else {
            printf("Error: division by zero\n");
        }

    } while (choice != 5);

    return 0;
}








