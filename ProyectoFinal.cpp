#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definición de la estructura Alumno
struct Alumno {
    int n;             // Número de estudiante
    string carnet;     // Número de carnet
    string nombre;     // Nombre del estudiante
    string apellido;   // Apellido del estudiante
    string sexo;       // Sexo del estudiante
    string telefono;   // Teléfono del estudiante
    string curso;      // Curso del estudiante
    string seccion;    // Sección del estudiante
};

const int MAX_ALUMNOS = 30;
Alumno alumnos[MAX_ALUMNOS];

// Función para crear una base de datos si no existe
void crearBaseDeDatos(const string& nombreArchivo) {
    ifstream archivoExistente(nombreArchivo);
    //Validacion si el archivo ya existe
    if (archivoExistente) {
        cout << "La base de datos ya existe: " << nombreArchivo << endl;
    }
    else {
        ofstream archivoNuevo(nombreArchivo);
        if (archivoNuevo.is_open()) {
            cout << "Base de datos creada: " << nombreArchivo << endl;
        }
        else {
            cerr << "No se pudo crear la base de datos." << endl;
        }
        archivoNuevo.close();
    }
    archivoExistente.close();
}

//funcionar para cargar la base de datos respectia
int cargarBaseDeDatos(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int contador = 0;

    if (archivo.is_open()) {
        cout << "Entroo: " << nombreArchivo << endl;
        Alumno alumno;
        while (contador < MAX_ALUMNOS && archivo >> alumno.n >> alumno.carnet >> alumno.nombre >> alumno.apellido >> alumno.sexo >> alumno.telefono >> alumno.curso >> alumno.seccion) {
            alumnos[contador] = alumno;
            contador++;
        }
        archivo.close();
    }
    else {
        cerr << "No se pudo abrir la base de datos." << endl;
    }

    return contador;
}

//Funcion que permite agregar alumnos
void agregarAlumno(int& contador, int& contador2) {
    //Contadorfinal para verificar si no hay registros anteriores
    int contadorFinal = contador2 + contador;

    if (contadorFinal >= MAX_ALUMNOS) {
        cerr << "No se pueden agregar mas alumnos, la base de datos esta llena." << endl;
        return;
    }
    //Agrega nuevos usuarios
    Alumno& alumno = alumnos[contador];
    cout << "Datos del alumno " << contadorFinal + 1 << ":" << endl;
    alumno.n = contadorFinal + 1;
    cout << "Carnet: ";
    cin >> alumno.carnet;
    cout << "Nombre: ";
    cin >> alumno.nombre;
    cout << "Apellido: ";
    cin >> alumno.apellido;
    cout << "Sexo: ";
    cin >> alumno.sexo;
    cout << "Telefono: ";
    cin >> alumno.telefono;
    cout << "Curso: ";
    cin >> alumno.curso;
    cout << "Seccion: ";
    cin >> alumno.seccion;

    contador++;
}

//Funcion que nos permite la visualizacion del archivo
void verAlumnos(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
    }
    else {
        cerr << "No se pudo abrir la base de datos." << endl;
    }
}


//fucnionq ue nos permite acutalizar alumno mediante su cartes
void actualizarAlumno(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    ofstream temp("temp.txt");

    string carnet, nombre, apellido, sexo, telefono, curso, seccion;
    string carnetaux;
    //buscamos el carnet a buscar
    cout << "Ingrese el numero de carnet del alumno a actualizar: ";
    cin >> carnetaux;

    //acutalizamos los datos respectivos
    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> carnet >> nombre >> apellido >> sexo >> telefono >> curso >> seccion) {
            if (carnet == carnetaux) {
                cout << "Nuevo Nombre: ";
                cin >> nombre;
                cout << "Nuevo Apellido: ";
                cin >> apellido;
                cout << "Nuevo Sexo: ";
                cin >> sexo;
                cout << "Nuevo Telefono: ";
                cin >> telefono;
                cout << "Nuevo Curso: ";
                cin >> curso;
                cout << "Nueva Seccion: ";
                cin >> seccion;
            }
            temp << carnet << " " << nombre << " " << apellido << " " << sexo << " " << telefono << " " << curso << " " << seccion << endl;
        }
    }
    else {
        cerr << "No se pudo abrir la base de datos o el archivo temporal." << endl;
    }

    archivo.close();
    temp.close();

    remove(nombreArchivo.c_str());
    rename("temp.txt", nombreArchivo.c_str());
}

//funcion que busca el archivo alumno
void buscarAlumno(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    string buscar;
    int metodo;
    cout << "\nMetodo de busqueda: " << endl;
    cout << "1. Carnet" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Curso" << endl;
    cout << "4. Seccion" << endl;
    cout << "Ingrese el numero del método: ";
    cin >> metodo;
    cout << "Ingrese el valor a buscar: ";
    cin >> buscar;

    if (archivo.is_open()) {
        string carnet, nombre, apellido, sexo, telefono, curso, seccion;
        bool encontrado = false;

        while (archivo >> carnet >> nombre >> apellido >> sexo >> telefono >> curso >> seccion) {
            if ((metodo == 1 && carnet == buscar) || (metodo == 2 && nombre == buscar) || (metodo == 3 && curso == buscar) || (metodo == 4 && seccion == buscar)) {
                encontrado = true;
                cout << "Numero de Carnet: " << carnet << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Apellido: " << apellido << endl;
                cout << "Sexo: " << sexo << endl;
                cout << "Telefono: " << telefono << endl;
                cout << "Curso: " << curso << endl;
                cout << "Seccion: " << seccion << endl;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron resultados." << endl;
        }
    }
    else {
        cerr << "No se pudo abrir la base de datos." << endl;
    }
}

//funcion que permite la eliminacion de Alumno respectivamente
void eliminarAlumno(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    ofstream temp("temp.txt");

    string carnetaux;
    //realizamos la buqueda mediante el carnet respectivo
    cout << "Ingrese el número de carnet del alumno a eliminar: ";
    cin >> carnetaux;

    if (archivo.is_open() && temp.is_open()) {
        string carnet, nombre, apellido, sexo, telefono, curso, seccion;
        bool eliminado = false;

        while (archivo >> carnet >> nombre >> apellido >> sexo >> telefono >> curso >> seccion) {
            if (carnet == carnetaux) {
                cout << "Alumno eliminado." << endl;
                eliminado = true;
            }
            else {
                temp << carnet << " " << nombre << " " << apellido << " " << sexo << " " << telefono << " " << curso << " " << seccion << endl;
            }
        }

        archivo.close();
        temp.close();

        if (eliminado) {
            remove(nombreArchivo.c_str());
            rename("temp.txt", nombreArchivo.c_str());
        }
        else {
            cerr << "No se encontró ningún alumno con el número de carnet especificado." << endl;
            remove("temp.txt");
        }
    }
    else {
        cerr << "No se pudo abrir la base de datos o el archivo temporal." << endl;
    }
}

//funcion que permite el almacenamiento de datos en nuestro archivo.txt
void grabarDB(const string& nombreArchivo, int& contador) {
    ofstream archivo(nombreArchivo, ios::app);
    
    if (archivo.is_open()) {
        //comienza el almacenamiento validando el contador respectivo
        for (int i = 0; i < contador; i++) {
            Alumno& alumno = alumnos[i];
            archivo << alumno.n << " " alumno.carnet << " " << alumno.nombre << " " << alumno.apellido << " " << alumno.sexo << " " << alumno.telefono << " " << alumno.curso << " " << alumno.seccion << endl;
        }
        cout << "Datos guardados en la base de datos." << endl;
    }
    else {
        cerr << "No se pudo abrir la base de datos." << endl;
    }
}

//Nos permite contar las lineas que tiene nuestro archivo txt que emula una DB
int contarLineasEnArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int contador = 0;

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            contador++;
        }
        archivo.close();
    }
    else {
        cerr << "No se pudo abrir el archivo." << endl;
    }

    return contador;
}

//Funcion Main que ejecuta toda el programa
int main() {
    int opcion;
    int contador = 0;
    int contador2 = 0;
    string nombreArchivo;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Crear Base de Datos" << endl;
        cout << "2. Agregar Alumno" << endl;
        cout << "3. Actualizar Alumno" << endl;
        cout << "4. Ver Alumnos" << endl;
        cout << "5. Buscar Alumno" << endl;
        cout << "6. Eliminar Alumno" << endl;
        cout << "7. Grabar en Base de Datos" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        //validaciones mediante el uso dw swtich
        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre de la base de datos (.txt): ";
            cin >> nombreArchivo;
            crearBaseDeDatos(nombreArchivo);
            break;
        case 2:

            contador2 = contarLineasEnArchivo(nombreArchivo);
            agregarAlumno(contador, contador2);
            break;
        case 3:
            actualizarAlumno(nombreArchivo);
            break;
        case 4:
            verAlumnos(nombreArchivo);
            break;
        case 5:
            buscarAlumno(nombreArchivo);
            break;
        case 6:
            eliminarAlumno(nombreArchivo);
            break;
        case 7:
            grabarDB(nombreArchivo, contador);
            contador = 0;
            break;
        case 8:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cerr << "Opcion no válida. Inténtelo de nuevo." << endl;
            break;
        }
    } while (opcion != 8);

    return 0;
}
