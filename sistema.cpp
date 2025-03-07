#include "sistema.h"
#include "montos.h"
#include "gestorArchivos.h"
#include <vector>
#include <string> 
#include <limits>
#include <iostream>
#include <iomanip>

using namespace std; 

void Sistema::mostrarReporteGeneral() {

    vector<Montos> montos = GestorArchivos::cargarDatos("montos.txt");

    if (montos.empty()) {
        cout << "No hay movimientos registrados.\n";
    } else {
        float montoTotal = 0;
        cout << "\n=== REPORTE GENERAL ===\n";
        cout << "------------------------------------------------------------\n";
        cout << setw(10) << "TIPO" << setw(15) << "CATEGORIA" << setw(20) << "DESCRIPCION"
             << setw(15) << "FECHA" << setw(10) << "ID" << endl;
        cout << "------------------------------------------------------------\n";

        for (const auto& monto : montos) {
            cout << setw(10) << (monto.getIngreso() >= 0 ? "INGRESO" : "GASTO")
                 << setw(15) << monto.getTipoIngreso()
                 << setw(20) << monto.getDescripcion()
                 << setw(15) << monto.getFecha()
                 << setw(10) << monto.getID() << endl;
            montoTotal += monto.getIngreso();
        }

        cout << "------------------------------------------------------------\n";
        cout << "MONTO TOTAL: " << fixed << setprecision(2) << montoTotal << " soles\n";
        cout << "------------------------------------------------------------\n";
    }
}

void Sistema::registrarMovimiento() {
    // Solicitar datos al usuario
    float ingreso;
    string tipoIngreso, descripcion, id, fecha; 

    cout << "\n=== REGISTRAR MOVIMIENTO ===\n";
    cout << "Ingrese el monto: ";
	    while (!(cin >> ingreso)) {
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Entrada invalida. Intente nuevamente: ";
	    }
    	cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese el tipo: ";
    getline(cin, tipoIngreso);

    cout << "Ingrese una descripcion: ";
    getline(cin, descripcion);

	fecha = Montos::obtenerFechaActual();
	id = Montos::generarID(); 
	

    // Crear un objeto Montos y guardarlo
    Montos nuevoMonto(ingreso, tipoIngreso, descripcion, fecha, id);
    vector<Montos> montos = GestorArchivos::cargarDatos("montos.txt");
    montos.emplace_back(nuevoMonto);
    GestorArchivos::guardarDatos(montos, "montos.txt");

    cout << "Movimiento registrado correctamente.\n";
}

