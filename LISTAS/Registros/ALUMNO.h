#ifndef __ALUMNO_H__
#define __ALUMNO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumno
{
	char nombre [30];
	char bol[11];
	char grupo[6];
	int edad;
	int calificacion;
}ALUMNO;

ALUMNO* ingresarAlumno();
void mostrarAlumno(ALUMNO);

#endif
