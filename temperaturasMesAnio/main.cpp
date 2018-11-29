#include <iostream>
#include <stdio.h>

#define DIAS 15
#define MESES 12

using namespace std;

// Tengo una matriz de 12 filas x 31 columnas. Va de 0 a 30, son 31.
// Son los d�as del a�o. Por fila tengo el mes y por columana tengo los d�as. en cada d�a tengo las
// temperatuas registradas de cada d�a, buscar:
// a) temp m�xima de cada mes
// b) temp m�xima de todo el a�o
// c) dia y mes en el que ocurri� la temp max de todo el a�o

int maxTempUnMes( float temps[MESES][DIAS], int mes )
{
    int maxTemp = temps[mes][0];
    int maxTempPos = 0;
    for ( int j = 1; j < DIAS; j++ )
    {
        int tempActual = temps[mes][j];
        if ( tempActual > maxTemp )
        {
            maxTemp = tempActual;
            maxTempPos = j;
        }
    }
    return maxTempPos;
}

void imprimirMaxTempTodosLosMeses( float temps[MESES][DIAS] )
{
    cout << "MAX TEMPS MENSUALES" << endl;
    for ( int i = 0; i < MESES; i++ )
    {
        int dia = maxTempUnMes( temps, i );
        cout << "- Mes " << i+1 << ": " << temps[i][dia] << endl;
    }
}

void llenarTemperaturas( float temps[MESES][DIAS] )
{
    for ( int i = 0; i < MESES; i++ )
    {
        for ( int j = 0; j < DIAS; j++ )
        {
            if ( j == 8)
                temps[i][j] = 31;
            else
                temps[i][j] = 2;
        }
    }
}

void imprimirTemperaturas( float temps[MESES][DIAS] )
{
    cout << " MES" << endl;
    for ( int i = 0; i < MESES; i++ )
    {
        printf("%4i", i+1);
        for ( int j = 0; j < DIAS; j++ )
        {
            printf(", %0.1f-C", temps[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    float temperaturas[MESES][DIAS];
    llenarTemperaturas( temperaturas );
    imprimirTemperaturas( temperaturas );
    cout << endl;
    imprimirMaxTempTodosLosMeses( temperaturas );
    return 0;
}
