#include "COLA.h"

void crearCola(COLA** C)
{
	(*C) -> frente = (*C) -> fin = NULL;
}

int colaVacia(COLA* C)
{
	return (C -> frente == NULL)? 1: 0;
}

Tipodatoc mostrarFrente(COLA* C)
{
	if(colaVacia(C))
	{	
		printf("La cola esta vacia\n");
		exit(-1);
	}
	else
		return C -> frente -> dato;
}
void insertarCola(COLA** C, Tipodatoc x)
{
	NODO* nuevo = (NODO*)malloc(sizeof(NODO));
	nuevo -> dato = x;
	nuevo -> ant = NULL;
	if(colaVacia(*C))
	{
		(*C) ->  fin = nuevo;
		(*C) -> frente = nuevo;
	}
	else
	{
		(*C) -> fin -> ant = nuevo;
		nuevo -> sig = (*C) -> fin;
		(*C) -> fin = nuevo;
	}
	
}
Tipodatoc quitarCola(COLA** C)
{
	Tipodatoc x;
	NODO* actual; 
	if (colaVacia(*C))
	{
		printf("La cola esta vacia\n");
		exit(-1);
		
	}
	if((*C) -> frente == (*C) -> fin)
	{
		actual = (*C) -> frente; 
		x = (*C) -> frente -> dato;
		(*C) -> frente = (*C) -> fin = NULL;
		//free(actual);
	}
	else 
	{
		actual = (*C) -> frente; 
		x = actual -> dato;
		actual -> ant -> sig = NULL;
		(*C) -> frente = actual -> ant;
		//free(actual);
	}
	return x;
}
