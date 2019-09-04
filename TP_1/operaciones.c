#include <stdio.h>
#include <stdlib.h>

/** \brief Esta funcion imprime el menu
 *
 * \return void
 *
 */
void imprimirOpciones()
{
    printf("Opcion a eleguir: \n");

    printf("\n1. Ingresar 1er operando (A=x)");
    printf("\n2. Ingresar 2do operando (B=y)");
    printf("\n3. Calcular todas las operaciones");
    printf("\n4. Informar resultados");
    printf("\n5. Salir\n");
}

/** \brief Esta funcion sirve para ingresar los operandos al programa
 *
 * \param numero float* Es un puntero a la variable en la que quiero guardar el operando.
 * \param mensaje[] char Mensaje para indicarle al usuario que operando esta ingrsando.
 * \param error[] char  Mensaje de error en caso de que ingrese valores no validos.
 * \param reintentos int La cantidad de veces que puede ingresar un valor valido.
 * \return int Retorna 1 si la operacion se realizo con exito en caso contrario retorna 0.
 *
 */
int getFloat(float* numero, char mensaje[], char error[],int reintentos)
{
    int retorno;
    printf(mensaje);

    while(reintentos > 0)
    {
        if(scanf("\n%f",numero) == 0)
        {
            printf(error);
            fflush(stdin);
            reintentos--;
            printf("\nLe quedan %d reintentos\n", reintentos);
        }
        else
        {
            retorno = 1;
            break;
        }
    }

    if(reintentos == 0)
    {
        retorno = 0;
    }


    return retorno;
}

/** \brief Esta funcion sirve para sumar 2 operandos
 *
 * \param numero_a float Primer operando
 * \param numero_b float Segundo operando
 * \return float El resultado de la suma
 *
 */
float suma(float numero_a, float numero_b)
{
    float resultado;

    resultado = numero_a + numero_b;

    return resultado;
}

/** \brief Esta funcion sirve para restar 2 operandos
 *
 * \param numero_a float
 * \param numero_b float
 * \return float
 *
 */
float resta(float numero_a, float numero_b)
{
    float resultado;

    resultado = numero_a - numero_b;

    return resultado;
}

/** \brief Esta funcion sirve para dividir 2 operandos
 *
 * \param numero_a float
 * \param numero_b float
 * \return float
 *
 */
float division(float numero_a, float numero_b )
{
    float resultado;

    resultado = numero_a/numero_b;

    return resultado;
}

/** \brief Esta funcion sirve para multiplicar 2 operandos
 *
 * \param numero_a float
 * \param numero_b float
 * \return float
 *
 */
float multiplicacion(float numero_a, float numero_b)
{
    float resultado;

    resultado = numero_a * numero_b;

    return resultado;
}

/** \brief Esta funcion resuelve el factorial de un numero
 *
 * \param numero float
 * \return float
 *
 */
float factorial(float numero)
{
    float resultado;

    if( numero == 0 || numero == 1)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero * factorial(numero-1);
    }

    return resultado;
}

/** \brief Esta funcion valida si un numero es menor a 0 para no factorizar
 *
 * \param numero float
 * \return int
 *
 */
int validarFactorial(float numero)
{
    int validarFactorial;

    if(numero < 0)
    {
        validarFactorial = 0;
    }
    else
    {
        validarFactorial = 1;
    }

    return validarFactorial;
}

/** \brief Valida que se hayan agregado los 2 operandos.
 *
 * \param flag_a int Indica si se ingreso o no el primer operando
 * \param flag_b int Indica si se ingreso o no el primer operando
 * \return int  Devuelve 1 si ambos datos fueron ingresados y 0 en caso contrario.
 *
 */
int validacionDeIngresoDeDatos(int flag_a,int flag_b)
{
    int retorno = 1;

    if(flag_a == 0 || flag_b == 0)
        {
            printf("\nError todavia falta agregar los operandos.\n");
            retorno = 0;
            system("pause");
        }

    return retorno;
}







