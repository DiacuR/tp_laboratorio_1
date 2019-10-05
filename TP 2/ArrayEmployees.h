#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

/** \brief Pide un valor numerico.
 *
 * \param text[] char Mensaje que se le muestra al usuario para que sepa que ingresar.
 * \return int  Devuelve el numero que ingreso el usuario.
 *
 */
int menu(char text[]);
/** \brief Inicializa los empleados.
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return int  retorna '0' si realiza la funcion, en caso contrario '-1'.
 *
 */
int initEmployees (Employee* lista, int len);
/** \brief  Agrega empleados nuevos.
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return int  retorna '0' en caso de no agregar el empleado, en caso de agregarlo '1',
 *              si tamaño es invalido o puntero es NULL '-1', Si no hay espacio en el array '-2'.
 *
 */
int addEmployee(Employee* lista, int len);
/** \brief Imprime en pantalla los empleados en el Array
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return void
 *
 */
void printEmployees(Employee* lista, int len);
/** \brief  Encuentra a un empleado usando el id
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \param id int    Id del empleado a buscar
 * \return int  Devuelve -1 en caso de error y en caso de exito devuelve en que posicion del array esta el empleado
 *
 */
int findEmployeeById(Employee* lista, int len, int id);
/** \brief  Borra a un empleado del array(borrado logico).
 *
 * \param lista Employee*   Array con lista de empleados.
 * \param len int   Tamaño del array.
 * \param id int    El id del empleado a borrar
 * \return int  Devuelve '-2' Si el id ingresado por el usuario es incorrecto. '-1' si tamaño es invalido o puntero es NULL,
                0 si se realizo con exito
 *
 */
int removeEmployee(Employee* lista, int len, int id);
/** \brief Ordena el array de empleados
 *
 * \param lista Employee*   Array con lista de empleados.
 * \param len int   Tamaño del array.
 * \param order int Indica a travez de '1' o '0' que tipo de ordenamiento va a ser.
 * \return int  retorna '-1' en caso de numero invalido, y '1' en caso de exito
 *
 */
int sortEmployees(Employee* lista, int len, int order);

/** \brief Muestra un solo empleado
 *
 * \param empleado Employee  El empleado a mostrar
 * \return void
 *
 */
void mostrarEmpleado(Employee empleado);
/** \brief  Pide los datos al ingresar un empleado y los valida
 *
 * \param Empleado Employee* Al empleado que se le guardan los datos ingresados por el usuario
 * \param index int Lugar en el array para ingresar al empleado
 * \return int Retorna '1' si se realizo con exito, '0' Si no se guardo.
 *
 */
int agregarDatosDeEmpleado(Employee* Empleado, int index);

/** \brief Modifica empleados.
 *
 * \param lista Employee*   Array con lista de empleados.
 * \param len int   Tamaño del array.
 * \return void
 *
 */
void modificarEmpleado(Employee* lista, int len);



/** \brief Valida que haya por lo menos un empleado.
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return int Devuelve '0' en caso de error, en caso contrario '1'.
 *
 */
int validarQueHayaEmpleado(Employee* lista, int len);
/** \brief Busca espacio libre en el array
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return int Retorna '-1' en caso de error, en caso contrario devuelve el indice del array donde hay una posicion libre
 *
 */
int buscarEspacioLibre(Employee* lista, int len);
/** \brief Agrega un empleado al Array
 *
 * \param empleado Employee*  El empleado a agregar.
 * \param index int     La posicion del array donde lo va a agregar
 * \return int Retorna '-2' si no hay espacio en el array. '0' en caso de no agregar el empleado, en caso de agregarlo '1',
 *
 */
int agregarEmpleadoAlArray(Employee* empleado,int index);


/** \brief Calcula el salario total de los empleados
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return float retorna el Salario total de los empleados.
 *
 */
float salarioTotal(Employee* lista, int len);
/** \brief Calcula el salario promedio
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return float   Devuelve el salario promedio
 *
 */
float salarioPromedio(Employee* lista, int len);
/** \brief Calcula cuantos salarios hay mayor al promedio
 *
 * \param lista Employee*   Array con lista de empleados
 * \param len int   Tamaño del array
 * \return int
 *
 */
int salariosMayoresAlPromedio(Employee* lista, int len);
#endif // ARRAYEMPLOYEES_H_INCLUDED
