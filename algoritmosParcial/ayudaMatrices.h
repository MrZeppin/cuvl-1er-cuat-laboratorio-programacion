#ifndef AYUDAMATRICES_H_INCLUDED
#define AYUDAMATRICES_H_INCLUDED

#include <iostream>
#include <stdlib.h>

void imprimirMatriz( int matriz[][6], int filas )
{
    for ( int i = 0; i < filas; i++ )
    {
        for ( int j = 0; j < 6; j++ )
        {
            printf( "%3i, ", matriz[i][j] );
        }
        std::cout << endl;
    }
}

void llenarMatriz( int matriz[][6], int filas )
{
    for ( int i = 0; i < filas; i++ )
    {
        for ( int j = 0; j < 6; j++ )
        {
            matriz[i][j] = i * 10 + j;
        }
    }
}

#endif // AYUDAMATRICES_H_INCLUDED
