/*
 ============================================================================
 Name        : biblioteca1.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "get_Entrada.h"


int get_EntradaInt(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int intentos);

int main(void)
{
	setbuf(stdout, NULL);
	int respuesta;

	if(get_EntradaInt(&respuesta,"Escriba un numero: ","No es un numero valido.\n",300,-5,3) == 0)
	{
		printf("El numero ingresado es %d.", respuesta);
	}
	else
	{
		printf("\nError.");
	}

	return EXIT_SUCCESS;
}
