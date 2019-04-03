#include "LISTA.h"
#include "TABLA.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

void menu();

int main (void)
{
	menu();
	return 0;
}

void menu()
{
	int res = 0;
	char clave [30];
	int n;
	Tipodatol A;
	Tipodatot L;
	char c;
	int dir = 0;
	TABLADISPERSION T;
	crearTabla(&T);
	for(n = 0; n < 30; n++)
		clave[n] = 0;
	n = 0;

	do
	{
		system("clear");
		puts("------------------------------------------------------------");
		puts("INGRESE EL NUMERO DE LA OPCION DESEADA");
		puts("------------------------------------------------------------");
		printf("\t1.-Dar de alta un alumno\n");
		printf("\t2.-Mostrar un alumno\n");
		printf("\t3.-Elimina un alumno\n");
		printf("\t4.-Mostrar todos los registros\n");
		printf("\t5.-Salir\n\t");
		scanf("%d", &res);

		switch(res)
		{
			case 1:
				system("clear");
				__fpurge(stdin);
				A = ingresarAlumno();
				insertarElemento(&T, A);
				break;
			case 2:
				system("clear");
				__fpurge(stdin);
				printf("INGRESE EL NOMBRE DEL ALUMNO QUE DESEA BUSCAR\n");
				for(n = 0; n < 30; n++)
					clave[n] = 0;
				n = 0;
				while((c = getchar()) != '\n')
				{
					clave[n] = c;
					n++;
				}
				L = busqTab(&T, clave);
				if(L)
				{
					dir = direccion(&T, L -> dato -> nombre);
					printf("Registro: %d\n", dir);
					mostrarAlumno(*(L -> dato));
				}
				else
					puts("EL ALUMNO AUN NO HA SIDO INGRESADO");

				__fpurge(stdin);
				getchar();

				break;
			case 3:
				system("clear");
				__fpurge(stdin);
				printf("INGRESE EL NOMBRE DEL ALUMNO QUE DESEA ELIMINAR\n");
				for(n = 0; n < 30; n++)
					clave[n] = 0;
				n = 0;
				while((c = getchar()) != '\n')
				{
					clave[n] = c;
					n++;
				}
				eliminarElemento(&T, clave);
				break;
			case 4:
				system("clear");
				mostrarTablaCompleta(&T);
				__fpurge(stdin);
				getchar();
				break;
			case 5:
				system("clear");
				puts("Hasta luego");
				break;
			default:
				system("clear");
				puts("Introduce una opcion correcta");
				break;
		}	
	}while(res != 5);
}

