//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_ORDENADOREQUIPOS_H
#define PROYECTO_ORDENADOREQUIPOS_H
#include "Equipo.h"

using namespace std;

class OrdenadorEquipos {
private:
    void mergeSortPorId(vector<Equipo*>& equipos, int inicio, int fin);
    void mergePorId(vector<Equipo*>& equipos, int inicio, int medio, int fin);
public:

    void ordenarPorPrioridad(vector<Equipo*>& equipos);
    void ordenarPorId(vector<Equipo*>& equipos);
    void mergeSort(vector<Equipo*>& equipos, int inicio, int fin);
    void merge(vector<Equipo*>& equipos, int inicio, int medio, int fin);
};


#endif //PROYECTO_ORDENADOREQUIPOS_H