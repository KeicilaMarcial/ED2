#include<stdio.h>
#include<stdlib.h>

/* ------ CABEÇALHO-----
    vetor v[1....m]
*/



static void constroiHeap (int v[], int inicio, int fim)
{
  int aux=v[inicio];
  int j= inicio*2+1;
  while(j<=fim){
    if(j<fim){
        //pai tem 2 filhos, quem é o maior?
        if(v[j]<v[j+1]){
            j++;
        }
    }
    if(aux<v[j]){
        //filho maior que o pai?
        //filho se torna o pai, repetir o processo
        v[inicio]=v[j];
        inicio=j;
        j=(2*inicio)+1;
    }else{
        j=fim+1;

    }
  }//antigo pai ocupa lugar do ultimo filho analisado
  v[inicio]=aux;

}
void heapSort (int n, int v[])
{
    int i, aux;
    //cria heap apartir dos dados
    for(i=(n-1)/2;i>=0;i--){
        constroiHeap(v,i,n-1);
    }
    for(i=n-1;i>=1;i--){
    // pegando o maior elemento do heap e colocando na sua correspondente dovetor, realizando a troca
        aux=v[0];
        v[0]=v[i];
        v[i]=aux;
        constroiHeap(v,0,i-1);
    }
}
main(){


    int v[]={38,1,43,3,1,82,10};
    int i=0;
    heapSort(7,v);
    for(i=0;i<7;i++){
        printf("%d\n", v[i]);
    }
system("pause");
}
