#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksortExter.c"


void QuicksortExterno(FILE **ArqLi, FILE **ArqEi,FILE **ArqLEs, int Esq, int Dir)
{
	int i,j;
	int Area = 3; /* Area de armazenamento interna */
	if (Dir - Esq < 1) return;

	particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i,&j);
	if (i – Esq < Dir – j){ /* ordene primeiro o subarquivo menor */
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
	}
	else{
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
		QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq,i);
	}
}

void LeSup(FILE LeSup(FILE **ArqLEs TipoRegistro ArqLEs, TipoRegistro*UltLido UltLido, int *Ls, short*OndeLer)
{
 	fseek(*ArqLEs, (*Ls – 1) * sizeof(TipoRegistro), SEEK_SET);
	fread(UltLido, sizeof(TipoRegistro), 1, *ArqLEs);
	(*Ls)--;
	*OndeLer = FALSE;
}

void LeInf(FILE **ArqLi, TipoRegistro *UltLido, int *Li, short*OndeLer)
{
	fread(UltLido, sizeof(TipoRegistro), 1, *ArqLi);
	(*Li)++;
	*OndeLer = TRUE;
}

void InserirArea(TipoArea *Area, TipoRegistro *UltLido, int *NRArea)
{
	/* Insere UltLido de forma ordenada na Area */
	InsereItem(*UltLido, Area);
	*NRArea = ObterNumCelOcupadas(Area);
}

void EscreveMax(FILE **ArqLEs, TipoRegistro R, int *Es)
{
	fseek(*ArqLEs, (*Es – 1) * sizeof(TipoRegistro), SEEK_SET);
	fwrite(&R,sizeof(TipoRegistro), 1, *ArqEi);
	(*Ei)++;

void EscreveMin( FILE **ArqEi,TipoRegistro R, int *Ei)
{
	fwrite(&R, sizeof(TipoRegistro), 1, *ArqEi);
	(*Ei)++;
}

void RetiraMax(TipoArea *Area, TipoRegistro *R, int *NRArea)
{
	RetiraUltimo(Area, R);
	*NRArea = ObterNumCelOcupadas(Area);
}

void RetiraMin(TipoArea *Area, TipoRegistro *R, int *NRArea)
{
	RetiraPrimeiro(Area, R);
	*NRArea = ObterNumCelOcupadas(Area);
}

void Particao (FILE **ArqLi, FILE **ArqEi FILE **A LE Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs,TipoArea Area, int Esq, int Dir, int *i, int *j)
{
	int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq, NRArea = 0,Linf = INT_MIN, Lsup = INT_MAX;
	short OndeLer=TRUE;
	TipoRegistro UltLido, R;

	fseek(*ArqLi, (Li – 1)* sizeof(TipoRegistro), SEEK_SET);
	fseek(*ArqEi, (Li – 1)* sizeof(TipoRegistro), SEEK_SET);
	*i = Esq – 1;
	*j = Dir + 1;
	while (Ls >= Li){
		if (NRArea < TamArea – 1)
		{
			if (OndeLer)
			LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
			else LeInf(ArqLi, &UltLido, &Li, &OndeLer);
			InserirArea(&Area, &UltLido, &NRArea);
			continue;
		}


		if (Ls == Es)
			LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);

		else if (Li == Ei) LeInf(ArqLi, &UltLido, &Li, &OndeLer);
			else
				if(OndeLer)
					LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
				else LeInf(ArqLi, &UltLido, &Li, &OndeLer);
		if (UltLido.Chave > Lsup)
		{ *
			j = Es;
			EscreveMax(ArqLEs, UltLido, &Es);
			continue;
		}
		if (UltLido.Chave < Linf)
		{
			*i = Ei;
			EscreveMin(ArqEi, UltLido, &Ei);
			continue;
		}
		InserirArea(&Area &UltLido &NRArea);
		if (Ei – Esq < Dir – Es)
		{
			RetiraMin(&Area, &R, &NRArea);
			EscreveMin(ArqEi, R, &Ei);
			Linf = R.Chave;
		}
		else
		{
			RetiraMax(&Area, &R, &NRArea);
			EscreveMax(ArqLEs, R, &Es);
			Lsup = R.Chave;
		}
	}
	while (Ei <= Es)
	{
		RetiraMin(&Area, &R, &NRArea);
		EscreveMin(ArqEi, R, &Ei);
	}


}
