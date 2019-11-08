/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*   El archivo del cual se lee los datos de los empleados
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \return int  Retorna '1' en caso de de que uno de los parametros de la funcion den NULL.
 *              Retorna '0' en caso de Exito.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief  Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*   El archivo del cual se lee los datos de los empleados
 * \param pArrayListEmployee LinkedList*    Lista de empleados
 * \return int  Retorna '1' en caso de de que uno de los parametros de la funcion den NULL.
 *              Retorna '0' en caso de Exito.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
