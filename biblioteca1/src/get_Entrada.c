/*
 * get_Entrada.c
 *
 *  Created on: 5 oct. 2020
 *      Author: Luciano Miralles
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000


static int get_Int(int* pResultado);
static int esNumericaInt(char* cadena);
static int myGetsInt(char* cadena, int longitud);
///
static int get_Float(float* pResultado);
static int esNumericaFloat(char* cadena);
static int myGetsFloat(char* cadena, int longitud);
///
static int get_String(char *cadena, int longitud);
static int esString(char* cadena, int longitud);
static int myGetsTexto(char* cadena, int longitud);
///
static int get_Char(char* cadena, int longitud);
static int myGetsChar(char* cadena, int longitud);
static int esChar(char* cadena);

int get_EntradaInt(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int intentos){

	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && intentos >= 0){

		do{
			printf("%s", mensaje);

			if(get_Int(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
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
/*get_Int le da un arrays de caracteres al usuario para que el usuario ingrese,
 * aca se va leer como texto (pero aca le pedimos numeros). Entonces entra la funciona esNumerica
 * para ver si es numero o no y la myGetsInt para que no me desborde la funcion antigua scanf
 */
static int get_Int(int* pResultado)
{
	int retorno = -1;
	char bufferInt[LEN];

	if(myGetsInt(bufferInt,sizeof(bufferInt)) == 0 && esNumericaInt(bufferInt))
	{
		*pResultado = atoi(bufferInt);
		retorno = 0;
	}
	return retorno;
}

static int esNumericaInt(char* cadena) //Esta funcion tira verdadero o falso (1 v o 0 en f)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && strlen(cadena)>0)
	{
		for(i=0; cadena[i] != '\0' ; i++)
		{
			if(i ==0 && (cadena[i] == '-' || cadena [i] == '+'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
	    }
	}
	return retorno;
}

static int myGetsInt(char* cadena, int longitud)
{
	int retorno = -1;
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)//fgets saca la informacion del fflush porque al limpiar la consola es un archivo
    {
    	fflush(stdin);//me limpia la consola
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

int get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError, float maximo, float minimo, int intentos){

	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && intentos >= 0){

		do{
			printf("%s", mensaje);

			if(get_Float(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
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

static int get_Float(float* pResultado)
{
	int retorno = -1;
	char bufferFloat[LEN];

	if(myGetsFloat(bufferFloat,sizeof(bufferFloat)) == 0 && esNumericaFloat(bufferFloat))
	{
		*pResultado = atof(bufferFloat);
		retorno = 0;
	}
	return retorno;
}

static int esNumericaFloat(char* cadena) //Esta funcion tira verdadero o falso (1 v o 0 en f)
{
	int i = 0;
	int retorno = 1;
    int contadorPunto = 0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		for(i=0; cadena[i] != '\0' ; i++)
		{
			if(i ==0 && (cadena[i] == '-' || cadena [i] == '+'))
			{
				continue;
			}
			if(cadena[i] <= '9' && cadena[i] >= '0')
			{
				if(cadena[i] == '.' && contadorPunto == 0)
				{
					contadorPunto ++;
				}
				else
				{
				retorno = 0;
				break;
				}
			}
	    }
	}
	return retorno;
}

static int myGetsFloat(char* cadena, int longitud)
{
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
    {
    	fflush(stdin);

    	if(cadena[strlen(cadena)-1] == '\n')
    	{
    		cadena[strlen(cadena)-1] = '\0';
    	}
    }
	return 0;
}



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
        }
        while(intentos >= 0);
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
            if(((cadena[i] <'a' || cadena[i] >'z') && (cadena[i] < 'A' || cadena[i] >'Z')))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}



int get_EntradaChar(char* pResultado, int longitud, char* mensaje, char* mensajeError, char maximo, char minimo, int intentos)
{
    int retorno = 1;
    char bufferChar[LEN];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo> minimo && intentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            if(get_Char(bufferChar, sizeof(bufferChar)) == 0 && bufferChar[0] >= minimo && bufferChar[0] <= maximo)
            {
                strncpy(pResultado, bufferChar, longitud);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                intentos --;
            }

        }while(intentos > 0);
    }
    return retorno;
}


static int get_Char(char* cadena, int longitud)
{
    int retorno = 1;
    char bufferChar[LEN];
    if(cadena != NULL && longitud > 0)
    {
        if(myGetsChar(bufferChar, LEN) == 0 && esChar(bufferChar))
        {
            strncpy(cadena, bufferChar, longitud);
            retorno = 0;
        }

    }
    return retorno;
}

static int myGetsChar(char* cadena, int longitud)
{
    int retorno = 1;
    if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)- 1] == '\n')
            {
                cadena[strlen(cadena) - 1] = '\0';
            }
        retorno = 0;
    }
    return retorno;
}

static int esChar(char* cadena)
{
    int i = 0;
	int retorno = 1;

	if(cadena != NULL)
	{
		for(i=0; cadena[i] != '\0' ; i++)
		{
			if((cadena[0] <'a' || cadena[0] >'z' || cadena[0] == '\0') ||
                (i >= 1 && ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9'))))
			{
				retorno = 0;
				break;
			}
	    }
	}
	return retorno;
}
