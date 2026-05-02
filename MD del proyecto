
# Documento Técnico: Sistema de Planificación Inteligente de Mantenimiento
**Curso:** Programación II


## 1. Resumen Ejecutivo
La construcción de sistemas de software robustos exige una disciplina rigurosa en el manejo de la memoria y el diseño orientado a objetos. Este proyecto representa la convergencia entre la teoría de patrones de diseño (como **Strategy**) y la optimización algorítmica para resolver problemas reales de gestión de activos de laboratorio.

---

## 2. Log de Cambios y Refactorización (30 de abril, 2026)
Se realizó una auditoría técnica para asegurar la estabilidad del sistema, corrigiendo errores críticos de lógica y gestión de recursos:

### Clase `Equipo` e `Incidencia`
*   **Gestión de Memoria:** Se implementó un destructor en `Equipo` para liberar el vector de incidencias y se aplicó `= delete` al constructor de copia para evitar errores de *double free*.
*   **Corrección de Bugs:** `Incidencia::estaActiva()` ahora retorna un booleano constante. Antes no retornaba nada, lo que provocaba un fallo lógico.
*   **Inicialización:** El constructor de `Incidencia` ahora garantiza que el estado inicie en `true` (activa), evitando valores basura del sistema.

### Arquitectura de Clases
*   **Mantenimiento:** Se eliminó la dependencia circular mediante *forward declaration* en los encabezados, moviendo los `#include` necesarios al archivo `.cpp`.
*   **Simplificación (YAGNI):** Se eliminaron atributos y constructores redundantes en `MantenimientoCorrectivo` y `Preventivo` que no aportaban valor a la lógica actual.

---

## 3. Diseño del Sistema y Responsabilidades

### Modelo del Dominio
| Clase | Responsabilidad Principal |
| :--- | :--- |
| **Equipo** | Gestiona criticidad (1-10), estado (0-100) y lista de incidencias. |
| **Incidencia** | Modela fallos técnicos con severidad (1-3) y estado de resolución. |
| **Mantenimiento** | Interfaz abstracta que define el contrato `aplicar(Equipo&)`. |

### Lógica de Control
*   **CalcularPrioridad:** Implementa la fórmula exacta: $prioridad = (criticidad \times 0.5) + (incidencias \times 0.3) + (inactivo \times 0.2)$.
*   **OrdenadorEquipos:** Utiliza un algoritmo **MergeSort** manual ($O(n \log n)$) para clasificar equipos por prioridad o ID.
*   **BuscarEquipos:** Implementa **búsqueda binaria** ($O(\log n)$) para consultas optimizadas sobre el inventario.

---

## 4. Patrón de Diseño: Strategy
El sistema implementa el patrón **Strategy** para permitir polimorfismo real en tiempo de ejecución.

*   **Contexto:** El `Simulador` decide la estrategia según el estado del equipo.
*   **Lógica de Selección:**
    *   Si el equipo tiene incidencias activas: Se aplica `MantenimientoCorrectivo` (Reparación total, estado = 100).
    *   Si el equipo no tiene incidencias: Se aplica `MantenimientoPreventivo` (Mejora parcial, estado + 25).

---

## 5. Análisis de la Simulación (30 días)
El flujo diario orquestado por la clase `Simulador` sigue un ciclo acumulativo y consistente:
1.  **Degradación:** Los equipos pierden estado gradualmente.
2.  **Generación:** Se crean incidencias aleatorias basadas en la criticidad.
3.  **Priorización:** Se calculan pesos y se ordena el vector de equipos.
4.  **Ejecución:** Los 3 técnicos disponibles aplican la estrategia de mantenimiento correspondiente.
5.  **Persistencia:** `ArchivoManager` registra el log diario y el resultado final en archivos de texto.

> **Conclusión Técnica:** La simulación demuestra que 3 técnicos al día son insuficientes para 100 equipos bajo este modelo de degradación, provocando un aumento del riesgo global de "BAJO" a "ALTO" hacia el día 28. Este comportamiento es realista y valida la precisión del simulador.

---
*Documento generado para la Escuela de Informática, UNA.*