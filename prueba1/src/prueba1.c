/*
 ============================================================================
 Name        : prueba1.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_Texto.h"
#define LEN 1000


int main()
{
	setbuf(stdout, NULL);
    char nombre[LEN];


    if(get_Texto(nombre, LEN,"Ingrese Texto:\n", "No es un texto\n" ,3) == 0)
    {
        printf("Ingreso: %s", nombre);
    }
    else
    {
        printf("\nError.");
    }
    return EXIT_SUCCESS;
}
