#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
#define ID_EMPLEADOS 1000
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
    int option = 0;
    int len;
    int i;
    int idEmpleado = ID_EMPLEADOS;
    LinkedList* listaEmpleados = ll_newLinkedList();
    FILE* pArchivo;

    do{
            //system("cls");
            getInt(&option,"\n1. CARGAR EMPLEADOS DE data.csv (MODO TEXTO)"
                         "\n2. CARGAR EMPLEADOS DE data.bin (MODO BINARIO)"
                         "\n3. ALTA DE EMPLEADO"
                         "\n4. MODIFICAR EMPLEADO"
                         "\n5. BAJA DE EMPLEADO"
                         "\n6. LISTAR EMPLEADOS"
                         "\n7. ORDENAR EMPLEADOS"
                         "\n8. GUARDAR EMPLEADOS EN data.csv (MODO TEXTO)"
                         "\n9. GUARDAR EMPLEADOS EN data.bin (MODO BINARIO)"
                         "\n10. SALIR\n\nElija una opcion: \n","\nERROR. No es un numero...\n", 1, 10);
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nArchivo cargado con exito\n");
                }
                else
                {
                    printf("\nERROR. El archivo no se pudo cargar...\n");
                }
                system("pause");
                break;

            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\nArchivo cargado con exito\n");
                    employee_Id(listaEmpleados, &idEmpleado);
                }
                else
                {
                    printf("\nERROR. El archivo no se pudo cargar...\n");
                }

                system("pause");
                break;

            case 3:
                controller_addEmployee(listaEmpleados,&idEmpleado);
                break;

            case 4:
                if(ll_isEmpty(listaEmpleados) == 0)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("ERROR. Primero carge Archivo...");
                }
                break;

            case 5:
                if(ll_isEmpty(listaEmpleados) == 0)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("ERROR. Primero carge Archivo...");
                }
                break;

            case 6:
                if(ll_isEmpty(listaEmpleados) == 0)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("ERROR. Primero carge Archivo...");
                }
                system("pause");
                break;

            case 7:
                if(ll_isEmpty(listaEmpleados) == 0)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("ERROR. Primero carge Archivo...");
                }
                system("pause");

                break;

            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;

            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;

            case 10:
                printf("\nSaliendo del Programa...");
                system("cls");
        }
    }while(option != 10);

    return 0;
}
