//
// Created by pedro on 26-10-2023.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 1025

typedef long unsigned int (*CoinProblem_functions)(unsigned int, unsigned int*);

long unsigned int N_COMPARISONS;

long unsigned int coinProblem_recursive(unsigned int n, unsigned int* array) {
    if (n == 0) return 0;
    else if (n == 1) return array[0];
    else {
        long unsigned int c1 = array[n-1] + coinProblem_recursive(n-2, array);
        long unsigned int c2 = coinProblem_recursive(n-1, array);
        N_COMPARISONS++;
        return c1 >= c2 ? c1 : c2;
    }
}

long unsigned int coinProblem_dynamic(unsigned int n, unsigned int* array) {
    /// Normal implementation
    long unsigned int coinP[n+1];

    coinP[0] = 0;
    coinP[1] = array[0];

    for (unsigned int i = 2; i <= n; i++) {
        long unsigned int c1 = array[i-1] + coinP[i-2];
        long unsigned int c2 = coinP[i-1];
        N_COMPARISONS++;
        coinP[i] = c1 >= c2 ? c1 : c2;
    }

    return coinP[n];
}


long unsigned int coinP_Cache[SIZE];

void initializeCache() {
    for (unsigned int i = 0; i < SIZE; i++)
        coinP_Cache[i] = -1;
}

long unsigned int coinProblem_memoization(unsigned int n, unsigned int* array) {

    // Return the previous calculated value
    if (coinP_Cache[n] != -1) return coinP_Cache[n];

    // Defaults
    long unsigned int value;
    if (n == 0) value = 0;
    else if (n == 1) value = array[0];
    else {
        long unsigned int c1 = array[n-1] + coinProblem_memoization(n-2, array);
        long unsigned int c2 = coinProblem_memoization(n-1, array);

        N_COMPARISONS++;
        value = c1 >= c2 ? c1 : c2;
    }

    coinP_Cache[n] = value;

    return value;
}


int main() {

#if 1
    /// MANUAL COMPARISONS TESTS

    // Seed the random number generator with the current time
    srand(time(NULL));
    // Start cache
    initializeCache();

    long unsigned int n = 5;
    unsigned int array[n];
    for (unsigned int i = 0; i < n; i++) array[i] = rand()%10+1;
    // Print the sequence
    for (unsigned int i = 0; i < n; i++) printf("%s%u%s",i==0? "Sequence: {" : " ",array[i],i==n-1? "}\n" : ",");

    N_COMPARISONS=0;
    //printf("%lu\n", coinProblem_recursive(n, array));
    //printf("%lu\n", coinProblem_dynamic(n, array));
    printf("Result: %lu\n", coinProblem_memoization(n, array));

    printf("Comparisons: %lu\n",N_COMPARISONS);

#else
    /// AUTOMATIC COMPARISONS TESTS

    // Seed the random number generator with the current time
    srand(time(NULL));
    // Start cache
    initializeCache();

    unsigned int n_tests = 5;
    unsigned int tests[] = {2, 4, 8, 16, 32};
    unsigned int n;
    double previous;

    CoinProblem_functions coinProblem_functions[] = {coinProblem_recursive, coinProblem_dynamic, coinProblem_memoization};
    char* coinProblem_functions_names[] = {"Recursive","Dynamic","Memoization"};

    for (unsigned int i = 0; i < 3; i++) {
        printf("\nThe Coin Row Problem's Matrix - %s Function\n", coinProblem_functions_names[i]);
        printf("\tn\tc(n)\tc(2n)/c(n) \n");

        for (unsigned int idx_tests = 0; idx_tests < n_tests; idx_tests++) {
            n = tests[idx_tests];
            N_COMPARISONS = 0;
            unsigned int array[n];
            for (unsigned int i = 0; i < n; i++) array[i] = rand()%10+1;
            coinProblem_functions[i](n, array);

            printf("\t%d\t%lu", n, N_COMPARISONS);
            if (idx_tests >= 1) {
                printf("\t%f\n",(double)N_COMPARISONS / (double)previous);
            } else printf("\t \n");

            previous = N_COMPARISONS;
        }

    }

#endif

    return EXIT_SUCCESS;

}