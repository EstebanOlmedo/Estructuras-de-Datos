#include "PILA.h"

void crearPila(PILA* P)
{
	P -> cima = P -> cab = NULL;
}
int pilaVacia(PILA P)
{
	return(P.cima == NULL? 1: 0);
}
void ingresarPila(PILA* P, TipoDatop x)
{
	NODO* nuevo = (NODO*)malloc(sizeof(NODO));
	nuevo -> dato = x;
	nuevo -> sig = P -> cima;
	P -> cima = nuevo;
}
TipoDatop quitarPila(PILA* P)
{
	TipoDatop x;
	//NODO* aux;
	if(pilaVacia(*P))
	{
		printf("La PILA esta vacia\n");
		exit(-1);
	}
	x = P -> cima -> dato;
	P -> cima  = P -> cima -> sig;
	return x;
}
TipoDatop mostrarCima(PILA P)
{

	TipoDatop x;
	if(pilaVacia(P))
	{
		printf("La PILA esta vacia\n");
		exit(-1);
	}
	x = P.cima -> dato;
	return x;
}

void eliminarPila(PILA* P)
{
	NODO* aux = P -> cab;
	P -> cima = NULL;
	while(aux)
	{
		P -> cab = P -> cab -> sig;
		free(aux);
		aux = P -> cab;
	}
}
