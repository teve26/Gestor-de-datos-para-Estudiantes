#include <iostream>
#include <fstream> //para el manejo de archivo.txt
#include <string>//Manejo de nombres y parsing
#include <vector>// para el uso de vectores y el almacenamiento
#include <algorithm>// para el ordenamiento y manipulación de datos

using namespace std;
//Creacion del tipo de dato "Estudiante"
struct Estudiante {
    int id=0;
    string nombre;
    double promedio=0.0;
};
//crea un vector de Tipo
vector<Estudiante> estudiantes;

void mostrarMenu() {
    cout << "\nGESTOR DE ESTUDIANTES\n";
    cout << "1. Agregar estudiante\n";
    cout << "2. Mostrar todos\n";
    cout << "3. Buscar por ID\n";
    cout << "4. Modificar estudiante\n";
    cout << "5. Eliminar estudiante\n";
    cout << "6. Ordenar por promedio\n";
    cout << "7. Calcular promedio general\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";
}

void guardarEnArchivo() {
    ofstream archivo("estudiantes.txt");
    for (const auto& e : estudiantes) {
        archivo << e.id << "," << e.nombre << "," << e.promedio << "\n";
    }
    cout << "\n** Datos guardados en estudiantes.txt **\n";
}

/*
Esta función permite registrar un nuevo estudiante en el sistema, solicitando al usuario 
que ingrese: ID, nombre completo y promedio, para luego almacenarlo en el vector estudiantes.*/

void limpiarBuffer() {//Ignora todo hasta encontrar un salto de línea \n, aunque haya varios de caracteres en el búfer
    cin.clear();//    Así limpia todo el búfer de entrada sin importar qué tan sucia esté la entrada anterior.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//para la validadcion de las entradas

void agregarEstudiante() {
    Estudiante nuevo;
    cout << "\nAGREGAR ESTUDIANTE\n";
    // Validar ID (entero)
    while (true) {
        cout << "ID (numero): ";
        cin >> nuevo.id;

        if (cin.fail()) {
            cout << "Error: Ingrese un numero valido.\n";
            limpiarBuffer();
        }
        else {
            limpiarBuffer();
            break;
        }
    }

    cout << "Nombre completo: ";
    getline(cin, nuevo.nombre);
    while (nuevo.nombre.empty()) {
        cout << "Error: El nombre no puede estar vacio.\n";
        cout << "Nombre completo: ";
        getline(cin, nuevo.nombre);
    }


    // Validar promedio (decimal entre 0.0 y 10.0)
    while (true) {
        cout << "Promedio (0.0 - 10.0): ";
        cin >> nuevo.promedio;

        if (cin.fail() || nuevo.promedio < 0.0 || nuevo.promedio > 10.0) {
            cout << "Error: Ingrese un promedio valido entre 0.0 y 10.0.\n";
            limpiarBuffer();
        }
        else {
            limpiarBuffer();
            break;
        }
    }

    estudiantes.push_back(nuevo);
    guardarEnArchivo();
}

void mostrarTodos() {
    cout << "\nLISTA DE ESTUDIANTES\n";
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados\n";
        return;
    }//por si se muestra cuando no se a ingresado los estudiantes

    //for (declaración : rango) 
    // se le puede colocar const auto para que el programa escoja el tipo de dato
    for (const Estudiante& e : estudiantes) {//este es un metodo para recorrer contenedores entonces "e" toma el valor de cada espacio del vector y lo va rrecorriendo
        cout << "ID: " << e.id << " | Nombre: " << e.nombre
            << " | Promedio: " << e.promedio << endl;
    }
}

void buscarPorID() {
    cout << "\nBUSCAR ESTUDIANTE\n";
    int id;

    // Validar ID (entero)
    while (true) {
        cout << "Ingrese ID: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Error: Ingrese un ID valido.\n";
            limpiarBuffer();
        }
        else {
            limpiarBuffer();
            break;
        }
    }

    
    for (const Estudiante& e : estudiantes) {
        if (e.id == id) {
            cout << "\nEncontrado:\n";
            cout << "Nombre: " << e.nombre << "\nPromedio: " << e.promedio << endl;
            return;//cierra la funcion y asi ya no se ejecuata el mensaje de que no se encontro
        }
    }
    cout << "\nNo se encontro el ID : " << id << endl;
}

void modificarEstudiante() {
    cout << "\nMODIFICAR ESTUDIANTE\n";
    int id;

    // Validar ID (entero)
    while (true) {
        cout << "ID a modificar: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Error: Ingrese un ID valido.\n";
            limpiarBuffer();
        }
        else {
            limpiarBuffer();
            break;
        }
    }

    
    for (Estudiante& e : estudiantes) {
        if (e.id == id) {
            cout << "Datos actuales:\n";
            cout << "Nombre: " << e.nombre << "\nPromedio: " << e.promedio << endl;

            cout << "Nuevo nombre: ";
            getline(cin, e.nombre);//igual para tomar nombre completo despues del espacio

            getline(cin, e.nombre);
            while (e.nombre.empty()) {
                cout << "Error: El nombre no puede estar vacio.\n";
                cout << "Nuevo nombre: ";
                getline(cin, e.nombre);
            }


            // Validar promedio (decimal entre 0.0 y 10.0)
            while (true) {
                cout << "Nuevo promedio: ";
                cin >> e.promedio;

                if (cin.fail() || e.promedio < 0.0 || e.promedio > 10.0) {
                    cout << "Error: Ingrese un promedio valido entre 0.0 y 10.0.\n";
                    limpiarBuffer();
                }
                else {
                    limpiarBuffer();
                    break;
                }
            }

            guardarEnArchivo();
            return;//igual aqui de una ves retorna y ya no pasa al id no encontrado
        }
    }
    cout << "ID no encontrado\n";
}

void eliminarEstudiante() {
    cout << "\nELIMINAR ESTUDIANTE\n";
    int id;

    // Validar ID (entero)
    while (true) {
        cout << "ID a eliminar: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Error: Ingrese un ID valido.\n";
            limpiarBuffer();
        }
        else {
            limpiarBuffer();
            break;
        }
    }

    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {//para encontrar el indice del estudiante que se va a borrar
        // Comprueba si el ID del estudiante actual (al que apunta 'it') coincide con el ID buscado
    // 'it->id' accede al campo 'id' del estudiante
        if (it->id == id) {
            // Elimina el elemento actual del vector (al que apunta 'it')
            estudiantes.erase(it);
            cout << "Eliminado!\n";
            guardarEnArchivo();
            // Sale del bucle inmediatamente después de eliminar
            return;
        }
    }
    cout << "ID no encontrado\n";
}

void ordenarPorPromedio() {
    sort(estudiantes.begin(), estudiantes.end(),//sort es una funcion de la libreria <algorithm> que ordena elementos
        [](const Estudiante& a, const Estudiante& b) { //aqui esta el rango desde donde hasta donde ordenan
            return a.promedio > b.promedio;//Devuelve true si a.promedio es mayor que b.promedio
                                           //Esto produce un orden (de mayor a menor)
        });
    //despues de esto ya esta ordenado los datos del vector
    cout << "\nEstudiantes ordenados por promedio!\n";
    //solo se muestra la lista ordenada
    mostrarTodos();
}

void calcularPromedioGeneral() {

    //Verificación si hay estudiantes
    if (estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados\n";
        return;  // Sale de la función si no hay estudiantes
    }
    //Inicialización del acumulador
    double suma = 0;  // Variable para acumular la suma de promedios

    for (const auto& e : estudiantes) {  // Recorre cada estudiante
        suma += e.promedio;  // Suma el promedio del estudiante actual
    }

    //Cálculo del promedio general
    double promedio = suma / estudiantes.size();  // Suma total / cantidad de estudiantes

    //Mostrar el resultado
    cout << "\nPROMEDIO GENERAL: " << promedio << endl;
}

void cargarDesdeArchivo() {
    //Abrir el archivo para lectura
    ifstream archivo("estudiantes.txt");

    //Limpiar el vector actual
    estudiantes.clear();

    //Variable para almacenar cada línea leída
    string linea;

    //Leer el archivo línea por línea
    while (getline(archivo, linea)) {
        //Encontrar posiciones de las comas
        size_t pos1 = linea.find(',');      // Primera coma
        size_t pos2 = linea.rfind(',');     // Última coma (segunda en este caso)

        //Crear un nuevo estudiante
        Estudiante e;

        //Extraer y convertir el ID (desde inicio hasta primera coma)
        e.id = stoi(linea.substr(0, pos1));

        //Extraer el nombre (entre primera y segunda coma)
        e.nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);

        //Extraer y convertir el promedio (desde última coma hasta final)
        e.promedio = stod(linea.substr(pos2 + 1));

        //Agregar el estudiante al vector
        estudiantes.push_back(e);
    }
    cout << "\nDatos cargados desde estudiantes.txt\n";
}

int main() {
    cargarDesdeArchivo();//esta es la funcion para agregar cada estudiante almacenado en el archivo estudiantes.txt en el arreglo que se va a usar en el codigo

    int opcion;
    do {

        // Validar ID (entero)
        while (true) {
            mostrarMenu();//llama a la funcion solo para mostrar el menu
            cin >> opcion;//guarda la opcion seleccionada

            if (cin.fail()) {//sirve para detectar si el usuario escribio algo que no se puede convertir a un número
                             //como letras o simbolos, y luego limpiar el flujo de entrada para evitar errores
                cout << "Error: Ingrese un numero valido.\n";
                limpiarBuffer();
            }
            else {
                limpiarBuffer();
                break;
            }
        }

        //aqui se encunetran las opciones para ir cada funcion
        switch (opcion) {
        case 1: agregarEstudiante(); break;
        case 2: mostrarTodos(); break;
        case 3: buscarPorID(); break;
        case 4: modificarEstudiante(); break;
        case 5: eliminarEstudiante(); break;
        case 6: ordenarPorPromedio(); break;
        case 7: calcularPromedioGeneral(); break;
        case 0:cout << "\nSaliendo...\n"; break;
        default: cout << "\nOpcion no valida\n";
        }
    } while (opcion != 0);//si se selecciona otro que no sea 0 sigue mostrando el menu si selecciona 0 se sale

    return 0;
}