#ifndef MONTOS_H
#define MONTOS_H

using namespace std;

class Montos{
	private:
		float ingreso;
		string tipoIngreso; 
		string fecha; 
		string ID; 
	public: 
		Montos(float ing, string tipo, string f, string id)  : ingreso(ing), tipoIngreso(tipo), fecha(f), ID(id) {}
	

	    float getIngreso() const { return ingreso; }
	    string getTipoIngreso() const { return tipoIngreso; }
	    string getFecha() const { return fecha; }
	    string getID() const { return ID; }
	    void setIngreso(float ing) { ingreso = ing; }
	    void setTipoIngreso(string tipo) { tipoIngreso = tipo; }
	    void setFecha(string f) { fecha = f; }
	    void setID(string id) { ID = id; }
	    void mostrarMontos() const {
	        cout << "ID: " << ID << "\n"
	             << "Fecha: " << fecha << "\n"
	             << "Tipo de Ingreso: " << tipoIngreso << "\n"
	             << "Monto: " << ingreso << " soles" << endl;
	    }
};

#endif // MONTOS_H