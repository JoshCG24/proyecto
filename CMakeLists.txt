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
        ReporteDiario.h)
