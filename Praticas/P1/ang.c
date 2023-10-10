#include<stdio.h>
#include<math.h>

int main(void){
  FILE *file;

  int inicial,inc,max;
  double ang_rad;

  file = fopen("angfile.txt","w");

  if(file == NULL) {
    printf("Erro na criação do ficheiro!");
    return -1;
  }
  if(scanf("%d %d %d",&inicial, &inc, &max) == 0) return -1;

  printf("%10s %10s %10s\n","ang","sin(ang)","cos(ang)");

  printf("%10s %10s %10s\n","---","--------","--------");


  // For file
  fprintf(file,"%10s %10s %10s\n","ang","sin(ang)","cos(ang)");

  fprintf(file,"%10s %10s %10s\n","---","--------","--------");

  for(int ang = inicial; ang <= max; ang = ang + inc){
      ang_rad = (M_PI / 180) * ang;
      printf("%10d %10.2f %10.2f\n",ang, sin(ang_rad), cos(ang_rad));
      // For file
      fprintf(file,"%10d %10.2f %10.2f\n",ang, sin(ang_rad), cos(ang_rad));

  }
  fclose(file);
}

