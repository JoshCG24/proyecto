//
// Created by joshu on 4/24/2026.
//

#include "OrdenadorEquipos.h"


void OrdenadorEquipos::ordenarPorPrioridad(vector<Equipo *> &equipos) {
    if (equipos.size() <= 1) return;
    mergeSort(equipos, 0, equipos.size() - 1);
}

void OrdenadorEquipos::mergeSort(vector<Equipo *> &equipos, int inicio, int fin) {
    if (inicio < fin) {

        int medio = inicio + (fin - inicio) / 2;

       //se llama multiples veces para dividirlo en 2
        mergeSort(equipos, inicio, medio);
        mergeSort(equipos, medio + 1, fin);

       //ordena
        merge(equipos, inicio, medio, fin);
    }
}

void OrdenadorEquipos::merge(vector<Equipo *> &equipos, int inicio, int medio, int fin) {
    vector<Equipo*> izquierda;
    vector<Equipo*> derecha;


    for (int i = inicio; i <= medio; i++) {
        izquierda.push_back(equipos[i]);
    }

    for (int j = medio + 1; j <= fin; j++) {
        derecha.push_back(equipos[j]);
    }


    int i = 0;
    int j = 0;
    int k = inicio;


    while (i < izquierda.size() && j < derecha.size()) {


        double prioIzquierda = calculador.calcularPrioridad( izquierda[i]);
        double prioDerecha = calculador.calcularPrioridad(derecha[j]);

        if (prioIzquierda >= prioDerecha) {
            equipos[k] = izquierda[i];
            i++;
        } else {
            equipos[k] = derecha[j];
            j++;
        }
        k++;
    }


    while (i < izquierda.size()) {
        equipos[k] = izquierda[i];
        i++;
        k++;
    }


    while (j < derecha.size()) {
        equipos[k] = derecha[j];
        j++;
        k++;
    }
}
