#include <stdio.h>

typedef struct{
    int vida, atk;
}Status;

void duelo(Status personagem1, Status personagem2){
    while((personagem1.vida > 0) && (personagem2.vida > 0)){
        personagem1.vida -= personagem2.atk;
        personagem2.vida -= personagem1.atk;
    }

    if(personagem1.vida <= 0 && personagem2.vida > 0){
        printf("Personagem 2\n");
    }
    else if(personagem2.vida <= 0 && personagem1.vida > 0){
        printf("Personagem 1\n");
    }
    else if(personagem1.vida <= 0 && personagem2.vida <= 0){
        printf("Empate\n");
    }
}

int main(){
    Status personagem1, personagem2;

    scanf("%d %d %d %d", &personagem1.vida, &personagem1.atk, &personagem2.vida, &personagem2.atk);

    duelo(personagem1, personagem2);

    return 0;
}