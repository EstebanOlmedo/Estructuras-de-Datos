#include "LISTA.h"

NODO* crearNodo(NODO* enlace, Tipodatol x)
{
	NODO* nuevo = (NODO*) malloc(sizeof(NODO));
	nuevo -> dato = x;
	nuevo -> siguiente = enlace;
	return nuevo;
}
void insertarNodoCabLSE(NODO** cab, Tipodatol x)
{
	NODO* nuevo = crearNodo(nuevo, x);
	nuevo -> siguiente = *cab;
	*cab = nuevo;
}
void insertarLSE(NODO* ant, Tipodatol x)
{
	NODO* nuevo = crearNodo(nuevo, x);
	nuevo -> siguiente = ant -> siguiente;
	ant -> siguiente = nuevo;
}
NODO* buscarLSE(NODO* cab, Tipodatol x)
{
	NODO* aux = cab;
	for(; aux; aux = aux -> siguiente)
	{
		if(aux -> dato == x)
			return aux;
	}
	return aux;
}

void eliminarLSE(NODO** cab, Tipodatol x)
{
	NODO* ant = NULL;
	NODO* actual = *cab;
	int encontrado = 0;

	while(!encontrado && actual)
	{
		encontrado = (actual -> dato == x);
		if(!encontrado)
		{
			ant = actual;
			actual = actual -> siguiente;
		}
	}
	if(actual != NULL)
	{
		if(actual == *cab)
			*cab = actual -> siguiente;
		else
			ant -> siguiente = actual -> siguiente;
		free (actual);
	}
}
void eliminarTodaLSE(NODO ** cab)
{
	while(*cab)
	{
		eliminarLSE(cab, (*cab) -> dato);
	}
}

void imprimirLista(NODO* L)
{
	while(L != NULL)
	{
		mostrarAlumno(*(L -> dato));
		L = L -> siguiente;
	}
}
