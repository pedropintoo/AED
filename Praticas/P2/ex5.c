#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

// The coefficients of a degree n polynomial
// are stored in an array p of size (n + 1)
// p[0] is the coefficient of the largest degree term
// p[n] is the coefficient of the zero-degree term

// Display a polynomial
// Pre-Conditions: coef != NULL and degree >= 0
// Example of produced output:
// Pol(x) = 1.000000 * x^2 + 4.000000 * x^1 + 1.000000
void DisplayPol(double* coef, size_t degree) {
    assert(coef != NULL && degree >= 0);

    printf("Pol(x) = ");

    for(int i = 0; i <= degree; i++){

        printf("%.2f",coef[i]);
        if(i < degree){
            printf(" * x^%zu + ",degree-i);
        }else printf("\n");

    }
}

// Compute the value of a polynomial using Horner’s method:
// Pre-Conditions: coef != NULL and degree >= 0
double ComputePol(double* coef, size_t degree, double x) {
    assert(coef != NULL && degree >= 0);

    double temp = coef[0];
    for(int i = 1; i <= degree; i++){
        temp = coef[i] + x*temp;
    }

    printf("Pol(%.2f) = %.2f\n",x, temp);

    return temp;
}

// Test example:
// Pol(x) = 1.000000 * x^2 + 4.000000 * x^1 + 1.000000
// Pol(2.000000) = 13.000000

// Compute the real roots, if any, of a second-degree polynomial
// Pre-Conditions: coef != NULL and degree == 2 and coef[0] != 0
// Pre-Conditions: root_1 != NULL and root_2 != NULL
// Return values:   0 -> no real roots
//                  1 -> 1 real root with multiplicity 2
//                  2 -> 2 distinct real roots
// The computed root values are returned via the root_1 and root_2
// pointer arguments
// Assign 0.0 to the *root_1 and *root_2 if there are no real roots
unsigned int GetRealRoots(double* coef, size_t degree, double* root_1, double* root_2) {
    assert(coef != NULL && degree == 2 && coef[0] != 0);
    assert(root_1 != NULL && root_2 != NULL);

    double eq1 = coef[1]*coef[1] - 4 * coef[0] * coef[2];


    if (eq1 < 0){
        // no real roots
        *root_1 = 0.0;
        *root_2 = 0.0;

        return 0;
    }else {
        double eq2 = -coef[1] / (2*coef[0]);
        if (eq1 == 0) {
            // 1 real root with multiplicity 2
            *root_1 = eq2;

            return 1;
        } else {
            // 2 distinct real roots
            *root_1 = eq2 - sqrt(eq1)/(2*coef[0]);
            *root_2 = eq2 + sqrt(eq1)/(2*coef[0]);

            return 2;
        }
    }

}

int main(void){

    double coef[] = {1, 4, 1};

    DisplayPol(coef, 2);

    ComputePol(coef, 2, 2);

    double x, y;
    double* newCoef = (double*) malloc(3 * sizeof(double));
    newCoef[0] = 1;
    newCoef[1] = 0;
    newCoef[2] = -9;
    int result = GetRealRoots(newCoef, 2, &x, &y);
    switch(result){
        case 0 :
            printf("No real roots in ");
            DisplayPol(newCoef,2);
            break;
        case 1 :
            printf("1 real root with multiplicity 2 -> %f\n", x);
            break;
        case 2 :
            printf("2 distinct real roots -> %.2f & %.2f\n",x,y);
            break;
    }

    free(newCoef);
    return 0;
}
