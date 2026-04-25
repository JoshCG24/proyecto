//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_INCIDENCIA_H
#define PROYECTO_INCIDENCIA_H

#include <string>
using namespace std;
class Incidencia {
private:
    string id;
    string descripcion;
    int severidad;
    int diaAparicion;
    bool activa;


public:
    Incidencia(string id, string descripcion, int dia, int severidad);
    void resolver();
    bool  estaActiva();
    int getSeveridad();
    int getDiaAparicion();

};


#endif //PROYECTO_INCIDENCIA_H