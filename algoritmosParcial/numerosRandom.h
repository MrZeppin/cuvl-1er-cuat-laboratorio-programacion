#ifndef NUMEROSRANDOM_H_INCLUDED
#define NUMEROSRANDOM_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <time.h>

void iniciarRandomNums()
{
    srand( time(NULL) );
    std::cin.sync();
    std::cin.clear();
}

int generarNumEntero( int maxNum )
{
    return rand() % maxNum;
}

void llenarVectorConEnterosRandoms( int vec[], int len, int maxNum )
{
    for( int i = 0; i < len; i++ )
    {
        vec[i] = generarNumEntero( maxNum );
    }
}


#endif // NUMEROSRANDOM_H_INCLUDED
