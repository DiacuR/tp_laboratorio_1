#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag_a = 0;
    int flag_b = 0;

    do
    {
        imprimirOpciones();
        scanf("\n%d", &opcion);
        system("cls");

        switch(opcion)
        {
            case 1:

            printf("Ingresar el valor del operando A: ");
            fflush(stdin);
            scanf("%f", &A);
            while((!validarNumero(A)) == 0)
            {
                printf("ERROR. Reingrese numero.\n");
                scanf("%f", &A);
            }
            flag_a = 1;
            break;
    return 0;
}
