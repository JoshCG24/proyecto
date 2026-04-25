cmake_minimum_required(VERSION 4.1)
project(proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(proyecto main.cpp
        Equipo.cpp
        Equipo.h
        Incidencia.cpp
        Incidencia.h
        CalcularPrioridad.cpp
        CalcularPrioridad.h
        Mantenimiento.cpp
        Mantenimiento.h
        MantenimientoPreventivo.cpp
        MantenimientoPreventivo.h
        MantenimientoCorrectivo.cpp
        MantenimientoCorrectivo.h
        OrdenadorEquipos.cpp
        OrdenadorEquipos.h
        BuscarEquipos.cpp
        BuscarEquipos.h
        ReporteDiario.cpp
        ReporteDiario.h
        ArchivoManager.cpp
        ArchivoManager.h
        GestorIncidencias.cpp
        GestorIncidencias.h
        SelectorTecnicos.cpp
        SelectorTecnicos.h
        CalculadorRiesgo.cpp
        CalculadorRiesgo.h
        Simulador.cpp
        Simulador.h)
