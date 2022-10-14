/*
 * eParticipantes.h
 *
 *  Created on: 14 oct. 2022
 *      Author: MCvitani
 */

#ifndef EPARTICIPANTES_H_
#define EPARTICIPANTES_H_

typedef struct
{
	int id_cuatri;
	char nombre[30];
	char categoria[30];
	int tiempo;
	float promedio;
}eParticipantes;

int set_id(eParticipantes* participantes, int id);
int set_nombre(eParticipantes* participantes, char* nombre);
int set_categoria(eParticipantes* participantes, char* categoria);
int set_tiempo(eParticipantes* participantes, int tiempo);
int set_promedio(eParticipantes* participantes, float promedio);

#endif /* EPARTICIPANTES_H_ */
