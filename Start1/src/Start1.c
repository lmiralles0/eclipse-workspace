/*
 ============================================================================
 Name        : Start1.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 3

int main(void) {

	setbuf(stdout,NULL);
	char cadena[LEN];
	fflush(stdin);

	printf("Puede escribir %d caracteres.\n", sizeof(cadena));
	printf("\nEscribe tu nombre:\n");
	fgets(cadena,sizeof(cadena),stdin);
    printf("Nombre: %s", cadena);

	return EXIT_SUCCESS;
}
