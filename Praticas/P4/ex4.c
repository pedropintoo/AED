//
// Created by pedro on 12-10-2023.
//

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <time.h>

unsigned int static number_comparisons;
unsigned int static number_copies;

void detectionEqMulSubMul(int* array, size_t* n) {
    unsigned int len = *n;
    assert(len > 1);

    number_comparisons = 0; number_copies = 0;

    unsigned int idx = 1, i, j, teste;

    for (i = 1; i < len; i++) {
        teste = 0;
        // No caso de apenas consideramos os selecionados metemos j < idx (resultado engracao)
        for (j = 0; j < i; j++) {
            number_comparisons++; // Considero as 3 uma só para simplificar!
            if (array[i] != array[j] && array[i] % array[j] != 0 && array[j] % array[i] != 0) {
                teste = 0;  // ignorar e continuar
                continue;
            }else {
                teste = 1; // ignorar e parar!
                break;
            }
        }
        if (teste == 0) {
            if (idx != i) {
                number_copies++;
                array[idx] = array[i]; // No caso de estar tudo ok!
            }
            idx++;
        }
    }

    *n = idx;
}

int main(void){
#if 1
    unsigned int i;

    // Starting array
    size_t n = 10;
    int array[] = { 2, 2, 2, 3, 3, 4, 5, 8, 8, 9 };
    //int array[] = { 7, 8, 2, 2, 3, 3, 3, 8, 8, 9 };
    //int array[] = { 1,1,1,1,1,1,1,1,1, 1};
    //int array[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};


    // print default
    for (i = 0; i < n; i++) printf("%s%d%s",i==0?"{":"",array[i],i!=n-1 ? "," : "}");

    detectionEqMulSubMul(array, &n);

    // print processed + results
    for (i = 0; i < n; i++) printf("%s%d%s",i==0?"  ->  {":"",array[i],i!=n-1 ? "," : "}");
    printf(" \tComparisons: %d\tCopies: %d\n",number_comparisons, number_copies);

#else
    // NOTA IMPORTANTE: estou a considerar numeros aleatorios de [1, 99]
    // no caso de [1, m-1] -> as complexidades eram ~ a sua multiplicacao por n

    srand(time(NULL)); // reset the seed of random numbers
    unsigned int i, j, counter;

    unsigned int total_comparisons = 0, total_copies = 0;

    unsigned int N = 1e4;

    unsigned int previous, result;

    size_t n_test = 7;
    unsigned int n_i[] = { 8, 16, 32, 64, 128, 256, 512};
    size_t n = n_i[0];

    /// Testing Comparisons

    printf("Comparisons\n");
    printf("\tn\tf7(n)\tf7(2n)/f7(n) \n");
    for (j = 0; j < n_test; j++) {

        for (counter = 0; counter < N; counter++) {
            n = n_i[j];

            // Starting array with random numbers
            int array0[n];
            for (i = 0; i < n; i++) array0[i] = (int) (rand()%99 + 1); // Randoms between 1-99


            detectionEqMulSubMul(array0, &n);

            // results
            total_comparisons += number_comparisons;

        }

        result = total_comparisons/N;

        printf("\t%d\t%d",n_i[j],result);
        if (j >= 1) {
            printf("\t%f\n",(double)result / (double)previous);
        } else printf("\t \n");

        previous = result;
    }

    /// Testing Copies

    printf("\nCopies\n");
    printf("\tn\tf7(n)\tf7(2n)/f7(n) \n");
    for (j = 0; j < n_test; j++) {

        for (counter = 0; counter < N; counter++) {
            n = n_i[j];

            // Starting array with random numbers
            int array0[n];
            for (i = 0; i < n; i++) array0[i] = (int) (rand()%99 + 1); // Randoms between 1-99


            detectionEqMulSubMul(array0, &n);

            // results
            total_copies += number_copies;

        }

        result = total_copies/N;

        printf("\t%d\t%d",n_i[j],result);
        if (j >= 1) {
            printf("\t%f\n",(double)result / (double)previous);
        } else printf("\t \n");

        previous = result;
    }





#endif
    return 0;
}