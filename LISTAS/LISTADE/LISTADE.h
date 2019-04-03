#ifndef __LISTADE_H__
#define __LISTADE_H__
#include <stdlib.h>

//LISTA DOBLEMENTE ENLAZADA

typedef int TipoDatoLDE;
typedef struct nodode
{
	TipoDatoLDE dato;
	struct nodode* sig;
	struct nodode* ant;
}NODODE;

void insertarCabLDE(NODODE**, TipoDatoLDE);
void insertarLDE (NODODE*, TipoDatoLDE);
NODODE* buscarLDE(NODODE*, TipoDatoLDE);
void eliminarLDE(NODODE**, TipoDatoLDE);

#endif
