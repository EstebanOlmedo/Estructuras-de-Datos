#include "ALUMNO.h"

ALUMNO* ingresarAlumno()
{
	ALUMNO* A = (ALUMNO*) malloc(sizeof(ALUMNO));
	int n = 0;
	char c;
	for(n = 0; n < 30; n++)
		A -> nombre[n] = 0;
	n = 0;
	printf("\tIngresa el nombre del alumno: ");
	while((c = getchar()) != '\n')
	{
		A -> nombre[n] = c;
		n++;
	}
	for(n = 0; n < 10; n++)
		A -> bol[n] = 0;
	n = 0;
	printf("\tIngrese el numero de boleta del alumno: ");
	while((c = getchar()) != '\n')
	{
		A -> bol[n] = c;
		n++;
	}
	for(n = 0; n < 10; n++)
		A -> grupo[n] = 0;
	n = 0;
	printf("\tIngrese el grupo del alumno: ");
	while((c = getchar()) != '\n')
	{
		A -> grupo[n] = c;
		n++;
	}
	printf("\tIngrese la edad del alumno: ");
	scanf("%d", &(A -> edad));
	printf("\tIngrese la calificacion del alumno: ");
	scanf("%d", &(A -> calificacion));

	return A;
}

void mostrarAlumno(ALUMNO A)
{
	printf("\tNombre: %s\n", A.nombre);
	printf("\tBoleta: %s\n", A.bol);
	printf("\tGrupo: %s\n", A.grupo);
	printf("\tEdad: %d\n", A.edad);
	printf("\tCalificacion: %d\n", A.calificacion);
}
