#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int menu(char text[])
{
    int opcion;

    printf("%s", text);
    scanf("%d", &opcion);

    return opcion;
}

int getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    char numero[10];
    int largo;
    int validarLimite;
    int retorno = -1;

    pedirDato(numero,message);

    largo = strlen(numero);
    numero[largo] = '\0';

    if(!esNumeroEntero(numero,largo))
    {
        validarLimite = atoi(numero);

        if(validarLimitesEnteros(validarLimite,lowLimit,hiLimit))
        {
            retorno = 0;
            *input = atoi(numero);
        }
        else
        {
            printf("\nERROR. El numero esta fuera de Rango...\n");
            system("pause");
            system("cls");
            retorno = -2;
        }
    }
    else
    {
        printf(eMessage);
    }
    return retorno;
}


int validarLimitesEnteros(int num, int lowLimit, int hiLimit)
{
    int retorno;

    if(num >= lowLimit && num <= hiLimit)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int esNumeroEntero(char* numero, int tam)
{
    int i;
    int retorno;

    for(i = 0; i < tam; i++)
    {
        if((numero[i] >= '0' && numero[i] <= '9') || numero[i] == '-')
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
            break;
        }
    }

    return retorno;
}

void pedirDato(char* dato, char message[])
{
    printf(message);
    fflush(stdin);
    scanf("%s", dato);
}


int getFloat(double* input,char message[],char eMessage[], double lowLimit, double hiLimit)
{
    char numero[10];
    int largo;
    double validarLimite;
    int retorno = -1;

    pedirDato(numero,message);

    largo = strlen(numero);

    if(!esNumeroFlotante(numero,largo))
    {
        numero[largo+1] = '\0';
        validarLimite = strtod(numero,NULL);

        if(validarLimitesFlotantes(validarLimite,lowLimit,hiLimit))
        {
            retorno = 0;
            (*input) = strtod(numero,NULL);
        }
        else
        {
            printf(eMessage);
            retorno = -2;
        }
    }
    return retorno;

}

int esNumeroFlotante(char* numero, int tam)
{
    int i;
    int retorno;
    int flagPuntoFlotante = 0;

    for(i = 0; i < tam; i++)
    {
        if((numero[i] >= '0' && numero[i] <= '9') || numero[i] == '-')
        {
            retorno = -1;
        }
        else if(numero[i] == '.')
        {
            flagPuntoFlotante = 1;
        }
        else
        {
            retorno = -2;
            break;
        }
    }

    if((retorno == -1 || flagPuntoFlotante == 1) && numero[0] != '.')
    {
        retorno = 0;
    }

    return retorno;
}

int validarLimitesFlotantes(double num, double lowLimit, double hiLimit)
{
    int retorno;

    if(num >= lowLimit && num <= hiLimit)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}


int soloLetras(char* letra)
{
    int retorno = 1;
    int i = 0;

    while(letra[i] != '\0')
    {
        if((letra[i] != ' ') && (letra[i] < 'a' || letra[i] > 'z') && (letra[i] < 'A' || letra[i] > 'Z'))
        {
            retorno = 0;
        }

        i++;
    }

    return retorno;
}


int getString(char* input,char message[])
{
    char aux[51];
    int retorno = 0;

    pedirDato(aux,message);

    if(soloLetras(aux))
    {
        strcpy(input,aux);
        retorno = 1;
    }

    return retorno;
}


void validacionEntreChar(char* input,char message[],char primerValor, char segundoValor, int reintentos)
{
    char aux;
    do
    {
       if(!getString(&aux,message))
        {
            printf("Error Debe ingresar la letra '%c' o '%c'\n", primerValor,segundoValor);
            system("pause");
            system("cls");
        }
        else
        {
            (*input) = tolower(aux);
        }


        if(*(input) != primerValor && *(input) != segundoValor)
        {
            reintentos--;
            printf("ERROR.Le quedan %d intentos.\n", reintentos);
        }

    }while((*(input) != primerValor && *(input) != segundoValor) && reintentos != 0);

}

void imprimirLimiteDeReintentos()
{
    printf("\nLimite de reintentos.\n\n");
    system("pause");
    system("cls");
}

int validarIngresoDeDatos(int numero, int* reintentos)
{
    int cantReintentos = (*reintentos);
    switch(numero)
    {

    case -1:

        printf("No es un numero\n");
        system("pause");
        system("cls");
        cantReintentos--;
        break;

    case -2:

        printf("Esta Fuera de Rango\n");
        cantReintentos--;
        system("pause");
        system("cls");
        break;

    case 0:

        cantReintentos = 3;
        system("cls");
        break;
    }

    (*reintentos) = cantReintentos;

    return numero;
}


int formaDeOrdenar(char message[], int* formaDeOrdenar)
{
    int retorno;
    int retGetInt;
    system("cls");
    printf(message);
    retGetInt = getInt(formaDeOrdenar,  "1. Ascendente\n"  ///REVISAR LAS OPCIONE CON LO QUE SE PASA COMO PARAMETRO EN LA FUNC ll_sort().
                                        "2. Decendente\n\n"
                                        "Ingrese Opcion: ", "ERROR. Debe ingresar un numero...",1,2);
    if(retGetInt == 0)
    {
        retorno = 0;
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}
