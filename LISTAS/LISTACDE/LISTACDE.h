#ifndef __LISTACDE_H__
#define __LISTACDE_H__
#include <stdlib.h>

//LISTA CIRCULAR DOBLEMENTE ENLAZADA

typedef int TipoDatoLCDE;
typedef struct nodocde
{
	TipoDatoLCDE dato;
	struct nodocde* ant;
	struct nodocde* sig;
}NODOCDE;

void ingresarLCDE(NODOCDE**, TipoDatoLCDE);
NODOCDE* buscarLCDE(NODOCDE*, TipoDatoLCDE);
void eliminarLCSE(NODOCDE**, TipoDatoLCDE);
#endif
