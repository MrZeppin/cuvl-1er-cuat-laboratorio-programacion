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

//void ordenarProductos( ST_PRODUCTO productos[PRODUCTOS_CANT] )
//{
//    // burbujeo simple
//    for ( int i=0; i < PRODUCTOS_CANT; i++  )
//    {
//        for ( int j = 0; j < PRODUCTOS_CANT; j++ )
//        {
//            if ( productos[j].codigo > productos[j+1].codigo )
//            {
//                ST_PRODUCTO aux = productos[j];
//                productos[j] = productos[j+1];
//                productos[j+1] = aux;
//            }
//        }
//    }
//}

void ordenarProductos( ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    // burbujeo pupu
    bool cambio = true;
    int jMax = PRODUCTOS_CANT;
    while ( cambio )
    {
        cambio = false;
        for ( int j = 0; j < PRODUCTOS_CANT-1; j++ )
        {
            if ( productos[j].codigo > productos[j+1].codigo )
            {
                ST_PRODUCTO aux = productos[j];
                productos[j] = productos[j+1];
                productos[j+1] = aux;
                cambio = true;
            }
        }
        jMax--;
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
                cant += ventas[i][j].cantidad;
            }
        }
    }
    return cant;
}

int productosMenosVendido( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT]  )
{
    int menosCantProd = 0;
    int menosCant = calcularCantidad( ventas, productos[0].codigo );
    for ( int i = 1; i < PRODUCTOS_CANT; i++  )
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

void losTresProductosMenosVendido( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT], int pos[3] )
{
    int TRES = 3;
    int cants[TRES];
    for ( int i = 0; i < TRES; i++ )
    {
        pos[i] = i;
        cants[i] = calcularCantidad( ventas, productos[i].codigo );
    }
    int j = 0;
    bool menor = false;
    for ( int i = TRES; i < PRODUCTOS_CANT; i++  )
    {
        int curCant = calcularCantidad( ventas, productos[i].codigo );
        j = 0;
        menor = false;
        while ( j < TRES && menor == false )
        {
            if ( curCant < cants[j] )
            {
                cants[j] = curCant;
                pos[j] = i;
                menor = true;
            }
            j++;
        }
    }
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
    for ( int i = 1; i < MESES; i++  )
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
    productos[i].codigo = 2145;
    strncpy( productos[i].nombre, "Vinagre", NOMBRE_CANT );
    productos[i].precio = 10;

    i++;
    productos[i].codigo = 1234;
    strncpy( productos[i].nombre, "Sal", NOMBRE_CANT );
    productos[i].precio = 5;

    i++;
    productos[i].codigo = 1194;
    strncpy( productos[i].nombre, "Harina", NOMBRE_CANT );
    productos[i].precio = 4;

    i++;
    productos[i].codigo = 9453;
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

// no lo pedia el parcial es para testear
void imprimirVentas( ST_VENTA ventas[MESES][DIAS], ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    cout << "MESES Y DINERO" << endl;
    for ( int i=0; i < MESES; i++  )
    {
        cout << "- mes " <<  i+1 << " se gano $" << calcularFactura( ventas, productos, i ) << endl;
    }
    cout << endl;
}

void imprimirProductos( ST_PRODUCTO productos[PRODUCTOS_CANT] )
{
    cout << "PRODUCTOS" << endl;
    for ( int i = 0; i < PRODUCTOS_CANT; i++ )
    {
        cout << "- "<< productos[i].codigo << ": " << productos[i].nombre << endl;
    }
    cout << endl;
}

int main()
{
    ST_PRODUCTO productos[PRODUCTOS_CANT];
    ST_VENTA ventas[MESES][DIAS];

    llenarProductos( productos );
    llenarVentas( ventas, productos );

    ordenarProductos( productos );

    imprimirProductos( productos );
    imprimirVentas( ventas, productos );

    cout << "RESUMEN" << endl;
    int indiceMenosVendido = productosMenosVendido( ventas, productos );
    cout << "- Producto menos vendido: " << productos[indiceMenosVendido].nombre << endl;

    int mesMayorFactura = mesConMayorFactura( ventas, productos );
    cout << "- Mes con mayor factura: " << mesMayorFactura+1 << endl;

    cout << endl;
    cout << "RESUMEN 2" << endl;
    int posMenos[3];// un array con posiciones de los productos menos vendidos
    losTresProductosMenosVendido( ventas, productos, posMenos );
    cout << productos[posMenos[0]].nombre << endl;
    cout << productos[posMenos[1]].nombre << endl;
    cout << productos[posMenos[2]].nombre << endl;

    return 0;
}
