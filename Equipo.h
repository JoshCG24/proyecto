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
class Mantenimiento;
class Equipo {
private:
    string id;//indentidad del equipo
    int criticidad;//que tan importante
    double estado=100;//que tan bien esta del 1-100
    int tiempo_inactivo;//cuanto tiempo lleva sin llevar
    vector<Incidencia*> Incidencias ;//lista prblemas


    public:
    Equipo(string id, int criticidad, double estado);
    void degradar();
    void agregarIncidencia( Incidencia* incidencia);
    void resolverIncidencia();
    void aplicarMantenimiento(Mantenimiento* mantenimiento);
    void setTiempoInactivo(int tiempo_inavtivo);
    void setEstado(double estado);
    int getCriticidad();
    double getEstado();
    string getId();
    int getTiempoInavtivo();
    int getIncidenciaActivas();



};


#endif //PROYECTO_EQUIPO_H