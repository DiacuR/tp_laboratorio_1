void imprimirOpciones()
{
    printf("\nOpcion a eleguir: \n");

    printf("\n1. Ingresar 1er operando (A=x)");
    printf("\n2. Ingresar 2do operando (B=y)");
    printf("\n3. Calcular todas las operaciones");
    printf("\n4. Informar resultados");
    printf("\n5. Salir\n");
}


int validarNumero(int numero)
{
    int retorno = 0;

    if(scanf("%f",&numero))
    {
        retorno = 1;
    }

    return retorno;
}
