#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Empleado.h"


#define BORRADO -1
#define OCUPADO 0
#define LIBRE 1

int menu(char text[])
{
    int opcion;

    printf("%s", text);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees (Employee* lista, int len)
{
    int i;
    int retorno = -1;

    if(len > 0 && lista != NULL)
    {
        retorno = 0;
        for(i = 0; i < len; i++)
        {
            lista[i].id = 0;
            strcpy(lista[i].name,"");
            strcpy(lista[i].lastName,"");
            lista[i].salary = 0.00;
            lista[i].sector = 0;
            lista[i].isEmpty = LIBRE;
        }
        retorno = 0;
    }
    return retorno;
}


void printEmployees(Employee* lista, int len)
{
    int i;

    system("cls");

    for(i = 0; i < len;  i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(lista[i]);
        }
    }
}

void mostrarEmpleado(Employee empleado)
{
    printf("\n\nID\t\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n");
    printf("%2d %18s %16s %16.2f %12d\n",empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}


int addEmployee(Employee* lista, int len)
{
    int index;
    int retorno = -1;

    if(len > 0 && lista != NULL)
    {
        index = buscarEspacioLibre(lista,len);

        retorno = agregarEmpleadoAlArray(lista,index);
    }

    return retorno;
}


int agregarEmpleadoAlArray(Employee* empleado,int index)
{
    int retorno;

    if(index != -1)
    {
        if(agregarDatosDeEmpleado(&empleado[index],index))
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
            printf("Empleado No Agregado");
        }
    }
    else
    {
        retorno = -2;
        printf("No hay espacio en el Sistema.");
    }

    return retorno;
}


int findEmployeeById(Employee* lista, int len, int id)
{
    int i;
    int index = -1;

    if(len > 0 && lista != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == OCUPADO)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}


int removeEmployee(Employee* lista, int len, int id)
{
    int empleadoEncontrado;
    char confirmar;
    int retorno = -1;

    if(len > 0 && lista != NULL)
    {
        printEmployees(lista,len);

        if(getInt(&id,"Ingrese el Id del Empleado a Borrar: ","\nError el Id solo debe tener numeros..",0,len))
        {
            retorno = -2;
        }
        else
        {
            empleadoEncontrado = findEmployeeById(lista,len,id);

            if(empleadoEncontrado != -1)
            {
                mostrarEmpleado(lista[empleadoEncontrado]);
                continuarSiONo(&confirmar,"\nEsta seguro que desea eliminar a este Empleado? S/N : ");

                if(confirmar == 'n')
                {
                    printf("Baja cancelada\n\n");
                }
                else
                {
                    lista[empleadoEncontrado].isEmpty = BORRADO;
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


int sortEmployees(Employee* lista, int len, int order)
{
    int i,j;
    int retorno;
    Employee auxEmpleado;

    if(getInt(&order,"\n Ingrese '1' para ordenar de manera ascendente o ingrese '0' para ordenar de manera descendente: ","Error\n",0,1))
    {
        printf("\nError.Solo numeros entre[0-1]...");
        retorno = -1;
    }
    else
    {

        switch(order)
        {

        case 1:

            for(i = 0; i < len - 1; i++)
            {
                for(j = i + 1; j < len; j++)
                {
                    if(strcmpi(lista[i].lastName,lista[j].lastName) > 0 && lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                    else if(strcmpi(lista[i].lastName,lista[j].lastName) == 0 && lista[i].sector > lista[j].sector && lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                }
            }
            retorno = 1;
            printf("\nOrdenado de menor a mayor...");
            break;

        case 0:

            for(i = 0; i < len - 1; i++)
            {
                for(j = i + 1; j < len; j++)
                {
                    if(strcmpi(lista[i].lastName,lista[j].lastName) < 0 && lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                    else if(strcmpi(lista[i].lastName,lista[j].lastName) == 0 && lista[i].sector < lista[j].sector && lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                }
            }
            retorno = 1;
            printf("\nOrdenado de Mayor a Menor...\n\n");
            break;

        }

    }

    return retorno;
}


int validarQueHayaEmpleado(Employee* lista, int len)
{
    int retorno = 0;
    int i;

    for(i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            retorno = 1;
            break;
        }
    }

    return retorno;
}

void modificarEmpleado(Employee* lista, int len)
{
    int id;
    int index;
    char continuar;
    Employee auxEmpleado;


    printEmployees(lista,len);

    if(!getInt(&id,"Ingrese el Id del Empleado a Modificar: ","Error el Id solo debe tener numeros..",0,len))
    {
        index = findEmployeeById(lista,len,id);

        if(index == -1)
        {
            printf("\nERROR.No hay empleado con ese Id..\n");
            system("pause");
            system("cls");
        }
        else
        {
            auxEmpleado = lista[index];
            system("cls");
            mostrarEmpleado(lista[index]);
            continuarSiONo(&continuar,"Desea modificar el nombre S/N: ");

            if(continuar == 's')
            {
                if(!getString(&auxEmpleado.name,"Ingrese Nuevo nombre: "))
                {
                    printf("\n Error. El nombre debe tener solo letras.");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\n\nHa modificado el nombre.\n\n");
                    system("pause");
                    system("cls");
                }

            }
            mostrarEmpleado(auxEmpleado);
            continuarSiONo(&continuar,"Desea modificar el apellido S/N: ");

            if(continuar == 's')
            {
                if(!getString(&auxEmpleado.lastName,"Ingrese Nuevo apellido: "))
                {
                    printf("\n Error. El apellido debe tener solo letras.");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\n\nHa modificado el apellido.\n\n");
                    system("pause");
                    system("cls");
                }

            }
            mostrarEmpleado(auxEmpleado);
            continuarSiONo(&continuar,"Desea modificar el salario S/N: ");

            if(continuar == 's')
            {
                if(getFloat(&auxEmpleado.salary,"Ingrese Nuevo salario: ","Error",10000.00,50000.00) == 0)
                {
                    printf("\n\nHa modificado el salario\n\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\n Error. El salario debe tener solo numeros.\n");
                    system("pause");
                    system("cls");
                }

            }
            mostrarEmpleado(auxEmpleado);
            continuarSiONo(&continuar,"Desea modificar el sector S/N: ");

            if(continuar == 's')
            {
                if(getInt(&auxEmpleado.sector,"Ingrese Nuevo sector: ","Error",0,5) == 0)
                {
                    printf("\n\nHa modificado el sector\n\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\n Error. El sector debe tener solo numeros [1-5].\n");
                    system("pause");
                    system("cls");
                }

            }

            mostrarEmpleado(auxEmpleado);

            continuarSiONo(&continuar,"Desea Guardar los cambios? S/N: ");

            if(continuar == 's')
            {
                lista[index] = auxEmpleado;
                printf("\n---------Cambios Guardados--------\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\n--------No se realizo ninguna modificacion---------\n");
                system("pause");
                system("cls");
            }

        }
    }
}



int agregarDatosDeEmpleado(Employee* Empleado,int index)
{
    Employee auxEmpleado;
    int flagNombre = 0;
    int flagLastName = 0;
    int respuestaSalary;
    int respuestaSector;
    int reintentos = 0;
    int retorno;
    char respuesta;

    do
    {
        do
        {

            if(!(getString(auxEmpleado.name,"\nIngrese nombre: ")))
            {
                printf("\nError");
                reintentos++;
            }
            else
            {
                flagNombre = 1;
                reintentos = 0;
            }

        }
        while(flagNombre == 0 && reintentos <= 2);

        if(reintentos == 3)
        {
            imprimirLimiteDeReintentos();
            break;
        }

        do
        {

            if(!(getString(auxEmpleado.lastName,"\nIngrese apellido: ")))
            {
                printf("\nError");
                reintentos++;
            }
            else
            {
                flagLastName  = 1;
                reintentos = 0;
            }

        }
        while(flagLastName == 0 && reintentos <= 2);

        if(reintentos == 3)
        {
            imprimirLimiteDeReintentos();
            break;
        }

        do
        {

            respuestaSalary = getFloat(&auxEmpleado.salary,"\nIngrese Salario( Ej: 15000.00 ): ","Error.",10000.00,20000.50);

            validarIngresoDeDatos(respuestaSalary,&reintentos);

        }
        while(respuestaSalary != 0 && reintentos <= 2);

        if(reintentos == 3)
        {
            imprimirLimiteDeReintentos();
            break;
        }

        do
        {

            respuestaSector = getInt(&auxEmpleado.sector,"\nIngrese Sector: \n","Error\n",1,5);

            validarIngresoDeDatos(respuestaSector,&reintentos);

        }
        while(respuestaSector != 0 && reintentos <= 2);


        if(reintentos == 3)
        {
            imprimirLimiteDeReintentos();
            break;
        }

        auxEmpleado.id = index + 1;

        mostrarEmpleado(auxEmpleado);
        continuarSiONo(&respuesta,"\nDesea dar de alta a este Empleado S/N: ");

        if(respuesta == 's')
        {
            auxEmpleado.isEmpty = OCUPADO;
            *(Empleado) = auxEmpleado;

            retorno = 1;
            printf("\n------Empleado Guardado-------\n");
            system("pause");
            system("cls");
        }
        else if(respuesta == 'n')
        {
            retorno = 0;
            printf("\n----------Empleado NO Guardado-----------\n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(respuesta != 's');


    return retorno;
}


int buscarEspacioLibre(Employee* lista, int len)
{
    int indice = -1;
    int i;

    for(i=0; i < len; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



void ImprimirInformes(Employee lista[], int len)
{
    int salir = 1;

    do
    {

        int opcion= menu("\n\nIngrese las siguientes opciones:\n"
                         "1.Total de salario.\n"
                         "2.Promedio de salario.\n"
                         "3.Empleados que superan el promedio de salario.\n"
                         "4.Volver al menu principal.\n\n"
                         "Elija una opcion:  ");

        switch (opcion)

        {
        case 1:
            printf("\n\n\nEl total de los salarios es de: %.2f \n\n", salarioTotal(lista,len));
            system("pause");
            break;
        case 2:
            printf("\n\nEl promedio de los salarios es de: %.2f\n\n", salarioPromedio(lista,len));
            system("pause");
            break;
        case 3:
            printf("\n\nLa cantidad de empleados que superan el salario promedio son: %d\n\n", salariosMayoresAlPromedio(lista,len));
            system("pause");
            break;
        case 4:
            printf(" Salir \n\n");
            salir = 0;
            system("pause");
            break;
        default:
            printf("\nERROR. Ingrese un numero [1-4].");
            system("pause");
            break;
        }
        system("cls");
    }
    while(salir != 0);
}


float salarioTotal(Employee* lista, int len)
{
    float acumSalario = 0;
    int i;

    for(i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            acumSalario = acumSalario + lista[i].salary;
        }
    }
    return acumSalario;
}


float salarioPromedio(Employee* lista, int len)
{
    float acumSalario = 0;
    int contSalario = 0;
    float promedio;
    int i;

    for(i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            acumSalario = acumSalario + lista[i].salary;
            contSalario++;
        }
    }

    promedio = (acumSalario / contSalario);

    return promedio;
}


int salariosMayoresAlPromedio(Employee lista[], int len)
{
    int contador = 0;

    for(int i = 0; i < len ; i++)
    {
        if(lista[i].isEmpty == OCUPADO && lista[i].salary > salarioPromedio(lista,len))
        {
            contador++;
        }
    }
    return contador;
}
