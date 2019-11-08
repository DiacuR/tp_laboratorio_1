/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int  Retorna '1' en caso de de que uno de los parametros de la funcion den NULL.
 *              Retorna '0' en caso de Exito.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);



/** \brief carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pArraylistEmployee linkedlist*    Lista de empleados.
 * \return int  Retorna '1' si no se pudieron cargar los datos y '0' si se pudo cargar los datos
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*    Lista de empledos
 * \return Retorna '0' si realizo el alta '1' si no se realiza.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* siguinteId);
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*    Lista de empleados.
 * \return Retorna '0' si realizo la modificacion '1' si no se realizo
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \return int   Retornoa '1' en caso de Fallo. Y en caso contrario retorna '0'
 *               Y si el id que ingreso el usuario es invalido retorna '-2'.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Lista empleados
 *
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \return int  Retornoa '1' en caso de Fallo. En caso contrario retorna '0'.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \return int  Retornoa '1' en caso de Fallo. Y en caso contrario retorna '0'
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList*
 * \return int  Retorna '1' en caso de de que uno de los parametros de la funcion den NULL.
 *              Retorna '0' en caso de Exito.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \return int  Retorna '1' en caso de de que uno de los parametros de la funcion den NULL.
 *              Retorna '0' en caso de Exito.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

