//
// Created by pedro on 12-10-2023.
//
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

unsigned static number_comparisons;

// Detection: array [k] = array [i] + array [j], para i < j < k
int detectionEquation(int* array, size_t n) {
    assert(n > 2);
    number_comparisons = 0;

    unsigned i,j,k, counter = 0;

    for (i = 0; i < n-2; i++) {
        for (j = i+1; j < n-1; j++) {
            for (k = j+1; k < n; k++) {
                number_comparisons++;
                if (array[k] == array[i] + array[j]) counter++;
            }
        }
    }

    return counter;
}

int main(void) {
    unsigned i, j;

    // Starting the arrays
    unsigned number_arrays = 5;

    int** arrays = (int**) malloc(number_arrays * sizeof(int*));

    int a0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a1[] = {1, 2, 4, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = {1, 2, 4, 8, 5, 6, 7, 8, 9, 10, 1, 2, 1, 3, 2, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a3[] = {1, 2, 4, 8, 16, 6, 7, 8, 9, 10, 0, 2, 2, 0, 3, 3, 0, 4, 4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a4[] = {1, 2, 4, 8, 16, 32, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    arrays[0] = a0; arrays[1] = a1; arrays[2] = a2; arrays[3] = a3; arrays[4] = a4;

    /// N = 5,10,20,30,40
    int N[] = {5,10,20,30,40};
    int n;

    for (j = 0; j < 5; j++) {
        n = N[j];
        printf("N = %d \n",n);

        for (i = 0; i < number_arrays; i++) {
            printf("Result: %d", detectionEquation(arrays[i], n));
            printf("\tComparisons: %d\n",number_comparisons);
        }
    }


    free(arrays);

    return 0;

}