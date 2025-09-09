#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char verificar(char x[12]){
    int y;
    y = strlen(x);
    if(y>=8 && y<=11){ // verifica se o valor está entre 8 e 11 para saber se é um número válido no Brasil
        return 1;
    }
    return 0;
}



char* verificar2(char x[12]){
    // x recebe o número, y verifica o tamanho do número
    int y;
    y = strlen(x);
    if(y==8 || y==9){
        return x;
    }
   else{
    return x+2;
   }
}


char* verificar3(char x[12], char b[3]){
    // x recebe o número, y verifica o tamanho do número e z é o novo valor do novo ddd
    int y;
    y = strlen(x);
    b[0]=x[0];
    b[1]=x[1];
    b[2]='\0';
    if(y==8 || y==9){
        return "00";
    }
   return b;
}

int main(){
    char e[12], a[3];
    scanf("%12s", &e);
    int y = strlen(e);

    printf("\nQuestão 1: %d", verificar(e)); // QUESTAO 1

    if (verificar(e)){
    char* minhastring = verificar2(e); // QUESTAO 2
    printf("\nQUestão 2: %s", minhastring);

    char* minhastring3 = verificar3(e, a); // QUESTAO 3
    printf("\nQuestão 3: %s", minhastring3);
        }
    return 0;
}
