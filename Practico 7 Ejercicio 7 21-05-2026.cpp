#include <iostream>
using namespace std;

void leerDatos(int &n, int &r){
    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "Ingrese el valor de r: ";
    cin >> r;
}

long long FAC(int n){
    long long factorial = 1;

    for(int i = 1; i <= n; i++){
        factorial = factorial * i;
    }

    return factorial;
}

void COMBI(int n, int r, double &C, bool &valido){

    if(n < 0 || r < 0 || r > n){
        valido = false;
        C = 0;
    } else {
        C = FAC(n) / (FAC(r) * FAC(n - r));
        valido = true;
    }
}

void mostrarResultado(int n, int r, double C, bool valido){

    cout << "\nNumero combinatorio registrado:" << endl;
    cout << "n = " << n << endl;
    cout << "r = " << r << endl;

    if(valido == false){
        cout << "\nNo se puede calcular el combinatorio." << endl;
        cout << "Recuerde que n y r deben ser positivos, y r no puede ser mayor que n." << endl;
    } else {
        cout << "\nEl resultado del combinatorio es:" << endl;
        cout << "C = " << C << endl;
    }
}

int main(){

    int n, r;
    double C;
    bool valido;

    leerDatos(n, r);

    COMBI(n, r, C, valido);

    mostrarResultado(n, r, C, valido);

    return 0;
}
