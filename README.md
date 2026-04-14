# my_top - Clon del Comando Unix "top"

## Descripción

Implementación del comando `top` que monitoriza CPU, memoria y procesos en tiempo real. Lee `/proc` del sistema, calcula estadísticas dinámicamente y renderiza interfaz interactiva con ncurses.

---

## Algoritmos Clave

### 1. **Cálculo de CPU % (Diferenciación)**
- **Uso**: Determinar uso actual de CPU
- **Método**: Restar estadísticas anteriores de actuales, calcular deltas
- **Complejidad**: O(1) por iteración
- **Fórmula**: `cpu% = (total_delta - idle_delta) / total_delta * 100`
- **Impacto**: Monitoreo preciso en tiempo real

### 2. **Parsing de /proc**
- **Uso**: Extraer información del sistema (CPU, memoria, procesos)
- **Archivos**: `/proc/stat`, `/proc/meminfo`, `/proc/[pid]/stat`, `/proc/uptime`, `/proc/loadavg`
- **Complejidad**: O(P) donde P=número procesos
- **Impacto**: Obtener datos actualizados del kernel

### 3. **Ordenamiento Dinámico de Procesos**
- **Uso**: Mostrar procesos más pesados primero
- **Algoritmo**: Quicksort típicamente
- **Complejidad**: O(P log P)
- **Impacto**: Top procesos siempre visibles

---

## Módulos

| Archivo | Función |
|---------|---------|
| `main.c` | Loop principal y manejo de entrada |
| `parse_flags.c` | Parsear argumentos (-d, -U, -n) |
| `read_files.c` | Leer archivos /proc |
| `calculs.c` | Cálculos de CPU, memoria |
| `display.c` | Renderizar con ncurses |
| `init.c` | Inicializar estructuras |

---

## Compilación y Ejecución

```bash
make                        # Compilar
./my_top                    # Sin opciones
./my_top -d 2               # Delay 2 segundos
./my_top -U username        # Filtrar por usuario
./my_top -n 10              # 10 iteraciones
./my_top -d 1 -U root -n 50 # Combinado
make clean                  # Limpiar
make fclean                 # Limpiar todo
```

### Flags Disponibles

| Flag | Valor | Descripción |
|------|-------|-------------|
| `-d` | float | Delay entre actualizaciones (segundos) |
| `-U` | string | Filtrar procesos de usuario |
| `-n` | int | Número máximo de frames |
| `-h` | - | Mostrar ayuda |

### Teclas en Ejecución

- **q**: Salir
- **h**: Ayuda
- **E**: Cambiar unidades memoria (B, KB, MB, GB)

---

## Salida Ejemplo

```
my_top - System Monitor
==================================================
Uptime: 15 days, 3 hours, 42 minutes
Load Average: 2.34, 1.78, 1.45
CPU Usage: 15.3%   User: 45%  System: 30%  Idle: 25%

Memory:  Total: 16 GB   Used: 8.5 GB   Available: 7.5 GB
Swap:    Total: 2 GB    Used: 0.5 GB

PID     USER        CPU%    MEM%    COMMAND
1234    manuel      5.2     2.1     firefox
5678    manuel      3.1     1.5     chrome
9012    root        2.5     0.8     systemd
...
==================================================
```

---

## Complejidad

| Operación | Complejidad |
|-----------|------------|
| Leer /proc/stat | O(1) |
| Leer /proc/meminfo | O(1) |
| Leer procesos | O(P) |
| Ordenar procesos | O(P log P) |
| Renderizar | O(P) |
| **Por iteración** | **O(P log P)** |

---

## Habilidades Demostradas

✓ Programación de sistemas (lectura /proc)
✓ Interfaz terminal avanzada (ncurses)
✓ Parsing de archivos del sistema
✓ Cálculos matemáticos precisos (CPU, memoria)
✓ Captura de eventos de teclado
✓ Gestión de memoria dinámica

