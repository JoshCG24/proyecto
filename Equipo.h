//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_EQUIPO_H
#define PROYECTO_EQUIPO_H
#include <string>
#include <vector>
#include "Incidencia.h"
using namespace std;


class Mantenimiento;

class Equipo {
private:
    string id;//indentidad del equipo
    int criticidad;//que tan importante
    double estado=100;//que tan bien esta del 1-100
    int tiempo_inactivo=0;//cuanto tiempo lleva sin reparar
    vector<Incidencia*> Incidencias ;//lista prblemas
    double prioridad=0.0;


    public:
    Equipo(string id, int criticidad, double estado);
    void degradar();
    void agregarIncidencia( Incidencia* incidencia);
    void resolverIncidencia();
    void aplicarMantenimiento(Mantenimiento* mantenimiento);
    void setTiempoInactivo(int tiempo_inavtivo);
    void setPrioridad(double p);
    void setEstado(double estado);

    int getCriticidad() const;
    double getEstado() const;
    string getId() const;
    int getTiempoInactivo() const;
    int getIncidenciaActivas() const ;
    bool tieneIncidenciaPendiente() const;
    double getPrioridad() const;
    ~Equipo();


};


#endif //PROYECTO_EQUIPO_H