//
// Created by pedro on 06-10-2023.
//
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

unsigned static number_operations;


// Detection: r = a[ 1 ] / a[ 0 ] e a[ i ] = r × a[ i – 1 ], i > 1
int detectionEquation(int* array, int n) {
    assert(n > 2);
    number_operations = 0;

    unsigned i;
    double r = array[1]/array[0];
    number_operations++;
    int start = array[1], current;

    for (i = 2; i < n; i++) {
        current = array[i]; // 1 memory access per iteration

        number_operations++;
        if (current != r * start) return 0;

        start = current;
    }

    return 1;
}

int main(void) {
    unsigned i;

    // Starting the arrays
    unsigned number_arrays = 8;
    int** arrays = (int**) malloc(number_arrays * sizeof(int*));
    int n = 10;
    int a0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a1[] = {1, 2, 4, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = {1, 2, 4, 8, 5, 6, 7, 8, 9, 10};
    int a3[] = {1, 2, 4, 8, 16, 6, 7, 8, 9, 10};
    int a4[] = {1, 2, 4, 8, 16, 32, 7, 8, 9, 10};
    int a5[] = {1, 2, 4, 8, 16, 32, 64, 128, 9, 10};
    int a6[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 10};
    int a7[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};


    arrays[0] = a0; arrays[1] = a1; arrays[2] = a2; arrays[3] = a3; arrays[4] = a4; arrays[5] = a5; arrays[6] = a6; arrays[7] = a7;

    for (i = 0; i < number_arrays; i++) {
        printf("Result: %s", detectionEquation(arrays[i], n) == 1? "True" : "False");
        printf("\tOperations: %d\n",number_operations);
    }

    // Clear the arrays
    free(arrays);

    return 0;

}
