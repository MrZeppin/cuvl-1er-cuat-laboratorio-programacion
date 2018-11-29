#include <iostream>
#include <stdio.h>

#define DIAS 15
#define MESES 12

using namespace std;

// Tengo una matriz de 12 filas x 31 columnas. Va de 0 a 30, son 31.
// Son los días del año. Por fila tengo el mes y por columana tengo los días. en cada día tengo las
// temperatuas registradas de cada día, buscar:
// a) temp máxima de cada mes
// b) temp máxima de todo el año
// c) dia y mes en el que ocurrió la temp max de todo el año

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
