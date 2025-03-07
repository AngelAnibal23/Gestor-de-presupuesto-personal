#include <iostream>
#include <vector>
#include "montos.h"
#include "gestorArchivos.h"
#include "sistema.h"

using namespace std;

int main() {
    vector<Montos> montos = GestorArchivos::cargarDatos("montos.txt");

    int opcion;

    do {
        cout << "------------GESTOR DE FINANZAS PERSONAL------------" << endl;
        cout << " [1] Mostrar registro general. " << endl;
        cout << " [2] Registrar ingresos o gastos. " << endl;
        cout << " [3] Modificar algun monto. " << endl;
        cout << " [4] Filtrar por fecha. " << endl;
        cout << " [5] Filtrar por tipo de monto." << endl;
        cout << " .Digite su eleccion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Sistema::mostrarReporteGeneral();
                break;
            }
            case 2: {
                Sistema::registrarMovimiento();
                break;
            }
            case 3: {
                // Implementar modificación
                break;
            }
            case 4: {
                // Implementar filtrado por fecha
                break;
            }
            case 5: {
                // Implementar filtrado por tipo de monto
                break;
            }
            default: {
                cout << "Opcion no valida, vuelva a ingresar" << endl;
                break;
            }
        }

    } while (opcion != 0);

    return 0;
}