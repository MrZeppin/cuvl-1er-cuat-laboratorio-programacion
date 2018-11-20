#include <iostream>
#include "ordenamientoVectorial.h"
#include "busquedaVectorial.h"
#include "apareoVectorial.h"
#include "corteDeControl.h"
#include "ayudaVectores.h"
#include "ayudaMatrices.h"

using namespace std;

void imprimirMensajeBusqueda( int pos )
{
    if ( pos < 0 )
        cout << ", no se encuentra en el vector." << endl;
    else
        cout << ", esta en la posicion: " << pos << endl;
}

int main()
{
    cout << "ORDENAMIENTO DE VECTORES: " << endl;
    cout << "=========================" << endl;
    cout << "Vector orginal: " << endl;
    int len = 10;
//    int vec[len];
    int vec[] = { 20, 30, 2, 40, 50, 2, 60, 3, -1, 10 };
    imprimirVector( vec, len );

    cout << "Vector ordenado (quick sort): " << endl;
    quickSort( vec, 0, len-1 );
//    quickSort( vec, 0, len );
    imprimirVector( vec, len );

    cout << "Vector ordenado (insertion order): " << endl;
    int vec2[] = { 20, 30, 2, 40, 50, 2, 60, 3, -1, 10 };
    insertionOrder( vec2, len );
    imprimirVector( vec2, len );

    cout << "Vector ordenado (burbujeo): " << endl;
    int vec3[] = { 20, 30, 2, 40, 50, 2, 60, 3, -1, 10 };
    burbujeo( vec3, len );
    imprimirVector( vec3, len );

    cout << endl;
    cout << "BUSQUEDA EN VECTORES: " << endl;
    cout << "=====================" << endl;
    int buscar = 40;
    cout << "busqueda secuencial de: " << buscar;
    int pos = busquedaSecuencial( vec, len, buscar );
    imprimirMensajeBusqueda( pos );

    cout << "busqueda binaria de: " << buscar;
    imprimirMensajeBusqueda( pos );
    pos = busquedaBinaria( vec, len, buscar );

    buscar = 100;
    cout << "busqueda secuencial de: " << buscar;
    pos = busquedaSecuencial( vec, len, buscar );
    imprimirMensajeBusqueda( pos );

    cout << "busqueda secuencial de: " << buscar;
    pos = busquedaBinaria( vec, len, buscar );
    imprimirMensajeBusqueda( pos );

    cout << endl;
    cout << "APAREAMIENTO DE VECTORES: " << endl;
    cout << "=========================" << endl;
    int lenA = 6;
    int lenB = 6;
    int vecA[] = { 1, 3, 5, 7, 9, 11 };
    int vecB[] = { 0, 2, 6, 8, 10, 12};
    int lenC = lenA + lenB;
    int vecC[lenC];
    cout << "vecA: ";
    imprimirVector( vecA, lenA );
    cout << "vecB: ";
    imprimirVector( vecB, lenB );
    cout << "vecC: ";
    apareoDeVectores( vecA, lenA, vecB, lenB, vecC, lenC );
    imprimirVector( vecC, lenC );

    cout << endl;
    cout << "CORTE DE CONTROL: " << endl;
    cout << "=================" << endl;
    Legajo legajos[] =
    {
        crearLegajo( 0, 10 ),
        crearLegajo( 0, 7 ),
        crearLegajo( 0, 3 ),
        crearLegajo( 1, 8 ),
        crearLegajo( 1, 6 ),
        crearLegajo( 1, 9 ),
        crearLegajo( 2, 5 ),
        crearLegajo( 2, 4 ),
        crearLegajo( 2, 3 ),
    };
    corteDeControl( legajos, 9 );

    cout << endl;
    cout << "MATRICEZ: " << endl;
    cout << "=========" << endl;
    int m[3][6];
    llenarMatriz( m, 3 );
    cout << "una matriz = {" << endl;
    imprimirMatriz( m, 3 );
    cout << "};" << endl;

    return 0;
}
