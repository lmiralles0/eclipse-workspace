/*
 ============================================================================
 Name        : estructuras1.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100

typedef struct
{
	int legajo;
	char nombre[LEN];
	char apellido[LEN];
	float altura;

}Alumno;

int main(void)
{
	Alumno auxiliar;

	auxiliar.legajo = 1;
	strcpy(auxiliar.nombre,"Luciano");
	strcpy(auxiliar.apellido,"Miralles");
	auxiliar.altura = 1.69;

	printf("Legajo N° %d.\nNombre : %s.\nApellido: %s.\nAltura: %f.",auxiliar.legajo, auxiliar.nombre, auxiliar.apellido, auxiliar.altura);

	return EXIT_SUCCESS;
}
