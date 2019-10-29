#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        char legajo[20];
        char nombre[20];
        char horasTrabajadas[20];
        char sueldo[20];

        pFile = fopen("datos.csv","r");

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",legajo, nombre, horasTrabajadas, sueldo);

        while(!feof(pFile))
        {
            Employee* unEmpleado;
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", legajo, nombre, horasTrabajadas, sueldo);

            unEmpleado->id = atoi(legajo);
            strcpy(unEmpleado->nombre, nombre);
            unEmpleado->horasTrabajadas = atoi(horasTrabajadas);
            unEmpleado->sueldo = atof(sueldo);

            pArrayListEmployee + i =  unEmpleado;
            i++;
        }
    }
    else
    {
        printf("\nERROR.Parametro nulo recibido...");
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
