//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_EQUIPO_H
#define PROYECTO_EQUIPO_H
#include <string>
#include <vector>
#include "mantenimiento.h"
#include "Incidencia.h"
using namespace std;
class Equipo {
private:
    string id;//indentidad del equipo
    int criticidad;//que tan importante
    double estado;//que tan bien esta del 1-100
    int tiempo_inavtivo;//cuanto tiempo lleva sin llevar
    vector<Incidencia*> Incidencias ;//lista prblemas


    public:
    void degradar();
    void agregarIncidencia( Incidencia* incidencia);
    void resolverIncidencia();
    double calcularPrioridad();
    void aplicarMantenimiento(Mantenimiento* mantenimiento);
    string getId();
    void setTiempoInavtivo(int tiempo_inavtivo);
    void setEstado(double estado);
    int getCriticidad();
    double getEstado();
    int getTiempoInavtivo();
    int incidenciaActivas();



};


#endif //PROYECTO_EQUIPO_H