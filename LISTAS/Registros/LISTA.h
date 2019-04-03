#ifndef __LISTA_H__
#define __LISTA_H__

#include <stdio.h>
#include <stdlib.h>
#include "ALUMNO.h"

typedef ALUMNO* Tipodatol;
typedef struct nodo
{
	Tipodatol dato;
	struct nodo* siguiente;
}NODO;

NODO* crearNodo(NODO*, Tipodatol);
void insertarNodoCabLSE(NODO**, Tipodatol);
void insertarLSE(NODO *,  Tipodatol);
NODO* buscarLSE(NODO*, Tipodatol);
void eliminarLSE(NODO**, Tipodatol);
void eliminarTodaLSE(NODO **);
void imprimirLista(NODO*);

#endif
