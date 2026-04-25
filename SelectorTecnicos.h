//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_SELECTORTECNICOS_H
#define PROYECTO_SELECTORTECNICOS_H
#include <vector>

#include "Equipo.h"


class SelectorTecnicos {
    private:
    int cantidadTecnicos;
    public:
    vector<Equipo*> EquipoTecnicos(vector<Equipo*> equipos);
};


#endif //PROYECTO_SELECTORTECNICOS_H