#ifndef AYUDASTRUCTS_H_INCLUDED
#define AYUDASTRUCTS_H_INCLUDED

#include <string.h>
#include <stdio.h>

#define NOM 40
#define CANT 4

//=======================
// FUNCS
//=======================

void copiarVec( int a[], int b[], int len )
{
    for ( int i = 0; i < len; i++ )
    {
        a[i] = b[i];
    }
}

//=======================
// ALUMNO
//=======================

struct ST_ALUMNO
{
    int id;
    char nombre[NOM];
    float promedio;
};

ST_ALUMNO crearAlumno( int id, char nombre[NOM], float promedio )
{
    ST_ALUMNO alum;
    alum.id = id;
    strncpy( alum.nombre, nombre, NOM );
    alum.promedio = promedio;
    return alum;
}

void imprimirAlumno( ST_ALUMNO alum )
{
//    cout << alum.id << ", " << alum.nombre << ", " << alum.promedio << endl;
    printf( " %3i %15s %10.2f\n", alum.id, alum.nombre, alum.promedio );
}

void imprimirAlumnos( ST_ALUMNO alum[], int len )
{
    for ( int i = 0; i < len; i++ )
    {
        imprimirAlumno( alum[i] );
    }
}

int ordenarAlumnosPorPromedio( ST_ALUMNO alum[], int len )
{
    for ( int i = 0; i < len; i++ )
    {
        for ( int j = 0; j < len-1; j++ )
        {
            if ( alum[i].promedio > alum[i+1].promedio )
            {
                ST_ALUMNO aux = alum[i];
                alum[i] = alum[i+1];
                alum[i+1] = aux;
            }
        }
    }
}
//=======================
// COSA
//=======================

struct ST_COSA
{
    char nombre[NOM];
    int num;
    int numeritos[CANT];
};

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

//=======================
// MAIN FUNC
//=======================

void ayudaStructs()
{
    cout << "ESTRUCTURAS" << endl;
    cout << "===========" << endl;

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

    cout << endl;
    cout << "ESTRUCTURAS: ORDENAMIENTO" << endl;
    cout << "=========================" << endl;
    ST_ALUMNO alumns[] = {
        crearAlumno( 30, "Pedro", 7.5 ),
        crearAlumno( 15, "Juli", 4 ),
        crearAlumno( 20, "Lora", 2 ),
        crearAlumno( 3, "Cacho", 6 ),
        crearAlumno( 2, "Jorgelina", 7 ),
        crearAlumno( 9, "Miguel", 3 ),//6
    };

    int len = 6;
    cout << "DESORDENADA: " << endl;
    imprimirAlumnos( alumns, len );
    cout << endl;
    cout << "POR PROMEDIO: " << endl;
    ordenarAlumnosPorPromedio( alumns, len );
    imprimirAlumnos( alumns, len );
}

#endif // AYUDASTRUCTS_H_INCLUDED
