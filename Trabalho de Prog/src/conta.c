// Código para copiar e colar no terminal:    gcc src/banco.c src/conta.c -I include -o exe

#include "conta.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>



void conta_init(Conta *c){ //inicializar a conta logo no início da aplicação. 
    c->saldo_corrente = 0;
    c->saldo_poupanca = 0;
    c->nlog = 0;
}



int depositar(long long valor, Conta *c){ // depositar na conta do usuário
    if(c->nlog == 100) return 3;    
    else if(valor<=0) return 1;
    else{
        // Adicionando os valores em suas variáveis respectivas e salvando na log
        c->nlog;
        c->saldo_corrente += valor;
        c->log[c->nlog].valor = valor;
        c->log[c->nlog].tipo = 0;
        c->log[c->nlog].saldo_corrente_apos = c->saldo_corrente;
        c->log[c->nlog].saldo_poupanca_apos = c->saldo_poupanca;
        strcpy(c->log[c->nlog].destino, "Conta corrente do usuario");

            // Horário do pc
            time_t t_agora;
            struct tm *data_hora_local;
            time(&t_agora);
            data_hora_local = localtime(&t_agora);
            sprintf(c->log[c->nlog].quando, "%d:%d:%d", data_hora_local->tm_hour, data_hora_local->tm_min, data_hora_local->tm_sec); 

        c->nlog++; // para o próximo ocupar a próxima posição do vetor

    return 0;
    }
}



int  sacar(long long valor, Conta *c){ // sacar da conta corrente
    if(c->nlog == 100) return 3;    
    else if(valor<=0) return 1;
    else if(valor>c->saldo_corrente) return 2;
    else{
        // Adicionando os valores em suas variáveis respectivas e salvando na log
        c->nlog;
        c->saldo_corrente -= valor;
        c->log[c->nlog].valor = valor;
        c->log[c->nlog].tipo = 1;
        c->log[c->nlog].saldo_corrente_apos = c->saldo_corrente;
        c->log[c->nlog].saldo_poupanca_apos = c->saldo_poupanca;
        strcpy(c->log[c->nlog].destino, "Dinheiro fisico");

            // Horário do pc
            time_t t_agora;
            struct tm *data_hora_local;
            time(&t_agora);
            data_hora_local = localtime(&t_agora);
            sprintf(c->log[c->nlog].quando, "%d:%d:%d", data_hora_local->tm_hour, data_hora_local->tm_min, data_hora_local->tm_sec); 

        c->nlog++; // para o próximo ocupar a próxima posição do vetor

    return 0;
    }
}



int  aplicar_poupanca(long long valor, Conta *c){ // passar dinheiro da conta para a poupança
    if(c->nlog == 100) return 3;    
    else if(valor<=0) return 1;
    else if(valor>c->saldo_corrente) return 2;
    else{
        // Adicionando os valores em suas variáveis respectivas e salvando na log
        c->nlog;
        c->saldo_corrente -= valor;
        c->saldo_poupanca += valor;
        c->log[c->nlog].valor = valor;
        c->log[c->nlog].tipo = 2;
        c->log[c->nlog].saldo_corrente_apos = c->saldo_corrente;
        c->log[c->nlog].saldo_poupanca_apos = c->saldo_poupanca;
        strcpy(c->log[c->nlog].destino, "Conta poupanca do usuario");

            // Horário do pc
            time_t t_agora;
            struct tm *data_hora_local;
            time(&t_agora);
            data_hora_local = localtime(&t_agora);
            sprintf(c->log[c->nlog].quando, "%d:%d:%d", data_hora_local->tm_hour, data_hora_local->tm_min, data_hora_local->tm_sec); 

        c->nlog++; // para o próximo ocupar a próxima posição do vetor

    return 0;
    }
}



int  resgatar_poupanca(long long valor, Conta *c){ // passar dinheiro da poupança para a conta
    if(c->nlog == 100) return 3;    
    else if(valor<=0) return 1;
    else if(valor>c->saldo_poupanca) return 2;
    else{
        // Adicionando os valores em suas variáveis respectivas e salvando na log
        c->nlog;
        c->saldo_corrente += valor;
        c->saldo_poupanca -= valor;
        c->log[c->nlog].valor = valor;
        c->log[c->nlog].tipo = 3;
        c->log[c->nlog].saldo_corrente_apos = c->saldo_corrente;
        c->log[c->nlog].saldo_poupanca_apos = c->saldo_poupanca;
        strcpy(c->log[c->nlog].destino, "Conta corrente do usuario");

            // Horário do pc
            time_t t_agora;
            struct tm *data_hora_local;
            time(&t_agora);
            data_hora_local = localtime(&t_agora);
            sprintf(c->log[c->nlog].quando, "%d:%d:%d", data_hora_local->tm_hour, data_hora_local->tm_min, data_hora_local->tm_sec); 

        c->nlog++; // para o próximo ocupar a próxima posição do vetor

    return 0;
    }
}



char* obterTipo(TipoTransacao n){// Função EXTRA para conseguir a string do tipo da transação ao imprimir o extrato
    switch(n){
        case DEP: return "Deposito";
        case SAQ: return "Saque";
        case APLI: return "Aplicacao na poupanca";
        case RESG: return "Resgate da poupanca";
        default: return "Sem logs";
    }
}



void extrato_imprimir(Conta *c){ // imprime as transações realizadas e o saldo final.
    printf("\nEXTRATO:\n");
    if(c->nlog == 0) printf("Sem transacoes ate o momento\n\n");
    for(int i = 0; i<c->nlog; i++){
        printf("\n* Transacao numero %d:\n", i+1);
        printf("Tipo de transacao: %s\n", obterTipo(c->log[i].tipo));
        printf("Valor da transacao: %lld,%02lldR$\n", c->log[i].valor/100, c->log[i].valor%100);
        printf("Saldo da conta corrente apos: %lld,%02lldR$\n", c->log[i].saldo_corrente_apos/100, c->log[i].saldo_corrente_apos%100);
        printf("Saldo da conta poupanca apos: %lld,%02lldR$\n", c->log[i].saldo_poupanca_apos/100, c->log[i].saldo_poupanca_apos%100);
        printf("Destino da transacao: %s\n", c->log[i].destino);
        printf("Horario em que transacao ocorreu: %s\n\n", c->log[i].quando);
    }
}
