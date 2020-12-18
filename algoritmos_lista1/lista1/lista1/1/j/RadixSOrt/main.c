#include <stdio.h>
#include<stdlib.h>
#include<math.h>

/*
k = maior numero do intervalo
n = tam do vet
d= coluna atual/ numero de digitos


*/
int* coutingSort(int a[], int k, int n ,int d)
{
    int i,g,h,aux;
    int *b=(int*)malloc(n*sizeof(int));
    int *c=(int*)malloc(k*sizeof(int));

    // Inicializando os contadores
    for (i=0; i<=k; i++)
    {
        c[i]=0;
    }

    //contando o nº de ocorrências de A[i]
    for (i=0;i<n; i++)
    {
        g=(pow(10,d));
        h=(pow(10,d-1));

        c[(a[i]%g)/h] = c[(a[i]%g)/h]+1;
        printf( "\n g=%d ", g);


        //c[a[i]]=((c[a[i]])+1);
    }

    printf("\n PRINT DOS VALORES DE C[i]\n");
    for (i=0;i<=k; i++)
    {
        printf("%d",c[i]);
    }

    printf("\n SOMANDO C[i]\n");
    for (i=1; i<=k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
       printf("\n printando a soma os valores de C[i]");
    for (i=0;i<=k; i++)
    {
        printf(" %d",c[i]);
    }

    for (i=n; i>=0;i--)
    {
        g=(pow(10,d));
        h=(pow(10,d-1));
        aux=(a[i]%g)/h;
        printf("   %d  ",aux);
        b[c[aux]-1]=a[i];
        c[aux]=c[aux]-1;
    }
       printf("\n valores de B \n");
    for (i=0;i<n; i++)
    {
        printf("  %d",b[i]);
    }
    printf("\n");
    return b;

}

int* radixSort( int *a,int n, int d)
{
  int i, *b;

  for( i=1; i<=d; i++)
  {
   b=coutingSort(a,9,n,i);
  }

  return b;
}

void main()
{
  int a[7]={794,257,127,375,439,911,271};
  int b [7]= {329,457,657,839,436,720,355};
  int d=3, n=7, i, *p;

  p=radixSort(b,n, d);

  for(i=0; i<7;i++)
  {
      printf(" %d ", p[i]);
  }

}
