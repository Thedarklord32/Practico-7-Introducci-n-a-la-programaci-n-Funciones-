#include <iostream>
using namespace std;

void leerBinario(long long &binario){
    cout << "Ingrese un numero binario: ";
    cin >> binario;
}

int BINARIO_DECIMAL(long long binario){
    int decimal = 0;
    int base = 1;
    int digito;

    while(binario > 0){
        digito = binario % 10;

        decimal = decimal + digito * base;

        base = base * 2;

        binario = binario / 10;
    }

    return decimal;
}

void mostrarResultado(long long binario, int decimal){
    cout << "\nEl numero binario registrado es: " << binario << endl;
    cout << "Su equivalente decimal es: " << decimal << endl;
}

int main(){

    long long binario;
    int decimal;

    leerBinario(binario);

    decimal = BINARIO_DECIMAL(binario);

    mostrarResultado(binario, decimal);

    return 0;
}
