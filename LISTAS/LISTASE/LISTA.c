#include "LISTA.h"

//LISTA SIMPLEMENTE ENLAZADA

NODOSE* crearNodoLSE(NODOSE* enlace, Tipodatol x)
{
	NODOSE* nuevo = (NODOSE*) malloc(sizeof(NODOSE));
	nuevo -> dato = x;
	nuevo -> siguiente = enlace;
	return nuevo;
}
void insertarNodoCabLSE(NODOSE** cab, Tipodatol x)
{
	NODOSE* nuevo = crearNodoLSE(nuevo, x);
	nuevo -> siguiente = *cab;
	*cab = nuevo;
}
void insertarLSE(NODOSE* ant, Tipodatol x)
{
	NODOSE* nuevo = crearNodoLSE(nuevo, x);
	nuevo -> siguiente = ant -> siguiente;
	ant -> siguiente = nuevo;
}
NODOSE* buscarLSE(NODOSE* cab, Tipodatol x)
{
	NODOSE* aux = cab;
	for(; aux; aux = aux -> siguiente)
	{
		if(aux -> dato == x)
			return aux;
	}
	return aux;
}

void eliminarLSE(NODOSE** cab, Tipodatol x)
{
	NODOSE* ant = NULL;
	NODOSE* actual = *cab;
	int encontrado = 0;

	while(!encontrado && actual)
	{
		encontrado = (actual -> dato == x);
		if(!encontrado)
		{
			ant = actual;
			actual = actual -> siguiente;
		}
	}
	if(actual != NULL)
	{
		if(actual == *cab)
			*cab = actual -> siguiente;
		else
			ant -> siguiente = actual -> siguiente;
		free (actual);
	}
}
void eliminarTodaLSE(NODOSE** cab)
{
	while(*cab)
	{
		eliminarLSE(cab, (*cab) -> dato);
	}
}
void mostrarCompletaLSE(NODOSE* cab)
{
	while(cab)
	{
		printf("%d ", cab -> dato);
		cab = cab -> siguiente;
	}
	printf("\n");
}
void voltearLSE(NODOSE** cab)
{
	NODOSE* inicio = *cab;
	NODOSE* final = *cab;
	int cont = 0;
	if(*cab)
	{
		while(final -> siguiente)
		{
			final = final -> siguiente;
			cont ++;
		}
		while(cont)
		{
			final -> siguiente = inicio;
			*cab  = (*cab) -> siguiente;
			inicio -> siguiente = NULL;
			inicio = *cab;
			final = final -> siguiente;
			cont--;
		}
		final -> siguiente = NULL;
		voltearLSE(&((*cab) -> siguiente));
	}
}
