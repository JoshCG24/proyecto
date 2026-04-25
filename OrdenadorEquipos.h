//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_ORDENADOREQUIPOS_H
#define PROYECTO_ORDENADOREQUIPOS_H
#include "Equipo.h"

class OrdenadorEquipos {
    private:
    bool criterioDescendente =true;
    public:
    void ordenarPorPreoridad(vector<Equipo*> equipos);
    void mergeSort(vector<Equipo*> equipos,int inicio,int fin);
    void merge(vector<Equipo*> equipos,int inicio,int fin);
};


#endif //PROYECTO_ORDENADOREQUIPOS_H