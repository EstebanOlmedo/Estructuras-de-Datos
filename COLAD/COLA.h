#ifndef __COLA_H__
#define __COLA_H__

#include <stdio.h>
#include <stdlib.h>

typedef int Tipodatoc;
typedef struct nodo
{
	struct nodo* sig;
	struct nodo* ant;
	Tipodatoc dato;
}NODO;

typedef struct cola
{
	NODO* frente;
	NODO* fin;
}COLA;

void crearCola(COLA**);
int colaVacia(COLA*);
Tipodatoc mostrarFrente(COLA*);
void insertarCola(COLA**, Tipodatoc);
Tipodatoc quitarCola(COLA**);
#endif
