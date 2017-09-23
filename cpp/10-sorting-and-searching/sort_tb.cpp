#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergesort.h"

#define SIZE 16

#define MIN -100
#define MAX  100

int main() {

    int evenArr[SIZE];
    int oddArr[SIZE+1];

    srand(time(NULL));

    //==========================================================================
    // Test Merge Sort
     //=========================================================================
    for(int i = 0; i < SIZE; i++) {
        evenArr[i] = (rand() % (MAX-MIN)) + MIN;
        oddArr[i]  = (rand() % (MAX-MIN)) + MIN;
    }
    oddArr[SIZE] = (rand() % (MAX-MIN)) + MIN;

    printf("Before Merge Sort\nEven Array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%3d ", evenArr[i]);
    }
    printf("\nOdd Array:  ");
    for(int i = 0; i < SIZE+1; i++) {
        printf("%3d ", oddArr[i]);
    }

    mergesort(evenArr, SIZE);
    mergesort(oddArr, SIZE+1);

    printf("\n\nAfter Merge Sort\nEven Array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%3d ", evenArr[i]);
    }
    printf("\nOdd Array:  ");
    for(int i = 0; i < SIZE+1; i++) {
        printf("%3d ", oddArr[i]);
    }

    //==========================================================================
    // Test Quick Sort
    //==========================================================================
    for(int i = 0; i < SIZE; i++) {
        evenArr[i] = (rand() % (MAX-MIN)) + MIN;
        oddArr[i]  = (rand() % (MAX-MIN)) + MIN;
    }
    oddArr[SIZE] = (rand() % (MAX-MIN)) + MIN;

    printf("\n\nBefore Quick Sort\nEven Array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%3d ", evenArr[i]);
    }
    printf("\nOdd Array:  ");
    for(int i = 0; i < SIZE+1; i++) {
        printf("%3d ", oddArr[i]);
    }

    mergesort(evenArr, SIZE);
    mergesort(oddArr, SIZE+1);

    printf("\n\nAfter Quick Sort\nEven Array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%3d ", evenArr[i]);
    }
    printf("\nOdd Array:  ");
    for(int i = 0; i < SIZE+1; i++) {
        printf("%3d ", oddArr[i]);
    }
    printf("\n");

    return 0;
}
