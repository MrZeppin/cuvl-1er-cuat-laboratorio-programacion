#ifndef AYUDAVECTORES_H_INCLUDED
#define AYUDAVECTORES_H_INCLUDED

#include <iostream>
using namespace std;

void imprimirVector( int vec[], int len, bool endLine=false )
{
    for( int i = 0; i < len; i++ )
    {
        cout << vec[i] << ( endLine ? "\n" : ", " );
    }
    if ( endLine == false )
    {
        cout << endl;
    }
}


#endif // AYUDAVECTORES_H_INCLUDED
