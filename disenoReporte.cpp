#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std; 

// Helpers seguros para “tabla bonita”
static string repetir(char c, int n) {
    return string((n > 0) ? n : 0, c);
}

static string truncar(const string& s, size_t w) {
    if (s.size() <= w) return s;
    if (w <= 3) return s.substr(0, w);
    return s.substr(0, w - 3) + "...";
}

static string formatearSoles(float x) {
    ostringstream oss;
    oss << "S/. " << fixed << setprecision(2) << x;
    return oss.str();
}

static void imprimirLinea(int wMonto, int wCat, int wDesc, int wFecha, int wId) {
    cout << '+'
         << repetir('-', wMonto + 2) << '+'
         << repetir('-', wCat   + 2) << '+'
         << repetir('-', wDesc  + 2) << '+'
         << repetir('-', wFecha + 2) << '+'
         << repetir('-', wId    + 2) << '+'
         << "\n";
}

static void imprimirFila(const string& monto, const string& cat, const string& desc,
                         const string& fecha, const string& id,
                         int wMonto, int wCat, int wDesc, int wFecha, int wId) {
    cout << "| " << right << setw(wMonto) << truncar(monto, wMonto)
         << " | " << left  << setw(wCat)   << truncar(cat, wCat)
         << " | " << left  << setw(wDesc)  << truncar(desc, wDesc)
         << " | " << left  << setw(wFecha) << truncar(fecha, wFecha)
         << " | " << left  << setw(wId)    << truncar(id, wId)
         << " |\n";
}
