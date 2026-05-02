//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_ARCHIVOMANAGER_H
#define PROYECTO_ARCHIVOMANAGER_H
#include <vector>
#include <fstream>
using namespace std;
#include "Equipo.h"
#include "ReporteDiario.h"
#include "BuscarEquipos.h"
#include "OrdenadorEquipos.h"
#include <iostream>

#include <exception>
#include <string>
class ArchivoInvalidoException : public exception {
private:
    string mensaje;
public:
    explicit ArchivoInvalidoException(const string& ruta = "")
        : mensaje("Error: No se pudo abrir el archivo" + (ruta.empty() ? "." : ": " + ruta)) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class FormatoInvalidoException : public exception {
private:
    string mensaje;
public:
    explicit FormatoInvalidoException(const string& detalle = "")
        : mensaje("Error: Formato de archivo invalido" + (detalle.empty() ? "." : ": " + detalle)) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class OperacionInconsistenteException : public exception {
private:
    string mensaje;
public:
    explicit OperacionInconsistenteException(const string& detalle = "")
        : mensaje("Error: Operacion inconsistente" + (detalle.empty() ? "." : ": " + detalle)) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class ArchivoManager {
public:
    vector<Equipo*> cargarEquipos(const string& ruta);
    int cargarIncidencias(const string& ruta, vector<Equipo*>& equipos,
                          BuscarEquipos* buscador, OrdenadorEquipos* ordenador);
    void guardarReporteDiario(ReporteDiario* reporte);
    void guardarReporteFinal(const string& ruta, const string& resumen);
    void imprimirArchivo(const string& ruta);
};



#endif //PROYECTO_ARCHIVOMANAGER_H