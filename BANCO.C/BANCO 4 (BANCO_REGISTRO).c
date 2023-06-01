#include<stdio.h>
#include<string.h>

typedef struct{
    int conta;
    float saldo;
}BANCO;

void credito(int n, BANCO banco[n], int num_conta, float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(num_conta == banco[i].conta){
            banco[i].saldo += valor;
            existe++;
        }
    }
    if(existe == 0){
        printf("Conta inexistente. Tente novamente.\n\n");
    }
}
void debito(int n, BANCO banco[n], int num_conta, float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(num_conta == banco[i].conta){
            if(banco[i].saldo >= valor){
                banco[i].saldo -= valor;
                existe++;
            }
            else{
                printf("Saldo insuficiente. Tente outra operacao.\n\n");
                existe++;
            }
        }
    }
    if(existe == 0){
        printf("Conta inexistente. Tente novamente.\n\n");
    }
}
void transferir(int n, BANCO banco[n], int origem, int destino, float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(origem == banco[i].conta){
            if(banco[i].saldo >= valor){
                for(int j = 0; j < n; j++){
                    if(destino == banco[j].conta && destino != banco[i].conta){
                        banco[i].saldo -= valor;
                        banco[j].saldo += valor;
                        existe++;
                    }
                }
                if(existe == 0){
                    printf("Conta de destino inexistente. Tente novamente!---------\n\n");
                    existe++;
                }
            }
            else{
                printf("Saldo insuficiente. Tente outra operacao.\n\n");
                existe++;
            }
        }
    }
    if(existe == 0){
        printf("Conta de origem inexistente. Tente novamente.---\n\n");
    }
}
void extrato(int n, BANCO banco[n], int num_conta, float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(num_conta == banco[i].conta){
            printf("SALDO DA CONTA %d: %.2f RS\n", banco[i].conta, banco[i].saldo);
            existe++;
        }
    }
    if(existe == 0){
        printf("Conta inexistente. Tente novamente.\n\n");
    }
}

int main(){
    int n, num_conta, existe = 0;
    float valor;
    char tipo[35];

    printf("Por favor, insira quantas contas serao gerenciadas: ");
    scanf("%d", &n);

    BANCO banco[n];

    for(int i = 0; i < n; i++){
        printf("Por favor, insira o numero da %da conta: ", i+1);
        scanf("%d", &banco[i].conta);

        banco[i].saldo = 0;
    }

    while(strcmp(tipo, "0") != 0){
        printf("\nInsira o tipo de operacao:\n.......CREDITO\n........DEBITO\n....TRANSFERIR\n.........SALDO\n..'0' - FINALIZAR\n");
        setbuf(stdin, NULL);
        gets(tipo);

        if(strcmp(tipo, "credito") == 0){
            printf("\nPor favor, insira o numero da conta e o valor a ser creditado: ");
            scanf("%d %f", &num_conta, &valor);
            credito(n, banco, num_conta, valor);
        }
        else if(strcmp(tipo, "debito") == 0){
            printf("Por favor, insira o numero da conta e o valor a ser debitado: ");
            scanf("%d %f", &num_conta, &valor);
            debito(n, banco, num_conta, valor);
        }
        else if(strcmp(tipo, "transferir") == 0){
            int origem, destino;
            printf("Por favor, insira o numero da conta de origem, o numero da conta de destino e o valor a ser transferido: ");
            scanf("%d %d %f", &origem, &destino, &valor);
            transferir(n, banco, origem, destino, valor);
        }
        else if(strcmp(tipo, "saldo") == 0){
            printf("Por favor, insira o numero da conta para se fazer o extrato: ");
            scanf("%d", &num_conta);
            extrato(n, banco, num_conta, valor);
        }
        else if(strcmp(tipo, "0") == 0){
            break;
        }
        else{
            printf("Operacao invalida. Tente novamente.\n\n");
        }
    }

    for(int i = 0; i < n; i++){
        printf("SALDO DA CONTA %d: %.2f RS\n", banco[i].conta, banco[i].saldo);
    }

    return 0;
}