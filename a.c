#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* signo(char x[], char y[]){
    if(strcmp(x, "Áries") == 0 || strcmp(x, "Leão") == 0 || strcmp(x, "Sagitário") == 0) y = "Fogo";
    else if(strcmp(x,"Touro") == 0 || strcmp(x, "Virgem") == 0 || strcmp(x, "Capricórnio") == 0) y = "Terra";
    else if(strcmp(x, "Gêmeos") == 0 || strcmp(x, "Libra") == 0 || strcmp(x, "Aquário") == 0) y = "Ar";
    else if(strcmp(x, "Câncer") == 0 || strcmp(x, "Escorpião") == 0 || strcmp(x, "Peixes") == 0) y = "Água";
    else y = "Não foi enviado nenhum valor válido";
    return y;
}



int main(){
char a[12], b[6];
scanf("%s", a);
char* c = signo(a, b);
printf("%s", c);
return 0;
}
