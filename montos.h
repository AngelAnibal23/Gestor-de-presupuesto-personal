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
		float general; 
		Montos(float ing, string tipo, string f, string id)  : ingreso(ing), tipoIngreso(tipo), fecha(f), ID(id) {}
	    float getIngreso() const { return ingreso; }
	    string getTipoIngreso() const { return tipoIngreso; }
	    string getFecha() const { return fecha; }
	    string getID();
	    float actualizarGeneral(float ingreso){
	    	general += ingreso;  
		}
};

#endif // MONTOS_H