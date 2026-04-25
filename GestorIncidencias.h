//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_GESTORINCIDENCIAS_H
#define PROYECTO_GESTORINCIDENCIAS_H

#include "Equipo.h"
class GestorIncidencias {
    public:
    void actualizarIncidencias(vector<Equipo*> equipos,int dia);
    void generarIncidencia(Equipo* e,int dia);
};


#endif //PROYECTO_GESTORINCIDENCIAS_H