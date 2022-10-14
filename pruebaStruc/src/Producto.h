/*
 * Producto.h
 *
 *  Created on: 22 nov. 2020
 *      Author: Luciano Miralles
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct{
	char name[50];
	int edad;
}Producto;

void imprimirProducto(Producto* list);

#endif /* PRODUCTO_H_ */
