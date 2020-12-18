#include <stdio.h>
#include <stdlib.h>

//a) Implemente o algoritmo quicksort aplicado a sequências de elementos de tipo
//genérico sem repetição de elementos.
// a comparado com b
// retorna 0 se igual 1 maior e -1 menor
int compara(void *a, void *b) {
	int *x = (int *)a;
	int *y = (int *)b;

	if (x > y)
		return 1;
	else if (x < y)
		return -1;
    else
        return 0;
}

void imprime(int * v , int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d  ",v[i]);

    printf("\n");
}





int particiona(void **v, int inicio, int fim, int (*comp)(void *, void *)){
    void *pivo = v[fim];
    int i = inicio, j = fim -1;

    while(i <= j){
        if(comp(v[i],pivo) == -1 || comp(v[i],pivo) == 0){ // v[i] <= pivo
            i++;
        } else {
            if (comp(v[j],pivo) == 1) { //  v[j] > pivo
            j--;
            }
            else {
            void *aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
        }
    }
    v[fim] = v[i];
    v[i] = pivo;
    return i;
}

void quicksort(void *v, int inicio, int fim, int (*comp)(void *, void *)){
    if (inicio < fim) {
        int r = particiona(v, inicio, fim, comp);
        quicksort(v,inicio,r-1, comp);
        quicksort(v,r+1,fim, comp);
    }
}
#define TAM 10
int main(){
    int i,j;
    int u[TAM];
    int v[] = {11,12,3,11,12,33};

    for(i=0;i<TAM;i++)
        u[i] = TAM+10 -i;

    /*
    imprime(v,6);
    quicksort(v,0,5);
    imprime(v,6);
    */

    quicksort(u,0,TAM-1,compara);

   imprime(u,TAM);

    return 0;

}
