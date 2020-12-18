#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMAREA 100
#define TRUE 1
#define FALSE 0

typedef int TipoApontador;

typedef struct TipoItem {
  int Chave;
  /* Outros Componentes */
} TipoItem;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox, Ant;
} TipoCelula;
typedef struct TipoArea {
  TipoCelula Itens[TAMAREA];
  TipoApontador CelulasDisp, Primeiro, Ultimo;
  int NumCelOcupadas;
} TipoArea;

typedef TipoItem TipoRegistro;

/*Declaracao dos tipos utilizados pelo quicksort externo*/

FILE *ArqLEs;   /* Gerencia o Ls e o Es */
FILE *ArqLi;    /* Gerencia o Li */
FILE *ArqEi;    /* Gerencia o Ei */

TipoItem R;


/*Procedimentos de manipulacao do tipo abstrato Area*/



void FAVazia(TipoArea *Area)
{ int i;
  Area->NumCelOcupadas = 0;
  Area->Primeiro = -1;
  Area->Ultimo = -1;
  Area->CelulasDisp = 0;
  for (i = 0; i < TAMAREA; i++) 
    { Area->Itens[i].Ant = -1;
      Area->Itens[i].Prox = i + 1;
    }
}

int ObterNumCelOcupadas(TipoArea *Area)
{ return (Area->NumCelOcupadas);
}

void InsereItem(TipoItem Item, TipoArea *Area)
{ int Pos, Disp, IndiceInsercao;
  if (Area->NumCelOcupadas == TAMAREA) 
  { printf("Tentativa de insercao em lista cheia.\n");
    return;
  }
  Disp = Area->CelulasDisp;
  Area->CelulasDisp = Area->Itens[Area->CelulasDisp].Prox;
  Area->Itens[Disp].Item = Item;
  Area->NumCelOcupadas++;
  if (Area->NumCelOcupadas == 1) 
  { /* Insercao do primeiro item */
    Area->Primeiro = Disp;
    Area->Ultimo = Area->Primeiro;
    Area->Itens[Area->Primeiro].Prox = -1;
    Area->Itens[Area->Primeiro].Ant = -1;
    return;
  }
  Pos = Area->Primeiro;
  if (Item.Chave < Area->Itens[Pos].Item.Chave)
  { /* Insercao realizada na primeira posicao */
    Area->Itens[Disp].Ant = -1;
    Area->Itens[Disp].Prox = Pos;
    Area->Itens[Pos].Ant = Disp;
    Area->Primeiro = Disp;
    return;
  }
  IndiceInsercao = Area->Itens[Pos].Prox;
  while (IndiceInsercao != -1 &&
     Area->Itens[IndiceInsercao].Item.Chave < Item.Chave) 
    { Pos = IndiceInsercao;
      IndiceInsercao = Area->Itens[Pos].Prox;
    }
  if (IndiceInsercao == -1) 
  { /*Insercao realizada na ultima posicao*/
    Area->Itens[Disp].Ant = Pos;
    Area->Itens[Disp].Prox = -1;
    Area->Itens[Pos].Prox = Disp;
    Area->Ultimo = Disp;
    return;
  }
  Area->Itens[Disp].Ant = Pos;
  Area->Itens[Disp].Prox = Area->Itens[Pos].Prox;
  Area->Itens[Pos].Prox = Disp;
  Pos = Area->Itens[Disp].Prox;
  Area->Itens[Pos].Ant = Disp;
  /* Insercao realizada no meio de Area */
}

void RetiraPrimeiro(TipoArea *Area, TipoItem *Item)
{ TipoApontador ProxTmp;
  if (Area->NumCelOcupadas == 0) 
  { /* Area vazia */
    printf("Erro - Lista vazia\n");
    return;
  }
  *Item = Area->Itens[Area->Primeiro].Item;
  ProxTmp = Area->Itens[Area->Primeiro].Prox;
  Area->Itens[Area->Primeiro].Prox = Area->CelulasDisp;
  Area->CelulasDisp = Area->Primeiro;
  Area->Primeiro = ProxTmp;
  if ((unsigned int)Area->Primeiro < TAMAREA)
  Area->Itens[Area->Primeiro].Ant = -1;
  Area->NumCelOcupadas--;
}

void RetiraUltimo(TipoArea *Area, TipoItem *Item)
{ TipoApontador AntTmp;
  if (Area->NumCelOcupadas == 0) 
  { /* Area vazia */
    printf("Erro - Lista vazia\n");
    return;
  }
  *Item = Area->Itens[Area->Ultimo].Item;
  AntTmp = Area->Itens[Area->Ultimo].Ant;
  Area->Itens[Area->Ultimo].Prox = Area->CelulasDisp;
  Area->CelulasDisp = Area->Ultimo;
  Area->Ultimo = AntTmp;
  if ((unsigned int)Area->Ultimo < TAMAREA)
  Area->Itens[Area->Ultimo].Prox = -1;
  Area->NumCelOcupadas--;
}

void ImprimeArea(TipoArea *Area)
{ int Pos;
  if (Area->NumCelOcupadas <= 0) 
  { printf("Lista Vazia\n");
    return;
  }
  printf("** LISTA **\n");
  printf("Numero de Celulas Ocupadas = %d\n", Area->NumCelOcupadas);
  Pos = Area->Primeiro;
  while (Pos != -1) 
    { printf("%d\n", Area->Itens[Pos].Item.Chave);
      Pos = Area->Itens[Pos].Prox;
    }
}

/*Procedimentos utilizados pelo Particao do quicksort externo*/
void LeituraSuperior(FILE **ArqLEs, TipoRegistro *UltLido, int *Ls, short *OndeLer){
    fseek(*ArqLEs, (*Ls - 1) * sizeof(TipoRegistro),SEEK_SET );
    fread(UltLido, sizeof(TipoRegistro), 1, *ArqLEs);
    (*Ls)--;  
    *OndeLer = FALSE;
}

void LeituraInferior(FILE **ArqLi,  TipoRegistro *UltLido, int *Li, short *OndeLer){  
    fread(UltLido, sizeof(TipoRegistro), 1, *ArqLi);
    (*Li)++; 
    *OndeLer = TRUE;
}

void InserirAreaMemoria(TipoArea *Area, TipoRegistro *UltLido, int *NRArea){ /*Insere UltLido de forma ordenada na Area*/
    InsereItem(*UltLido, Area);  
    *NRArea = ObterNumCelOcupadas(Area);
}

void EscreverMaior(FILE **ArqLEs, TipoRegistro R, int *Es){    
    fseek(*ArqLEs, (*Es - 1) * sizeof(TipoRegistro),SEEK_SET );
    fwrite(&R, sizeof(TipoRegistro), 1, *ArqLEs);  (*Es)--;
}

void EscreverMenor(FILE **ArqEi,  TipoRegistro R, int *Ei){    
    fwrite(&R, sizeof(TipoRegistro), 1, *ArqEi);  
    (*Ei)++; 
}

void RetiraMaior(TipoArea *Area,  TipoRegistro *R, int *NRArea){
    RetiraUltimo(Area, R);
    *NRArea = ObterNumCelOcupadas(Area); 
}

void RetiraMenor(TipoArea *Area, TipoRegistro *R, int *NRArea){ 
    RetiraPrimeiro(Area, R);
    *NRArea = ObterNumCelOcupadas(Area); 
}

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j){ 
    int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq, NRArea = 0, Linf = INT_MIN, Lsup = INT_MAX;
    short OndeLer = TRUE;  TipoRegistro UltLido, R;
    fseek (*ArqLi, (Li - 1)* sizeof(TipoRegistro), SEEK_SET );
    fseek (*ArqEi, (Ei - 1)* sizeof(TipoRegistro), SEEK_SET );
    *i = Esq - 1;  *j = Dir + 1;

    while (Ls >= Li) { 
        if (NRArea < TAMAREA - 1){                          //CONDIÇÃO DE PARADA PARA QUANDO A MEMORIA ESTIVER CHEIA
            if (OndeLer)                                    //A LEITURA É FEITA ALTERNADAMENTE ENTRE Ls E li 
             
                LeituraSuperior(ArqLEs, &UltLido, &Ls, &OndeLer);
            else 
                LeituraInferior(ArqLi, &UltLido, &Li, &OndeLer);
                InserirAreaMemoria(&Area, &UltLido, &NRArea);      //CASO O REGISTRO SEJA MAIOR QUE LIMITE INFERIOR E MENOR QUE LIMETE SUPERIOR, O REGISTRO É INSERIDO NA AREA DE MEMORIA
            continue;
        }
        //CONDIÇÕES QUE GARANTEM QUE OS PONTEIROS DE LEITURA FIQUEM NA FRENTE DOS PONTEIROS DE ESCRITA, PARA QUE NENHUM REGISTRO SEJA PERDIDO
        if (Ls == Es) 
          LeituraSuperior(ArqLEs, &UltLido, &Ls, &OndeLer);
          else if (Li == Ei) 
             LeituraInferior(ArqLi, &UltLido, &Li, &OndeLer);
             else if (OndeLer) 
                LeituraSuperior(ArqLEs, &UltLido, &Ls, &OndeLer);
                else 
                LeituraInferior(ArqLi, &UltLido, &Li, &OndeLer);
        
        //CONDIÇÕES DE COMPARAÇÃO COM OS LIMETES INF. E SUP. PARA SEREM ESCRITOS NOS SUBARQUIVOS 
        if (UltLido.Chave > Lsup) {                        
            *j = Es;
            EscreverMaior(ArqLEs, UltLido, &Es);
            continue;
        }
        if (UltLido.Chave < Linf) {
            *i = Ei;
            EscreverMenor(ArqEi, UltLido, &Ei);
            continue;
        }
        InserirAreaMemoria(&Area, &UltLido, &NRArea);
        
        //NO MOMENTO EM QUE A AREA DE MEMORIA ESTA CHEIA, REMOVE-SE UM REGISTRO DELA        
        if (Ei - Esq < Dir - Es) {                      //CASO A CONDIÇÃO SEJA ACEITA, O REGISTRO DE MENOR CHAVE É REMOVIDO DA MEMÓRIA E ESCRITO NA SUBARVORE A ESQUERDA. O LIMITE INF RECEBE O VALOR DA CHAVE  
            RetiraMenor(&Area, &R, &NRArea);
            EscreverMenor(ArqEi, R, &Ei);
            Linf = R.Chave;
        } 
        else {                                          //SENÃO, O REGISTRO O REGISTRO DE MAIOR CHAVE É REMOVIDO E ESCRITO NA SUBARVORE A DIREITA. O LIMITE SUP. RECEBE O VALOR DA CHAVE
            RetiraMaior(&Area, &R, &NRArea);
            EscreverMaior(ArqLEs, R, &Es);
            Lsup = R.Chave;
        }
    }
    
    
    //QUANDO Ls<Li (QUANDO SE CRUZAM) OS REGISTROS ARMAZENADOS NA AREA DE MEMÓRIA INTERNA SÃO COPIADOS JÁ ORDENADOS, DO MENOR AO MAIOR SÃO REMOVIDOS E ESCRITOS NA POSIÇÃO INDICADA POR Ei       
    while (Ei <= Es) {
        RetiraMenor(&Area, &R, &NRArea);
        EscreverMenor(ArqEi, R, &Ei);
    }
}

void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir){ 
    int i, j;
    TipoArea Area;   /* Area de armazenamento interna*/
    if (Dir - Esq < 1) return;
    FAVazia(&Area);
    Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j);
    if (i - Esq < Dir - j) { /* ordene primeiro o subarquivo menor */
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
    }
    else{ 
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
    }
}



