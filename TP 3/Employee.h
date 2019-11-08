#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor por defecto de empleado. Crea un empleado en memoria dinamica
 *
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_new();
/** \brief Constructor parametrizado de empleado. Crea un empleado en memoria dinamica
           con los datos recibidos como parametros
 *
 * \param id int El id del empleado
 * \param nombre char* El nombre del empleado
 * \param horasTrabajadas int Las horas trabajadas del empleado
 * \param sueldo int El sueldo del empleado
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo);
/** \brief Función que setea el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int El id a setear
 * \return int Devuelve '0' si se pudo setear, y '1' si no se pudo
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Función que obtiene el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int* El id obtenido
 * \return int Devuelve '0' si se pudo obtener, y '1' si no se pudo
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief Función que setea el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El nombre a setear
 * \return int Devuelve '0' si se pudo setear, y '1' si no se pudo
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Función que obtiene el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El nombre obtenido
 * \return int Devuelve '0' si se pudo obtener, y '1' si no se pudo
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Función que setea las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param horasTrabajadas int Las Horas trabajadas a setear
 * \return int Devuelve '0' si se pudo setear, y '1' si no se pudo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Función que obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param horasTrabajadas char* Las horas trabajadas obtenida
 * \return int Devuelve '0' si se pudo obtener, y '1' si no se pudo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Función que setea el sueldo de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param sueldo int El sueldo a setear
 * \return int Devuelve '0' si se pudo setear, y '1' si no se pudo
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Función que obtiene el sueldo de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param sueldo int* El sueldo obtenido
 * \return int Devuelve '0' si se pudo obtener, y '1' si no se pudo
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Muestra las columnas de la estructura empleado
 *
 * \return void
 *
 */
void mostrarColumnas();

/** \brief Pide y valida el nombre ingresado por el usuario
 *
 * \param nombre[] char     Guarda el nombre ingresado
 * \param reintentos int*   La cantidad de intentos que le quedan para poner un valor correcto
 * \return int  Retorna '0' en caso de Exito. Y '1' en caso contrario.
 *
 */
int pedirNombre(char nombre[], int* reintentos);

/** \brief Pide y valida las horas trabajadas ingresadas por el usuario
 *
 * \param horasTrabajadas int*     Guarda las horas trabajadas ingresadas
 * \param reintentos int*   La cantidad de intentos que le quedan para poner un valor correcto
 * \return int  Retorna '0' en caso de Exito. Y '1' en caso contrario.
 *
 */
int pedirHorasTrabajadas(int* horasTrabajadas, int* reintentos);
/** \brief Pide y valida el sueldo ingresado por el usuario
 *
 * \param sueldo int*     Guarda el sueldo ingresado
 * \param reintentos int*   La cantidad de intentos que le quedan para poner un valor correcto
 * \return int  Retorna '0' en caso de Exito. Y '1' en caso contrario.
 *
 */
int pedirSueldo(int* sueldo, int* reintentos);

/** \brief Encuentra a un empleado por id y lo devuelve por referencia
 *
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \param this Employee*    Es donde se carga el empleado con el id pasado como parametro
 * \param id int    Es el id del empleado a buscar
 * \return int  Retorna la pocicion index del empleado en caso de Exito. En caso contrario '-1'
 *
 */
int employee_EncontrarPorId(LinkedList* pArrayListEmployee,Employee* this, int id);

/** \brief Muestra un empleado
 *
 * \param emp Employee* El empleado a mostrar
 * \return void
 *
 */
void mostrarEmpleado(Employee* emp);
/** \brief Sirve para comparar y asi poder ordenar los empleados por id
 *
 * \param void* puntero que apunta a un empleado
 * \param void* puntero que apunta al segundo empleado
 * \return int  Devuelve '1' si el id del empleado es mayor
 *              al del segundo empleado. En caso contrario '-1'. Y en caso de ser iguales '0'
 */
int compararPorLegajo(void* e1,void* e2);
/** \brief Sirve para comparar y asi poder ordenar los empleados por sueldo
 *
 * \param void* puntero que apunta a un empleado
 * \param void* puntero que apunta al segundo empleado
 * \return int  Devuelve '1' si el sueldo del empleado e1 es mayor
 *              al del empleado e2. En caso contrario '-1'. Y en caso de ser iguales '0'
 */
int compararPorSueldo(void* e1,void* e2);
/** \brief Sirve para comparar y asi poder ordenar los empleados por nombre
 *
 * \param void* puntero que apunta a un empleado
 * \param void* puntero que apunta al segundo empleado
 * \return int  Devuelve '1' si el nombre del empleado e1 es mayor(segun ASCII)
 *              al del empleado e2. En caso contrario '-1'. Y en caso de ser iguales '0'
 */
int compararPorNombre(void* e1,void* e2);
/** \brief Sirve para comparar y asi poder ordenar los empleados por horas trabajadas
 *
 * \param void* puntero que apunta a un empleado
 * \param void* puntero que apunta al segundo empleado
 * \return int  Devuelve '1' si el sueldo del empleado e1 es mayor
 *              al del empleado e2. En caso contrario '-1'. Y en caso de ser iguales '0'
 */
int compararPorHorasTrabajadas(void* e1,void* e2);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \param criterio int  Funcion que determina cual va a ser el criterio de orden(id,nombre,hsTrabajadas,sueldo)
 * \param orden int     Determina si se ordena ascendentemento o decendentemente
 * \return int      Retorna '0' en caso de Exito. Y '1' en caso contrario.
 *
 */
int ordenarAscendienteODecendiente(LinkedList* pArrayListEmployee,int(*criterio)(void* e1, void* e2),int orden);
#endif // employee_H_INCLUDED
