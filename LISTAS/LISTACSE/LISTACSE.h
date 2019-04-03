#ifndef __LISTACSE_H__
#define __LISTACSE_H__
#include <stdlib.h>

//LISTA CIRCULAR SIMPLEMENTE ENLAZADA

typedef int TipoDatoLCSE;
typedef struct nodocse
{
	struct nodocse* sig;
	TipoDatoLCSE dato;
}NODOCSE;

void ingresarLCSE(NODOCSE**, TipoDatoLCSE);
NODOCSE* buscarLCSE(NODOCSE*, TipoDatoLCSE);
void eliminarLCSE(NODOCSE**, TipoDatoLCSE);

#endif
