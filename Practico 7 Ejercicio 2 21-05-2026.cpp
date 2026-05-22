#include <iostream>
using namespace std;

void leerDatos(int &n) {
    cout << "Ingrese un numero entero positivo: ";
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

void mostrarResultado(int n, int resultado) {
    cout << "\nEl numero ingresado es: " << n << endl;
    cout << "\nResultado del factorial:" << endl;
    cout << n << "! = " << resultado << endl;
}

int main() {
    int n;
    int resultado;

    leerDatos(n);
    resultado = FAC(n);
    mostrarResultado(n, resultado);

    return 0;
}
