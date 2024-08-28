#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 30

int n_alpha(char* str){
    int n = 0;

    for(int i = 0; i < strlen(str); i++){
        if((('A' <= str[i]) && (str[i] <= 'Z')) || (('a' <= str[i]) && (str[i] <= 'z'))){
            n++;
        }
    }

    return n;
}

int n_alpha_upper(char* str){
    int n = 0;

    for(int i = 0; i < strlen(str); i++){
        if(('A' <= str[i]) && (str[i] <= 'Z')){
            n++;
        }
    }

    return n;
}

void to_upper(char* str){

    for(int i = 0; i < strlen(str); i++){
        if(('a' <= str[i]) && (str[i] <= 'z')){
            str[i] -= 'a' - 'A';
        }
    }

}

int main(void){

    char *str1 = (char *) malloc(MAX_LEN * sizeof(char));
    char *str2 = (char *) malloc(MAX_LEN * sizeof(char));

    printf("Insira duas strings no máximo com %d caracteres:\n", MAX_LEN-1);
    scanf("%[^\n]%*c",str1); // vai ler até um \n e vai retirar o \n
    scanf("%[^\n]%*c",str2);

    printf("A string 1 é: %s\n", str1);
    printf("A string 2 é: %s\n", str2);

    printf("Número de carateres da string 1 é: %d\n", n_alpha(str1));
    printf("Número de carateres maiusculos da string 2 é: %d\n", n_alpha_upper(str2));

    to_upper(str1);
    to_upper(str2);
    printf("A string 1 em maiusculas é: %s\n", str1);
    printf("A string 2 em maiusculas é: %s\n", str2);

    int comp = strcmp(str1, str2);
    if(comp == 0){
        printf("As strings são iguais!\n");
    }else if(comp < 0){
        printf("A string 1 vem primeiro, na ordem lexicográfica!\n");
    }else{
        printf("A string 2 vem primeiro, na ordem lexicográfica!\n");
    }

    char *str3 = malloc(strlen(str2) * sizeof(char));
    strcpy(str3, str2);

    printf("A string 3 é: %s\n", str3);

    char *str4 = malloc((strlen(str2) + strlen(str3)) * sizeof(char));
    strcpy(str4, str2);
    strcat(str4,str3);

    printf("A string 4 é: %s\n", str4);

    return 0;
}

