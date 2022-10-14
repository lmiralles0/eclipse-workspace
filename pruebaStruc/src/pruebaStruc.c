/*
 ============================================================================
 Name        : pruebaStruc.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"


int main(void)
{
	setbuf(stdout, NULL);

	Producto auxiliar;

	strcpy(auxiliar.name, "HOLAA");
	auxiliar.edad = 50;

	imprimirProducto(&auxiliar);

	return EXIT_SUCCESS;
}
