#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int n = 1000;
	FILE* pf = fopen ("numeros.txt", "wt");
	while(n)
	{
		fputc('1', pf);
		n--;
	}
}
