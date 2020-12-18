#include<stdio.h>
#include<stdlib.h>
#define RUBRO 'R'
#define NEGRA  'N'


typedef struct No{
    int ch;
    struct No *esq;
    struct No *dir;
    struct No *pai;
    char cor;
}No;
//Definindo T_nil_no como nó sentinela
//nil -> folhas nulas
struct No  T_nil_no;
       No* T_nil = &T_nil_no;

No* Root = NULL;


    No* novoNo(int chave){
        No *temp   = (No*) malloc(sizeof(No));
        temp->ch = chave;
        temp->cor = RUBRO;
        temp->dir=NULL;
        temp->esq=NULL;
        temp->pai=NULL;
        return temp;
    }

void rotacaoE(No**T, No* x){

     No *y  = x->dir;    // seta y
    x->dir = y->esq;     // transformar a subárvore direita de y na subárvore esquerda de x
    if (y->esq != T_nil)
        y->esq->pai = x;
    y->pai = x->pai;  //vincular o pai de x a y
    if (x->pai == T_nil)
       *T = y;
    else if (x == x->pai->esq)
       x->pai->esq = y;
    else
       x->pai->dir = y;
        y->esq = x;            // colcoca x á esquerda de y
        x->pai = y;
}

// T -> arvore; y -> nó
void rotacaoD(No**T, No* y){
    No *x;
    x = y->esq;     // seta x
    y->esq  = x->dir;    // transformar a subárvore direita de x na subárvore esquerda de y
    if (x->dir != T_nil)
        x->dir->pai = y;
    x->pai = y->pai;  //vincular o pai de y a x
    if (y->pai == T_nil)
       *T = x;
    else if (y == y->pai->dir)
       y->pai->dir = x;
    else
       y->pai->esq  = x;
    x->dir  = y;         // coloca y a direita de x
    y->pai = x;
}


void insereArvoreConserta(No** Root, No* New)
{
    No* temp;
    while(New->pai->cor == RUBRO)// Enquanto  a cor do pai for vermelha
    {
           if(New->pai->ch== New->pai->pai->ch){//New->pai->pai->ch
        
         // if (New->pai == New->pai->pai->esq){
            temp = New->pai->pai->dir;
            if(temp->cor == RUBRO)
            {
                New->pai->cor = NEGRA;
                temp->cor = NEGRA;
                New->pai->pai->cor = RUBRO;
                New = New->pai->pai;
            }
            else if(New->ch == New->pai->dir->ch)
            //if(New == New->pai->dir)
            {
                New = New->pai;
                rotacaoE(Root,New);
            }
            New->pai->cor = NEGRA;
            New->pai->pai->cor = RUBRO;
            rotacaoD(Root,New->pai->pai);
        }
        else
        {
            temp = New->pai->pai->esq;
            if(temp->cor == RUBRO)
            {
                New->pai->cor = NEGRA;
                New->cor = NEGRA;
                //temp->cor=NEGRA;
                New->pai->pai->cor = RUBRO;
                New = New->pai->pai;
                
            }
            else if(New->ch == New->pai->esq->ch)
            // if(New == New->pai->esq)
            {
                New = New->pai;
                rotacaoD(Root,New);
            }
             if(New->pai==T_nil){
                printf("Entrou1\n");
                New->pai->cor = NEGRA;
                New->esq->cor=NEGRA;
                New->dir->cor=NEGRA;

          //  New->pai->pai->cor = RUBRO;
            //rotacaoE(Root, New->pai);
            }else{
                printf("Entou2\n");
                 New->pai->cor = NEGRA;
                 New->pai->pai->cor = RUBRO;
                rotacaoE(Root, New->pai->pai);
            }
        }
    }
    //(*Root)->cor = NEGRA;
    Root[0]->cor=NEGRA;
    //New>pai->cor=NEGRA;
}


void insereRB(No** T, int chave)
{
    No* z =  novoNo(chave);
    No* y =  T_nil;
    No* x = *T;// x recebe um filho

    // Acha aonde inserir o novo nó Z na arvore
    while (x != T_nil) {
       y = x;
       if (z->ch < x->ch)
          x = x->esq;
       else
          x = x->dir;
    }

    z->pai = y;
    if (y == T_nil)
       *T = z;
    else if (z->ch < y->ch)
        y->esq  = z;
    else
        y->dir = z;

    // inicializa Z como uma folha vermelha
    z->esq  = T_nil;
    z->dir = T_nil;
    z->cor = RUBRO;

    // Assegurando que a propriedade  rubro -negra é mantida
    insereArvoreConserta(T,z);
}

void Imprime(No* Root, int nivel)
{ int i;
    No* temp = Root;
    if (temp != NULL){
    //ajudaPrint(Root);
    //Imprime(Root->esq, nivel+1);
    Imprime(temp->esq, nivel+1);
    for (int i = 0; i < nivel; ++i) printf("\t");
    //printf("[%d:%c]\n",Root->ch,Root->cor);
    printf("[%d:%c]\n",temp->ch,Root->cor);
   // Imprime(Root->dir, nivel+1);
    Imprime(temp->dir, nivel+1);
    //printf("\n");
    }
}

No* consulta_Arv(No** Root, int valor){
    if(*Root == NULL)
        return NULL;
    struct No* temp;
    temp = *Root;
    while(temp != NULL){
        if(valor == temp->ch){
            return temp;
        }
        if(valor > temp->ch)
            temp = temp->dir;
        else
            temp = temp->esq;
    }
    return NULL;
}


No *RemoverNaArvore(No *raiz, No *x){
    No *aux;
    while(x != raiz && x->cor == NEGRA){
        if(x == x->pai->esq){
            aux = x->pai->dir;
            if(aux->cor == RUBRO){ //CASO 1
                aux->cor = NEGRA;
                x->pai->cor = RUBRO;
                rotacaoE(&raiz, x->pai);
                aux = x->pai->dir;
            }
             aux = x->pai->esq;//coloquei depois k
            if(aux->esq->cor == NEGRA && x->dir->cor == NEGRA){//CASO 2
                aux->cor = RUBRO;
                x = x->pai;
            }
            else{
                 aux = x->pai->dir;//coloquei depois k
                if(aux->dir->cor == NEGRA){ //CASO 3
                    aux->esq->cor = NEGRA;
                    aux->cor = RUBRO;
                    rotacaoD(&raiz, aux);
                    aux = x->pai->dir;
                }
                aux->cor = x->pai->cor; //CASO 4
                x->pai->cor = NEGRA;
                aux->dir->cor = NEGRA;
                rotacaoE(&raiz, x->pai);
                x = raiz;
            }
        }
        else{
            aux = x->pai->esq;
            if(aux->cor == RUBRO){
                aux->cor = NEGRA;
                x->pai->cor = RUBRO;
                rotacaoD(&raiz, x->pai);
                aux = x->pai->esq;
            }
              //aux = x->pai->dir;//coloquei depois k
            if(aux->dir->cor == NEGRA && aux->esq->cor == NEGRA){
                aux->cor = RUBRO;
                x = x->pai;
            }
            else{
                // aux = x->pai->esq;
                if(aux->esq->cor == NEGRA){
                    aux->dir->cor = NEGRA;
                    aux->cor = RUBRO;
                    rotacaoE(&raiz, aux);
                    aux = x->pai->esq;
                }
                aux->cor = x->pai->cor;
                x->pai->cor = NEGRA;
                aux->esq->cor = NEGRA;
                rotacaoD(&raiz, x->pai);
                x = raiz;
            }
        }
    }
    x->cor = NEGRA;
    return raiz;
}

No *Sucessor(No *raiz){
    No *aux = raiz->dir;
    while(aux->esq != T_nil)
        aux = aux->esq;
    return aux;
}

void **RemoverNo(No **raiz, int elemento) {
    No *x = consulta_Arv(raiz, elemento);
    if(x == NULL){
        printf("Noh nao se encontra na Arvore!\n\n");
       
    }else{
        No *aux1;
        No *aux2;
        if(x->esq == T_nil || x->dir == T_nil)
            aux1 = x;
        else
            aux1 = Sucessor(x);
        
        if(aux1->esq != T_nil)
            aux2 = aux1->esq;
        else
            aux2 = aux1->dir;
        
        aux2->pai = aux1->pai;
        if(aux1->pai == T_nil)
            *raiz = aux2;
        else{
            if(aux1 == aux1->pai->esq)
                aux1->pai->esq = aux2;
            else
                aux1->pai->dir = aux2;
        }
        
        if(aux1 != x)
            x->ch = aux1->ch;
        if(aux1->cor == NEGRA)
            *raiz = RemoverNaArvore(*raiz, x);
    }
}

