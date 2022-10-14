/*
 * Controller.c
 *
 *  Created on: 31 ago. 2022
 *      Author: Luciano Miralles
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "eParticipantes.h"
#include "parser.h"


/** \brief Guarda los datos del struc en el archivo .csv (modo binario)
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return 1 en caso de falla o 0 en caso de exito
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArray)
{

	int retorno = 1;
	FILE* f = fopen(path, "wb");
	int tam = ll_len(pArray);
	int cant;
	if(f != NULL && pArray != NULL)
	{
		for(int i = 0; i < tam; i ++)
		{
			cant = fwrite((eParticipantes*) ll_get(pArray, i), sizeof(eParticipantes), 1, f);
			if(cant !=  1)
			{
				break;
			}
		}
		retorno = 0;
	}
	fclose(f);
	return retorno;
}


/** \brief Guarda los datos del struc en el archivo .csv (modo texto)
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return 1 en caso de falla o 0 en caso de exito
 *
 */
int controller_saveAsText(char* path, LinkedList* pArray)
{
	int retorno = 1;
	FILE* f = fopen(path, "w");
	int tam = ll_len(pArray);
	eParticipantes* aux = NULL;
	int cant;
	if(f != NULL && pArray != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			aux = (eParticipantes*)ll_get(pArray, i);
			cant = fprintf(f, "%d,%s,%s,%d,%f\n",aux->id_cuatri, aux->nombre, aux->categoria, aux->tiempo, aux->promedio);
			if(cant < 7)
			{
				break;
			}
		}
		retorno = 0;

	}
	fclose(f);
	return retorno;
}


/** \brief Carga los datos del struct desde el archivo .csv (modo binario).
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return 1 en caso de falla o 0 en caso de exito
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArray)
{
	int retorno = 1;
		FILE* f = fopen(path, "rb");
		if(f != NULL)
		{
			if(parser_FromBinary(f, pArray) == 0)
			{
				retorno = 0;
			}
			fclose(f);
		}
	    return retorno;
}


/** \brief Carga los datos del struct desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return 1 en caso de falla o 0 en caso de exito
 *
 */
int controller_loadFromText(char* path, LinkedList* pArray)
{
	int retorno = 1;
	FILE* f = fopen(path, "r");
	if(f != NULL)
	{
		if(parser_FromText(f, pArray) == 0)
		{
			retorno = 0;
		}
		fclose(f);
	}
	return retorno;
}



