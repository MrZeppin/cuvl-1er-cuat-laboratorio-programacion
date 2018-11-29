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

// mes y anio se usan para el punto c
void maxTempUnAnio( float temps[MESES][DIAS], int &maxTempMes, int &maxTempDia )
{
    int maxTemp = temps[0][0];
    // aca no lo incializo ningun for en 1 porque sino saltearia todo un mes y el primer dia de todos los otros meses
    for ( int i = 0; i < MESES; i++ )
    {
        for ( int j = 0; j < DIAS; j++ )
        {
            int tempActual = temps[i][j];
            if ( tempActual > maxTemp )
            {
                maxTemp = tempActual;
                maxTempMes = i;
                maxTempDia = j;
            }
        }
    }
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
            if ( i == 3 && j == 3 )
                temps[i][j] = 31;
            else if ( j == 8)
                temps[i][j] = 26;
            else
                temps[i][j] = 0;
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
            printf(", %4.1f-C", temps[i][j]);
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
    cout << endl;
    int m;
    int d;
    maxTempUnAnio( temperaturas, m, d );
    cout << "Max temperatura en todo el anio: " << temperaturas[m][d] << "-C en el mes " << m << ", dia " << d << endl;
    return 0;
}
