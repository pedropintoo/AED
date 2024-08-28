#include<stdio.h>

void printArray(char *s, int *a, int size_A){
  printf("%s:\n",s);

  for(int i = 0; i < size_A; i++){
      printf("%d ",a[i]);
  }
  printf("\n");
      
}

void cumSum(const int *a, int size_A, int *b){
    int c = 0;
    for(int i = 0; i < size_A; i++){
        c += a[i];
        b[i] = c;
    }
}

int main(void){
   int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printArray("a",a,12);

    int b[12];
    cumSum(a, 12, b);
    printArray("b", b, 12);
    return 0;
}


