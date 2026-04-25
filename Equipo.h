//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_EQUIPO_H
#define PROYECTO_EQUIPO_H
#include <string>
#include <vector>

#include "Incidencia.h"
using namespace std;
class Equipo {
private:
    string id;
    string nombre;
    int criticidad;
    double estado;
    int tiempo_inavtivo;
    vector<Incidencia*> Incidencia ;


    public:
    void degradar();
    void agregarIncidencia();
    void resolverIncidencia();
    double calcularPrioridad();
    void aplicarMantenimiento();
    string getId();
    int getCriticidad();
    double getEstado();
    int getTiempoInavtivo();
    int incidenciaActiva();



};


#endif //PROYECTO_EQUIPO_H