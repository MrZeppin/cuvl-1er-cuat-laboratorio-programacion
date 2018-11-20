#ifndef AYUDASTRUCTS_H_INCLUDED
#define AYUDASTRUCTS_H_INCLUDED

#include <string.h>

#define NOM 40
#define CANT 4

struct ST_COSA
{
    char nombre[NOM];
    int num;
    int numeritos[CANT];
};

void copiarVec( int a[], int b[], int len )
{
    for ( int i = 0; i < len; i++ )
    {
        a[i] = b[i];
    }
}

void imprimirCosa( ST_COSA c )
{
    cout << c.nombre << ", " << c.num << " | ";
    for ( int i = 0; i < CANT; i++ )
    {
        cout << c.numeritos[i] << ", ";
    }
    cout << endl;
}

ST_COSA crearCosa( char nb[], int n, int nums[] )
{
    ST_COSA c;
    strncpy( c.nombre, nb, NOM );
    c.num = n;
    copiarVec( c.numeritos, nums, CANT );
    return c;
}

void configuraCosa( ST_COSA &c, char nb[], int n, int nums[] )
{
    strncpy( c.nombre, nb, NOM );
    c.num = n;
    copiarVec( c.numeritos, nums, CANT );
}

void ayudaStructs()
{
    ST_COSA cosa1;
    strncpy( cosa1.nombre, "Jacinto Merienda", NOM );
    cosa1.num = 43;
    cosa1.numeritos[0] = 12;
    cosa1.numeritos[1] = 33;
    cosa1.numeritos[2] = 10;
    cosa1.numeritos[3] = 54;
    cout << cosa1.nombre << ", " << cosa1.num << " | ";
    for ( int i = 0; i < CANT; i++ )
    {
        cout << cosa1.numeritos[i] << ", ";
    }
    cout << endl;

    ST_COSA cosa2;
    int nums2[] = {12, 33, 10, 54};
    configuraCosa( cosa2, "Jacinto Merienda", 43, nums2 );
    imprimirCosa( cosa2 );
}

#endif // AYUDASTRUCTS_H_INCLUDED
