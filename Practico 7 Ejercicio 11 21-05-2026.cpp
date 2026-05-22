#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void leerMonto(double &R){
    cout << "Ingrese el monto en Bs: ";
    cin >> R;
}

string UNIDADES(int n){
    switch(n){
        case 1: return "un";
        case 2: return "dos";
        case 3: return "tres";
        case 4: return "cuatro";
        case 5: return "cinco";
        case 6: return "seis";
        case 7: return "siete";
        case 8: return "ocho";
        case 9: return "nueve";
        default: return "";
    }
}

string DECENAS(int n){
    if(n < 10){
        return UNIDADES(n);
    }

    switch(n){
        case 10: return "diez";
        case 11: return "once";
        case 12: return "doce";
        case 13: return "trece";
        case 14: return "catorce";
        case 15: return "quince";
        case 16: return "dieciseis";
        case 17: return "diecisiete";
        case 18: return "dieciocho";
        case 19: return "diecinueve";
        case 20: return "veinte";
        case 21: return "veintiun";
        case 22: return "veintidos";
        case 23: return "veintitres";
        case 24: return "veinticuatro";
        case 25: return "veinticinco";
        case 26: return "veintiseis";
        case 27: return "veintisiete";
        case 28: return "veintiocho";
        case 29: return "veintinueve";
    }

    int decena = n / 10;
    int unidad = n % 10;
    string texto;

    switch(decena){
        case 3: texto = "treinta"; break;
        case 4: texto = "cuarenta"; break;
        case 5: texto = "cincuenta"; break;
        case 6: texto = "sesenta"; break;
        case 7: texto = "setenta"; break;
        case 8: texto = "ochenta"; break;
        case 9: texto = "noventa"; break;
    }

    if(unidad > 0){
        texto = texto + " y " + UNIDADES(unidad);
    }

    return texto;
}

string CENTENAS(int n){
    if(n < 100){
        return DECENAS(n);
    }

    if(n == 100){
        return "cien";
    }

    int centena = n / 100;
    int resto = n % 100;
    string texto;

    switch(centena){
        case 1: texto = "ciento"; break;
        case 2: texto = "doscientos"; break;
        case 3: texto = "trescientos"; break;
        case 4: texto = "cuatrocientos"; break;
        case 5: texto = "quinientos"; break;
        case 6: texto = "seiscientos"; break;
        case 7: texto = "setecientos"; break;
        case 8: texto = "ochocientos"; break;
        case 9: texto = "novecientos"; break;
    }

    if(resto > 0){
        texto = texto + " " + DECENAS(resto);
    }

    return texto;
}

void LITERAL(double R, string &literal, int &centavos, bool &valido){

    int entero;

    if(R < 0 || R > 9999.99){
        valido = false;
        literal = "";
        centavos = 0;
    } else {
        valido = true;

        entero = int(R);
        centavos = round((R - entero) * 100);

        if(centavos == 100){
            entero = entero + 1;
            centavos = 0;
        }

        if(entero == 0){
            literal = "cero";
        }
        else if(entero < 1000){
            literal = CENTENAS(entero);
        }
        else {
            int miles = entero / 1000;
            int resto = entero % 1000;

            if(miles == 1){
                literal = "un mil";
            } else {
                literal = UNIDADES(miles) + " mil";
            }

            if(resto > 0){
                literal = literal + " " + CENTENAS(resto);
            }
        }
    }
}

void mostrarResultado(double R, string literal, int centavos, bool valido){

    cout << fixed << setprecision(2);
    cout << "\nEl monto registrado es: Bs " << R << endl;

    if(valido == false){
        cout << "No se puede convertir el monto." << endl;
        cout << "Debe ingresar un numero entre 0 y 9999.99" << endl;
    } else {
        cout << "\nMonto en literal:" << endl;
        cout << literal << " ";

        if(centavos < 10){
            cout << "0";
        }

        cout << centavos << "/100 bolivianos" << endl;
    }
}

int main(){

    double R;
    string literal;
    int centavos;
    bool valido;

    leerMonto(R);

    LITERAL(R, literal, centavos, valido);

    mostrarResultado(R, literal, centavos, valido);

    return 0;
}
