#ifndef MONTOS_H
#define MONTOS_H
#include <string>


using namespace std;

class Montos{
	private:
		float ingreso;
		string tipoIngreso; 
		string fecha; 
		string ID; 
	public: 
		float general = 0;
		Montos(){} 
		Montos(float ing, string tipo, string f, string id)  : ingreso(ing), tipoIngreso(tipo){
			fecha = obtenerFechaActual(); 
			ID = generarID(); 	
		}
	    float getIngreso() const { return ingreso; }
	    string obtenerFechaActual();
		string generarID();  
	    string getTipoIngreso() const { return tipoIngreso; }
	    string getFecha() const { return fecha; }
	    float getGeneral() const { return general; }
	    string getID() const { return ID; }
	    void actualizarGeneral(float ingreso){
	    	general += ingreso;  
		}
};

#endif // MONTOS_H