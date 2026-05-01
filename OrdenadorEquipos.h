//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_ORDENADOREQUIPOS_H
#define PROYECTO_ORDENADOREQUIPOS_H
#include "Equipo.h"
#include "CalcularPrioridad.h"
using namespace std;

class OrdenadorEquipos {
private:
    bool criterioDescendente = true;
    CalcularPrioridad calculador;
public:

    void ordenarPorPrioridad(vector<Equipo*>& equipos);
    void mergeSort(vector<Equipo*>& equipos, int inicio, int fin);
    void merge(vector<Equipo*>& equipos, int inicio, int medio, int fin);
};


#endif //PROYECTO_ORDENADOREQUIPOS_H