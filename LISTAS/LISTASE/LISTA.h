#ifndef __LISTA_H__
#define __LISTA_H__

/*LISTA SIMPLEMENTE ENLAZADA*/

#include <stdio.h>
#include <stdlib.h>

typedef int Tipodatol;

typedef struct nodose
{
	Tipodatol dato;
	struct nodose* siguiente;
}NODOSE;

NODOSE* crearNodoLSE(NODOSE*, Tipodatol);
void insertarNodoCabLSE(NODOSE**, Tipodatol);
void insertarLSE(NODOSE*,  Tipodatol);
NODOSE* buscarLSE(NODOSE*, Tipodatol);
void eliminarLSE(NODOSE**, Tipodatol);
void eliminarTodaLSE(NODOSE**);
void mostrarCompletaLSE(NODOSE*);
void voltearLSE(NODOSE**);

#endif
