//
// Created by pedro on 28-09-2023.
//
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int power(int number, int e){
    int result = 1;
    for(int i = 0; i < e; i++){
        result *= number;
    }
    return result;
}

void calcPowers(int** pow, int n_alg){
    for(int num = 0; num < 10; num++){
        for(int p = 1; p <= n_alg; p++){
            if(num == 0) pow[num][p-1] = 0;
            else pow[num][p-1] = power(num,p);
        }
    }
}

int armstrong(int n_digits, int** pow, int print){
    unsigned int n_max = power(10,n_digits);
    unsigned int num, alg, sum;
    unsigned int number_operations = 0;

    for(int n = power(10, n_digits-1); n < n_max; n++){
        num = n;
        sum = 0;
        while(num != 0){
            alg = num % 10;

            sum += pow[alg][n_digits-1];
            number_operations++;

            num = num / 10;
        }
        //printf("%d -> %d\n",n,sum);

        if(sum == n && print == 1){
            printf("%d\n",n);
        }
    }

    return number_operations;
}

int main(void){

#if 0
    /// TODO: Simples test for n digits
    unsigned int i;

    int n_digits = 3;

    /// Reserve space
    int** pow = malloc(10 * sizeof(int*));
    for(i = 0; i < 10; i++){
        pow[i] = malloc(n_digits * sizeof(int));
    }

    /// Calculate the powers to array 2D
    calcPowers(pow, n_digits);

    /// Printing the armstrong numbers
    armstrong(n_digits, pow, 1);


#else
    /// TODO: Testing the complexity
    unsigned int i;
    unsigned int n;
    unsigned int result;
    unsigned int previous;
    double ratio;

    unsigned int start_n = 1;
    unsigned int end_n = 10;

    printf("\n armstrong \n");
    printf("      n     armstrong(n)    a(2n)/a(n)\n");
    printf("-------  ---------------  ------------\n");

    /// Reserve space (not included in complexity)
    int** pow = malloc(10 * sizeof(int*));
    for(i = 0; i < 10; i++){
        pow[i] = malloc(end_n * sizeof(int));
    }
    /// Calculate the powers to array 2D (not included in complexity)
    calcPowers(pow, end_n);

    for (n = start_n; n < end_n; n *= 2) {

        result = armstrong(n, pow, 0);
        printf("%7u  %15u", n, result);

        if (n > start_n) {
            ratio = (double)result / (double)previous;
            printf("  %12.5f", ratio);
        }

        printf("\n");

        previous = result;
    }

    // COMPLEXIDADE DO ALGORITMO É EXPONENCIAL

#endif

    /// Cleaning space
    for(i = 0; i < 10; i++){
        free(pow[i]);
    }
    free(pow);

    return 0;

}