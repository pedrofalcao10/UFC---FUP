#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int collatz(int n){
    int count = 0;

    while(n != 1){
        if(n%2 == 0){
            n = n/2;
            count++;
        }
        else{
            n = 3*n+1;
            count++;
        }
    }
    return count;
}

bool quadradoperfeito(long n){
    bool t = true;
    int a = sqrt(n);

    if(a*a != n){
        t = false;
    }

    return t;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    long portas[n], seq_collatz[n], achou = -1, maior = 0;

    for(int i = 0; i < n; i++){
        scanf("%ld", &portas[i]);
        seq_collatz[i] = collatz(portas[i]);
    }

    for(int i = 0; i < n; i++){
        if(quadradoperfeito(portas[i]) == true){
            if(seq_collatz[i] > maior){
                maior = seq_collatz[i];
                achou = i;
            }
        }
    }

    if(achou == -1){
        printf("a porta nao existe\n");
    }
    else{
        printf("%ld\n", portas[achou]);
    }
}