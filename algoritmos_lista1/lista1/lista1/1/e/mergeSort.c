#include<stdio.h>
#include<stdlib.h>


/*-----CABEÇALHO----------
    p = inicio
    q = meio
    r = fim

*----------------------------/


/*------------------- FUNÇÕES DE INTERCALAÇÃO-----------------------------------------------------*/
static void intercala1 (int p, int q, int r, int v[])
{
   int *w;                                 //  1
   w = malloc ((r-p) * sizeof (int));     //  2
   int i = p, j = q;                       //  3
   int k = 0;
                               //  4
   while (i < q && j < r) {                //  5
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);
}

/*intercala2 -Primeiro, copia o vetor v[p..q-1] para o espaço de trabalho w[0..q-p-1];
 depois, copia v[q..r-1] para o espaço w[q-p..r-p-1] em ordem inversa.
 Com isso, a metade esquerda de w serve de sentinela para a metade direita durante o processo de intercalação,
 e vice-versa.  Assim, a intercalação de w[0..q-p-1] com w[q-p..r-p-1] pode ser feita com base na comparação  w[i] <= w[j]
 sem que seja preciso verificar, a cada iteração, as condições  i < q-p  e  j ≥ q-p.
static void intercala2 (int p, int q, int r, int v[])
*/
static void intercala2 (int p, int q, int r, int v[])
{
   int i, j, *w;
   w = malloc ((r-p) * sizeof (int));

   for (i = p; i < q; ++i) w[i-p] = v[i];
   for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
   i = 0; j = r-p-1;
   for (int k = p; k < r; ++k)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
   free (w);
}

/*----------------------- ALGORITIMO MERGE SORT ------------------------------------------------*/
// A função mergesort rearranja o vetor
// v[p..r-1] em ordem crescente.
void mergeSort (int p, int r, int v[])
{
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergeSort (p, q, v);        // 3
      mergeSort (q, r, v);        // 4
      intercala1 (p, q, r, v);     // 5
   }
}
main()
{
   // int v[]={38,27,43,3,9,82,10};
   int v[]={1,0,1,1,0,0,1};
    int i=0;
    mergeSort (0,7,v);

    for(i=0;i<7;i++){
        printf("%d\n", v[i]);
    }
system("pause");
}
