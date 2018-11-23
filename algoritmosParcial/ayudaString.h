#ifndef AYUDASTRING_H_INCLUDED
#define AYUDASTRING_H_INCLUDED

#include <stdio.h>
#include <string.h>

using namespace std;

void ingreseoVecChar()
{
    cout << "escriba algo: ";
    char palabra[200];
    cin.getline( palabra, 200 );
    cout << "usted escribio: " << palabra << endl;
    cout << endl;

//    cout << "escriba algo: ";
//    string cadena;
//    cin >> cadena;
//    strncpy( palabra, cadena.c_str(), 200 );// no funco piola
//    cout << "usted escribio: " << palabra << endl;
//    cout << endl;
}

#endif // AYUDASTRING_H_INCLUDED
