#include "LISTACSE.h"

//LISTA CIRCULAR SIMPLEMENTE ENLAZADA

void ingresarLCSE(NODOCSE** cab, TipoDatoLCSE x)
{
	NODOCSE* nuevo = (NODOCSE*)malloc(sizeof(NODOCSE));
	nuevo -> dato = x;
	if((*cab) != NULL)
	{
		nuevo -> sig = (*cab) -> sig;
		(*cab) -> sig = nuevo;
	}
	*cab = nuevo;
}

NODOCSE* buscarLCSE(NODOCSE* cab, TipoDatoLCSE x)
{
	NODOCSE* aux = cab;
	if(cab != NULL)
	{
		while(aux -> sig != cab)
		{
			if(aux -> sig -> dato != x)
				aux = aux -> sig;
			else
				return aux -> sig;
		}
		if(cab -> dato == x)
			return cab;
	}
	return NULL;
}

void eliminarLCSE(NODOCSE** cab, TipoDatoLCSE x)
{
	NODOCSE* aux = *cab;
	NODOCSE* aux2;
	int encontrado = 0;
	if(*cab)
	{
		while(!encontrado && aux -> sig != (*cab))
		{
			encontrado = (aux -> sig -> dato == x);
			if(!encontrado)
				aux = aux -> sig;
		}
		if(encontrado)
		{
			aux2 = aux -> sig;
			if((*cab) == (*cab) -> sig)
				*cab = NULL;
			else
			{
				if(aux2 == (*cab))
					(*cab) = aux;
				aux -> sig = aux2 -> sig;
			}
			free(aux);
		}
	}
}
