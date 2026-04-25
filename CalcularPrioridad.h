//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_CALCULARPRIORIDAD_H
#define PROYECTO_CALCULARPRIORIDAD_H

#include<string>
#include"Equipo.h"
class CalcularPrioridad {
    private:
    double pesoCriticidad= 0.5;
    double pesoIncidente =0.3;
    double pesoInactividad= 0.2;
public:
    double calcularPrioridad(Equipo e);
};


#endif //PROYECTO_CALCULARPRIORIDAD_H