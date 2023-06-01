#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[25], sexo;
    int idade;
}IDOSO;

int main (){
    int n, mulheres = 0, idade = 0, mais_velha;

    scanf("%d", &n);

    IDOSO idoso[n], aux[1];

    for(int i = 0; i < n; i++){
        scanf(" %s %d %c", &idoso[i].nome, &idoso[i].idade, &idoso[i].sexo);
    
        if(idoso[i].sexo == 'f'){
            mulheres++;
        }
    }

    if(mulheres == 0){
        printf("nao tem mulher\n");
    }
    else{
        for(int i = 0; i < n; i++){
            if(idoso[i].sexo == 'f'){
                if(idoso[i].idade > idade){
                    idade = idoso[i].idade;
                    mais_velha = i;
                }
            }
        }
        printf("%s\n", idoso[mais_velha].nome);
    }
    
    return 0;
}