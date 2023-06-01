#include <stdio.h>
#include <math.h>

typedef struct{
    float x, y;
}Ponto;

float distancia(Ponto p1, Ponto p2){
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

Ponto proximo(Ponto vetor[], int n, Ponto p){
    int ponto_proximo;
    for(int i = 0; i+1 < n; i++){
        if(distancia(vetor[i+1], p) < distancia(vetor[i], p)){
            ponto_proximo = i+1;
        }
    }
    return vetor[ponto_proximo];
}

int main(){

    Ponto p;
    scanf("%f %f", &p.x, &p.y);

    int n;

    scanf("%d", &n);

    Ponto vet[n];

    for(int i = 0; i < n; i++){
        scanf("%f %f", &vet[i].x, &vet[i].y);
    }

    Ponto q = proximo(vet, n, p);

    printf("%.2f %.2f\n", q.x, q.y);
}