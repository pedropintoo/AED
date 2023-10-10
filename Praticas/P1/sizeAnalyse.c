#include<stdio.h>

int main(void){
  printf("%20s %20ld\n","sizeof(void *)",sizeof(void*));
  printf("%20s %20ld\n","sizeof(void)",sizeof(void));
  printf("%20s %20ld\n","sizeof(char)",sizeof(char));
  printf("%20s %20ld\n","sizeof(short)",sizeof(short));
  printf("%20s %20ld\n","sizeof(int)",sizeof(int));
  printf("%20s %20ld\n","sizeof(long)",sizeof(long));
  printf("%20s %20ld\n","sizeof(long long)",sizeof(long long));  
  printf("%20s %20ld\n","sizeof(float)",sizeof(float));
  printf("%20s %20ld\n","sizeof(double)",sizeof(double));
  return 0;
}

