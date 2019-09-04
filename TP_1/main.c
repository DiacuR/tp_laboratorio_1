#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


int main()
{
    float numero_A;
    float numero_B;
    float sumar;
    float restar;
    float dividir;
    float multiplicar;
    float factorizar_a;
    float factorizar_b;
    int opcion;
    int flag_a = 0;
    int flag_b = 0;
    int salir;
    int validarFactorial_a;
    int validarFactorial_b;
    int validacionNumerica;

    do
    {
        imprimirOpciones();
        scanf("\n%d", &opcion);
        system("cls");

        switch(opcion)
        {
        case 1:

            validacionNumerica = getFloat(&numero_A,"Ingresar el valor del operando A: \n","\nERROR. Reingrese numero.\n",3);

            if(validacionNumerica == 1)
            {
                flag_a = 1;
            }
            else
            {
                system("pause");

            }
            system("cls");

            break;

        case 2:

            validacionNumerica = getFloat(&numero_B,"Ingresar el valor del operando B: \n","\nERROR. Reingrese numero.\n",3);

            if(validacionNumerica == 1)
            {
                flag_b = 1;
            }
            else
            {
                system("pause");
            }
            system("cls");

            break;

        case 3:

            if((!validacionDeIngresoDeDatos(flag_a,flag_b)))
            {
                break;
            }

            sumar = suma(numero_A,numero_B);
            restar = resta(numero_A,numero_B);

            if(numero_B != 0)
            {
                dividir = division(numero_A,numero_B);
            }

            multiplicar = multiplicacion(numero_A,numero_B);

            validarFactorial_a = validarFactorial(numero_A);
            validarFactorial_b = validarFactorial(numero_B);

            if(validarFactorial_a == 1)
            {
                factorizar_a = factorial(numero_A);
            }

            if(validarFactorial_b == 1)
            {
                factorizar_b = factorial(numero_B);
            }

            break;

        case 4:

            if((!validacionDeIngresoDeDatos(flag_a,flag_b)))
            {
                break;
            }
            printf("-------- Resultados --------");
            printf("\nEl resultado de A+B es: %0.2f",sumar);
            printf("\nEl resultado de A-B es: %0.2f",restar);

            if( numero_B == 0)
            {
                printf("\nNo es posible dividir por '0'.");
            }
            else
            {
                printf("\nEl resultado de A/B es: %0.2f",dividir);
            }

            printf("\nEl resultado de A*B es: %0.2f",multiplicar);

            if(numero_A < 0)
            {
                printf("\nNo se puede sacar factorial de un numero negativo");
            }
            else
            {
                printf("\nEl factorial de A es: %0.0f", factorizar_a);
            }

            if(numero_B < 0)
            {
                printf("\nNo se puede sacar factorial de un numero negativo");
            }
            else
            {
                printf("\nEl factorial de B es: %0.0f\n\n", factorizar_b);
            }
            system("pause");
            system("cls");

            break;

        case 5:
            salir = 1;

            break;
        }
    }while(salir != 1);


    return 0;
}
