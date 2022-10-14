#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "Employee.h"
#include "LinkedList.h"
#include "get_Entrada.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int id = 1001;

    LinkedList* listaEmpleados = ll_newLinkedList();

    FILE* f1 = NULL;
    FILE* f1 = fopen("f_Id.bin", "rb");
    if(f1 == NULL)
    {
        printf("Error en el Id.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int cant;
        cant = fread(&id, sizeof(int),1 , f1);
        if(cant < 1)
        {
            printf("Error en el Id.\n");
            exit(EXIT_FAILURE);
        }
        fclose(f1);
    }

    do{
        printf("Menu:\n");
        printf("\t1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("\t2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf("\t3. Alta de empleado.\n");
        printf("\t4. Modificar datos de empleado.\n");
        printf("\t5. Baja de empleado.\n");
        printf("\t6. Listar empleados.\n");
        printf("\t7. Ordenar empleados.\n");
        printf("\t8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("\t9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("\t10. Salir.\n");


        if(get_EntradaInt(&option, "Ingrese un numero del menu.\n", "Error al ingresar numero del menu.\n",10, 1, 4 ) == 0)
        {
            switch(option)
            {
            case 1:
                system("cls");
                if(controller_loadFromText("data.txt", listaEmpleados) == 0)
                {
                	printf("Empleados desde modo texto, cargados con exito.\n");
                }
                system("pause");
            	system("cls");
				break;
            case 2:
                system("cls");
            	if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
            	{
            		printf("Empleados desde modo binario, cargados con exito.\n");
            	}
            	system("pause");
            	system("cls");
            	break;
            case 3:
                system("cls");
            	if((controller_addEmployee(listaEmpleados)) == 0)
                {
                    ((Employee*)ll_get(listaEmpleados, (ll_len(listaEmpleados)-1)))->id = id;
                    id++;
                }
                system("pause");
                system("cls");
            	break;
            case 5:

            	break;
            case 6:
                system("cls");
            	if(employees_Print(listaEmpleados) == 1)
            	{
            		printf("No hay empleados para mostrar.\n");
            	}
            	system("pause");
            	system("cls");
            	break;
            case 8:
                system("cls");
            	if(controller_saveAsText("data.txt", listaEmpleados) == 0)
            	{
            		printf("El archivo de texto se ha guardado con exito.\n");
            	}
            	system("pause");
            	system("cls");
            	break;
            case 9:
                system("cls");
            	if(controller_saveAsBinary("data.bin", listaEmpleados) == 0)
            	{
            		printf("El archivo binario se ha guardado con exito.\n");
            	}
            	system("pause");
            	system("cls");
            	break;
            case 10:
                system("cls");
                f = fopen("f_Id.bin", "wb");
                if(f != NULL)
                {
                    int cant1 = fwrite(&id, sizeof(int), 1, f);
                    if(cant1 < 1)
                    {
                        printf("Error en el Id.\n");
                        system("pause");
                    }
                }
                fclose(f);
                break;
        	}
        }
    }while(option != 10);
    return 0;
}



