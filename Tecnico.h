//
// Created by joshu on 4/27/2026.
//

#ifndef ARCHIVOMANAGER_H_TECNICO_H
#define ARCHIVOMANAGER_H_TECNICO_H
#include "Mantenimiento.h"


class Tecnico {

    public:
    void aplicarMantenimiento(Mantenimiento* m);
    void resolverIncidencia(Equipo* equipo,Incidencia* incidencia);
};


#endif //ARCHIVOMANAGER_H_TECNICO_H