#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[100];
    float n1, n2, n3, media;
}ALUNOS;

void ordena(int n, ALUNOS alunos[n]){
    int i;
    ALUNOS aux[1];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(alunos[j].media < alunos[i].media){
            aux[0].media = alunos[j].media;
            alunos[j].media = alunos[i].media;
            alunos[i].media = aux[0].media;
            
            aux[0].n1 = alunos[j].n1;
            alunos[j].n1 = alunos[i].n1;
            alunos[i].n1 = aux[0].n1;
            
            aux[0].n2 = alunos[j].n2;
            alunos[j].n2 = alunos[i].n2;
            alunos[i].n2 = aux[0].n2;
            
            aux[0].n3 = alunos[j].n3;
            alunos[j].n3 = alunos[i].n3;
            alunos[i].n3 = aux[0].n3;

            strcpy(aux[0].nome, alunos[j].nome);
            strcpy(alunos[j].nome, alunos[i].nome);
            strcpy(alunos[i].nome, aux[0].nome);
            }
        }
    }
}

int main (){
    int n;
    scanf("%d", &n);

    ALUNOS alunos[n], aux[1];

    for(int i = 0; i < n; i++){
        setbuf(stdin, NULL);
        gets(alunos[i].nome);

        scanf("%f %f %f", &alunos[i].n1, &alunos[i].n2, &alunos[i].n3);

        alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3)/3;
    }

    ordena(n, alunos);

    for(int i = n-1; i >= 0; i--){
        printf("%d: %s\n", n-1-i, alunos[i].nome);
        printf("   Media: %.2f\n", alunos[i].media);
        printf("   N1: %.2f, N2: %.2f, N3: %.2f\n", alunos[i].n1, alunos[i].n2, alunos[i].n3);
    }

    return 0;
}