#include "gestorArchivos.h"
#include "montos.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iostream>
#include <string>

using namespace std; 


void GestorArchivos::guardarDatos(const vector<Montos>& montos, const string& archivo){
	ofstream file(archivo, ios::app);  // Abre el archivo en modo escritura

    if (!file) {
        cerr << "Error al abrir el archivo para escritura: " << archivo << endl;
        return;
    }

    for (const auto& monto : montos) {
        file << monto.getIngreso() << ","
             << monto.getTipoIngreso() << ","
             << monto.getDescripcion() << ","
             << monto.getFecha() << "," 
             << monto.getID() << "\n";
    }

    file.close();
    cout << "Datos guardados correctamente en " << archivo << endl;	
}



vector<Montos> GestorArchivos::cargarDatos(const string& archivo) {
    vector<Montos> montos;
    ifstream file(archivo);

    if (!file) {
        cerr << "Error al abrir el archivo.\n";
        return montos;
    }

    string linea;
    while (getline(file, linea)) {
        istringstream iss(linea);
        string ingresoStr, tipoIngreso, descripcion, fecha, ID;

        if (getline(iss, ingresoStr, ',') &&
            getline(iss, tipoIngreso, ',') &&
            getline(iss, descripcion, ',') &&  // Asegúrate de leer la descripción correctamente
            getline(iss, fecha, ',') &&
            getline(iss, ID)) {

            try {
                float ingreso = stof(ingresoStr);
                montos.emplace_back(ingreso, tipoIngreso, descripcion, fecha, ID);
            } catch (const exception& e) {
                cerr << "Error al convertir el monto: " << e.what() << endl;
            }
        } else {
            cerr << "Error al leer línea del archivo: " << linea << endl;
        }
    }

    file.close();
    return montos;
}