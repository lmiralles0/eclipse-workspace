/*
 * eParticipantes.c
 *
 *  Created on: 14 oct. 2022
 *      Author: MCvitani
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "eParticipantes.h"
#include "LinkedList.h"



eParticipantes* new_Participantes()
{
	eParticipantes* aux = NULL;
	aux = (eParticipantes*) malloc(sizeof(eParticipantes));
	if(aux != NULL)
	{
		aux->id_cuatri = 0;
		strcpy(aux->nombre, "");
		strcpy(aux->categoria, "");
		aux->tiempo = 0;
		aux->promedio = 0;
	}
	return aux;
}


eParticipantes* new_Participantes_Param(char* id_cuatri, char* nombre, char* categoria, char* tiempo, char* promedio)
{
	eParticipantes* aux = NULL;
	aux = new_Participantes();

	if(!(set_id(aux, atoi(id_cuatri))) && !(set_nombre(aux, nombre)) && !(set_categoria(aux, categoria))
	   && !(set_tiempo(aux, atoi(tiempo))) && !(set_promedio(aux, atof(promedio))))
	{
		aux = NULL;
		free(aux);
	}
	return aux;
}


int set_id(eParticipantes* participantes, int id)
{
	int result = 0;
	if(participantes != NULL && id >= 0)
	{
		participantes->id_cuatri = id;
		result = 1;
	}
	return result;
}


int set_nombre(eParticipantes* participantes, char* nombre)
{
	int result = 0;
	if(participantes != NULL && nombre != NULL)
	{
		strcpy(participantes->nombre, nombre);
		result = 1;
	}
	return result;
}


int set_categoria(eParticipantes* participantes, char* categoria)
{
	int result = 0;
	if(participantes != NULL && categoria != NULL)
	{
		strcpy(participantes->categoria, categoria);
		result = 1;
	}
	return result;
}


int set_tiempo(eParticipantes* participantes, int tiempo)
{
	int result = 0;
	if(participantes != NULL && tiempo >= 0)
	{
		participantes->tiempo = tiempo;
		result = 1;
	}
	return result;
}


int set_promedio(eParticipantes* participantes, float promedio)
{
	int result = 0;
	if(participantes != NULL && promedio >= 0)
	{
		participantes->promedio = promedio;
		result = 1;

	}
	return result;
}





