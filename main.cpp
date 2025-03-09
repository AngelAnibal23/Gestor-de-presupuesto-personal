#include <iostream>
#include <vector>
#include "montos.h"
#include "gestorArchivos.h"
#include "sistema.h"

using namespace std;

int main() {
    vector<Montos> montos = GestorArchivos::cargarDatos("montos.txt");

    int opcion;
    string idBuscado;

    do {
        cout << "------------GESTOR DE FINANZAS PERSONAL------------" << endl;
        cout << " [1] Mostrar reporte general. " << endl;
        cout << " [2] Registrar movimiento. " << endl;
        cout << " [3] Editar movimiento. " << endl;
        cout << " [4] Eliminar movimiento. " << endl;
        cout << " [0] Cerrar el gestor. " << endl;
        cout << " .Digite su eleccion: ";
        cin >> opcion;
    	system("cls"); 

        switch (opcion) {
            case 1: {
                Sistema::mostrarReporteGeneral();
                system("PAUSE"); 
                system("cls"); 
                break;
            }
            case 2: {
                Sistema::registrarMovimiento();
                system("PAUSE"); 
                system("cls"); 
                break;
            }
            case 3: {
            	Sistema::mostrarReporteGeneral();
            	
			    cout << "Digite el ID del movimiento por editar: ";
			    cin.ignore();
			    getline(cin, idBuscado);
			    	
	        	Sistema::modificarMovimiento(idBuscado); 
	        	system("PAUSE"); 
                system("cls"); 
                break;
            }
            case 4: {
                Sistema::mostrarReporteGeneral();
                
                cout << "Digite el ID del movimiento por eliminar: ";
			    cin.ignore();
			    getline(cin, idBuscado);
                
                Sistema::eliminarMovimiento(idBuscado);
                system("PAUSE"); 
                system("cls"); 
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