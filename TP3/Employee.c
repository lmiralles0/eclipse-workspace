#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "get_Entrada.h"


Employee* employee_new()
{
	Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
	if(newEmployee != NULL)
	{
		newEmployee->id = 0;
		newEmployee->horasTrabajadas = 0;
		newEmployee->sueldo = 0;
		strcpy(newEmployee->nombre, "  ");
	}
	return newEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee = employee_new();
	if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(!(employee_setId(newEmployee, atoi(idStr)) && employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) &&
			employee_setNombre(newEmployee, nombreStr) && employee_setSueldo(newEmployee, atoi(sueldoStr))))
		{
			free(newEmployee);
			newEmployee = NULL;
		}

	}
	return newEmployee;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this, int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int employee_getId(Employee* this, int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{

	int retorno = 0;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{

	int retorno = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;

}

int employee_setSueldo(Employee* this, int sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{

	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

void employee_Print(Employee* employee)
{
	printf("%d    %10s        %d     %d \n", employee->id, employee->nombre, employee->sueldo, employee->horasTrabajadas);
}


int employees_Print(LinkedList* pArrayLinkedlist)
{
	int retorno = 1;
	int tam = ll_len(pArrayLinkedlist);
	if(pArrayLinkedlist != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			employee_Print((Employee*) ll_get(pArrayLinkedlist, i));
		}
		retorno = 0;
	}
	return retorno;
}
