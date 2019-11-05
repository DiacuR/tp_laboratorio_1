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
    int cant;
    int retorno = 1;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        char legajo[20];
        char nombre[20];
        char horasTrabajadas[20];
        char sueldo[20];

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",legajo, nombre, horasTrabajadas, sueldo);

        while(!feof(pFile))
        {

            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", legajo, nombre, horasTrabajadas, sueldo);

            if(cant == 4)
            {
                Employee* this = new_employee();

                this->id = atoi(legajo);
                strcpy(this->nombre, nombre);
                this->horasTrabajadas = atoi(horasTrabajadas);
                this->sueldo = atof(sueldo);

                ll_add(pArrayListEmployee,this);
            }
            else
            {
                printf("\nERROR. No se pudo cargar el archivo...");
                system("pause");
                system("cls");
            }
        }
        retorno = 0;
        fclose(pFile);
    }
    else
    {
        printf("\nERROR.Parametro nulo recibido...\n");
        system("pause");
        system("cls");
    }

    return retorno;
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
    int retorno = 1;
    int freadRetorno;
    int contador = 0;
    Employee* aux = new_employee();

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        Employee* this;

        while(!feof(pFile))
        {
            this = employee_new();
            int tam = sizeof(Employee);
            printf("\n%d\n", tam);

            freadRetorno = fread(this,sizeof(Employee),1,pFile);

            mostrarEmpleado(this);
            printf("\n\n");

            if(freadRetorno == 1)
            {
                mostrarEmpleado(this);
                ll_add(pArrayListEmployee,this);
                contador++;
            }
            else
            {
                printf("\nERROR. No se pudo cargar el archivo...");
                system("pause");
                system("cls");
                break;
            }
        }
        retorno = 0;
    }
    else
    {
        printf("\nERROR.Parametro nulo recibido...\n");
        system("pause");
        system("cls");
    }
    return retorno;
}
