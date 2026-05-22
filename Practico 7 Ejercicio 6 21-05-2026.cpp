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

void LITERAL(int dia, int mes, int anio, string &mesLiteral, int &anioCompleto){

    switch(mes){
        case 1: mesLiteral = "Enero"; break;
        case 2: mesLiteral = "Febrero"; break;
        case 3: mesLiteral = "Marzo"; break;
        case 4: mesLiteral = "Abril"; break;
        case 5: mesLiteral = "Mayo"; break;
        case 6: mesLiteral = "Junio"; break;
        case 7: mesLiteral = "Julio"; break;
        case 8: mesLiteral = "Agosto"; break;
        case 9: mesLiteral = "Septiembre"; break;
        case 10: mesLiteral = "Octubre"; break;
        case 11: mesLiteral = "Noviembre"; break;
        case 12: mesLiteral = "Diciembre"; break;
        default: mesLiteral = "Mes invalido";
    }

    if(anio < 100){
        anioCompleto = 1900 + anio;
    } else {
        anioCompleto = anio;
    }
}

void mostrarFecha(int dia, int mes, int anio, string mesLiteral, int anioCompleto){

    cout << "\nLa fecha que registro es: " << dia << "/" << mes << "/" << anio << endl;

    cout << "\nFecha en formato literal:" << endl;

    if(mesLiteral == "Mes invalido"){
        cout << "No se puede mostrar la fecha porque el mes es invalido." << endl;
    } else {
        cout << dia << " de " << mesLiteral << " de " << anioCompleto << endl;
    }
}

int main(){

    int dia, mes, anio;
    int anioCompleto;
    string mesLiteral;

    leerFecha(dia, mes, anio);

    LITERAL(dia, mes, anio, mesLiteral, anioCompleto);

    mostrarFecha(dia, mes, anio, mesLiteral, anioCompleto);

    return 0;
}
