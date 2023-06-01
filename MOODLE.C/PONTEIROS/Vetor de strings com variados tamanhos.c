#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void end_string(char *s){
	int i=0;
	while(s[i] != '\n' && s[i] !='\0'){
		i++;
	}
	s[i] = '\0';
}


int encontrar_numero(char *s){
    int i = 0;
    char *aux;

    while(s[i] != ' '){
        i++;
    }

    aux = (char*)malloc(sizeof(char)*(i+1));
    
    for(int j=0;j<i;j++){
        aux[j]=s[j];
    }
    aux[i] = '\0';

    i = atoi(aux);

    free(aux);

    return i;
    
}

void copiar_string(char *s, char *v){
    int i=0,j=0;
    while(v[i]!=' '){
        i++;
    }
    i++;
    while(v[i]!='\0'){
        s[j] = v[i];
        i++;
        j++;
    }
    s[j]=v[i];
}

void ordenar_strings(char** s, int n){
    char *aux;
    int i,j;
    for(i=1;i<n;i++){
        aux = s[i];
        j = i-1;
        while(j>=0 && strcmp(aux,s[j])<0){
            s[j+1]=s[j];
            j--;
        }
        s[j+1] = aux;
    }


}

int main(){
    int n, aux_n;
    char **v, aux[256];
    
    scanf("%d\n", &n);
    
    v = (char**)malloc(sizeof(char*)*n);
    
    //Alocacao de Memoria falhou
    if(v==NULL){
        return 1;
    }

    for(int i=0;i<n;i++){
        fgets(aux, 256,stdin);
        end_string(aux);
        aux_n =encontrar_numero(aux);
        
        v[i] = (char*)malloc(sizeof(char)*(aux_n+1));

        //Testando se houve erro na alocacao
        if(v[i]==NULL){
            for(int j =0;j<n;j++){
                free(v[j]);
            }
            free(v);
            return 1;
        }

        copiar_string(v[i],aux);
    
    }

    ordenar_strings(v,n);
    
    for(int i=0;i<n;i++){
        printf("%s\n",v[i]);
    }

    //Desalocando o vator de vetores da memÃ³ria
    for(int i=0;i<n;i++){
        free(v[i]);
    }
    free(v);
    return 0;
}