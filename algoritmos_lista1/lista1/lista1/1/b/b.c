#include <stdio.h>
#include <stdlib.h>

//b) Implemente o algoritmo quicksort que trata elementos de tipo genérico repetidos
//no vetor.

void imprime(int * v , int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d  ",v[i]);

    printf("\n");
}

void troca(void **v, int i, int j){
    void *aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


int particiona2(void **v,int p, int r, int (*comp)(void *, void *)) {
    int i = p - 1, j = r + 1;
    void *pivo = v[p];
    while (1) {
        do  i++; while (comp(v[i],pivo) == -1 ); //(v[i] < pivo);
        do  j--; while (comp(v[j],pivo) == 1 ); // (v[j] > pivo);
        if  (i >= j)
            return j;
        troca(v,i,j);
    }
}

void quicksort2(void **v,int ini,int fim, int (*comp)(void *, void *)) {
    int meio;
    if (fim <= ini)
        return;
    meio = particiona2(v,ini,fim,comp);
    quicksort2(v,ini,meio,comp);
    quicksort2(v,meio+1,fim,comp);
}

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

#define TAM 10

int main(){
    int i,j;
    int u[TAM];
    int v[] = {2,1,7,20,5,2,20};

    for(i=0;i<TAM;i++)
       u[i] =  TAM+10-i;




 //   imprime(v,7);
   // quicksort2(v,0,6);
    //imprime(v,7);

    printf("\n\n\n\n\n repetidos \n\n\n\n");

    imprime(u,TAM);
//    quicksort2(u,0,TAM-1);
 //   imprime(u,TAM);


 //  quicksort2((void*)u,0,TAM-1,compara);

  //  imprime(u,TAM);

    return 0;
}
