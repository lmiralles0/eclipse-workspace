#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_Entrada.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "r");
	if(f != NULL)
	{
		if(parser_EmployeeFromText(f, pArrayListEmployee) == 0)
		{
			retorno = 0;
		}
		fclose(f);
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "rb");
	if(f != NULL)
	{
		if(parser_EmployeeFromBinary(f, pArrayListEmployee) == 0)
		{
			retorno = 0;
		}
		fclose(f);
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* aux = NULL;
	if(pArrayListEmployee != NULL)
	{
        aux = employee_new();
        if(aux != NULL)
        {
            if((get_EntradaTexto(aux->nombre, 130, "Ingrese nombre del empleado.\n", "Error al ingresar nombre.\n", 4) == 0) &&
              (get_EntradaInt(&aux->horasTrabajadas, "Ingrese las horas trabajadas por el empleado.\n", "Error en el ingreso.\n", 400, 5, 3) == 0) &&
              (get_EntradaInt(&aux->sueldo, "Ingrese sueldo del empleado.\n", "Error al ingresar sueldo.\n", 100000, 500, 5) == 0))

            {
                ll_add(pArrayListEmployee, (Employee*)aux);
                retorno = 0;
            }
        }
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "w");
	int tam = ll_len(pArrayListEmployee);
	Employee* aux = NULL;
	int cant;
	if(f != NULL && pArrayListEmployee != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			aux = (Employee*)ll_get(pArrayListEmployee, i);
			cant = fprintf(f, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
			if(cant < 4)
			{
				break;
			}
		}
		retorno = 0;

	}
	fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* f = fopen(path, "wb");
	int tam = ll_len(pArrayListEmployee);
	//Employee* aux = NULL;
	int cant;
	if(f != NULL && pArrayListEmployee != NULL)
	{
		for(int i = 0; i < tam; i ++)
		{
			cant = fwrite((Employee*) ll_get(pArrayListEmployee, i), sizeof(Employee), 1, f);
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
