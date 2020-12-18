#include<stdio.h>
#include<stdlib.h>
/*CABEÇALHO
    n -> tamanho do vetor
    max -> maior elemento do vetor
*/

#define MAX 255
void countingSort(int v[],int n)
{
   int i;
   int saida [n];
   int *cont;
   cont =(int *)calloc(MAX, sizeof (int)); // o calocc inicia as posições com 0
  // for(i=0;i<MAX;i++)printf("%d\n",cont[i]);
   for(i=0;i<n;i++) cont[v[i]]++; //somando as ocorrencias de mesmo elemento
   for(i=1;i<=MAX;i++) cont[i]=cont[i]+cont[i-1];// somando o indice na posição i com i-
  // o valor de count[aux] é  indice do vetor saida
   for (i=n-1; i>=0; i--){
    int aux = v[i];
    saida [cont[aux]-1]=aux;
    --cont[aux];// decrementando o valor existente no cont[aux]
   }
   for (i=0;i<n;i++) v[i]=saida[i];
}


main(){
        int v[]={6,6,2,7,9,9,0};
            int i=0;
            countingSort (v, 7);

            for(i=0;i<7;i++){
                printf("%d\n", v[i]);
            }
        system("pause");
        }
