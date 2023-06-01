/*
>>>>>>>>
1
0
========
[]
<<<<<<<<

>>>>>>>>
1
3 10 16 11
========
[10, 16, 11]
<<<<<<<<

>>>>>>>>
3
3 10 16 11
1 88
4 34 12 32 100
========
[10, 16, 11]
[88]
[34, 12, 32, 100]
<<<<<<<<

>>>>>>>>
4
3 10 16 11
1 88
4 34 12 32 100
0
========
[10, 16, 11]
[88]
[34, 12, 32, 100]
[]
<<<<<<<<
 */

#include <stdio.h>

void print_vet(int size, int vet[size]){
    printf("[");
    for(int i = 0; i < size; i++){
        if(i != size - 1){
            printf("%d, ", vet[i]);
        }
        else{
            printf("%d", vet[i]);
        }
    }
    printf("]\n");
}

int main(){
    int qtd = 0;
    scanf("%d", &qtd); // quant de casos teste

    while(qtd--){
        int size = 0;
        scanf("%d", &size); // tamanho do vetor desse caso teste

        int vet[size]; // cria vetor com o tamanho escolhido

        for(int i = 0; i < size; i++){
            scanf("%d", &vet[i]); // l
        }
        print_vet(size, vet);
    }
}