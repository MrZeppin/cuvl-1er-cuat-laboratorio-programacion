#ifndef APAREOVECTORIAL_INCLUDED
#define APAREOVECTORIAL_INCLUDED

#include <iostream>


/**
 * necesita que el vectorer esten ordenados ascendientemente
 * lenC = lenA + lenB
 */
void apareoDeVectores( int vecA[], int lenA, int vecB[], int lenB, int vecC[])
{
    // EJEMPLO
    // vecA = 30, 50, 80
    // vecB = 20, 60, 90
    // se empieza a analizar al vecA desde 30
    // y al vecB desde el 90
    int a = 0;
    int b = 0;
    int c = 0;
    while ( a < lenA && b < lenB )
    {
        if ( vecA[a] < vecB[b] )
        {
            vecC[c] = vecA[a];
            a++;
        }
        else
        {
            vecC[c] = vecB[b];
            b++;
        }
        c++;
    }
    while ( a < lenA ) {
        vecC[c] = vecA[a];
        a++;
        c++;
    }
    while ( b < lenB ) {
        vecC[c] = vecB[b];
        b++;
        c++;
    }
}


void apareoDeVectores2( int vecA[], int lenA, int vecB[], int lenB, int vecC[])
{
    // EJEMPLO
    // vecA = 30, 50, 80
    // vecB = 90, 60, 20
    // se empieza a analizar al vecA desde 30
    // y al vecB desde el 20
    int a = 0;
    int b = lenB-1;
    int c = 0;
    while ( a < lenA && b >= 0 )
    {
        if ( vecA[a] < vecB[b] )
        {
            vecC[c] = vecA[a];
            a++;
        }
        else
        {
            vecC[c] = vecB[b];
            b--;
        }
        c++;
    }
    while ( a < lenA ) {
        vecC[c] = vecA[a];
        a++;
        c++;
    }
    while ( b >= 0 ) {
        vecC[c] = vecB[b];
        b--;
        c++;
    }
}


#endif // APAREOVECTORIAL_INCLUDED
