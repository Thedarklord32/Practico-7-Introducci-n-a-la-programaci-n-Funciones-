#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void leerDatos(double &a, double &b, double &c){
    cout << "Ingrese el valor de a: ";
    cin >> a;

    cout << "Ingrese el valor de b: ";
    cin >> b;

    cout << "Ingrese el valor de c: ";
    cin >> c;
}

void CUADRATICA(double a, double b, double c,
                double &x1, double &x2,
                double &parteReal, double &parteImaginaria,
                string &tipo){

    double discriminante;

    if(a == 0){
        if(b == 0){
            if(c == 0){
                tipo = "Infinitas soluciones";
            } else {
                tipo = "Sin solucion";
            }
        } else {
            x1 = -c / b;
            tipo = "Ecuacion lineal";
        }
    } else {
        discriminante = pow(b, 2) - 4 * a * c;

        if(discriminante > 0){
            x1 = (-b + sqrt(discriminante)) / (2 * a);
            x2 = (-b - sqrt(discriminante)) / (2 * a);
            tipo = "Dos raices reales";
        }
        else if(discriminante == 0){
            x1 = -b / (2 * a);
            x2 = x1;
            tipo = "Raiz doble";
        }
        else {
            parteReal = -b / (2 * a);
            parteImaginaria = sqrt(-discriminante) / (2 * a);
            tipo = "Dos raices complejas";
        }
    }
}

void mostrarResultado(double a, double b, double c,
                      double x1, double x2,
                      double parteReal, double parteImaginaria,
                      string tipo){

    cout << "\nLa ecuacion registrada es:" << endl;
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    cout << "\nTipo de solucion: " << tipo << endl;

    if(tipo == "Dos raices reales"){
        cout << "\nLas raices son:" << endl;
        cout << "X1 = " << x1 << endl;
        cout << "X2 = " << x2 << endl;
    }
    else if(tipo == "Raiz doble"){
        cout << "\nLa raiz doble es:" << endl;
        cout << "X1 = X2 = " << x1 << endl;
    }
    else if(tipo == "Dos raices complejas"){
        cout << "\nLas raices complejas son:" << endl;
        cout << "X1 = " << parteReal << " + " << parteImaginaria << "i" << endl;
        cout << "X2 = " << parteReal << " - " << parteImaginaria << "i" << endl;
    }
    else if(tipo == "Ecuacion lineal"){
        cout << "\nNo es ecuacion cuadratica, es lineal." << endl;
        cout << "La solucion es: X = " << x1 << endl;
    }
    else if(tipo == "Infinitas soluciones"){
        cout << "\nLa ecuacion tiene infinitas soluciones." << endl;
    }
    else {
        cout << "\nLa ecuacion no tiene solucion." << endl;
    }
}

int main(){

    double a, b, c;
    double x1, x2;
    double parteReal, parteImaginaria;
    string tipo;

    leerDatos(a, b, c);

    CUADRATICA(a, b, c, x1, x2, parteReal, parteImaginaria, tipo);

    mostrarResultado(a, b, c, x1, x2, parteReal, parteImaginaria, tipo);

    return 0;
}
