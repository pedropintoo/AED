#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// Display the contents of array a with n elements
// Pre-Conditions: a != NULL and n > 0
// Example of produced output: Array = [ 1.00, 2.00, 3.00 ]
void DisplayArray(double* a, size_t n){
    assert(a != NULL && n > 0);
    for(int i = 0; i < n; i++){
        printf("%.2f ",a[i]);
    }
    printf("\n");
}
// Read the number of elements, allocate the array and read its elements
// Condition: number of elements > 0
// Pre-Condition: size_p != NULL
// Return NULL if memory allocation fails
// Set *size_p to ZERO if memory allocation fails
double* ReadArray(size_t* size_p){

    assert(size_p != NULL);

    do{
        printf("Número de elementos: ");
        scanf("%lu", size_p);
    }while(*size_p <= 0);

    double* array = (double*) malloc(*size_p * sizeof(double));

    if (array == NULL){
        *size_p = 0;
        return NULL;
    }

    for(int i = 0; i < *size_p; i++){
        scanf("%lf", &array[i]);
    }

    return array;
}
// Allocate and return a new array with (size_1 + size_2) elements
// which stores the elements of array_1 followed by the elements of array_2
// Pre-Conditions: array_1 != NULL and array_2 != NULL
// Pre-Conditions: size_1 > 0 and size_2 > 0
// Return NULL if memory allocation fails
double* Append(double* array_1, size_t size_1, double* array_2, size_t size_2){
    assert(array_1 != NULL && array_2 != NULL);
    assert(size_1 > 0 && size_2 > 0);

    double* array = (double *) malloc((size_1 + size_2) * sizeof(double));

    if(array == NULL) return NULL;

    int i;
    for(i = 0; i < size_1; i++){
        array[i] = array_1[i];
    }
    for(i = 0; i < size_2; i++){
        array[i + size_1] = array_2[i];
    }

    return array;
}


int main(void){
    double array1[] = {1.00, 2.00, 3.00 };
    double array2[] = {4.00, 5.00, 6.00, 7.00 };

    printf("\n\n FUNC 1 ----------\n");
    DisplayArray(array1, 3);

    printf("\n\n FUNC 2 ----------\n");
    size_t size = 3;
    double* array = ReadArray(&size);
    DisplayArray(array, size);

    free(array);

    printf("\n\n FUNC 3 ----------\n");
    double* array3 = Append(array1, 3, array2, 4);
    DisplayArray(array3, 3 + 4);

    free(array3);
    return 0;
}
