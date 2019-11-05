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
    Employee* emp;
    char nombre[10] = {"diacu"};
    emp= employee_newParametros(1,nombre,150,10000);
    mostrarColumnas();
    mostrarEmpleado(emp);
    do{
            system("cls");
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
                controller_loadFromBinary("data.bin",listaEmpleados);
                employee_Id(listaEmpleados, &idEmpleado);
                system("pause");
                break;

            case 3:
                controller_addEmployee(listaEmpleados,&idEmpleado);
                ///employee_newParametros();
                break;

            case 4:
                controller_editEmployee(listaEmpleados);
                break;

            case 5:
                controller_removeEmployee(listaEmpleados);
                break;

            case 6:

                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;

            case 7:
                controller_sortEmployee(listaEmpleados);
                //ordenarAscendienteODecendiente(listaEmpleados,compararPorNombre,0);  ///PASAR LA FUNC PARA ORDENAR COMO PARAMETRO Y PASAR LA LINKEDLIST
                controller_ListEmployee(listaEmpleados);
                system("pause");

                break;

            case 8:
                ///controller_saveAsText();
                break;

            case 9:
                ///controller_saveAsBinary();
                break;

            case 10:
                printf("\nSaliendo del Programa...");
                system("cls");
        }
    }while(option != 10);






/*
    int i;
    int len;
    Employee* e1 = employee_newParametros("5","Maria","10","5000");
    Employee* e2 = employee_newParametros("2","Carlos","15","6500");
    Employee* e3 = employee_newParametros("6","Jose","15","7500");
    Employee* e4 = employee_newParametros("7","Juan","10","100");

    Employee* auxEmpleado;

    ll_add(listaEmpleados,e1);       ///Devulve 0 si esta bien -1 si esta mal
    ll_add(listaEmpleados,e2);
    ll_add(listaEmpleados,e3);

    ll_push(listaEmpleados,1,e4);     ///Pone a e4 entre e1 y e2.

    ///ll_set(listaEmpleados,2,e4);       ///De esta manera e4 pisa a e3. Sirbe para sacar un elem de la lista modificarlo y agregarlo devuelta



    len = ll_len(listaEmpleados);

    for(i = 0; i < len; i++)
    {
       auxEmpleado = (Employee*)ll_get(listaEmpleados,i);            ///Hace un malloc adentro
       mostrarEmpleado(auxEmpleado);
    }

    printf("\n");
    ll_sort(listaEmpleados,compararPorNombre,1);



    len = ll_len(listaEmpleados);

    for(i = 0; i < len; i++)
    {
       auxEmpleado = (Employee*)ll_get(listaEmpleados,i);            ///Hace un malloc adentro
       mostrarEmpleado(auxEmpleado);
    }
*/
/*
    int i;
    int len;
    len = ll_len(listaEmpleados);

    for(i = 0; i < len; i++)
    {
       auxEmpleado = (Employee*)ll_get(listaEmpleados,i);            ///Hace un malloc adentro
       mostrarEmpleado(auxEmpleado);
    }

    //ll_remove(listaEmpleados,1);                  ///elimina
    auxEmpleado = ll_pop(listaEmpleados,1);         ///Saca de la lista

    printf("Saque a este de la lista:\n");
    mostrarEmpleado(auxEmpleado);
    printf("\n");

    len = ll_len(listaEmpleados);

    for(i = 0; i < len; i++)
    {
       auxEmpleado = (Employee*)ll_get(listaEmpleados,i);            ///Hace un malloc adentro
       mostrarEmpleado(auxEmpleado);
    }

    printf("\n");

    LinkedList* listaAux = ll_subList(listaEmpleados,0,1);             ///El 2 param es inclusivo el 3 exclusivo Ej: (0,2) la sub lista tiene 0,1


    len = ll_len(listaEmpleados);

    for(i = 0; i < len; i++)
    {
       auxEmpleado = (Employee*)ll_get(listaEmpleados,i);            ///Hace un malloc adentro
       mostrarEmpleado(auxEmpleado);
    }
*/
    return 0;
}
