#ifndef EJERCICIO2_H_INCLUDED
#define EJERCICIO2_H_INCLUDED

#include <iostream>
//
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

#define DIAS_X_MES 31
#define MEJORES_CANT 3

// 2. Una empresa cargo los datos del presentismo de sus empleados ingresando por cada empleado:
//    Legajo (entero de 8 digitos) y por cada dia del mes un 1 si se presento a trabajo o un 0 si falto.
//    Para simplificar, todos los empleados trabajan 31 dias.
//    Realizar un programa que permita:
//      a. Cargar los datos de N empleados, siendo N tamein informado por el usuario
//      b. Informar los legajos de los tres empleados con mejor presentismo
//      c. Informar el numero del dia con mayor ausentismo

struct Presentismo
{
    int legajo = -1;
    bool dias[DIAS_X_MES];
};

void generarVecPresentismosAutomaticamente( Presentismo p[], int len )
{
    srand( time(NULL) );
    std::cin.sync();
    std::cin.clear();
    for( int i = 0; i < len; i++ )
    {
        int diaMayorAusentismo = 20;
        p[i].legajo = rand() % 99999999;
        for ( int j = 0; j < DIAS_X_MES; j++ )
        {
            if ( j == diaMayorAusentismo )
                p[i].dias[j] = false;
            else
                p[i].dias[j] = ( rand() % 10 ) % 2 == 0 ?  false : true;
                // p[i].dias[j] = ( rand() % 10 ) % 2 == 0 ?  false : true;
        }
    }
}

void cargarPresentismo( Presentismo &p )
{
    do
    {
        cout << "legajo (8 digitos): ";
        cin >> p.legajo;
    }
    while ( p.legajo < 0 || p.legajo > 99999999 );

    for ( int i = 0; i < DIAS_X_MES; i++ )
    {
        cout << "dia " << i+1 << "/31: ";
        int ingreso;
        cin >> ingreso;
        if ( ingreso > 0 )
            p.dias[i] = true;
        else
            p.dias[i] = false;
    }
}

void cargarDatosDeEmpleados( Presentismo p[], int len )
{
    for ( int i = 0; i < len; i++ )
    {
        cout << "EMPLEADO (" << i+1 << "/" << len << ")" << endl;
        cargarPresentismo( p[i] );
        cout << endl;
    }
}

int calcularPresentismo( Presentismo p )
{
    int acum = 0;
    for ( int i = 0; i < DIAS_X_MES; i ++ )
    {
        if ( p.dias[i] == true )
        {
            acum++;
        }
    }
    return acum;
}

void imprimirPresentismos( Presentismo p[], int len )
{
    cout << "LEGAJO      PRESENCIAS" << endl;
    for( int i = 0; i < len; i++ )
    {
        printf( "%8i      %2i\n", p[i].legajo, calcularPresentismo( p[i] ) );
    }
}

void informarMejorPresentismo( Presentismo p[], int len )
{
    int cont = 0;
    int mejores[MEJORES_CANT];
    for ( int i = 0; i < len; i ++ )
    {
        mejores[i] = -1;
    }

    for ( int i = 0; i < len; i ++ )
    {
        int pre = calcularPresentismo( p[i] );
        int j = 0;
        bool noEsMayor = true;
        while ( j < MEJORES_CANT && noEsMayor )
        {
            int pi = mejores[j];
            if ( mejores[j] == -1 || pre > calcularPresentismo( p[pi] ) )
            {
                mejores[j] = i;
                noEsMayor = false;
            }
            j++;
        }
    }

    cout << "MEJORES PRESENTISMOS: " << endl;
    for ( int i = 0; i < MEJORES_CANT; i ++ )
    {
        int pi = mejores[i];
        cout << p[pi].legajo << endl;
    }
}

void informarNumeroDeDiaConMayorAusentismo( Presentismo p[], int len )
{
    int dia = 0;
    int mayor = 0;
    for ( int i = 0; i < len; i++ )
    {
        if ( p[i].dias[0] == false )
        {
            mayor++;
        }
    }
    for ( int i = 1; i < DIAS_X_MES; i ++ )//dias
    {
        int acum = 0;
        for ( int j = 0; j < len; j++ )//personas
        {
            if ( p[j].dias[i] == false )
            {
                acum++;
            }
        }
        if ( acum > mayor )
        {
            dia = i;
            mayor = acum;
        }
    }

    cout << "DIA CON MAYOR AUSENTISMO: " << dia << endl;
}

void ejercicio2()
{
    int N;
    cout << "cuantos empleados hay? ";
    cin >> N;
    cout << endl;
    if ( N >= 3 )
    {
        Presentismo presentes[N];

//        cargarDatosDeEmpleados( presentes, N );
        generarVecPresentismosAutomaticamente( presentes, N );

        imprimirPresentismos( presentes, N );
        cout << endl;
        informarMejorPresentismo( presentes, N );
        cout << endl;
        informarNumeroDeDiaConMayorAusentismo( presentes, N );
    }
}

#endif // EJERCICIO2_H_INCLUDED
