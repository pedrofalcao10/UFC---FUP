#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef enum {LT, EQ, GT} compare; // less than, equal, greater than

compare compararDatas(Data dt1, Data dt2){
    compare res = GT;
    if(dt1.ano < dt2.ano){
        res = LT;
    }
    else if(dt1.ano == dt2.ano){
        if (dt1.mes < dt2.mes){
            res = LT;
        }
        else if(dt1.mes == dt2.mes){
            if(dt1.dia < dt2.dia){
                res = LT;
            }
            else if(dt1.dia == dt2.dia){
                res = EQ;
            }
        }
    }
    return res;
}

int main(){
    Data d1, d2;
    compare res;

    scanf("%d %d %d %d %d %d", &d1.dia, &d1.mes, &d1.ano, &d2.dia, &d2.mes, &d2.ano);

    res = compararDatas(d1,d2);
    if(res == 0){
        printf("Mais antiga\n");
    }
    else if(res == 1){
        printf("Iguais\n");
    }
    else{
        printf("Mais recente\n");
    }

    return 0;
}