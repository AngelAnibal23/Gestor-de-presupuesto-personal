#include "gestorArchivos.h"
using namespace std; 

#include "montos.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

/*
void GestorArchivos::guardarDatos(const vector<Montos>& montos){
	
}
*/


vector<Montos> GestorArchivos::cargarDatos(const string& archivo){
	vector<Montos> montos; 
	ifstream file(archivo);
	string linea; 
	while(getline(file, linea)){
		istringstream iss(linea); 
		float ingreso; 
		string tipoIngreso, string fecha, string ID; 
		if (getline(iss, ingreso, ',') && getline(iss, tipoIngreso) && getline(iss, fecha, ',') && getline(iss, ID)) {
            montos.emplace_back(ingreso, tipoIngreso, fecha, ID); 
        }
	}
	
	return montos; 
}