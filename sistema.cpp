#include "sistema.h"
#include "montos.h"
#include "gestorArchivos.h"
#include <vector>
#include <string> 
#include <limits>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std; 		

// Función para centrar una línea en la consola
void centrarLinea(const string& texto, int anchoConsola = 80) {
    int espacios = (anchoConsola - texto.length()) / 2;
    if (espacios > 0) {
        cout << string(espacios, ' ');
    }
    cout << texto << endl;
}

void Sistema::mostrarReporteGeneral() {
    vector<Montos> montos = GestorArchivos::cargarDatos("montos.txt");

    if (montos.empty()) {
        centrarLinea("No hay movimientos registrados.");
    } else {
        float montoTotal = 0;

        // Encabezado del reporte
        centrarLinea("==================== REPORTE GENERAL ====================");
        centrarLinea("------------------------------------------------------------");

        // Encabezados de la tabla
        string encabezados = "MONTO       CATEGORIA    DESCRIPCION         FECHA       ID";
        centrarLinea(encabezados);
        centrarLinea("------------------------------------------------------------");

        // Datos de la tabla
        for (const auto& monto : montos) {
            string tipo = "s/." + to_string((int)monto.getIngreso());
            string categoria = monto.getTipoIngreso();
            string descripcion = monto.getDescripcion();
            string fecha = monto.getFecha();
            string id = monto.getID();

            string linea = tipo + string(10 - tipo.length(), '   ') +
                           categoria + string(15 - categoria.length(), '  ') +
                           descripcion + string(20 - descripcion.length(), ' ') +
                           fecha + string(15 - fecha.length(), ' ') +
                           id;

            centrarLinea(linea);
            montoTotal += monto.getIngreso();
        }

        // Pie del reporte
        centrarLinea("------------------------------------------------------------");
        string total = "MONTO TOTAL: " + to_string(montoTotal) + " soles";
        centrarLinea(total);
        centrarLinea("------------------------------------------------------------");
    }
}

void Sistema::registrarMovimiento() {

    float ingreso;
    string tipoIngreso, descripcion, fecha; 
	string id = Montos::generarID(); 
	

    cout << "\n=== REGISTRAR MOVIMIENTO ===\n";
    cout << "Ingrese el monto: ";
	    while (!(cin >> ingreso)) {
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Entrada invalida. Intente nuevamente: ";
	    }
    	cin.ignore(); 

    cout << "Ingrese el tipo: ";
    getline(cin, tipoIngreso);

    cout << "Ingrese una descripcion: ";
    getline(cin, descripcion);

	fecha = Montos::obtenerFechaActual();
	 
	
	Montos nuevoMonto(ingreso, tipoIngreso, descripcion, fecha, id);
	vector<Montos> nuevoVector = {nuevoMonto};
	GestorArchivos::guardarDatos(nuevoVector, "montos.txt");
    
    

    cout << "Movimiento registrado correctamente.\n";
}



void Sistema::modificarMovimiento(string idBuscado) {

    ifstream archivoEntrada("montos.txt");
    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    vector<Montos> montos;
    string linea;
    bool encontrado = false;

    while (getline(archivoEntrada, linea)) {
        istringstream ss(linea);
        string ingresoStr, tipoIngreso, descripcion, fecha, id;

        getline(ss, ingresoStr, ',');
        getline(ss, tipoIngreso, ',');
        getline(ss, descripcion, ',');
        getline(ss, fecha, ',');
        getline(ss, id, ',');

        float ingreso = stof(ingresoStr); 

        if (id == idBuscado && !encontrado) {  
          
            encontrado = true;
            cout << "Ingrese el nuevo monto: ";
            while (!(cin >> ingreso)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Intente nuevamente: ";
            }
            cin.ignore();

            cout << "Ingrese el nuevo tipo de ingreso: ";
            getline(cin, tipoIngreso);

            cout << "Ingrese la nueva descripción: ";
            getline(cin, descripcion);

            // El ID y la fecha se mantienen iguales
        }

        // Guardar en el vector
        montos.emplace_back(ingreso, tipoIngreso, descripcion, fecha, id);
    }
    archivoEntrada.close();

    if (!encontrado) {
        cout << "No se encontró un movimiento con ese ID.\n";
        return;
    }

    ofstream archivoSalida("montos.txt");
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return;
    }

    for (const auto& monto : montos) {
        archivoSalida << monto.getIngreso() << ","
                      << monto.getTipoIngreso() << ","
                      << monto.getDescripcion() << ","
                      << monto.getFecha() << "," 
                      << monto.getID() << endl;   
    }
    archivoSalida.close();

    cout << "Movimiento modificado correctamente.\n";
}

void Sistema::eliminarMovimiento(string idBuscado){
	ifstream archivoEntrada("montos.txt");
    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    vector<string> lineas;
    string linea, monto, categoria, descripcion, fecha, id;
    bool encontrado = false;

    while (getline(archivoEntrada, linea)) {
        istringstream ss(linea);
        vector<string> datos;
        string dato;

        while (getline(ss, dato, ',')) {
            datos.push_back(dato);
        }

        if (datos.size() == 5) {
            id = datos[4];

            if (id == idBuscado) {
                encontrado = true;
                continue;
            }

            lineas.push_back(linea);
        }
    }

    archivoEntrada.close();

    if (!encontrado) {
        cout << "ID no encontrado. No se eliminó ningún movimiento.\n";
        return;
    }

    ofstream archivoSalida("montos.txt");
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return;
    }

    for (const auto& l : lineas) {
        archivoSalida << l << endl;
    }
    
    archivoSalida.close();
    cout << "Movimiento con ID " << idBuscado << " eliminado correctamente.\n";
	
}
