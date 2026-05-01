//
// Created by joshu on 4/24/2026.
//

#include "BuscarEquipos.h"

Equipo * BuscarEquipos::buscarBinario(vector<Equipo *> equipos, string id) {
    int inicio = 0;
    int fin = equipos.size() - 1;

    while (inicio <= fin) {

        int medio = inicio + (fin - inicio) / 2;


        if (equipos[medio]->getId() == id) {
            return equipos[medio];
        }


        if (equipos[medio]->getId() < id) {
            inicio = medio + 1;
        }

        else {
            fin = medio - 1;
        }
    }


    return nullptr;
}
