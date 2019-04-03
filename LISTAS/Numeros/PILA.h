#ifndef __PILA_H__
#define __PILA_H__

#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"

typedef NODO* TipoDatop;
typedef struct pila
{
	TipoDatop dato;
	struct pila* cima;
}PILA;

int pilaVacia(PILA*);
void insertarPila (PILA **, TipoDatop);
TipoDatop quitarPila(PILA**);
TipoDatop mostrarCima(PILA*);
#endif
