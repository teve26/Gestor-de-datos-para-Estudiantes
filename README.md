# Gestor-de-datos-para-Estudiantes
esta es una herramienta diseñada para que los docentes puedan registrar, consultar y actualizar información sobre sus estudiantes de manera sencilla y eficiente. Este programa facilita la organización de datos permitiendo llevar un control claro y ordenado de su grupo, asegurando que la información siempre esté guardada y disponible.

📚 Gestor de Estudiantes en C++
Este proyecto es una aplicación de consola desarrollada en C++ que permite gestionar un listado de estudiantes, sus nombres, ID y promedios. Los datos se almacenan en un archivo de texto (estudiantes.txt) para mantener la persistencia entre ejecuciones.

🧩 Funcionalidades
1.Agregar estudiantes con validación de datos.
2.Mostrar la lista completa de estudiantes.
3.Buscar un estudiante por su ID.
4.Modificar la información de un estudiante existente.
5.Eliminar un estudiante del registro.
6.Ordenar estudiantes por promedio (de mayor a menor).
7.Calcular el promedio general de todos los estudiantes registrados.

Cargar y guardar automáticamente los datos en el archivo estudiantes.txt.

📁 Estructura del Proyecto
estudiantes.txt
Archivo de texto donde se guarda la información de los estudiantes en el siguiente formato:

ID,Nombre,Promedio
ejemplo:

10,Jack Lopez,6.7

proyectoFinal.cpp
Contiene todo el código fuente del proyecto.

📌 Uso del programa

Al ejecutar el programa, se mostrará un menú interactivo como el siguiente:

GESTOR DE ESTUDIANTES
1. Agregar estudiante
2. Mostrar todos
3. Buscar por ID
4. Modificar estudiante
5. Eliminar estudiante
6. Ordenar por promedio
7. Calcular promedio general
0. Salir

Endonde se puede seleccionar mediante el nuemero de la opcion deseada la funcion que se quiere realizar

📝 Funciones Principales

mostrarMenu() 	Muestra las opciones del menú principal.

agregarEstudiante()	Solicita los datos de un nuevo estudiante y lo guarda.

mostrarTodos()	Imprime en pantalla todos los estudiantes registrados.

buscarPorID()	Busca e imprime los datos de un estudiante por su ID.

modificarEstudiante()	Permite editar el nombre y promedio de un estudiante.

eliminarEstudiante()	Elimina un estudiante del vector por su ID.

ordenarPorPromedio()	Ordena los estudiantes de mayor a menor promedio.

calcularPromedioGeneral()	Calcula y muestra el promedio general de todos los estudiantes.

guardarEnArchivo()	Guarda los datos actuales en estudiantes.txt.

cargarDesdeArchivo()	Carga los datos desde el archivo al iniciar el programa.

Validación de Entradas
para la validacion de la entrada de datos se utilizo la función limpiarBuffer() en conjunto con la validacion para cada entrada de ID, Nmbre, Promedio.
Para evitar errores al ingresar datos, especialmente si el usuario introduce letras donde se esperan números o deja campos vacíos.
