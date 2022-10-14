/*
 ============================================================================
 Name        : Start.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void cargarVector(int* pVector, int longitud);
void imprimirVector(int* pVector, int longitud);

int main()
{

	setbuf(stdout, NULL);
	int* vector = NULL;
	int* aux = NULL;
	int tam;

	tam = 5;
	vector = (int*) malloc(sizeof(int) * tam);

	if(vector != NULL)
	{
		cargarVector(vector, tam);
		imprimirVector(vector, tam);
	}

	aux = (int*) realloc (vector, sizeof(int) * 10);

	if(aux != NULL)
	{
		vector = aux;
		aux = NULL;
		tam += 5;
	}

	for(int i = 5; i < tam; i++)
	{
		printf("\nIngrese el numero a cargar: \n");
		scanf("%d", vector + i);
	}
	imprimirVector(vector, tam);

	free(vector);

	return EXIT_SUCCESS;
}

void cargarVector(int* pVector, int longitud)
{
	if(pVector != NULL)
	{
		for(int i = 0; i < longitud; i++)
		{
			printf("\nIngrese el numero a cargar: \n");
			scanf("%d", pVector + i);
		}

	}
}

void imprimirVector(int* pVector, int longitud)
{
	if(pVector != NULL)
	{
		printf("Vector: ");
		for(int i = 0; i < longitud; i++)
		{
			printf("%d ", *(pVector + i));
		}

	}
}
