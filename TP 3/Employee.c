#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/*
Employee* new_employee()
{
    Employee* this;
    this = (Employee*) malloc(sizeof(Employee));
    return this;
}
*/
int employee_setId(Employee* this, int id)
{

    int retorno = 1;

    if( this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{

    int retorno = 1;

    if( this != NULL && id != NULL )
    {

        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = 1;

    if( this != NULL && nombre != NULL && strlen(nombre) > 2)
    {

        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;

}
int employee_getNombre(Employee* this,char* nombre)
{

    int retorno = 1;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int retorno = 1;

    if( this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int retorno = 1;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;

}

int employee_setSueldo(Employee* this,int sueldo)
{

    int retorno = 1;

    if( this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 1;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}


Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo)
{

    Employee* this;
    this = employee_new();

    if( this != NULL)
    {
        if( employee_setId(this, id)||

            employee_setNombre(this, nombre) ||

            employee_setHorasTrabajadas(this, horasTrabajadas) ||

            employee_setSueldo(this, sueldo))
        {
            free(this);
            this = NULL;
        }
    }


    return this;
}
void mostrarColumnas()
{
    printf("\n\nID\t\tNOMBRE\t\tHORAS TRABAJADAS\tSUELDO\n");
}

void mostrarEmpleado(Employee* this){
    if(this != NULL)
    {
        printf("%2d %19s %12d %24d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}

int compararPorLegajo(void* e1,void* e2)
{
    int compara = -1;
    int id;
    int id2;

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2;

    employee_getId(empleado1,&id);
    employee_getId(empleado2,&id2);

    if(id > id2)
    {
        compara = 1;
    }
    else if(id == id2)
    {
        compara = 0;
    }

    return compara;
}


int compararPorSueldo(void* e1,void* e2)
{
    int compara = -1;
    int sueldo;
    int sueldo2;

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2;

    employee_getSueldo(empleado1,&sueldo);
    employee_getSueldo(empleado2,&sueldo2);

    if(sueldo > sueldo2)
    {
        compara = 1;
    }
    else if(sueldo == sueldo2)
    {
        compara = 0;
    }

    return compara;
}

int compararPorHorasTrabajadas(void* e1,void* e2)
{
    int compara = -1;
    int hTrabajadas;
    int hTrabajadas2;

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2;

    employee_getHorasTrabajadas(empleado1,&hTrabajadas);
    employee_getHorasTrabajadas(empleado2,&hTrabajadas2);

    if(hTrabajadas > hTrabajadas2)
    {
        compara = 1;
    }
    else if(hTrabajadas == hTrabajadas2)
    {
        compara = 0;
    }

    return compara;
}

int compararPorNombre(void* e1,void* e2)
{
    int compara = -1;
    char nombre[50];
    char nombre2[50];

    employee_getNombre(e1,&nombre);
    employee_getNombre(e2,nombre2);

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2;

    compara = strcmp(nombre,nombre2);

    return compara;
}


int employee_EncontrarPorId(LinkedList* pArrayListEmployee,Employee* this, int id)
{
    int i;
    int index = -1;
    int len;

    len = ll_len(pArrayListEmployee);

    if(len > 0 && pArrayListEmployee != NULL)
    {
        for(i = 0; i < len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);

            if( this->id == id )
            {
                index = i;
                break;
            }
        }

    }
    return index;
}

int pedirNombre(char nombre[], int* reintentos)
{
    int retorno = 1;
    int flagNombre = 0;

    do
    {
        if(!(getString(nombre,"\nIngrese nombre: ")))
        {
            printf("\nError. Reingrese solo caracteres[a-z A-Z](min 3 caracteres).\n");
            system("pause");
            system("cls");
            (*reintentos)--;
        }
        else
        {
            system("cls");
            flagNombre = 1;
            (*reintentos) = 3;
            retorno = 0;
        }
    }while(flagNombre == 0 && (*reintentos) > 0);

        return retorno;
}


int pedirHorasTrabajadas(int* horasTrabajadas, int* reintentos)
{
    int retornoHorasTrabajadas = 0;
    int hsTrabajadas;
    int retorno = 1;

    hsTrabajadas = *horasTrabajadas;

    do
        {
            retornoHorasTrabajadas = getInt(&hsTrabajadas,"\nIngrese horas trabajadas: \n","\nError. ",1,900);

            validarIngresoDeDatos(retornoHorasTrabajadas,reintentos);

        }
        while(retornoHorasTrabajadas != 0 && (*reintentos) > 0);

    if(retornoHorasTrabajadas == 0 && (*reintentos) > 0)
    {
        *horasTrabajadas = hsTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int pedirSueldo(int* sueldo, int* reintentos)
{
    int retornoSueldo = 0;
    int retorno = 1;

    do
    {
        retornoSueldo = getInt(sueldo,"\nIngrese sueldo: \n","\nError. ",1,100000);

        validarIngresoDeDatos(retornoSueldo,reintentos);

    }while(retornoSueldo != 0 && (*reintentos) > 0);

    if(retornoSueldo == 0 && (*reintentos) > 0)
    {
        retorno = 0;
    }

    return retorno;
}


void mostrarEmpleadoAModificar(Employee* this)
{
    printf("\t---------- Empleado a Modificar ----------\n");
    mostrarColumnas();
    mostrarEmpleado(this);
}


int ordenarAscendienteODecendiente(LinkedList* pArrayListEmployee,int(*criterio)(void* e1, void* e2),int orden)
{
    int retorno = 1;

    switch(orden)
        {
        case 0:
            printf("\n\n\t---------- Ordenado de manera Decendente----------\n\n");
            ll_sort(pArrayListEmployee,criterio,orden);
            retorno = 0;
            break;

        case 1:
            printf("\n\n\t---------- Ordenado de manera Ascendente ----------\n\n");
            ll_sort(pArrayListEmployee,criterio,orden);
            retorno = 0;
            break;
        }

        return retorno;
}
