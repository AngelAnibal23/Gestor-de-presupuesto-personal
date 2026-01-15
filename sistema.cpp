#include "sistema.h"
#include "montos.h"
#include "gestorArchivos.h"
#include <vector>
#include <string> 
#include <limits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "disenoReporte.cpp"

using namespace std; 		


void Sistema::mostrarReporteGeneral() {
    vector<Montos> montos = GestorArchivos::cargarDatos("montos.txt");

    if (montos.empty()) {
        cout << "No hay movimientos registrados.\n";
        return;
    }

    // Anchos de columnas (ajústalos a tu gusto)
    const int wMonto = 12;
    const int wCat   = 20;
    const int wDesc  = 28;
    const int wFecha = 10; // dd/mm/yyyy
    const int wId    = 6;

    cout << "====================== REPORTE GENERAL ======================\n";

    imprimirLinea(wMonto, wCat, wDesc, wFecha, wId);
    imprimirFila("MONTO", "CATEGORIA", "DESCRIPCION", "FECHA", "ID",
                 wMonto, wCat, wDesc, wFecha, wId);
    imprimirLinea(wMonto, wCat, wDesc, wFecha, wId);

    float total = 0.0;

    for (const auto& m : montos) {
        string montoStr = formatearSoles(m.getIngreso());
        imprimirFila(montoStr, m.getTipoIngreso(), m.getDescripcion(),
                     m.getFecha(), m.getID(),
                     wMonto, wCat, wDesc, wFecha, wId);
        total += m.getIngreso();
    }

    imprimirLinea(wMonto, wCat, wDesc, wFecha, wId);

    // Fila de total (alineada y bonita)
    string totalStr = formatearSoles(total);
    cout << "| " << right << setw(wMonto) <<  total
         << " | " << left  << setw(wCat)   << ""
         << " | " << left  << setw(wDesc)  << ""
         << " | " << left  << setw(wFecha) << ""
         << " | " << left  << setw(wId)    << truncar(totalStr, wId)
         << " |\n";

    imprimirLinea(wMonto, wCat, wDesc, wFecha, wId);
}

void Sistema::registrarMovimiento() {
try {
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
    catch (const std::exception& e) {
        cout << "EXCEPCION: " << e.what() << "\n";
        system("PAUSE");
    }
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
