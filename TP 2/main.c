#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int opcion;

    Employee listadoDeEmpleado[TAM];

    int salir = 1;
    int ordenar = 0;
    int id = 0;

    initEmployees(listadoDeEmpleado,TAM);


    do
    {
        opcion=menu("\n  Menu de opciones \n\n"
                    "1. Altas \n"
                    "2. Modificar\n"
                    "3. Bajas \n"
                    "4. Informar\n"
                    "5. Salir\n\nElija una opcion: ");

        switch (opcion)
        {
        case 1:

           addEmployee(listadoDeEmpleado,TAM);
           break;

        case 2:

            if(validarQueHayaEmpleado(listadoDeEmpleado,TAM))
            {
               modificarEmpleado(listadoDeEmpleado,TAM);

            }else{

            printf("Error debe cargar por lo menos un empleado. ");
            system("pause");

            }

            break;

        case 3:

            if(validarQueHayaEmpleado(listadoDeEmpleado,TAM))
            {
                removeEmployee(listadoDeEmpleado,TAM,id);
            }
            else
            {
                printf("Error debe cargar por lo menos un empleado. ");
                system("pause");
            }

            break;

       case 4:

            if(validarQueHayaEmpleado(listadoDeEmpleado,TAM))
            {
                sortEmployees(listadoDeEmpleado,TAM,ordenar);
                printEmployees(listadoDeEmpleado,TAM);
                system("pause");
                system("cls");
                ImprimirInformes(listadoDeEmpleado,TAM);
            }
            else
            {
                printf("\nError debe cargar por lo menos un empleado.\n");
                system("pause");
            }

            break;

        case 5:
            printf(" Salir \n\n");
            salir = 0;
            system("pause");
            break;
        default:
            printf("Error.Debe ingresar un numero del 1 al 5\n\n");
            system("pause");
            break;

        }
    }
    while(salir != 0);


    return 0;
}
