#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno=-1;
    pArchivo = fopen(path,"rb");
    if(pArchivo!=NULL)
    {
        retorno=parser_EmployeeFromText(pArchivo,pArrayListEmployee);
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
    return 1;
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
    return 1;
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
    int empleadoEncontrado;
    char confirmar;
    int id;
    int retorno = -1;
    int len;
    Employee* this;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        controller_ListEmployee(pArrayListEmployee);

        if(getInt(&id,"Ingrese el Id del Empleado a Borrar: ","\nError el Id solo debe tener numeros..",0,len))
        {
            retorno = -2;
        }
        else
        {
          ///  empleadoEncontrado = findEmployeeById(lista,len,id);///CAMBIAR ESTA FUNCION

            if(empleadoEncontrado != -1)
            {
                this = ll_get(pArrayListEmployee,empleadoEncontrado);
                mostrarEmpleado(this);

                continuarSiONo(&confirmar,"\nEsta seguro que desea eliminar a este Empleado? S/N : ");///ESTA TAMBIEN

                if(confirmar == 'n')
                {
                    printf("Baja cancelada\n\n");
                }
                else
                {
                    ll_remove(pArrayListEmployee,empleadoEncontrado);
                    printf("Borrado exitoso\n\n");
                    retorno = 0;
                }

                system("pause");
                system("cls");
            }
            else
            {
                printf("\nEmpleado NO encontrado..\n");
                system("pause");
                system("cls");
            }
        }
    }

    return retorno;
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
    int order;
    int comoOrdenar;
    getInt(&order,"\t---------- Menu Ordenar ----------\n\n"
           "1. Ordenar por id\n"
           "2. Ordenar por Nombre\n"
           "3. Ordenar por Horas Trabajadas\n"
           "4. Ordenar por Sueldo\n\n"
           "Ingrese opcion: ","ERROR. Debe ingresar un numero...",1,4);

    switch(order)
    {
    case 1:

        formaDeOrdenar("\t---------- Ordenar por id ----------\n\n",&comoOrdenar);

        ordenarAscendienteODecendiente(pArrayListEmployee,compararPorLegajo,comoOrdenar);  ///PASAR LA FUNC PARA ORDENAR COMO PARAMETRO Y PASAR LA LINKEDLIST
        break;

    case 2:

        formaDeOrdenar("\t---------- Ordenar por id ----------\n\n",&comoOrdenar);




    }
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
    return 1;
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
    return 1;
}

