#include <iostream>

using namespace std;

int main()
{
    int p_int; float p_dc;
    cout << "\n INGRESE PARTE ENTERA: "; cin >> p_int;
    cout << "\n INGRESE PARTE DECIMAL (0.DECIMAL): "; cin >> p_dc;

    //CONVERSION DE LA PARTE ENTERA A BINARIO
    string int_bin;
    while (p_int != 0) {
        if (p_int % 2 == 0) {
            int_bin = "0" + int_bin;
        }
        else {
            int_bin = "1" + int_bin;
        }
        p_int = p_int / 2;
    }
    cout << "\n PARTE ENTERA A BINARIO: " << int_bin;

    //CONVERSION DE LA DECIMAL A BINARIO
    int dec_bin[23];
    int reset = 1;
    for (int i = 0; i < 23; i++) {
        p_dc *= 2;
        if (p_dc >= 1) {
            dec_bin[i] = 1;
            p_dc = p_dc - reset;
        }
        else {
            dec_bin[i] = 0;
        }
    }
    cout << "\n PARTE DECIMAL A BINARIO: ";
    for (int i = 0; i < 23; i++){
        cout << dec_bin[i];
    }

    //NUMERO BINARIO COMPLETO (NO NORMALIZADO)
    cout << "\n BINARIO COMPLETO: " << int_bin << " . ";
    for (int i = 0; i < 23; i++) {
        cout << dec_bin[i];
    }

    //CORRER COMA A BIT DE SIGNO
    int contador;
    contador = int_bin.size();
    cout << "\n TAMANO DEL ENTERO: " << contador;
    //para el corrimiento de la coma, debe ser tamaño de bit - el bit de signo
    int coma;
    coma = contador - 1;
    cout << "\n LA COMA CORRIO: " << coma << " ESPACIOS";

    //BORRAR EL PRIMER BIT
    int_bin.erase(0, 1);
    cout << "\n SIN EL PRIMER BIT: " << int_bin;

    //OPERAR EL BIASED EXPONENT
    int b_exp;
    b_exp = 127 + coma;
    string b_exponent;
    while (b_exp != 0) {
        if (b_exp % 2 == 0) {
            b_exponent = "0" + b_exponent;
        }
        else {
            b_exponent = "1" + b_exponent;
        }
        b_exp = b_exp / 2;
    }
    cout << "\n REPRESENTACION BIASED " << b_exponent;

    //positivo o negativo
    int bit_signo;
    if (p_int >= 1) {
        bit_signo = 0;
    }
    else {
        bit_signo = 0;
    }

    int n = 24 - contador;
    //NUMERO BINARIO COMPLETO (NORMALIZADO)
    cout << "\n NUMERO BINARIO COMPLETO : ";
    cout << bit_signo << " " << b_exponent << " " << int_bin;
    for (int i = 0; i < n; i++) {
        cout << dec_bin[i];
    }
}
