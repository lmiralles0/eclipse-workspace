/*
 * get_Texto.c
 *
 *  Created on: 22 oct. 2020
 *      Author: Luciano Miralles
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000

static int get_String(char *cadena, int longitud);
static int esString(char* cadena, int longitud);
static int myGetsTexto(char* cadena, int longitud);

int get_Texto(char* pResultado, int longitud, char* mensaje, char* mensajeError, int intentos)
{
    int retorno = -1;
    char bufferString[LEN];

    if(pResultado != NULL && longitud > 0 && mensaje != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            if(get_String(bufferString, LEN) == 0)
            {
            	strncpy(pResultado, bufferString, longitud);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                intentos --;
            }
        }while(intentos >= 0);
    }
    return retorno;
}

static int get_String(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[LEN];
    if(cadena != NULL && longitud > 0)
    {
        if(myGetsTexto(bufferString, LEN) == 0 && esString(bufferString, LEN) && strnlen(bufferString,sizeof(bufferString)) < longitud)
        {
            strncpy(cadena, bufferString, longitud);
            retorno = 0;
        }
    }
    return retorno;
}

static int myGetsTexto(char* cadena, int longitud)
{
    int retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
    {
        fflush(stdin);
        retorno = 1;
        if(cadena[0] != '\n')
        {
            if(cadena[strlen(cadena)-1] == '\n')
            {
                cadena[strlen(cadena)-1] = '\0';
            }
        }
        retorno = 0;
    }
    return retorno;
}

static int esString(char* cadena, int longitud)
{
    int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0; cadena[i] != '\0' ; i++)
		{
			if((cadena[i] <'a' || cadena[i] >'z') && (cadena[i] < 'A' || cadena[i] >'Z'))
			{
				retorno = 0;
				break;
			}
	    }
	}
	return retorno;
}


