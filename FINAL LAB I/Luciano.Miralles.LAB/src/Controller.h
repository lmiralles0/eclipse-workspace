/*
 * Controller.h
 *
 *  Created on: 31 ago. 2022
 *      Author: Luciano Miralles
 */
#include "LinkedList.h"
#include "parser.h"
#include "eParticipantes.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_saveAsBinary(char* path , LinkedList* pArray);
int controller_saveAsText(char* path, LinkedList* pArray);
int controller_loadFromBinary(char* path , LinkedList* pArray);
int controller_loadFromText(char* path, LinkedList* pArray);

#endif /* CONTROLLER_H_ */
