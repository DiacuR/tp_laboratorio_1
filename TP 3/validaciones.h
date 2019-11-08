#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED


/** \brief Pide un valor numerico.
 *
 * \param text[] char Mensaje que se le muestra al usuario para que sepa que ingresar.
 * \return int  Devuelve el numero que ingreso el usuario.
 *
 */
int menu(char text[]);
/** \brief  Su funcion es pedir una cadena de char al usuario
 *
 * \param dato char*    Se usa para guardar lo que el usuario ingrese.
 * \param message[] char    Se usa como mensaje para el usuario sepa que dato ingresar.
 * \return void
 *
 */
void pedirDato(char* dato, char message[]);

/** \brief  Pide un entero y valida y analiza que cumpla con ciertas reglas (que este dentro de un limite, que sea un numero)
 *
 * \param input int*    Es el puntero donde se guarda el dato que el usuario ingreso si cumplio con las condiciones.
 * \param message[] char    Se usa como mensaje para el usuario sepa que dato ingresar.
 * \param eMessage[] char   Se usa como mensaje de error.
 * \param lowLimit int  Sirve para marcar un limite inferior al numero a ingresar.
 * \param hiLimit int   Sirve para marcar un limite superior al numero a ingresar.
 * \return int  retorna '-1' si no es un numero, '-2' si esta fuera de rango, '0' si se realizo con exito
 *
 */
int getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/** \brief  Valida los limites del numero ingresado.
 *
 * \param num int   Numero ingresado por el usuario.
 * \param lowLimit int  Limite menor del rango valido para el numero.
 * \param hiLimit int   Limite mayor del rango valido para el numero.
 * \return int  retorna '1' si se realizo con exito, caso contrario retorna '0'.
 *
 */
int validarLimitesEnteros(int num, int lowLimit, int hiLimit);
/** \brief  Valida que sea un Numero.
 *
 * \param numero char*  Cadena de caracteres que guarda el numero para analizar.
 * \param tam int   Es el la cantidad de caracteres necesarios para guardar el numero.
 * \return int  retorna '0' si se realizo con exito, caso contrario retorna '1'.
 *
 */
int esNumeroEntero(char* numero, int tam);


/** \brief  Pide un numero flotante valida y analiza que cumpla con ciertas condiciones (que este dentro de un limite, que sea un numero flotante)
 *
 * \param input float*  Es el puntero donde se guarda el dato que el usuario ingreso si cumplio con las condiciones.
 * \param message[] char    Se usa como mensaje para el usuario sepa que dato ingresar.
 * \param eMessage[] char   Se usa como mensaje de error.
 * \param lowLimit float  Sirve para marcar un limite inferior al numero a ingresar.
 * \param hiLimit float   Sirve para marcar un limite superior al numero a ingresar.
 * \return int  retorna '-1' si no es un numero, '-2' si esta fuera de rango, '0' si se realizo con exito
 *
 */
int getFloat(double* input, char message[], char eMessage[], double lowLimit, double hiLimit);
/** \brief Valida los limites del numero flotante ingresado.
 *
 * \param num float     Numero flotante ingresado por el usuario
 * \param lowLimit float    Sirve para marcar un limite inferior al numero a ingresar.
 * \param hiLimit float     Sirve para marcar un limite superior al numero a ingresar.
 * \return int  retorna '1' si se realizo con exito, caso contrario retorna '0'.
 *
 */
int validarLimitesFlotantes(double num, double lowLimit, double hiLimit);
/** \brief  Valida que sea un Numero Flotante.
 *
 * \param numero char*  Cadena de caracteres que guarda el numero para analizar.
 * \param tam int   Es el la cantidad de caracteres necesarios para guardar el numero.
 * \return int  retorna '0' si se realizo con exito, caso contrario retorna '1'.
 *
 */
int esNumeroFlotante(char* numero, int tam);

/** \brief  Pide una cadena de caracteres al usuario. Y hace validaciones.
 *
 * \param input char*   Donde se guarda lo que el usuario ingreso.
 * \param mensaje[] char    Mensaje que se le muestra al usuario para que sepa que ingresar.
 * \return int  Devuelve '0' en caso de error, y en caso contrario '1'.
 *
 */
int getString(char* input, char mensaje[]);
/** \brief Valida que sean Letras.
 *
 * \param letra char*   Variable que guarda la cadena a validar.
 * \return int  Devuelve '0' en caso de error, y en caso contrario '1'.
 *
 */
int soloLetras(char* letra);

/** \brief Valida que ingresen 2 variables char
 *
 * \param input char*   Se guarda la opcion que el usuario ingrese.
 * \param mensaje[] char    Mensaje que se le muestra al usuario para que sepa que ingresar.
 * \param primerValor char  Primer valor para validar
 * \param segundoValor char Primer valor para validar
 * \param reintentos int    Cantidad de veces que el usuario puede ingresar un dato erroneo.
 * \return void
 *
 */
void validacionEntreChar(char* input,char message[],char primerValor, char segundoValor, int reintentos);

/** \brief Imprime Error de limite de Reintentos.
 *
 * \return void
 *
 */
void imprimirLimiteDeReintentos();

/** \brief  Guia al usuario en que error esta cometiendo al ingresar un numero.
 *
 * \param numero int    Se guarda un valor recibido de otra funcion, diciendo que tipo de error se cometio.
 * \param reintentos int*   Indica los reintentos que tiene el usuario para agregar un dato valido.
 * \return int
 *
 */
int validarIngresoDeDatos(int numero, int* reintentos);


/** \brief Le pide al usuario que ingrese de que manera quiere ordenar (descendentemente o ascendentemente)
 *
 * \param message[] char    Mensaje que se le muestra al usuario para que agrege la forma de ordenar
 * \param formaDeOrdenar int*   Donde se guarda la opcion que ingreso el usuario
 * \return int  En caso de Exito retorna '0'. Caso contrario '1'
 *
 */
int formaDeOrdenar(char message[], int* formaDeOrdenar);

#endif // VALIDACIONES_H_INCLUDED
