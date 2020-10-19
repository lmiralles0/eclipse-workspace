/*
 * get_Entrada.c
 *
 *  Created on: 5 oct. 2020
 *      Author: Luciano Miralles
 */

#include <stdio.h>
#include <stdlib.h>


float get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError, float maximo, float minimo, int intentos){

	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && intentos >= 0){

		do{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("\n%s", mensajeError);
				intentos --;
			}
		} while(intentos >= 0);


	}
	return retorno;
}

char get_EntradaChar(char* pResultado, char* mensaje, char* mensajeError, char maximo, char minimo, int intentos){
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && intentos >= 0)
	{
		do{
			printf("%s", mensaje);
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("\n%s", mensajeError);
				intentos --;
			}
		} while(intentos >= 0);

	}
	return retorno;
}
