#include <stdio.h>

typedef struct{
    int x, y
}pos;

pos posicao_atual(int x, int y){
    pos aux = {x, y};
    return aux;
}

void atualizar_cobra(pos cobra[], int tam, char direcao){
    for(int i = tam - 1 ; i > 0; i--) {
        cobra[i] = cobra[i-1];
    }
    
    if (direcao == 'U') {
        cobra[0].y--;
    }
    else if (direcao == 'R') {
        cobra[0].x++;
    }
    else if (direcao == 'D') {
        cobra[0].y++;
    }
    else if (direcao == 'L') {
        cobra[0].x--;
    }
}

void imprimir_cobra (pos posicao[],int tam, char d){
    for(int i = 0; i < tam; i++) {
        printf ("%i %i\n", posicao[i].x, posicao[i].y);
    }
}

int main(){
    int tam, x, y;
    char d;

    scanf ("%i%*c", &tam);

    pos posicao[tam];

    scanf ("%c%*c", &d);

    for(int i = 0; i < tam; i++) {
        scanf ("%i%*c %i%*c", &x, &y);
        posicao[i] = posicao_atual (x, y);
    }

    atualizar_cobra (posicao, tam, d);
    imprimir_cobra (posicao, tam, d);

    return 0;
}