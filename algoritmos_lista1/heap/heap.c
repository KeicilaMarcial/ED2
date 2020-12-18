#include<stdio.h>
#include<stdlib.h>
#define troca (A, B) {int t = A; A = B; B = t;}

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

static void
constroiHeap (int m, int v[])
{
   for (int k = 1; k < m; ++k) {
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v[f/2], v[f]);          // 6
         f /= 2;                        // 7
      }
   }


static void
peneira (int m, int v[]) {
   int f = 2;
   while (f <= m) {
      if (f < m && v[f] < v[f+1]) ++f;
      // f é o filho mais valioso de f/2
      if (v[f/2] >= v[f]) break;
      troca (v[f/2], v[f]);
      f *= 2;
   }
}

   // Rearranja os elementos do vetor v[1..n]
// de modo que fiquem em ordem crescente.

void
heapsort (int n, int v[])
{
   constroiHeap (n, v);
   for (int m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}


main(){

}
