#include <iostream>
#include <cmath>
using namespace std;

void leerDatos(double &R, int &n){
    cout << "Ingrese un numero real: ";
    cin >> R;

    cout << "Ingrese la cantidad de decimales: ";
    cin >> n;
}

double REDONDEAR(double R, int n){
    double factor;
    double resultado;

    factor = pow(10, n);

    resultado = round(R * factor) / factor;

    return resultado;
}

void mostrarResultado(double R, int n, double resultado){

    cout << "\nEl numero registrado es: " << R << endl;
    cout << "Cantidad de decimales: " << n << endl;

    cout << "\nNumero redondeado:" << endl;
    cout << resultado << endl;
}

int main(){

    double R;
    double resultado;
    int n;

    leerDatos(R, n);

    resultado = REDONDEAR(R, n);

    mostrarResultado(R, n, resultado);

    return 0;
}
