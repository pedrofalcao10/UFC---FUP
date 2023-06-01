#include<stdio.h>
#include<string.h>

void credito(int n, int conta[n], int num_conta, float saldo[n], float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(num_conta == conta[i]){
            saldo[i] += valor;
            existe++;
        }
    }
    if(existe == 0){
        printf("Conta inexistente. Tente novamente.\n\n");
    }
}

void debito(int n, int conta[n], int num_conta, float saldo[n], float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(num_conta == conta[i]){
            if(saldo[i] >= valor){
                saldo[i] -= valor;
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

void transferir(int n, int conta[n], int origem, int destino, float saldo[n], float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(origem == conta[i]){
            if(saldo[i] >= valor){
                for(int j = 0; j < n; j++){
                    if(destino == conta[j] && destino != conta[i]){
                        saldo[i] -= valor;
                        saldo[j] += valor;
                        existe++;
                    }
                }
                if(existe == 0){
                    printf("Conta de destino inexistente. Tente novamente!\n\n");
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
        printf("Conta de origem inexistente. Tente novamente.\n\n");
    }
}

void extrato(int n, int conta[n], int num_conta, float saldo[n], float valor){
    int existe = 0;
    for(int i = 0; i < n; i++){
        if(num_conta == conta[i]){
            printf("SALDO DA CONTA %d: %.2f RS\n", conta[i], saldo[i]);
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

    int conta[n];
    float saldo[n];

    for(int i = 0; i < n; i++){
        printf("Por favor, insira o numero da %da conta: ", i+1);
        scanf("%d", &conta[i]);

        saldo[i] = 0;
    }

    while(strcmp(tipo, "0") != 0){
        printf("\nInsira o tipo de operacao:\n'1'.......CREDITO\n'2'........DEBITO\n'3'....TRANSFERIR\n'4'.........SALDO\n..'0' - FINALIZAR\n");
        setbuf(stdin, NULL);
        gets(tipo);

        if(strcmp(tipo, "credito") == 0){
            printf("\nPor favor, insira o numero da conta e o valor a ser creditado: ");
            scanf("%d %f", &num_conta, &valor);
            credito(n, conta, num_conta, saldo, valor);
        }
        else if(strcmp(tipo, "debito") == 0){
            printf("Por favor, insira o numero da conta e o valor a ser debitado: ");
            scanf("%d %f", &num_conta, &valor);
            debito(n, conta, num_conta, saldo, valor);
        }
        else if(strcmp(tipo, "transferir") == 0){
            int origem, destino;
            printf("Por favor, insira o numero da conta de origem, o numero da conta de destino e o valor a ser transferido: ");
            scanf("%d %d %f", &origem, &destino, &valor);
            transferir(n, conta, origem, destino, saldo, valor);
        }
        else if(strcmp(tipo, "saldo") == 0){
            printf("Por favor, insira o numero da conta para se fazer o extrato: ");
            scanf("%d", &num_conta);
            extrato(n, conta, num_conta, saldo, valor);
        }
        else if(strcmp(tipo, "0") == 0){
            break;
        }
        else{
            printf("Operacao invalida. Tente novamente.\n\n");
        }
    }

    for(int i = 0; i < n; i++){
        printf("SALDO DA CONTA %d: %.2f RS\n", conta[i], saldo[i]);
    }

    return 0;
}