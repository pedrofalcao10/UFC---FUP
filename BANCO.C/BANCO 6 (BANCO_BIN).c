#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct{
    char conta[10];
    float saldo;
}BANCO;

int ja_existe_conta(int num_conta){
    FILE *arquivo;
    BANCO *conta_aux;

    arquivo = fopen("banco.txt", "rb");
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    conta_aux =(BANCO*)malloc(sizeof(BANCO));
    while(fread(conta_aux,sizeof(BANCO),1, arquivo)){
        if(atoi(conta_aux->conta) == num_conta){
            fclose(arquivo);
            free(conta_aux);
            return 0;
        }
    }
    
    fclose(arquivo);
    free(conta_aux);
    return -1;
}

BANCO* acessar_conta(int num_conta){
    BANCO *conta_aux;
    FILE *arquivo;

    arquivo = fopen("banco.txt", "rb");

    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!");
        return NULL;
    }

    conta_aux =(BANCO*)malloc(sizeof(BANCO));
    while(fread(conta_aux,sizeof(BANCO),1, arquivo)){
        if(atoi(conta_aux->conta) == num_conta){

            fclose(arquivo);
            return conta_aux;
        }
    }
    
    fclose(arquivo);
    free(conta_aux);
    return NULL;

}

int salvar_mudanca(BANCO* conta){
    FILE *arquivo1, *arquivo2;
    BANCO *conta_aux;

    arquivo1 = fopen("banco.txt", "rb");
    arquivo2 = fopen("banco.tmp", "wb");

    if(arquivo1==NULL || arquivo2==NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    conta_aux=(BANCO*)malloc(sizeof(BANCO));
    while(fread(conta_aux,sizeof(BANCO),1, arquivo1)){
        if(strcmp(conta->conta, conta_aux->conta)==0){
            fwrite(conta,sizeof(BANCO),1, arquivo2);
        }
        else{
            fwrite(conta_aux,sizeof(BANCO),1, arquivo2);
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);
    free(conta_aux);

    remove("banco.txt");
    rename("banco.tmp", "banco.txt");

    return 0;
}

int salvar_mudancas(BANCO* conta1, BANCO* conta2){
    BANCO *conta_aux;
    FILE *arquivo1, *arquivo2;
    
    arquivo1 = fopen("banco.txt", "rb");
    arquivo2 = fopen("banco.tmp", "wb");

    if(arquivo1==NULL || arquivo2==NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    conta_aux = (BANCO*)malloc(sizeof(BANCO));
    while(fread(conta_aux,sizeof(BANCO),1, arquivo1)){
        if(strcmp(conta1->conta,conta_aux->conta)==0){
            fwrite(conta1,sizeof(BANCO),1, arquivo2);
        }
        else if(strcmp(conta2->conta,conta_aux->conta)==0){
            fwrite(conta2,sizeof(BANCO),1, arquivo2);
        }
        else{
           fwrite(conta_aux,sizeof(BANCO),1, arquivo2);
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);
    free(conta_aux);

    remove("banco.txt");
    rename("banco.tmp", "banco.txt");

    return 0;
}

int main(){
    int opcao = 1;
    FILE *arquivo;

    arquivo = fopen("banco.txt","wt");
    fclose(arquivo);
    while(opcao != 0){
        printf("\nInsira a opcao de operacao:\n1......CRIAR CONTA\n2....REMOVER CONTA\n3..........CREDITO\n4...........DEBITO\n5.......TRANSFERIR\n6............SALDO\n..'0' - FINALIZAR\n");
        scanf("%d", &opcao);

        
        if(opcao == 0){
            printf("Finalizado!\n\n");
        }
        else if(opcao == 1){
            int num_conta;
            FILE *arquivo;
            BANCO *conta_aux;

            printf("Por favor, insira o numero da conta: ");
            setbuf(stdin, NULL);
            scanf("%d", &num_conta);

            if(ja_existe_conta(num_conta)==0){
                printf("Já existe uma conta com esse número!\n");
            }
            else{
                arquivo = fopen("banco.txt", "ab");
                if(arquivo == NULL){
                    printf("Erro na abertura do arquivo!");
                    return 1;
                }

                conta_aux = (BANCO*)malloc(sizeof(BANCO));
                sprintf(conta_aux->conta,"%d",num_conta);
                conta_aux->saldo = 0.0;

                fwrite(conta_aux,sizeof(BANCO),1, arquivo);
                free(conta_aux);
                fclose(arquivo);
            }
        }
        else if(opcao == 2){
            int i,num_conta, removeu = 0;
            BANCO *conta_aux;
            FILE *arquivo1, *arquivo2;
            
            printf("Por favor, insira o numero da conta: ");
            setbuf(stdin, NULL);
            scanf("%d", &num_conta);

            arquivo1 = fopen("banco.txt", "rb");
            arquivo2 = fopen("banco.tmp", "wb");

            if(arquivo1==NULL || arquivo2==NULL){
                printf("Erro na abertura do arquivo!");
                return 1;
            }

            conta_aux = (BANCO*)malloc(sizeof(BANCO));
            while(fread(conta_aux,sizeof(BANCO),1, arquivo1)){
                if(atoi(conta_aux->conta) != num_conta){
                    fwrite(conta_aux,sizeof(BANCO),1, arquivo2);
                }
                else{
                    removeu = 1;
                }
            }
            
            fclose(arquivo1);
            fclose(arquivo2);
            free(conta_aux);

            remove("banco.txt");
            rename("banco.tmp", "banco.txt");

            if(removeu == 0){
                printf("Conta inexistente. Tente novamente.\n\n");
            }
        }
        else if(opcao == 3){
            int num_conta;
            float valor;
            FILE *arquivo;
            BANCO *conta;

            printf("Por favor, insira o numero da conta e o valor a ser creditado: ");
            scanf("%d %f", &num_conta, &valor);
            
            conta = acessar_conta(num_conta);
            if(conta == NULL){
                printf("Conta inexistente. Tente novamente.\n\n");
                return 1;
            }
            
            conta->saldo += valor;
            salvar_mudanca(conta);

            free(conta);
        }
        else if(opcao == 4){
            int num_conta;
            float valor;
            FILE *arquivo;
            BANCO *conta;

            printf("Por favor, insira o numero da conta e o valor a ser debitado: ");
            scanf("%d %f", &num_conta, &valor);
            
            conta = acessar_conta(num_conta);
            if(conta == NULL){
                printf("Conta inexistente. Tente novamente.\n\n");
                return 1;
            }

            if(conta->saldo>=valor){
                conta->saldo -= valor;
                salvar_mudanca(conta);
            }
            else{
                printf("Saldo insuficiente. Tente outra operacao.\n\n");
            }
            
            free(conta);
        }
        else if(opcao == 5){
            int origem,destino;
            float valor;
            FILE *arquivo;
            BANCO *conta_origem, *conta_destino;

            printf("Por favor, insira o numero da conta de origem, o numero da conta de destino e o valor a ser transferido: ");
            scanf("%d %d %f", &origem, &destino, &valor);
            
            conta_origem = acessar_conta(origem);
            if(conta_origem == NULL){
                printf("Conta de origem nao existe. Tente novamente!\n\n");
                return 1;
            }

            conta_destino = acessar_conta(destino);
            if(conta_destino == NULL){
                printf("Conta de destino inexistente. Tente novamente!\n\n");
                free(conta_origem);
                return 1;
            }

            if(conta_origem->saldo>=valor){
                conta_origem->saldo -= valor;
                conta_destino->saldo +=valor;
                salvar_mudancas(conta_origem, conta_destino);
            }
            else{
                printf("Saldo insuficiente. Tente outra operacao.\n\n");
            }
            
            free(conta_origem);
            free(conta_destino);
        }
        else if(opcao == 6){
            int num_conta;
            BANCO *conta;

            printf("Por favor, insira o numero da conta para se fazer o extrato: ");
            scanf("%d", &num_conta);

            conta = acessar_conta(num_conta);
            if(conta == NULL){
                printf("Conta inexistente. Tente novamente.\n\n");
                return 1;
            }

            printf("SALDO DA CONTA %s: %.2f RS\n", conta->conta, conta->saldo);
            free(conta);
        }
        else{
            printf("Operacao invalida. Tente novamente.\n\n");
        }
    }

    return 0;
}