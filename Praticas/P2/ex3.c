//
// Created by pedro on 21-09-2023.
//

#include<stdio.h>

void Permute(int* a, int* b, int* c){
    int aux = *c;
    *c = *b;
    *b = *a;
    *a = aux;
}

int main(void){
    int x, y, z;
    x = 10;
    y = 20;
    z = 30;

    printf("%d %d %d\n",x, y, z);
    Permute(&x, &y, &z);
    printf("%d %d %d\n",x, y, z);

    return 0;
}