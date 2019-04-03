#include "LISTA.h"
#include "PILA.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void menu ();
NODO* sumarNumeros(NODO*, NODO*);
NODO* multiplicarNumeros(NODO*, NODO*);
void imprimirLista(NODO*);
void imprimirListaCar(NODO*);
NODO* voltearLista(NODO*);
void hacerCopiaEnPila(NODO*, PILA**, int);

int main ()
{
	menu();
	return 0;
}

void menu()
{
	int res  = 0;
	char dig;
	NODO* numero1 = NULL;
	NODO* numero2 = NULL;
	NODO* resul;
	do
	{
		system("clear");
		puts("Ingresa el numero de la opcion deseada");
		printf("\t1.-Ingresar numero 1\n");
		printf("\t2.-Ingresar numero 2\n");
		printf("\t3.-Sumar numeros y mostrar el resultado\n");
		printf("\t4.-Multiplicar numeros y mostrar el resultado\n");
		printf("\t5.-Salir\n\t");
		scanf("%d", &res);

		switch(res)
		{
			case 1:
				system("clear");
				printf("Ingresa el numero con un enter cuando termines\n");
				__fpurge(stdin);
				numero1 = NULL;
				while((dig = getchar()) != '\n')
				{
					insertarNodoCabLSE(&numero1, dig - 48);
				}

				__fpurge(stdin);
				break;
			case 2:
				system("clear");
				printf("Ingresa el numero con un enter cuando termines\n");
				__fpurge(stdin);
				numero2 = NULL;
				while((dig = getchar()) != '\n')
				{
					numero2 = crearNodo(numero2, dig - 48);
				}

				__fpurge(stdin);
				break;
			case 3:	
				system("clear");
				__fpurge(stdin);
				printf("Numero 1: ");
				imprimirLista(numero1);
				printf("\n");
				printf("Numero 2: ");
				imprimirLista(numero2);
				printf("\n");
				printf("Resultado: ");
				resul = sumarNumeros(numero1, numero2);
				imprimirLista(resul);
				printf("\n");

				__fpurge(stdin);
				getchar();
				break;
			case 4:
				system("clear");
				printf("Numero 1: ");
				imprimirLista(numero1);
				printf("\n");
				printf("Numero 2: ");
				imprimirLista(numero2);
				printf("\n");
				printf("Resultado: ");
				resul = multiplicarNumeros(numero1, numero2);
				imprimirLista(resul);
				printf("\n");

				__fpurge(stdin);
				getchar();
				break;
			case 5:
				system("clear");
				printf("Hasta luego\n");

				__fpurge(stdin);
				getchar();
				break;
		}
	}while(res!=5);
}

NODO* sumarNumeros(NODO* numero1, NODO* numero2)
{
	char acarreo = 0;
	char res = 0;
	NODO* aux1 = numero1;
	NODO* aux2 = numero2;
	NODO* suma = NULL;
	while(aux1 && aux2)
	{
		res = (aux1 -> dato) + (aux2 -> dato) + acarreo;
		if(res >= 10)
			acarreo = 1;
		else
			acarreo = 0;
		res = res % 10;
		suma = crearNodo(suma, res);
		aux1 = aux1 -> siguiente;
		aux2 = aux2 -> siguiente;
	}
	if(aux1)
	{
		while(aux1)
		{
			res = (aux1 -> dato) + acarreo;
			aux1 = aux1 -> siguiente;
			if(res >= 10)
				acarreo = 1;
			else
				acarreo = 0;
			res = res % 10;
			suma = crearNodo(suma, res);
		}
	}
	if(aux2)
	{
		while(aux2)
		{
			res = (aux2 -> dato) + acarreo;
			aux2 = aux2 -> siguiente;
			if(res >= 10)
				acarreo = 1;
			else
				acarreo = 0;
			res = res % 10;
			suma = crearNodo(suma, res);
		}
	}
	if(acarreo)
	{
		suma = crearNodo(suma, acarreo);
		acarreo = 0;	
	}
	return voltearLista(suma);
}

NODO*  multiplicarNumeros(NODO* numero1, NODO* numero2)
{
	NODO* aux1;
	NODO* aux2;
	NODO* sumaPar = NULL;
	NODO* multiplicacion = NULL;
	char acarreo = 0;
	int n = 0, res = 0;
	PILA* P = NULL;

	for(aux1 = numero1; aux1; aux1 = aux1 -> siguiente)
	{
		acarreo  = 0;
		sumaPar = NULL;
		for(aux2 = numero2; aux2; aux2 = aux2 -> siguiente)
		{
			res = ((aux2 -> dato) * (aux1 -> dato)) + acarreo;
			acarreo = (res / 10);
			res = res % 10;
			sumaPar = crearNodo(sumaPar, res);
		}
		if(acarreo)
			sumaPar = crearNodo(sumaPar, acarreo);
		hacerCopiaEnPila(sumaPar, &P, n);
		n++;
	}
	multiplicacion = quitarPila(&P);
	while(!pilaVacia (P))
	{
		multiplicacion = sumarNumeros(multiplicacion, quitarPila(&P));
	}
	return multiplicacion;
}

void hacerCopiaEnPila(NODO* rec, PILA** P, int n)
{
	NODO* ins = NULL;
	NODO* copia = rec;
	char quit;
	while(copia)
	{
		quit = copia -> dato;
		ins = crearNodo(ins, quit);
		copia = copia -> siguiente;
	}
	while (n)
	{
		ins = crearNodo(ins, 0);
		n--;
	}
	insertarPila(P, ins);
}

NODO* voltearLista(NODO* nod)
{
	NODO* aux =  NULL;
	char quit;
	while(nod)
	{
		quit = nod -> dato;
		aux = crearNodo(aux, quit);
		nod = nod -> siguiente;
	}
	return aux;
}

void imprimirLista(NODO* aux)
{
	char quit;
	if(aux)
	{
		quit = aux -> dato;
		imprimirLista(aux -> siguiente);
		printf("%d", quit);
	}
}
