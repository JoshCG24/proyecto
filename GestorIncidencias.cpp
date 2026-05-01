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
        probabilidad += 20;
    }

    int numeroAleatorio = rand() % 100 + 1;

    if (numeroAleatorio <= probabilidad) {
        int severidad = (rand() % 3) + 1; //calcula un numero con "%" , da un numero entre 0 y 3, pero se le suma 1, para que entre en el switch
        //se le sumo uno para que la severidad no de 0, evitando la referencia a que no hay severidad.

        // Descripción según severidad
        string descripcion;
        switch (severidad) {
            case 1:
                descripcion = "Desgaste menor detectado";
                break;
            case 2:
                descripcion = "Falla parcial en componente";
                break;
            case 3:
                descripcion = "Falla critica - requiere intervencion inmediata";
                break;
        }

        Incidencia* nueva = new Incidencia(
            "INC-" + e->getId(),
            descripcion,
            dia,
            severidad
        );
        e->agregarIncidencia(nueva);
    }
}
