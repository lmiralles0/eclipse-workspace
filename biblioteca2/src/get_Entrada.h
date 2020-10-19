/*
 * get_Entrada.h
 *
 *  Created on: 5 oct. 2020
 *      Author: Luciano Miralles
 */

#ifndef GET_ENTRADA_H_
#define GET_ENTRADA_H_


float get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError, float maximo, float minimo, int intentos);
char get_EntradaChar(char* pResultado, char* mensaje, char* mensajeError, char maximo, char minimo, int intentos);




#endif /* GET_ENTRADA_H_ */
