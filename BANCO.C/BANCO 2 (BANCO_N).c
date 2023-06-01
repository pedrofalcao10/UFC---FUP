#include<stdio.h>
#include<string.h>

int main(){
    int n, num_conta, origem, destino, existe = 0;
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
        printf("\nInsira o tipo de operacao:\n..........CREDITO\n...........DEBITO\n.......TRANSFERIR\n............SALDO\n..'0' - FINALIZAR\n");
        setbuf(stdin, NULL);
        gets(tipo);

        if(strcmp(tipo, "credito") == 0){
            printf("Por favor, insira o numero da conta e o valor a ser creditado: ");
            scanf("%d %f", &num_conta, &valor);

            for(int i = 0; i < n; i++){
                if(num_conta == conta[i]){
                    saldo[i] += valor;
                    existe++;
                }
            }
            if(existe == 0){
                printf("Conta inexistente. Tente novamente.\n\n");
            }
            existe = 0;
        }
        else if(strcmp(tipo, "debito") == 0){
            printf("Por favor, insira o numero da conta e o valor a ser debitado: ");
            scanf("%d %f", &num_conta, &valor);
            
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
            existe = 0;
        }
        else if(strcmp(tipo, "transferir") == 0){
            printf("Por favor, insira o numero da conta de origem, o numero da conta de destino e o valor a ser transferido: ");
            scanf("%d %d %f", &origem, &destino, &valor);
            
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
            existe = 0;
        }
        else if(strcmp(tipo, "saldo") == 0){
            printf("Por favor, insira o numero da conta para se fazer o extrato: ");
            scanf("%d", &num_conta);

            for(int i = 0; i < n; i++){
                if(num_conta == conta[i]){
                    printf("SALDO DA CONTA %d: %.2f RS\n", conta[i], saldo[i]);
                    existe++;
                }
            }
            if(existe == 0){
                printf("Conta inexistente. Tente novamente.\n\n");
            }
            existe = 0;
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