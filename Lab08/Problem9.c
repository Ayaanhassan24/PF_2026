#include <stdio.h>

int sumShelf(const int *shelf, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum = sum + *(shelf + i);
    }
    return sum;
}

int findLargestShelf(const int *counts, int shelves_count) {
    int maxIndex = 0;
    int maxBooks = *counts; 

    for (int i = 1; i < shelves_count; i++) {
        if (*(counts + i) > maxBooks) {
            maxBooks = *(counts + i);
            maxIndex = i; 
        }
    }
    return maxIndex;
}
int main() {
    
    int shelfA[] = {101, 102, 103};      
    int shelfB[] = {201, 202};          
    int shelfC[] = {301, 302, 303, 304}; 

    int *shelves[] = {shelfA, shelfB, shelfC};
    
    int counts[] = {3, 2, 4};
    int total_shelves = 3;

    for (int i = 0; i < total_shelves; i++) {
        int total_id_sum = sumShelf(shelves[i], counts[i]);
        printf("Shelf %d ID total: %d\n", i + 1, total_id_sum);
    }

    int largestIndex = findLargestShelf(counts, total_shelves);

    printf("Shelf with the most books: Shelf %d (%d books)\n", 
           largestIndex + 1, counts[largestIndex]);

    return 0;
}




