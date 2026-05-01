//
// Created by joshu on 4/24/2026.
//

#include "GestorIncidencias.h"

#include "Incidencia.h"
#include <cstdlib>

void GestorIncidencias::actualizarIncidencias(vector<Equipo*> equipos, int dia) {
    for (int i = 0; i < equipos.size(); i++) {

        generarIncidencia(equipos[i], dia);
    }
}

void GestorIncidencias::generarIncidencia(Equipo* e, int dia) {

    int probabilidad = e->getCriticidad() * 2;

    if (e->getEstado() < 50) {
        probabilidad += 20; // Bonus de falla por mal estado
    }


    int numeroAleatorio = rand() % 100 + 1;


    if (numeroAleatorio <= probabilidad) {
        int severidad = (rand() % 3) + 1;


        Incidencia* nueva = new Incidencia("INC-" + e->getId(), "Falla detectada", severidad, dia);
        e->agregarIncidencia(nueva);
    }
}



