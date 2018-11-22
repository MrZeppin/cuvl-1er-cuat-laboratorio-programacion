#ifndef BUSQUEDAVECTORIAL_INCLUDED
#define BUSQUEDAVECTORIAL_INCLUDED

int busquedaSecuencial( int vec[], int len, int buscar  )
{
    for ( int i = 0; i < len; i++ )
    {
        if ( vec[i] == buscar )
        {
            return i;
        }
    }
    return -1;
}

int busquedaSecuencialDos( int vec[], int len, int buscar  )
{
    int i = 0;
    int pos = -1;
    bool encontrado = false;
    while ( i < len && encontrado == false )
    {
        if ( vec[i] == buscar )
        {
            pos = i;
            encontrado = true;
        }
        i++;
    }
    return pos;
}

int busquedaSecuencialTres( int vec[], int len, int buscar  )
{
    int i = 0;
    while ( vec[i] != buscar )
    {
        i++;
    }
    if ( vec[i] == buscar )
    {
        return i;
    }
    return -1;
}

/**
 * necesita que el vector este ordenado ascendientemente
 * @return {int} posicion del numero que se desea buscar, sino existe retorna -1
 */
int busquedaBinaria( int vec[], int len, int buscar )
{
    int inf, sup, med;
    inf = 0;
    sup = len-1;
    med = 0;
    while ( inf < sup )
    {
        med = (sup-1) / 2 + inf / 2;
        if ( buscar == vec[med] )
        {
            return med;
        }
        else if ( buscar > vec[med] )
        {
            inf = med + 1;
        }
        else
        {
            sup = med - 1;
        }
    }
    return -1;
}

#endif // BUSQUEDAVECTORIAL_INCLUDED
