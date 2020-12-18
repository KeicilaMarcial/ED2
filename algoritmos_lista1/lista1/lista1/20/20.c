#include <stdio.h>
#include <stdlib.h>

typedef struct Avl{
    int ch;
    struct Avl *esq;
    struct Avl *dir;
    int alt;
}avl;

int altura(avl *raiz){
    if(raiz == NULL)return 0;
    return raiz->alt;
}
int max(int a,int b){
    return(a>b)?a:b;
}

int getBalanco(avl* raiz){
    if(raiz) return(altura(raiz->esq) - altura(raiz->dir));
    else return 0;
}

avl* novoNo(int chave){
    avl* no = (avl*)calloc(1,sizeof(avl));
    no->ch = chave;
    no->alt = 1;
    return no;
}

avl* rotacaoD(avl *raiz){

    avl* novaRaiz = raiz->esq;
    raiz->esq = novaRaiz->dir;
    novaRaiz->dir = raiz;
    raiz->alt = max(altura(raiz->esq),altura(raiz->dir))+1;
    novaRaiz->alt = max(altura(novaRaiz->esq),altura(novaRaiz->dir))+1;
    return novaRaiz;

}
avl* rotacaoE(avl *raiz){

    avl* novaRaiz = raiz->dir;
    raiz->dir = novaRaiz->esq;
    novaRaiz->esq = raiz;
    raiz->alt = max(altura(raiz->esq),altura(raiz->dir))+1;
    novaRaiz->alt = max(altura(novaRaiz->esq),altura(novaRaiz->dir))+1;
    return novaRaiz;

}

avl* rotacaoDD(avl *raiz){

    raiz->esq = rotacaoE(raiz->esq);
    return(rotacaoD(raiz));
}

avl* rotacaoEE(avl* raiz){

    raiz->dir = rotacaoD(raiz->dir);
    return(rotacaoE(raiz));
}

avl* insereArvore(avl* raiz,int ch){
        if(raiz == NULL) return(novoNo(ch));
        if(ch<raiz->ch)raiz->esq = insereArvore(raiz->esq,ch);
        else if(ch>raiz->ch)raiz->dir = insereArvore(raiz->dir,ch);

        else return raiz;

        raiz->alt = 1+(max(altura(raiz->dir),altura(raiz->esq)));
        int balanco = getBalanco(raiz);

        if(balanco>1 && getBalanco(raiz->esq)>0)return rotacaoD(raiz);
        if(balanco>1 && getBalanco(raiz->esq)<0) return rotacaoDD(raiz);
        if(balanco<-1 && getBalanco(raiz->dir)<0)return rotacaoE(raiz);
        if(balanco<-1 && getBalanco(raiz->dir)>0)return rotacaoEE(raiz);
    return raiz;

}
avl *antecessor(avl *raiz){
    avl* aux = raiz->esq;
    if(aux==NULL) return NULL;
        while(aux->dir != NULL){
        aux = aux->dir;
        }
    return aux;
}
avl* removeArvore(avl* raiz,int ch){
        if(raiz == NULL) return raiz;
        if(ch<raiz->ch)raiz->esq = removeArvore(raiz->esq,ch);
        else if(ch>raiz->ch)raiz->dir = removeArvore(raiz->dir,ch);
        else{
            if((raiz->esq == NULL)||(raiz->dir == NULL)){
                avl* aux = raiz->esq ? raiz->esq:raiz->dir;
                if(aux == NULL){
                    aux = raiz;
                    raiz = NULL;
                }else{
                    *raiz = *aux;
                    free(aux);
                }
            }else{
                avl* aux = antecessor(raiz->dir);
                raiz->ch = aux->ch;
                raiz->dir = removeArvore(raiz->dir,aux->ch);
            }
        }
        if(raiz == NULL) return raiz;
        raiz->alt = 1+(max(altura(raiz->dir),altura(raiz->esq)));
        int balanco = getBalanco(raiz);

        if(balanco>1 && getBalanco(raiz->esq)>=0)return rotacaoD(raiz);
        if(balanco>1 && getBalanco(raiz->esq)<0) return rotacaoDD(raiz);
        if(balanco<-1 && getBalanco(raiz->dir)<=0)return rotacaoE(raiz);
        if(balanco<-1 && getBalanco(raiz->dir)>0)return rotacaoEE(raiz);
    return raiz;

}

void imprimeArv (avl *raiz,int nv){
    if(raiz!=NULL){
     int i;
    imprimeArv(raiz->dir , nv+1);
	for(i=0; i<nv; i++) 	printf("\t");
	printf("%d\n",raiz->ch);
	imprimeArv(raiz->esq, nv+1);
    }
}

int main(){

    avl* raiz =NULL;


    raiz=insereArvore(raiz,19);
    raiz=insereArvore(raiz,18);
    raiz=insereArvore(raiz,16);
    raiz=insereArvore(raiz,15);
    raiz=insereArvore(raiz,17);
     raiz=insereArvore(raiz,2);
    raiz=insereArvore(raiz,6);






    printf("\n");
    imprimeArv(raiz,0);

    return 0;
}

