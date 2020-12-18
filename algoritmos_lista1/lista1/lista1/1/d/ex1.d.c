#include<stdio.h>
#include<stdlib.h>


/*-----CABEÇALHO----------
    p = inicio
    q = meio
    r = fim

*----------------------------*/

static void intercala (int p, int q, int r, int v[])
{
   int *w;                                 //  1
   w = malloc ((r-p) * sizeof (int));     //  2
   int i = p, j = q;                       //  3
   int k = 0;
                                            //  4
   while (i < q && j < r) {                //  5
      printf("  valor  i - %d ---- valor J %d\n", i,j);
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);
}



void mergeSort (int p, int r, int v[])
{

   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergeSort (p, q, v);        // 3
      mergeSort (q, r, v);        // 4
      intercala (p, q, r, v);     // 5
   }
}
main()
{

   int v[]={1,9,1,6,7,4,0};
    int i=0;
    mergeSort (0,7,v);

    for(i=0;i<7;i++){
        printf("%d\n", v[i]);
    }
system("pause");
}
