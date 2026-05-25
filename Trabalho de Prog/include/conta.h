#ifndef CONTA_H
#define CONTA_H

#define MAX_TRANS 100

typedef enum {DEP, SAQ, APLI, RESG} TipoTransacao;

typedef struct {
    TipoTransacao tipo;
    long long valor;
	long long saldo_corrente_apos;
	long long saldo_poupanca_apos;
    char destino[128];
    char quando[20];
} Transacao;

typedef struct {
    long long saldo_corrente;
    long long saldo_poupanca;
    Transacao log[MAX_TRANS];
    int nlog;
} Conta;

enum {
    OK = 0,
    ERRO_VALOR_INVALIDO = 1,
    ERRO_SALDO_INSUFICIENTE = 2,
    ERRO_CAPACIDADE_LOG = 3
};

void conta_init(Conta *c); //inicializar a conta logo no início da aplicação.  
int  depositar(long long valor, Conta *c); // depositar na conta
int  sacar(long long valor, Conta *c); // sacar da conta
int  aplicar_poupanca(long long valor, Conta *c); // passar dinheiro da conta para a poupança
int  resgatar_poupanca(long long valor, Conta *c); // passar dinheiro da poupança para a conta
void extrato_imprimir(Conta *c); // imprime as transações realizadas e o saldo final.

#endif // CONTA