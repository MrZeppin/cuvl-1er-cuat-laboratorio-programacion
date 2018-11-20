#ifndef CORTEDECONTROL_H_INCLUDED
#define CORTEDECONTROL_H_INCLUDED


struct Legajo
{
    int idAlumno;
    int nota;
};

Legajo crearLegajo( int id, int nota )
{
    Legajo leg;
    leg.idAlumno = id;
    leg.nota = nota;
    return leg;
}


/**
 * necesita que el vector este ordenado por idAlumno
 */
void corteDeControl( Legajo vec[], int len )
{
    int i = 0;
    while ( i < len )
    {
        int key = vec[i].idAlumno;
        int suma = 0;
        int cant = 0;
        while ( i < len && vec[i].idAlumno == key )
        {
            suma += vec[i].nota;
            cant++;
            i++;
        }
        std::cout << "alumno: " << key << ", promedio: " << suma / cant << std::endl;
    }
}

#endif // CORTEDECONTROL_H_INCLUDED
