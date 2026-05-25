// Código para copiar e colar no terminal:    gcc src/banco.c src/conta.c -I include -o exe

#include "conta.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>



// INICIALIZANDO A STRUCT DA CONTA
Conta user; 


// INICIALIZANDO AS FUNÇÕES:
    int opcoes(void); // Função para printar o Menu de Opções e verificar a opção escolhida
    int opcaofuncao(int status, int v, int opcaoEscolhida); // Função que fará o que acontecerá de acordo com a escolha do user



int main(){
           
    conta_init(&user); //Inicializazção da conta CORRENTE e POUPANÇA:  
    long long v; // Será o valor escolhido pelo cliente de saques, depósitos, pixs etc
    int status; // Será o valor de return da possibilidade de realizar os saques, depósitos, etc
    int opcaoEscolhida; // Será o número da opção escolhida pelo usuário


    while(1){ // Loop para repetir pedido da escolha da opção:
        opcaoEscolhida = opcoes(); // Menu de Opções
        if(opcaofuncao(status, v, opcaoEscolhida) == 3) break;
    }
    
return 0;
}



// FUNÇÃO 1:
    int opcoes(void){ // Função para printar o Menu de Opções e verificar a opção escolhida
        int opcao;
        printf("\n==#==#== BANK ==#==#==\n1. Depositar na conta corrente\n2. Sacar da conta corrente (sem cheque especial)\n3. Aplicar na poupanca\n4. Resgatar da poupanca\n5. Consultar saldos\n6. Extrato (listar transacoes com data/hora)\n7. Sair\n\nDigite a sua opcao: ");
        scanf("%d", &opcao);
        return opcao;
    }




// FUNÇÃO 2:
    int opcaofuncao(int status, int v, int opcaoEscolhida){ 

        switch(opcaoEscolhida){

                // DEPÓSITO            
                case 1:{

                    printf("\nValor para depositar (em centavos): ");
                    scanf("%lld", &v);
                    status = depositar(v,&user);

                        if(status == ERRO_CAPACIDADE_LOG)
                        printf("\n[ALERTA] Capacidade de registros atingida (100 transacoes), seu depostio nao foi efetuado. O servico do VoidBank saira do ar agora.\n");

                        else if(status == ERRO_VALOR_INVALIDO) printf("\nValor invalido.\n");

                        else printf("\nDeposito realizado.\n");

                    Sleep(1500);
                break;
                }


                // SAQUE:
                case 2:{

                    printf("\nValor para sacar (em centavos): ");
                    scanf("%lld", &v);
                    status = sacar(v, &user);

                        if(status == ERRO_CAPACIDADE_LOG) 
                        printf("\n[ALERTA] Capacidade de registros atingida (100 transacoes), seu saque nao foi efetuado. O servico do VoidBank saira do ar agora.\n");
 
                        else if (status == ERRO_VALOR_INVALIDO) 
                        printf("\nValor invalido.\n");

                        else if(status == ERRO_SALDO_INSUFICIENTE) 
                        printf("\nSaldo insuficiente\n");
                        
                        else printf("\nSaque Realizado\n");

                    Sleep(1500);
                break;
                }


                // APLICAR DINHEIRO DA CONTA CORRENTE NA POUPANCA
                case 3:{
                    printf("\nValor para transferir da conta corrente para a poupanca: ");
                    scanf("%lld", &v);
                    status = aplicar_poupanca(v, &user);

                        if(status == ERRO_CAPACIDADE_LOG) 
                        printf("\n[ALERTA] Capacidade de registros atingida (100 transacoes), sua transferencia nao foi efetuada. O servico do VoidBank saira do ar agora.\n");
 
                        else if (status == ERRO_VALOR_INVALIDO) 
                        printf("\nValor invalido.\n");

                        else if(status == ERRO_SALDO_INSUFICIENTE) 
                        printf("\nSaldo na conta corrente insuficiente\n");
                        
                        else printf("\nTransferencia realizada\n");

                    Sleep(1500);
                break;
                }


                // TRANSFERIR DINHEIRO DA POUPANCA PARA A CONTA CORRENTE
                case 4:{
                    printf("\nValor para transferir da poupanca para a conta corrente: ");
                    scanf("%lld", &v);
                    status = resgatar_poupanca(v, &user);

                        if(status == ERRO_CAPACIDADE_LOG) 
                        printf("\n[ALERTA] Capacidade de registros atingida (100 transacoes), sua transferencia nao foi efetuada. O servico do VoidBank saira do ar agora.\n");
 
                        else if (status == ERRO_VALOR_INVALIDO) 
                        printf("\nValor invalido.\n");

                        else if(status == ERRO_SALDO_INSUFICIENTE) 
                        printf("\nSaldo na poupanca insuficiente\n");
                        
                        else printf("\nTransferencia realizada\n");

                    Sleep(1500);
                break;
                }


                // CONSULTAR SALDO:
                case 5:{

                    printf("\nSaldo da conta corrente: %lld,%02lldR$\n", user.saldo_corrente/100, user.saldo_corrente%100);
                    printf("\nSaldo da conta poupanca: %lld,%02lldR$\n", user.saldo_poupanca/100, user.saldo_poupanca%100);

                    Sleep(1500);
                    break;
                }
                

                // CONSULTAR EXTRATO:
                case 6:{
                    extrato_imprimir(&user);
                    Sleep(1500);
                    break;
                }


                // SAIR:
                case 7:{
                    printf("\nSessao encerrada com sucesso. Obrigado por utilizar nossos servicos!\n");
                    printf("\n\n|VoidBank|");
                    return 3;
                    break;
                }


                default:
                    printf("\nOpcao invalida.\n");
                    Sleep(1500);
            }
            return status;
    }





     
/* Relatório do trabalho:

1- Perguntei a professora e ela me permitiu utilizar ponteiros mesmo que não havia sido ensinado em aula ainda


2- Funções não utilizadas:

    long long saldo_corrente(void);
    long long saldo_poupanca(void);

(acabei não usando essas funções pois não achei necessário visto que utilizei ponteiros)


*/