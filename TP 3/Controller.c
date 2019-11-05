#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int employee_Id(LinkedList* pArrayListEmployee, int* idEmpleado){
    int estado= 0;
    int i;

    if(pArrayListEmployee != NULL && idEmpleado != NULL)
    {
        Employee* this;

        for(i=0; i< ll_len(pArrayListEmployee);i++)
        {
            this= ll_get(pArrayListEmployee, i);

            if(this->id >= *idEmpleado)
            {
                *idEmpleado= this->id;
            }
        }
        estado= 1;
    }
    return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno;
    FILE* pFile;

    pFile = fopen(path,"r");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
        fclose(pFile);
    }
    else
    {
        printf("\nERROR.El archivo a cargar no existe..");
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
    int retorno;
    FILE* pFile;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        retorno = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        fclose(pFile);
    }
    else
    {
        printf("\nERROR.El archivo a cargar no existe...");
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idEmpleado)
{
    int id;
    char nombre[50];
    int modNombre;
    char respuesta;
    int horasTrabajadas;
    int sueldo;
    int retorno;
    int reintentos = 3;
    int retornoHorasTrabajadas;
    int retornoSueldo;
    Employee* this = employee_new();


    do
    {
        system("cls");
        printf("\t---------- Alta de Empleado ----------\n");

        pedirNombre(nombre,&reintentos);

        if(reintentos == 0)
        {
            imprimirLimiteDeReintentos();
            break;
        }

        pedirHorasTrabajadas(&horasTrabajadas,&reintentos);

        if(reintentos == 0)
        {
            imprimirLimiteDeReintentos();
            break;
        }

        pedirSueldo(&sueldo,&reintentos);

        if(reintentos == 0)
        {
            imprimirLimiteDeReintentos();
            break;
        }

        id = *idEmpleado;
        id++;

        this = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

        if(this != NULL)
        {
            mostrarColumnas();
            mostrarEmpleado(this);

            validacionEntreChar(&respuesta,"\nDesea dar de alta a este Empleado S/N: ",'s','n',reintentos);

            *idEmpleado = id;


            if(respuesta == 's')
            {

                ll_add(pArrayListEmployee,this);

                retorno = 0;
                printf("\n------Empleado Guardado-------\n");
                system("pause");
                system("cls");
            }
            else if(respuesta == 'n')
            {
                retorno = 1;
                printf("\n----------Empleado NO Guardado-----------\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            printf("ERROR.Datos recibidos invalidos...");
        }
    }while(respuesta != 's');

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
    int retorno;
    int reintentos = 3;
    int id;
    int index;
    int len;
    Employee* this;
    Employee emp;
    Employee* aux;
    char nombre[30];
    char modNombre;
    int horasTrabajadas;
    char modHorasTrabajadas;
    int sueldo;
    char modSueldo;
    char guardarEmpleado;


    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        if(!getInt(&id,"Ingrese el Id del Empleado a Modificar: ","Error el Id solo debe tener numeros..",0,len))
        {

            index = employee_EncontrarPorId(pArrayListEmployee,this,id);

            if(index == -1)
            {
                printf("\nERROR.No hay empleado con ese Id..\n");
                system("pause");
                system("cls");
            }
            else
            {
                this = ll_get(pArrayListEmployee,index);
                if(this != NULL)
                {
                    emp = *this;
                    aux = &emp;

                    system("cls");
                    mostrarEmpleadoAModificar(aux);

                    validacionEntreChar(&modNombre,"Desea modificar el nombre? S/N: ",'s','n',reintentos);
                    system("cls");
                    if(modNombre == 's')
                    {
                        pedirNombre(nombre,&reintentos);
                        employee_setNombre(aux,nombre);
                    }

                    mostrarEmpleadoAModificar(aux);

                    validacionEntreChar(&modHorasTrabajadas,"Desea modificar las horas trabajadas? S/N: ",'s','n',reintentos);
                    system("cls");
                    if(modHorasTrabajadas == 's')
                    {
                        pedirHorasTrabajadas(&horasTrabajadas,&reintentos);
                        employee_setHorasTrabajadas(aux,horasTrabajadas);
                    }

                    system("cls");

                    mostrarEmpleadoAModificar(aux);
                    validacionEntreChar(&modSueldo,"Desea modificar el Sueldo? S/N: ",'s','n',reintentos);
                    system("cls");

                    if(modSueldo == 's')
                    {
                        pedirSueldo(&sueldo, &reintentos);
                        employee_setSueldo(aux,sueldo);
                    }

                    system("cls");

                    mostrarEmpleadoAModificar(aux);
                    validacionEntreChar(&guardarEmpleado,"Desea guardar la modificacion de este empleado? S/N: ",'s','n',reintentos);

                    if(guardarEmpleado == 's')
                    {
                        *this = emp;
                        ll_set(pArrayListEmployee,index,this);
                        printf("\t---------- El empleado a sido modificado ----------\n");
                    }
                    else if(guardarEmpleado == 'n')
                    {
                        printf("\t---------- El empleado NO a sido modificado ----------\n");
                        aux = NULL;
                    }
                }

            }

        }
    }
    else
    {
       printf("ERROR. Parametro nulo recivido...");
    }

    return retorno;
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
    int reintentos = 3;
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
            do
            {
                empleadoEncontrado = employee_EncontrarPorId(pArrayListEmployee,this,id);

                if(empleadoEncontrado != -1)
                {
                    this = ll_get(pArrayListEmployee,empleadoEncontrado);
                    mostrarEmpleado(this);

                    validacionEntreChar(&confirmar,"\nEsta seguro que desea eliminar a este Empleado? S/N : ",'s','n',reintentos);///ESTA TAMBIEN


                    if(confirmar == 'n')
                    {
                        printf("Baja cancelada\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    else if(confirmar == 's')
                    {
                        ll_remove(pArrayListEmployee,empleadoEncontrado);
                        printf("Borrado exitoso\n\n");
                        system("pause");
                        system("cls");
                        retorno = 0;
                    }

                }
                else
                {
                    printf("\nEmpleado NO encontrado..\n");
                    system("pause");
                    system("cls");
                }
            }while(confirmar != 's');
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
    int i;
    int len;
    Employee* auxEmpleado;

    len = ll_len(pArrayListEmployee);

    for(i = 0; i < len; i++)
    {
       auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
       mostrarEmpleado(auxEmpleado);
    }
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
        ordenarAscendienteODecendiente(pArrayListEmployee,compararPorLegajo,comoOrdenar-1);  ///PASAR LA FUNC PARA ORDENAR COMO PARAMETRO Y PASAR LA LINKEDLIST
        break;

    case 2:

        formaDeOrdenar("\t---------- Ordenar por Nombre ----------\n\n",&comoOrdenar);
        ordenarAscendienteODecendiente(pArrayListEmployee,compararPorNombre,comoOrdenar-1);
        break;

    case 3:

        formaDeOrdenar("\t---------- Ordenar por Horas Trabajadas ----------\n\n",&comoOrdenar);
        ordenarAscendienteODecendiente(pArrayListEmployee,compararPorHorasTrabajadas,comoOrdenar-1);
        break;

    case 4:

        formaDeOrdenar("\t---------- Ordenar por Sueldo ----------\n\n",&comoOrdenar);
        ordenarAscendienteODecendiente(pArrayListEmployee,compararPorSueldo,comoOrdenar-1);
        break;

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

