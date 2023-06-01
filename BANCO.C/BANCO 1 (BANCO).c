#include<stdio.h>
#include<string.h>

int main(){
    int conta1, conta2, conta3, num_conta, origem, destino;
    float saldo1 = 0, saldo2 = 0, saldo3 = 0, valor;
    char tipo[35];

    printf("Por favor, insira o numero da primeira conta: ");
    scanf("%d", &conta1);
    printf("Por favor, insira o numero da segunda conta: ");
    scanf("%d", &conta2);
    printf("Por favor, insira o numero da terceira conta: ");
    scanf("%d", &conta3);

    while(strcmp(tipo, "0") != 0){
        printf("\nInsira o tipo de operacao:\n..........CREDITO\n...........DEBITO\n.......TRANSFERIR\n............SALDO\n..'0' - FINALIZAR\n");
        setbuf(stdin, NULL);
        gets(tipo);

        if(strcmp(tipo, "credito") == 0){
            printf("Por favor, insira o numero da conta e o valor a ser creditado: ");
            scanf("%d %f", &num_conta, &valor);

            if(num_conta == conta1){
                saldo1 += valor;
            }
            else if(num_conta == conta2){
                saldo2 += valor;
            }
            else if(num_conta == conta3){
                saldo3 += valor;
            }
            else{
                printf("Conta inexistente. Tente novamente.\n\n");/////
            }
        }
        else if(strcmp(tipo, "debito") == 0){
            printf("Por favor, insira o numero da conta e o valor a ser debitado: ");
            scanf("%d %f", &num_conta, &valor);

            if(num_conta == conta1 && saldo1 >= valor){
                saldo1 -= valor;
            }
            else if(num_conta == conta2 && saldo2 >= valor){
                saldo2 -= valor;
            }
            else if(num_conta == conta3 && saldo3 >= valor){
                saldo3 -= valor;
            }
            else{
                printf("Operacao invalida. Tente novamente.\n\n");/////
            }
        }
        else if(strcmp(tipo, "transferir") == 0){
            printf("Por favor, insira o numero da contade origem, o numero da conta de destino e o valor a ser transferido: ");
            scanf("%d %d %f", &origem, &destino, &valor);

            if(origem == conta1 && saldo1 >= valor){
                if(destino == conta2){
                    saldo1 -= valor;
                    saldo2 += valor;
                }
                else if(destino == conta3){
                    saldo1 -= valor;
                    saldo3 += valor;
                }
                else{
                    printf("Operacao invalida. Tente novamente.\n\n");/////
                }

            }
            else if(origem == conta2 && saldo2 >= valor){
                if(destino == conta1){
                    saldo2 -= valor;
                    saldo1 += valor;
                }
                else if(destino == conta3){
                    saldo2 -= valor;
                    saldo3 += valor;
                }
                else{
                    printf("Operacao invalida. Tente novamente.\n\n");/////
                }
            }
            else if(origem == conta3 && saldo3 >= valor){
                if(destino == conta1){
                    saldo3 -= valor;
                    saldo1 += valor;
                }
                else if(destino == conta2){
                    saldo3 -= valor;
                    saldo2 += valor;
                }
                else{
                    printf("Operacao invalida. Tente novamente.\n\n");/////
                }
            }
            else{
                printf("Operacao invalida. Tente novamente.\n\n");/////
            }
        }
        else if(strcmp(tipo, "saldo") == 0){
            printf("Por favor, insira o numero da conta para se fazer o extrato: ");
            scanf("%d", &num_conta);

            if(num_conta == conta1){
                printf("SALDO DA CONTA %d: %.2f RS\n", conta1, saldo1);
            }
            else if(num_conta == conta2){
                printf("SALDO DA CONTA %d: %.2f RS\n", conta2, saldo2);
            }
            else if(num_conta == conta3){
                printf("SALDO DA CONTA %d: %.2f RS\n", conta3, saldo3);
            }
            else{
                printf("Conta inexistente. Tente novamente.\n\n");/////
            }
        }
        else if(strcmp(tipo, "0") == 0){
            break;
        }
        else{
            printf("Operacao invalida. Tente novamente.\n\n");/////
        }
    }

    printf("\nSALDO DA CONTA %d: %.2f RS\n\n", conta1, saldo1);
    printf("SALDO DA CONTA %d: %.2f RS\n\n", conta2, saldo2);
    printf("SALDO DA CONTA %d: %.2f RS\n\n", conta3, saldo3);

    return 0;
}