#include <iostream>
using namespace std;

void leerFecha(int &dia, int &mes, int &anio){
    cout << "Ingrese el dia: ";
    cin >> dia;

    cout << "Ingrese el mes: ";
    cin >> mes;

    cout << "Ingrese el anio: ";
    cin >> anio;
}

bool ESBISIESTO(int anio){
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
        return true;
    } else {
        return false;
    }
}

bool VALIDARFECHA(int dia, int mes, int anio){
    int diasMes;

    if(anio <= 0){
        return false;
    }

    if(mes < 1 || mes > 12){
        return false;
    }

    switch(mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            diasMes = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            diasMes = 30;
            break;

        case 2:
            if(ESBISIESTO(anio)){
                diasMes = 29;
            } else {
                diasMes = 28;
            }
            break;
    }

    if(dia < 1 || dia > diasMes){
        return false;
    } else {
        return true;
    }
}

void mostrarResultado(int dia, int mes, int anio, bool valida){

    cout << "\nLa fecha registrada es: " << dia << "/" << mes << "/" << anio << endl;

    if(valida == true){
        cout << "La fecha es valida." << endl;
    } else {
        cout << "La fecha no es valida." << endl;
    }
}

int main(){

    int dia, mes, anio;
    bool valida;

    leerFecha(dia, mes, anio);

    valida = VALIDARFECHA(dia, mes, anio);

    mostrarResultado(dia, mes, anio, valida);

    return 0;
}
