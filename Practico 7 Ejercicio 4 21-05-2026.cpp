#include <iostream>
using namespace std;

void leerDatos(int &x, int &n) {
    cout << "Ingrese el valor de X: ";
    cin >> x;
    cout << "Ingrese el valor de N (impar): ";
    cin >> n;
}

int FAC(int n) {
    if (n == 0 || n == 1) return 1;
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

double POTEN(int x, int y) {
    if (y == 0) return 1.0;
    double resultado = 1.0;
    for (int i = 0; i < y; i++) {
        resultado *= x;
    }
    return resultado;
}

double calcularSerie(int x, int n) {
    double suma = 0.0;
    int signo = 1;
    for (int i = 1; i <= n; i += 2) {
        suma += signo * (POTEN(x, i) / FAC(i));
        signo *= -1;
    }
    return suma;
}

void mostrarResultado(int x, int n, double suma) {
    cout << "\nLos valores ingresados son: X = " << x << ", N = " << n << endl;
    cout << "\nSuma de la serie:" << endl;
    cout << "S = ";
    int signo = 1;
    for (int i = 1; i <= n; i += 2) {
        if (i > 1) {
            if (signo == 1) cout << " + ";
            else cout << " - ";
        }
        cout << "(" << x << "^" << i << "/" << i << "!)";
        signo *= -1;
    }
    cout << "\nS = " << suma << endl;
}

int main() {
    int x, n;
    double suma;

    leerDatos(x, n);
    suma = calcularSerie(x, n);
    mostrarResultado(x, n, suma);

    return 0;
}
