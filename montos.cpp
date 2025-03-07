#include "montos.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std; 


Montos::Montos(float ingreso_, const string& tipoIngreso_, const string& descripcion_, const string& fecha_, const string& id_){
				 ingreso = ingreso_;  
				 tipoIngreso = tipoIngreso_; 
				 fecha = fecha_; 
				 ID = id_; 
				 descripcion = descripcion_;
}


string Montos::generarID(){
	char letra = 'A' + rand()% 26; 
	int n1, n2, n3; 
	
	n1 = rand() % 10;
	n2 = rand() % 10;
	n3 = rand() % 10;
	
	string id = "";
    id += letra;
    id += to_string(n1);
    id += to_string(n2);
    id += to_string(n3);

    return id;	
}

string Montos::obtenerFechaActual(){
	time_t tiempo_actual = time(NULL);
    tm* ahora_local = localtime(&tiempo_actual);

    char arreglo_hora[100];
    strftime(arreglo_hora, sizeof(arreglo_hora), "%d/%m/%Y %H:%M:%S", ahora_local);
    
    return string(arreglo_hora);
}