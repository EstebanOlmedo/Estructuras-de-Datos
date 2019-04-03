#include <stdio.h>

int main (void)
{
	char prueba = 0;
	prueba += 20;

	printf("%c, %c, %c\n", prueba, prueba / 10, prueba % 10);

	return 0;
}
