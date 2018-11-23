#include <string.h>//no hace falta
#include <iostream>//no hace falta
#include <cstdlib>//no hace falta
#include <time.h>//no hace falta

#include <iostream>

#define PRODUCTOS_CANT 4
#define NOMBRE_CANT 40
#define MESES 12
#define DIAS 31

using namespace std;


struct ST_VENTA
{
    int fecha;//AAAAMMDD
    int codigo;
    int cantidad;
};

struct ST_PRODUCTO
{
    int codigo;
    char nombre[NOMBRE_CANT+1];// string nombre;
    double precio;
};


void ordenarProductos( ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    // burbujeo simple
    for ( int i=0; i < PRODUCTOS_CANT; i++  )
    {
        for ( int j = 0; j < PRODUCTOS_CANT; j++ )
        {
            if ( productos[j].codigo > productos[j+1].codigo )
            {
                ST_PRODUCTO aux = productos[j];
                productos[j] = productos[j+1];
                productos[j+1] = aux;
            }
        }
    }
}

int buscarProducto( ST_PRODUCTO productos[PRODUCTOS_CANT], int codigo )
{
    // busqueda binaria
    int inf, sup, med;
    inf = 0;
    sup = PRODUCTOS_CANT-1;
    med = 0;
    while ( inf < sup )
    {
        med = (sup-1) / 2 + inf / 2;
        if ( codigo == productos[med].codigo )
        {
            return med;
        }
        else if ( codigo > productos[med].codigo )
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

int calcularCantidad(  ST_VENTA ventas[MESES][DIAS], int codigo )
{
    int cant = 0;
    for ( int i=0; i < MESES; i++  )
    {
        for ( int j = 0; j < DIAS; j++ )
        {
            if ( ventas[i][j].codigo == codigo )
            {
                cant++;
            }
        }
    }
    return cant;
}

int productotMenosVendido( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT]  )
{
    int menosCantProd = 0;
    int menosCant = calcularCantidad( ventas, productos[0].codigo );
    for ( int i=0; i < PRODUCTOS_CANT; i++  )
    {
        int curCant = calcularCantidad( ventas, productos[i].codigo );
        if ( curCant < menosCant )
        {
            menosCant = curCant;
            menosCantProd = i;
        }
    }
    return menosCantProd;
}

double calcularFactura( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT], int mes )
{
    double fact = 0;
    for ( int i = 0; i < DIAS; i++ )
    {
        int codigo = ventas[mes][i].codigo;
        int indiceProd = buscarProducto( productos, codigo );

        ST_PRODUCTO ventaProd = productos[indiceProd];
        int ventaCantidad = ventas[mes][i].cantidad;

        fact += ventaProd.precio * ventaCantidad;
    }
    return fact;
}

int mesConMayorFactura( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    int mayorFactMes = 0;
    double mayorFact = calcularFactura( ventas, productos, 0);
    for ( int i=0; i < MESES; i++  )
    {
        double curFact = calcularFactura( ventas, productos, i);
        if ( curFact > mayorFact)
        {
            mayorFact = curFact;
            mayorFactMes = i;
        }
    }
    return mayorFactMes;
}

// no lo pedia el parcial es para testear
void llenarProductos( ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    int i = 0;
    productos[i].codigo = 50;
    strncpy( productos[i].nombre, "Vinagre", NOMBRE_CANT );
    productos[i].precio = 10;

    i++;
    productos[i].codigo = 15;
    strncpy( productos[i].nombre, "Sal", NOMBRE_CANT );
    productos[i].precio = 5;

    i++;
    productos[i].codigo = 2;
    strncpy( productos[i].nombre, "Harina", NOMBRE_CANT );
    productos[i].precio = 4;

    i++;
    productos[i].codigo = 20;
    strncpy( productos[i].nombre, "Tomates", NOMBRE_CANT );
    productos[i].precio = 7;
}


// no lo pedia el parcial es para testear
void llenarVentas( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    srand( time(NULL) );
    std::cin.sync();
    std::cin.clear();

    int cant = 0;
    for ( int i=0; i < MESES; i++  )
    {
        for ( int j = 0; j < DIAS; j++ )
        {
            ventas[i][j].fecha = 20180000 + i * 100 + j;
            // PRODUCTOS_CANT - 1 signfica que no se venden tomates
            ventas[i][j].codigo = productos[ rand() % (PRODUCTOS_CANT-1) ].codigo;
            ventas[i][j].cantidad =  rand() % 10;
        }
    }
}

void imprimirVentas( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    cout << "MESES Y DINERO" << endl;
    for ( int i=0; i < MESES; i++  )
    {
        cout << "- mes " <<  i+1 << " se gano $" << calcularFactura( ventas, productos, i ) << endl;
    }
}

int main()
{
    ST_PRODUCTO productos[PRODUCTOS_CANT];
    ST_VENTA ventas[MESES][DIAS];

    llenarProductos( productos );
    llenarVentas( ventas, productos );

    ordenarProductos( productos );

    imprimirVentas( ventas, productos );

    cout << endl;
    int indiceMenosVendido = productotMenosVendido( ventas, productos );
    cout << "- Producto menos vendido: " << productos[indiceMenosVendido].nombre << endl;

    int mesMayorFactura = mesConMayorFactura( ventas, productos );
    cout << "- Mes con mayor factura: " << mesMayorFactura+1 << endl;

    return 0;
}
