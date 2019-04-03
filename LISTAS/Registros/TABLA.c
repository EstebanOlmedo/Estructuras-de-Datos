#include "TABLA.h"

void crearTabla(TABLADISPERSION* T)
{
	T -> elementos = 0;
	int i;
	for(i = 0; i < TAM; i++)
		T -> tabla[i] = NULL;
}

long funcionhash(char* clave)
{
	int i;
	long d = 0;
	for(i = 0; i < strlen(clave); i++)
		d = d*31 + clave[i];
	d = abs(d);
	return d;
}

int direccion(TABLADISPERSION *T, char* clave)
{
	int i = 0;
	long p, dir;

	dir = funcionhash(clave);
	p = dir % TAM;
	return (int) p;
}

void insertarElemento(TABLADISPERSION* T, ALUMNO* A)
{
	int dir;
	dir = direccion(T, A -> nombre);
	T -> tabla[dir] = crearNodo(T -> tabla[dir], A);
}

Tipodatot busqTab(TABLADISPERSION* T, char* clave)
{
	int dir = direccion(T, clave);
	Tipodatot aux = T -> tabla[dir]; /*Tipodatot = NODO* */
	while((aux != NULL) && (strcmp(clave, aux -> dato -> nombre) != 0))   
		aux = aux -> siguiente;
	return aux;
}
void eliminarElemento(TABLADISPERSION* T, char* clave)
{
	int dir = direccion(T, clave);
	Tipodatot aux = busqTab(T, clave);
	eliminarLSE(&(T -> tabla[dir]), aux -> dato);
}
void mostrarTablaCompleta(TABLADISPERSION* T)
{
	int i;
	for(i = 0; i < TAM; i++)
	{
		if((T -> tabla[i]) != NULL)
		{
			printf("Registro: %d\n", i);
			imprimirLista(T -> tabla[i]);
		}
	}		
}
