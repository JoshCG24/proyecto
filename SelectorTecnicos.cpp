//
// Created by joshu on 4/24/2026.
//

#include "SelectorTecnicos.h"
vector<Equipo*> SelectorTecnicos::EquipoTecnicos(const vector<Equipo*>& equipos) {
    vector<Equipo*> seleccionados;
    for (int i = 0; i < cantidadTecnicos && i < equipos.size(); i++) {
        seleccionados.push_back(equipos[i]);
    }
    return seleccionados;
}