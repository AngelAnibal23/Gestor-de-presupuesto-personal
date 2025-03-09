#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>

#include "montos.h"
#include "gestorArchivos.h"

using namespace std;

class Sistema{
	public: 
		static void mostrarReporteGeneral(); 
		static void registrarMovimiento(); 
		static void modificarMovimiento(string idBuscado); 
		static void eliminarMovimiento(string idBuscado); 
};

#endif // SISTEMA_H

