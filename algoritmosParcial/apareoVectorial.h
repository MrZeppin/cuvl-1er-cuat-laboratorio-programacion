#ifndef APAREOVECTORIAL_INCLUDED
#define APAREOVECTORIAL_INCLUDED

#include <iostream>


/**
 * necesita que el vectorer esten ordenados ascendientemente
 */
void apareoDeVectores( int vecA[], int lenA, int vecB[], int lenB, int vecC[], int lenC )
{
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
    while ( a < lenA )
    {
        vecC[c] = vecA[a];
        a++;
        c++;
    }
    while ( b < lenB )
    {
        vecC[c] = vecB[b];
        b++;
        c++;
    }
}

#endif // APAREOVECTORIAL_INCLUDED
