#include <iostream>
#include <cmath>
using namespace std;

void leerDatos(double &base, double &exponente) {
    cout << "Ingrese la base (x): ";
    cin >> base;
    cout << "Ingrese el exponente (y): ";
    cin >> exponente;
}

double POTEN(double x, double y) {
    if (y == 0) return 1.0;
    if (x == 0) return 0.0;

    int y_entero = (int)y;
    if (y == y_entero) {
        double resultado = 1.0;
        int exp_abs = abs(y_entero);
        for (int i = 0; i < exp_abs; i++) {
            resultado *= x;
        }
        return (y_entero >= 0) ? resultado : 1.0 / resultado;
    }

    if (x < 0) {
        cout << "Error: base negativa con exponente no entero." << endl;
        return 0.0;
    }
    return exp(y * log(x));
}

void mostrarResultado(double base, double exponente, double resultado) {
    cout << "\nLos valores ingresados son: " << base << " y " << exponente << endl;
    cout << "\nResultado de la potencia:" << endl;
    cout << base << " ^ " << exponente << " = " << resultado << endl;
}

int main() {
    double base, exponente;
    double resultado;

    leerDatos(base, exponente);
    resultado = POTEN(base, exponente);
    mostrarResultado(base, exponente, resultado);

    return 0;
}
