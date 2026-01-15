#include "montos.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <random>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std; 


Montos::Montos(float ingreso_, const string& tipoIngreso_, const string& descripcion_, const string& fecha_, const string& id_){
				 ingreso = ingreso_;  
				 tipoIngreso = tipoIngreso_; 
				 fecha = fecha_; 
				 ID = id_; 
				 descripcion = descripcion_;
}


string Montos::generarID(){
	 static std::mt19937 gen(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> distLetra(0, 25);
        std::uniform_int_distribution<int> distNumero(0, 999);
        
        char letra = 'A' + distLetra(gen);
        int numero = distNumero(gen);
        
        std::ostringstream oss;
        oss << letra << std::setfill('0') << std::setw(3) << numero;
        return oss.str();
}

string Montos::obtenerFechaActual() {
    time_t tiempo_actual = time(NULL);
    tm* ahora_local = localtime(&tiempo_actual);

    char arreglo_fecha[11];  
    strftime(arreglo_fecha, sizeof(arreglo_fecha), "%d/%m/%Y", ahora_local);
    
    return string(arreglo_fecha);
}