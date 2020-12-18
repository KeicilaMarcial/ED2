#include<stdio.h>
#include<stdlib.h>
#define TAM 10
#define MAX 255
void insertionSort(int v[], int n)
{
   int i,j=0,aux;
   for (i=1;i<n;i++){
    aux = v[i];
    j=i-1;
      while(j>=0 && aux<v[j]){
        v[j+1]=v[j];
        j--;
      }
      v[j+1]=aux;
   }

}

void BucketSort(int v[], int n)
{
  int i, j;
  int *cont;
  cont =(int *)calloc(TAM, sizeof (int));
 /*for(i=0; i < n; i++)
 {
  (cont[v[i]])++;
 }*/
 for(i=0,j=0; i < n; i++)
 {
  for(; cont[i]>0;(cont[i])--)
  {
   v[j++] = i;
  }
 }
    insertionSort(v,n);
}

main()
{
    //int v[]={38,27,43,3,9,82,10};
   int v[]={1,0,1,1,0,0,2};
    int i=0;
    BucketSort(v,7);

    for(i=0;i<7;i++){
        printf("%d\n", v[i]);
    }
system("pause");
}
