//
// Created by pedro on 28-09-2023.
//
#include<stdio.h>
#include<stdlib.h>


int calcFactR(int n){
    return (n == 1 || n == 0) ? 1 : n * calcFactR(n-1);
}

void calcFact(int* fact) {
    for(int i = 0; i < 10; i++){
        fact[i] = calcFactR(i);
    }
}

int fatoriao(int limit, int* fact, int print){
    int num, alg;
    int sum;

    int number_operations = 0;

    for(int n = 1; n < limit; n++){
        num = n;
        sum = 0;
        while(num != 0){
            alg = num % 10;

            sum += fact[alg];
            number_operations++;

            num = num / 10;

        }

        if(sum == n && print == 1){
            printf("%d\n",n);
        }

    }

    return number_operations;
}


int main(void){

    int* fact = malloc(10 * sizeof(int));
    calcFact(fact);

    // Testing the complexity

    unsigned int n;
    unsigned int result;
    unsigned int previous;
    double ratio;

    unsigned int start_n = 10;
    unsigned int end_n = 1e6;

    printf("\n fatoriao \n");
    printf("      n   fatoriao(n)    f(2n)/f(n)\n");
    printf("-------  ------------  ------------\n");

    for (n = start_n; n < end_n; n *= 2) {
        result = fatoriao(n, fact, 0);
        printf("%7u  %12u", n, result);

        if (n > start_n) {
            ratio = (double)result / (double)previous;
            printf("  %12.5f", ratio);
        }

        printf("\n");

        previous = result;
    }

    // ORDEM DE COMPLEXIDADE (n) -> linear

    free(fact);

    return 0;
}