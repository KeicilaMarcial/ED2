#include "stdio.h"
#include "stdlib.h"


void quickSort(int *V, int inicio, int fim){
    int pivo;
    if(fim>inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1,fim);
    }
}

int particiona(int *V, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio; // i
    dir = final; // j
    pivo = V[inicio];
    while(esq<dir){
        while(V[esq]<=pivo)
            esq++;
        while(V[dir]>pivo)
            dir--;
        if(esq<dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir]=aux;
        }
    }

    V[inicio] = V[dir];
    V[dir]=pivo;
    return dir;
}
/* particiona() que escolhe o pivo a partir de  3 valores aleatorios */
int particiona(int *V, int inicio, int final){
    int esq, i, j, tam, dir, pivo, aux;
    int vetAux[2];
    int tam = sizeof(V)/sizeof(int);
    for(i=0;i<=2;i++){
        j = rand()%tam-1;
        vetAux[i] = V[j];
    }
    for(i=0;i<=2;i++){
        if(vetAux[i]>vetAux[i+1] && vetAux[i]<vetAux[i+2])
            pivo = vetAux[i];
    }
    esq = inicio; // i
    dir = final; // j
    //pivo = V[inicio];
    while(esq<dir){
        while(V[esq]<=pivo)
            esq++;
        while(V[dir]>pivo)
            dir--;
        if(esq<dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir]=aux;
        }
    }

    V[inicio] = V[dir];
    V[dir]=pivo;
    return dir;
}
/* Entrada para ser estave */

typedef struct{
    int chave;
    int posicao;

}Estavel;

for(i=0; i<tam; i++){
        Estavel Q[tam];
        Q[i].chave = V[i];
        Q[i].posicao = i;
}
