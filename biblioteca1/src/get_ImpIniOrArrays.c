/*
 * ImprimirYOrdenarArrays.c
 *
 *  Created on: 15 oct. 2020
 *      Author: Luciano Miralles
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_Entrada.h"



int inicializaArraysInt(int* pArrays, int longitud, int valorInicial)//esta funcion devuelve -1 como error y 0 como todo ok
{
	int retorno = -1;
	int i;

	if(pArrays != NULL && longitud > 0)
	{
		retorno = 0;
		for(i= 0; i < longitud; i++)
		{
			pArrays[i] = valorInicial;

		}
	}
	return retorno;
}

int imprimeArraysInt(int* pArrays, int longitud)//esta funcion devuelve -1 como error y 0 como todo ok
{
	int retorno = -1;
	int i;

	if(pArrays != NULL && longitud > 0)
	{
		retorno = 0;
		for(i= 0; i < longitud; i++)
		{
			printf("\nIndice [%d], tiene el valor: %d",i, pArrays[i]);
		}
	}
	return retorno;
}

int get_EntradaArraysInt(int* pArrays, int longitud)
{
	int retorno = -1;
	int i= 0;
	int contenidoPosicion;

	if(pArrays != NULL && longitud > 0 && get_EntradaInt(&i,"" ,"", 1000, 0, 4) == 0)
	{
		retorno = 0;
		if(get_EntradaInt(&contenidoPosicion,"","",1000, 0, 4)){

			pArrays[i-1] = contenidoPosicion;
		}
	}
	return retorno;

}

int ordenarArrays(int* pArray, int limite)
{

	int retorno = -1;
	int i;
	int flagSwap;
	int bufferInt;

	if(pArray != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			limite --;
			for(i =0;i < limite; i++)
			{
				if(pArray[i] > pArray [i +1])
				{
					bufferInt = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = bufferInt;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}
