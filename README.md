# Gestor-de-datos-para-Estudiantes
Esta es una herramienta realizada por:<br>

<h3>Jack Bruce Lopez Lopez</h3>
<h3>José David Gómez López</h3>
<h3>Marlon Iván Fuentes Velásquez</h3>
<h3>Jorge Daniel Escobar Fuentes</h3>

Diseñada para que los docentes puedan registrar, consultar y actualizar información sobre sus estudiantes de manera sencilla y eficiente. Este programa facilita la organización de datos permitiendo llevar un control claro y ordenado de su grupo, asegurando que la información siempre esté guardada y disponible.
<h2>📚 Gestor de Estudiantes en C++</h2>

Este proyecto es una aplicación de consola desarrollada en C++ que permite gestionar un listado de estudiantes, sus nombres, ID y promedios. Los datos se almacenan en un archivo de texto (estudiantes.txt) para mantener la persistencia entre ejecuciones.

<h2>🧩 Funcionalidades</h2>
1.Agregar estudiantes con validación de datos.<br>
2.Mostrar la lista completa de estudiantes.<br>
3.Buscar un estudiante por su ID.<br>
4.Modificar la información de un estudiante existente.<br>
5.Eliminar un estudiante del registro.<br>
6.Ordenar estudiantes por promedio (de mayor a menor).<br>
7.Calcular el promedio general de todos los estudiantes registrados.<br>

Cargar y guardar automáticamente los datos en el archivo estudiantes.txt.<br>

<h2>📁 Estructura del Proyecto</h2>
estudiantes.txt<br>
Archivo de texto donde se guarda la información de los estudiantes en el siguiente formato:<br>

ID,Nombre,Promedio<br>
ejemplo:<br>

10,Jack Lopez,6.7

proyectoFinal.cpp
Contiene todo el código fuente del proyecto.<br>

<h2>📌 Uso del programa</h2>

Al ejecutar el programa, se mostrará un menú interactivo como el siguiente:<br>

GESTOR DE ESTUDIANTES<br>
1. Agregar estudiante<br>
2. Mostrar todos<br>
3. Buscar por ID<br>
4. Modificar estudiante<br>
5. Eliminar estudiante<br>
6. Ordenar por promedio<br>
7. Calcular promedio general<br>
0. Salir<br>

Endonde se puede seleccionar mediante el nuemero de la opcion deseada la funcion que se quiere realizar<br>

<h2>📝 Funciones Principales</h2>

mostrarMenu() 	Muestra las opciones del menú principal.<br>

agregarEstudiante()	Solicita los datos de un nuevo estudiante y lo guarda.<br>

mostrarTodos()	Imprime en pantalla todos los estudiantes registrados.<br>

buscarPorID()	Busca e imprime los datos de un estudiante por su ID.<br>

modificarEstudiante()	Permite editar el nombre y promedio de un estudiante.<br>

eliminarEstudiante()	Elimina un estudiante del vector por su ID.<br>

ordenarPorPromedio()	Ordena los estudiantes de mayor a menor promedio.<br>

calcularPromedioGeneral()	Calcula y muestra el promedio general de todos los estudiantes.<br>

guardarEnArchivo()	Guarda los datos actuales en estudiantes.txt.<br>

cargarDesdeArchivo()	Carga los datos desde el archivo al iniciar el programa.<br>

<h2>🛡️Validación de Entradas</h2>
para la validacion de la entrada de datos se utilizo la función limpiarBuffer() en conjunto con la validacion para cada entrada de ID, Nombre, Promedio.<br>
Para evitar errores al ingresar datos, especialmente si el usuario introduce letras donde se esperan números o deja campos vacíos.
