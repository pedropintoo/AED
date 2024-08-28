//
// Created by pedro on 06-10-2023.
//
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

unsigned static number_comparisons;

// Detection: array [i] = array [i – 1] + array [i + 1], para 0 < i < (n – 1)
int detectionEquation(int* array, size_t n) {
    assert(n > 2);
    number_comparisons = 0;

    unsigned i, counter = 0;
    int start = array[0], mid = array[1], current;

    for (i = 2; i < n; i++) {
        current = array[i]; // 1 memory access per iteration

        number_comparisons++;
        if (start + current == mid) counter++;

        start = mid;
        mid = current;
    }

    return counter;
}

int main(void) {
    unsigned i;

    // Starting the arrays
    unsigned number_arrays = 5;
    int** arrays = (int**) malloc(number_arrays * sizeof(int*));
    int n = 10;
    int a0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a1[] = {1, 2, 1, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = {1, 2, 1, 3, 2, 6, 7, 8, 9, 10};
    int a3[] = {0, 2, 2, 0, 3, 3, 0, 4, 4, 0};
    int a4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    arrays[0] = a0; arrays[1] = a1; arrays[2] = a2; arrays[3] = a3; arrays[4] = a4;

    for (i = 0; i < number_arrays; i++) {
        printf("Result: %d", detectionEquation(arrays[i], n));
        printf("\tComparisons: %d\n",number_comparisons);
    }

    free(arrays);

    return 0;

}