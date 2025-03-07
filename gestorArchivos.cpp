#include "gestorArchivos.h"
#include "montos.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iostream>
#include <string>

using namespace std; 


void GestorArchivos::guardarDatos(const vector<Montos>& montos, const string& archivo){
	ofstream file(archivo, ios::out);  // Abre el archivo en modo escritura

    if (!file) {
        cerr << "Error al abrir el archivo para escritura: " << archivo << endl;
        return;
    }

    for (const auto& monto : montos) {
        file << monto.getIngreso() << ","
             << monto.getTipoIngreso() << "\n";
            // << monto.getFecha() << ","
            // << monto.getID() << 
    }

    file.close();
    cout << "Datos guardados correctamente en " << archivo << endl;	
}



vector<Montos> GestorArchivos::cargarDatos(const string& archivo){
	vector<Montos> montos; 
	ifstream file(archivo);
	string linea; 
	while(getline(file, linea)){
		istringstream iss(linea); 
		string ingreso, tipoIngreso, fecha, ID; 
		if (getline(iss, ingreso, ',') && getline(iss, tipoIngreso) && getline(iss, fecha, ',') && getline(iss, ID)) {
    		float convert = stof(ingreso);
			
            montos.emplace_back(convert, tipoIngreso, fecha, ID);  //mandando los datos al constructor de montos
        }
	}
	
	return montos; 
}