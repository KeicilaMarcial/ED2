#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "quickSort.h"
#define TAMAREA 100
#define TRUE 1
#define FALSE 0



int main(int argc, char *argv[]){ 
    ArqLi = fopen ("teste.txt", "wb");
    
    if(ArqLi == NULL) {
        printf("Arquivo nao pode ser aberto\n "); exit(1);
    }

    for(int i=0;i<10;i++){
        int j=rand()%100;
        
        R.Chave = j;  fwrite(&R, sizeof(TipoRegistro), 1, ArqLi); 
        
        printf("%d\n", j);           

    }
    fclose(ArqLi);
    printf("Ordenados:\n");



    ArqLi = fopen ("teste.txt", "r+b");
    if (ArqLi == NULL) {
        printf("Arquivo nao pode ser aberto\n"); exit(1);
    } 
  
    ArqEi = fopen ("teste.txt", "r+b");
    if (ArqEi == NULL) {    
        printf("Arquivo nao pode ser aberto\n"); exit(1);
    }
    ArqLEs = fopen ("teste.txt", "r+b");
    if (ArqLEs == NULL) { 
        printf ("Arquivo nao pode ser aberto\n");  exit(1);
    }

    QuicksortExterno(&ArqLi, &ArqEi, &ArqLEs, 1, 10);
    fflush(ArqLi); 
    fclose(ArqEi); 
    fclose(ArqLEs);
    fseek(ArqLi,0, SEEK_SET);

    while(fread(&R, sizeof(TipoRegistro), 1, ArqLi)) { 
        printf("%d\n", R.Chave);
    }

    fclose(ArqLi);

    return 0;
}
