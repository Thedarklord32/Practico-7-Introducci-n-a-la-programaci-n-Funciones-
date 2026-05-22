#include <iostream>
using namespace std;

void leerNumero(int &N){
    cout << "Ingrese un numero entero: ";
    cin >> N;
}

void ROMANO(int N, string &romano, bool &valido){

    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    romano = "";

    if(N <= 0 || N > 3999){
        valido = false;
    } else {
        valido = true;

        for(int i = 0; i < 13; i++){
            while(N >= valores[i]){
                romano = romano + simbolos[i];
                N = N - valores[i];
            }
        }
    }
}

void mostrarResultado(int N, string romano, bool valido){

    cout << "\nEl numero registrado es: " << N << endl;

    if(valido == false){
        cout << "No se puede convertir a numeros romanos." << endl;
        cout << "Debe ingresar un numero entre 1 y 3999." << endl;
    } else {
        cout << "Su equivalente en numeros romanos es: " << romano << endl;
    }
}

int main(){

    int N;
    string romano;
    bool valido;

    leerNumero(N);

    ROMANO(N, romano, valido);

    mostrarResultado(N, romano, valido);

    return 0;
}
