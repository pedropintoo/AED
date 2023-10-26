//
// Created by pedro on 26-10-2023.
//
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef long unsigned int (*Delannoy_functions)(unsigned int, unsigned int);

long unsigned int N_SUMS;

long unsigned int delannoy_recursive(unsigned int m, unsigned int n) {
    if (m*n == 0) return 1;
    N_SUMS += 3;
    return delannoy_recursive(m-1, n) + delannoy_recursive(m-1, n-1) + delannoy_recursive(m, n-1);
}

long unsigned int delannoy_dynamic(unsigned int m, unsigned int n) {
    long unsigned int del[m+1][n+1];

    for (unsigned int i = 0; i <= m; i++) {
        for (unsigned int j = 0; j <= n; j++) {
            if (i*j == 0) del[i][j] = 1;
            else {
                N_SUMS += 3;
                del[i][j] = del[i-1][j] + del[i-1][j-1] + del[i][j-1];
            }
        }
    }

    return del[m][n];
}


long unsigned int del_cache[SIZE][SIZE];

void initializeCache() {
    for (unsigned int i = 0; i < SIZE; i++)
        for (unsigned int j = 0; j < SIZE; j++)
            del_cache[i][j] = -1;
}

long unsigned int delannoy_memoization(unsigned int m, unsigned int n) {

    // Return the previous calculated value
    if (del_cache[m][n] != -1) return del_cache[m][n];

    // Default values
    long unsigned int value;
    if(m*n == 0) value = 1;
    else {
        N_SUMS += 3;
        value = delannoy_memoization(m-1, n) + delannoy_memoization(m-1, n-1) + delannoy_memoization(m, n-1);
    }

    del_cache[m][n] = value;

    return value;
}

int main() {
    // Start cache
    initializeCache();

    Delannoy_functions delannoyFunctions[] = {delannoy_recursive, delannoy_dynamic, delannoy_memoization};
    char* delannoyFunctions_names[] = {"Recursive","Dynamic","Memoization"};

    for (unsigned int i = 0; i < 3; i++) {
        printf("\nDelannoy's Matrix - %s Function\n", delannoyFunctions_names[i]);

        for (unsigned int m = 0; m <= 10; m++) {
            for (unsigned int n = 0; n <= 10; n++) {
                N_SUMS = 0;
                delannoyFunctions[i](m,n);
                printf("%-7lu ",N_SUMS);
            }
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}