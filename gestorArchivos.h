#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

using namespace std;

#include "montos.h"
#include <vector>

class GestorArchivos {
public:
    static vector<Montos> cargarDatos(const string& archivo);
    static void guardarDatos(const vector<Montos>& montos, const string& archivo);

};

#endif // GESTORARCHIVOS_H