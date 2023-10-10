#include<stdio.h>
#include<math.h>

int main(void){
  int n_linhas;
  
  scanf("%d", &n_linhas);
  
  // cabeçalho
  printf("%10s %10s %10s\n","Numero", "Quadrado", "Raiz Quadrada");
  for(int i = 1; i <= n_linhas; i++){
      printf("%10d %10d %10.2f\n",i,i*i,sqrt(i));
  }
}
