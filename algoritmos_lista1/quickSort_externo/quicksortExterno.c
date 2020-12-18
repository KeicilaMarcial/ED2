#include <stdlib.h>
#include <stdio.h>
#include<limits.h> // assegura que as variaveis não estorem os limites
 // bibliotecas criadas pelo programador e importadas
#include "cabecalho.h"
#include "vetor.h"
#include "ordenacaoInterna.h"

#define TAM_BUFFER 3

void quickSortExterno( int esq, int dir, FILE **fileLEs, FILE ** fileLEi, int tipoOrdenacao){
    int i, j;
    if(dir - esq >=1){
        particao( esq,dir, &i, &j, fileLEs, fileLEi, tipoOrdenacao);
        fflush( *fileLEs);
        fflush(*fileLEi);

        if((i-esq) < (dir-j)){
            quickSortExterno(esq,i, fileLEs, fileLEi, tipoOrdenacao);
            quickSortExterno(j, dir, fileLEs, fileLEi, tipoOrdenacao);
        }else{
             quickSortExterno(j, dir, fileLEs, fileLEi, tipoOrdenacao);
             quickSortExterno(esq,i, fileLEs, fileLEi, tipoOrdenacao);
        }
    }else{
        puts("[quicksortExterno] Nada a fazer.");
    }
}

void particao(int esq,int dir, int *i,int *j,FILE **fileLEs,FILE ** fileLEi,int tipoOrdenacao){
    int lim_inf, lim_sup;
    int ei, es, li, ls;
    int ultimo_lido;
    int qdt_buffer =0;
    int ler_sup;
    int ordenado;
    int buffer[TAM_BUFFER];

    // INT_MIN e INT_MAX -> pertencem a biblioteca limits.h
    lim_inf = INT_MIN; // limite inferior recebe o menor tamanho de um inteiro
    lim_sup = INT_MAX; // limite superior recebe o maior tamanho de um inteiro

    ler_sup =1;

    *i = esq-1;
    j= dir+1;

    /* Alinha ponteiro de leitura e escrita aqui:
    Li e Ei <- começam e esq
    Ls e Es <- começam em dir
    */
    li= esq;
    ei = esq;
    ls= dir;
    es= dir;

    while(li<=ls){

    }
}
