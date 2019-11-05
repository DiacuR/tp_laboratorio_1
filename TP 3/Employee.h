#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

Employee* new_employee();

void mostrarColumnas();

int pedirNombre(char nombre[], int* reintentos);

int pedirHorasTrabajadas(int* horasTrabajadas, int* reintentos);

int pedirSueldo(int* sueldo, int* reintentos);

int employee_EncontrarPorId(LinkedList* pArrayListEmployee,Employee* this, int id);

void mostrarEmpleado(Employee* emp);

int compararPorLegajo(void*,void*);

int compararPorSueldo(void*,void*);

int compararPorNombre(void* e1,void* e2);

int compararPorHorasTrabajadas(void* e1,void* e2);

int ordenarAscendienteODecendiente(LinkedList* pArrayListEmployee,int(*criterio)(void* e1, void* e2),int orden);
#endif // employee_H_INCLUDED
