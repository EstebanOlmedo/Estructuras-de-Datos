#include "PILA.h"

int pilaVacia(PILA* P)
{
	return(P  == NULL? 1: 0);
}
void insertarPila(PILA** P, TipoDatop x)
{
	PILA* nuevo = (PILA*)malloc(sizeof(PILA));
	nuevo -> dato = x;
	nuevo -> cima = *P;
	*P = nuevo;
}
TipoDatop quitarPila(PILA** P)
{
	TipoDatop x;
	PILA* aux = *P;
	if(pilaVacia(*P))
	{
		printf("La PILA esta vacia\n");
		exit(-1);
	}
	x = aux -> dato;
	*P = aux -> cima;
	free(aux);
	return x;
}
TipoDatop mostrarCima(PILA* P)
{

	TipoDatop x;
	if(pilaVacia(P))
	{
		printf("La PILA esta vacia\n");
		exit(-1);
	}
	x = P -> dato;
	return x;
}
