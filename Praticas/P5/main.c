//
// Created by pedro on 19-10-2023.
//
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int N1;
int N2;
int N3;

int f1(int n){
    if ( n == 1 ) return 1;
    N1++;
    return f1(n/2) + n;
}

int f2(int n){
    if ( n == 1 ) return 1;
    N2+=2;
    return f2(n/2) + f2((n+1)/2) + n;
}

int f3(int n){
    if ( n == 1 ) return 1;
    if ( n % 2 == 0 ) {
        N3++;
        return 2 * f3(n/2) + n;
    }else {
        N3+=2;
        return f3(n/2) + f3((n+1)/2) + n;
    }
}

int main(void){

    for (int n = 1; n <= 15; n++) {
        N1=0;
        N2=0;
        N3=0;

        printf("N= %-10d ",n);
        printf("F1= %-6d ",f1(n));
        printf("N1= %-6d | ",N1);
        printf("F2= %-6d ",f2(n));
        printf("N2= %-6d | ",N2);
        printf("F3= %-6d ",f3(n));
        printf("N3= %-6d\n",N3);
    }


    return 0;
}