#ifndef __PILA_H__
#define __PILA_H__
#include <stdio.h>
#include <stdlib.h>
typedef int TipoDatop;
typedef struct nodo
{
	TipoDatop dato;
	struct nodo* sig;
}NODO;

typedef struct pila
{
	NODO* cima;
	NODO* cab;
}PILA;

int pilaVacia(PILA);
void ingresarPila (PILA*, TipoDatop);
TipoDatop quitarPila(PILA*);
TipoDatop mostrarCima(PILA);
void eliminarPila(PILA*);
#endif
