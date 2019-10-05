#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"


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
            printf(eMessage);
            retorno = -2;
        }
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


int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    char numero[10];
    int largo;
    float validarLimite;
    int retorno = -1;

    pedirDato(numero,message);

    largo = strlen(numero);

    if(!esNumeroFlotante(numero,largo))
    {
        numero[largo+1] = '\0';
        validarLimite = atof(numero);

        if(validarLimitesFlotantes(validarLimite,lowLimit,hiLimit))
        {
            retorno = 0;
            *input = atof(numero);
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

int validarLimitesFlotantes(float num, float lowLimit, float hiLimit)
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
    int i=0;

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
    char aux[256];
    int retorno = 0;

    pedirDato(aux,message);

    if(soloLetras(aux))
    {
        strcpy(input,aux);
        retorno = 1;
    }

    return retorno;
}


void continuarSiONo(char* input,char message[])
{

    do
    {
        if(!getString(input,message))
        {
            printf("Error Debe ingresar la letra S o N");
            system("pause");
            system("cls");
        }

         (*input) = tolower((*input));

    }while(!(input[0] == 's' || input[0] == 'n'));

}

void imprimirLimiteDeReintentos()
{
    printf("Limite de reintentos.");
    system("pause");
    system("cls");
}

int validarIngresoDeDatos(int numero, int* reintentos)
{
    switch(numero)
        {

        case -1:

            printf("\nNo es un numero");
            (*reintentos)++;
            break;

        case -2:

            printf("\nEsta Fuera de Rango");
            (*reintentos)++;
            break;

        case 0:

            *reintentos = 0;
            break;
        }

        return numero;
}
