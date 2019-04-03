#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
#include <string.h>

#define TAM 103

typedef NODO* Tipodatot;

typedef struct tabla
{
	Tipodatot tabla[TAM];
	int elementos;
}TABLADISPERSION;

void crearTabla(TABLADISPERSION*);
long funcionhash(char*);
int direccion(TABLADISPERSION *, char*);
void insertarElemento(TABLADISPERSION*, ALUMNO*);
void eliminarElemento(TABLADISPERSION*, char*);
Tipodatot busqTab(TABLADISPERSION*, char*);
void mostrarTablaCompleta(TABLADISPERSION*);
