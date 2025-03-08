#include "sistema.h"
#include "montos.h"
#include "gestorArchivos.h"
#include <vector>
#include <string> 
#include <limits>
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
        centrarLinea("=== REPORTE GENERAL ===");
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

            string linea = tipo + string(10 - tipo.length(), '    ') +
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
	
	Montos nuevoMonto(ingreso, tipoIngreso, descripcion, fecha, id);
	vector<Montos> nuevoVector = {nuevoMonto}; // Solo guarda el nuevo registro
	GestorArchivos::guardarDatos(nuevoVector, "montos.txt");
    
    

    cout << "Movimiento registrado correctamente.\n";
}

