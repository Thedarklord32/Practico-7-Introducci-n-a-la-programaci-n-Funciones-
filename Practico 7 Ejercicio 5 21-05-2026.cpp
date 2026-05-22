#include <iostream>
using namespace std;

void leerCoeficientes(double &A, double &B, double &C,
                      double &D, double &E, double &F){

    cout << "Ingrese A: ";
    cin >> A;

    cout << "Ingrese B: ";
    cin >> B;

    cout << "Ingrese C: ";
    cin >> C;

    cout << "Ingrese D: ";
    cin >> D;

    cout << "Ingrese E: ";
    cin >> E;

    cout << "Ingrese F: ";
    cin >> F;
}

void SISTEMA(double A, double B, double C,
             double D, double E, double F,
             double &X, double &Y, bool &tieneSolucion){

    double determinante;

    determinante = A * E - B * D;

    if(determinante == 0){
        tieneSolucion = false;
    } else {
        X = (B * F - C * E) / determinante;
        Y = (C * D - A * F) / determinante;
        tieneSolucion = true;
    }
}

void mostrarResultado(double A, double B, double C,
                      double D, double E, double F,
                      double X, double Y, bool tieneSolucion){

    cout << "\nEl sistema registrado es:" << endl;
    cout << A << "x + " << B << "y + " << C << " = 0" << endl;
    cout << D << "x + " << E << "y + " << F << " = 0" << endl;

    if(tieneSolucion == false){
        cout << "\nEl sistema no tiene solucion unica." << endl;
    } else {
        cout << "\nLa solucion del sistema es:" << endl;
        cout << "X = " << X << endl;
        cout << "Y = " << Y << endl;
    }
}

int main(){

    double A, B, C, D, E, F;
    double X, Y;
    bool tieneSolucion;

    leerCoeficientes(A, B, C, D, E, F);

    SISTEMA(A, B, C, D, E, F, X, Y, tieneSolucion);

    mostrarResultado(A, B, C, D, E, F, X, Y, tieneSolucion);

    return 0;
}
