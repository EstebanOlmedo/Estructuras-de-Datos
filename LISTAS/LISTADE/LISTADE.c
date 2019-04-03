#include "LISTADE.h"

//LISTA DOBLEMENTE ENLAZADA

void insertarCabLDE(NODODE** cab, TipoDatoLDE x)
{
	NODODE* nuevo = (NODODE*)malloc(sizeof(NODODE));

	nuevo -> dato = x;
	nuevo -> sig = *cab;
	nuevo -> ant = NULL;

	if(*cab)
		(*cab) -> ant = nuevo;
	*cab = nuevo;
}

void insertarLDE(NODODE* anterior, TipoDatoLDE x)
{
	NODODE* nuevo = (NODODE*)malloc(sizeof(NODODE));
	nuevo -> dato = x;
	nuevo -> sig = anterior -> sig;
	anterior -> sig  -> ant = nuevo;
	nuevo -> ant = anterior;
	anterior -> sig = nuevo;
}

NODODE* buscarLDE(NODODE* cab, TipoDatoLDE x)
{
	if(cab && (cab -> dato != x))
		return buscarLDE(cab -> sig, x);
	return cab;
}

void eliminarLDE(NODODE** cab, TipoDatoLDE x)
{
	NODODE* actual = buscarLDE(*cab, x);
	if(actual != NULL)
	{
		if(actual == *cab)
		{
			*cab = actual -> sig;
			if(actual -> sig != NULL)
				actual -> sig -> ant = NULL;
		}
		else if(actual -> sig != NULL)
		{
			actual -> ant -> sig = actual -> sig;
			actual -> sig -> ant = actual -> ant;
		}
		else
			actual -> ant -> sig = NULL;
		free(actual);
	}
}
