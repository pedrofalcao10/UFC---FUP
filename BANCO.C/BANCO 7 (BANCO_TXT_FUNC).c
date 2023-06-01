#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct{
    char conta[10];
    float saldo;
}BANCO;

int ja_existe_conta(int num_conta){
    FILE *arquivo;
    int i,linha_arquivo=0;
    char dados[256], num_conta_2[33];

    arquivo = fopen("banco.txt", "r");
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    while(fgets(dados, 256, arquivo) != NULL){
        i = 0;
        while(dados[i]!=','){
            num_conta_2[i] = dados[i];
            i++;
        }
        num_conta_2[i] = '\0';

        if(num_conta == atoi(num_conta_2)){
            fclose(arquivo);
            return 0;
        }
        linha_arquivo++;
    }
    
    fclose(arquivo);
    return -1;
}


BANCO* acessar_conta(int num_conta){
    BANCO *conta;
    FILE *arquivo;
    int i,j;
    char dados[256], num_conta_2[33],saldo[33];

    arquivo = fopen("banco.txt", "r");

    if(arquivo == NULL){
        printf("Erro na abertura do arquivo!");
        return NULL;
    }

    while(fgets(dados, 256, arquivo) != NULL){
        i = 0;
        while(dados[i]!=','){
            num_conta_2[i] = dados[i];
            i++;
        }
        num_conta_2[i] = '\0';

        if(num_conta == atoi(num_conta_2)){
            conta =(BANCO*)malloc(sizeof(BANCO));
            sprintf(conta->conta,"%d",num_conta);
            i++;
            j=0;
            while(dados[i]!='\n'){
                saldo[j] = dados[i];
                i++;
                j++;
            }
            saldo[j] = '\0';

            conta->saldo = atof(saldo);

            fclose(arquivo);
            return conta;
        }
    }
    
    fclose(arquivo);
    return NULL;

}


int criar_conta(){
    int num_conta;
    FILE *arquivo;
    
    printf("Por favor, insira o numero da conta: ");
    setbuf(stdin, NULL);
    scanf("%d", &num_conta);
    
    if(ja_existe_conta(num_conta)==0){
        printf("Já existe uma conta com esse número!\n");
    }
    else{
        arquivo = fopen("banco.txt", "a");
        if(arquivo == NULL){
            printf("Erro na abertura do arquivo!");
            return 1;
        }
        fprintf(arquivo, "%d,%f\n", num_conta, 0.0);
        fclose(arquivo);
    }

    return 0;
}

int remover_conta(){
    int i,num_conta, removeu = 0;
    char dados[256], num_conta_2[33];
    FILE *arquivo1, *arquivo2;
    
    printf("Por favor, insira o numero da conta: ");
    setbuf(stdin, NULL);
    scanf("%d", &num_conta);

    arquivo1 = fopen("banco.txt", "r");
    arquivo2 = fopen("banco.tmp", "w");

    if(arquivo1==NULL || arquivo2==NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    while(fgets(dados, 256, arquivo1) != NULL){
        i = 0;
        while(dados[i]!=','){
            num_conta_2[i] = dados[i];
            i++;
        }
        num_conta_2[i] = '\0';

        if(num_conta != atoi(num_conta_2)){
            fprintf(arquivo2, "%s",dados);
        }
        else{
            removeu = 1;
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);

    remove("banco.txt");
    rename("banco.tmp", "banco.txt");

    if(removeu == 0){
        printf("Conta inexistente. Tente novamente.\n\n");
    }

    return 0;
}

int salvar_mudanca(BANCO* conta){
    int i;
    char dados[256], num_conta_2[33];
    FILE *arquivo1, *arquivo2;
    
    arquivo1 = fopen("banco.txt", "r");
    arquivo2 = fopen("banco.tmp", "w");

    if(arquivo1==NULL || arquivo2==NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    while(fgets(dados, 256, arquivo1) != NULL){
        i = 0;
        while(dados[i]!=','){
            num_conta_2[i] = dados[i];
            i++;
        }
        num_conta_2[i] = '\0';

        if(strcmp(conta->conta,num_conta_2)==0){
            fprintf(arquivo2,"%s,%f\n",conta->conta,conta->saldo);
        }
        else{
            fprintf(arquivo2, "%s",dados);
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);

    remove("banco.txt");
    rename("banco.tmp", "banco.txt");

    return 0;
}

int salvar_mudancas(BANCO* conta1, BANCO* conta2){
    int i;
    char dados[256], num_conta_2[33];
    FILE *arquivo1, *arquivo2;
    
    arquivo1 = fopen("banco.txt", "r");
    arquivo2 = fopen("banco.tmp", "w");

    if(arquivo1==NULL || arquivo2==NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    while(fgets(dados, 256, arquivo1) != NULL){
        i = 0;
        while(dados[i]!=','){
            num_conta_2[i] = dados[i];
            i++;
        }
        num_conta_2[i] = '\0';

        if(strcmp(conta1->conta,num_conta_2)==0){
            fprintf(arquivo2,"%s,%f\n",conta1->conta,conta1->saldo);
        }
        else if(strcmp(conta2->conta,num_conta_2)==0){
            fprintf(arquivo2,"%s,%f\n",conta2->conta,conta2->saldo);
        }
        else{
            fprintf(arquivo2, "%s",dados);
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);

    remove("banco.txt");
    rename("banco.tmp", "banco.txt");

    return 0;
}

int inserir_credito(){
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
    return 0;    
}

int debito(){
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
    return 0;
}

int transferir(){
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
    return 0;   
}

int saldo(){
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
            criar_conta();
        }
        else if(opcao == 2){
            remover_conta();
        }
        else if(opcao == 3){
           inserir_credito();
        }
        else if(opcao == 4){
           debito();
        }
        else if(opcao == 5){
           transferir();
        }
        else if(opcao == 6){
            saldo();
        }
        else{
            printf("Operacao invalida. Tente novamente.\n\n");
        }
    }

    return 0;
}