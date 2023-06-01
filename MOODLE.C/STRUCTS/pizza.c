#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    int pontos; 
}RESTAURANTE;

void max_pontos(int n, RESTAURANTE restaurante[n]){
    char melhor[30];
    int posicao_melhor, maior_pontos = 0;
    for(int i = 0; i < n; i++){
        if(restaurante[i].pontos > maior_pontos){
            maior_pontos = restaurante[i].pontos;
            posicao_melhor = i;
        }
        else if(restaurante[i].pontos == maior_pontos){
            if(strcmp(restaurante[i].nome, restaurante[posicao_melhor].nome) < 0){
                posicao_melhor = i;
            }
        }
    }
    printf("%s\n", restaurante[posicao_melhor].nome);
}

int main (){
    int n;

    scanf("%d", &n);

    RESTAURANTE restaurante[n];

    for(int i = 0; i < n; i++){
        scanf("%s %d", &restaurante[i].nome, &restaurante[i].pontos);
    }

    max_pontos(n, restaurante);

    return 0;
}