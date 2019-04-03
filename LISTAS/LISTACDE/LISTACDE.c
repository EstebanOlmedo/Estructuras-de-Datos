#include "LISTACDE.h"

//LISTA CIRCULAR DOBLEMENTE ENLAZADA

void ingresarLCDE(NODOCDE** cab, TipoDatoLCDE x)
{
	NODOCDE* nuevo =  (NODOCDE*)malloc(sizeof(NODOCDE));
	nuevo -> dato = x;

	if(*cab)
	{
		(*cab) -> ant -> sig = nuevo;
		(*cab) -> ant = nuevo;
		nuevo -> sig = *cab;
		*cab = nuevo;
	}
	else
	{
		*cab = nuevo;
		nuevo -> sig  = nuevo;
		nuevo -> ant =  nuevo;
	}
}

NODOCDE* buscarLCDE(NODOCDE* cab, TipoDatoLCDE x)
{
	NODOCDE* aux = cab;
	if(aux)
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

void eliminarLCSE(NODOCDE** cab, TipoDatoLCDE x)
{
	int encontrado = 0;
	NODOCDE* aux = *cab;
	NODOCDE* aux2 = NULL;
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
				*cab = aux;
			aux -> sig = aux2 -> sig;
			aux2 -> sig -> ant = aux;
		}
		free(aux2);
	}
}

