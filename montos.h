#ifndef MONTOS_H
#define MONTOS_H
#include <string>

using namespace std;

class Montos {
private:
    float ingreso;
    string tipoIngreso;
    string fecha;
    string ID;
    string descripcion;

public:
    float general = 0;
    Montos() : ingreso(0), tipoIngreso(""), fecha(""), ID(""), descripcion("") {}
    Montos(float ingreso, const string& tipoIngreso, const string& descripcion, const string& fecha, const string& id);
    float getIngreso() const { return ingreso; }
    static string obtenerFechaActual();
    static string generarID();
    string getTipoIngreso() const { return tipoIngreso; }
    string getFecha() const { return fecha; }
    string getDescripcion() const { return descripcion; }
    float getGeneral() const { return general; }
    string getID() const { return ID; }
    void actualizarGeneral(float ingreso) {
        general += ingreso;
    }
};

#endif // MONTOS_H