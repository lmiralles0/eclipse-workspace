/*
 * Producto.c
 *
 *  Created on: 22 nov. 2020
 *      Author: Luciano Miralles
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"

void imprimirProducto(Producto* list);

void imprimirProducto(Producto* list)
{
	printf("NOMBRE %s, EDAD %d.",list->name, list->edad);

}


