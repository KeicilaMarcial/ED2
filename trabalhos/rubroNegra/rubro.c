#include "RubroNegra.c"
#include "cabecalho.h"


int main(int argc, char* argv[])
{

    No* Root = T_nil, T_nil_no;

    insereRB(&Root, 100);
    insereRB(&Root, 50);
    insereRB(&Root, 150);
    //insereRB(&Root, 80);
    insereRB(&Root, 30);
    insereRB(&Root, 160);
    insereRB(&Root, 180);
    RemoverNo(&Root, 50);
    RemoverNo(&Root, 100);
   RemoverNo(&Root, 80);
    Imprime(Root,0);
    No* temp;
    No* temp2;
   // temp =consulta_Arv(&Root, 100);
   // temp2 = TreeSuccessor(&Root,temp);
   /* if(temp!=NULL){
    	printf("\nNo - %d\n", temp->ch );
    }else{
    	printf("esse no nao existe na arvore\n" );
    }
   /* RBTreeDestroy(&Root,consulta_Arv(&Root,180));
    Imprime(Root);*/
    
}
