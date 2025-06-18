#ifndef RING_BUFFER_H
#define RING_BUFFER_H

// Incluye tipos de datos de tamaño fijo (uint8_t, uint16_t)
#include <stdint.h>
// Incluye el tipo booleano (true/false)
#include <stdbool.h>

// Estructura que define un buffer circular
// Un buffer circular es una estructura de datos que permite almacenar datos
// de manera eficiente en memoria, reutilizando el espacio cuando se llena
typedef struct {
    uint8_t *buffer;    // Puntero al array que almacena los datos
    uint16_t head;      // Índice donde se escribirá el próximo dato
    uint16_t tail;      // Índice donde se leerá el próximo dato
    uint16_t capacity;  // Tamaño máximo del buffer
    bool is_full; // Optional: to track if the buffer is full
} ring_buffer_t;

// Inicializa un buffer circular
// Parámetros:
//   - rb: puntero al buffer circular a inicializar
//   - buffer: puntero al array que se usará como almacenamiento
//   - capacity: tamaño máximo del buffer
void ring_buffer_init(ring_buffer_t *rb, uint8_t *buffer, uint16_t capacity);

// Escribe un byte en el buffer circular
// Parámetros:
//   - rb: puntero al buffer circular
//   - data: byte a escribir
// Retorna: true si se pudo escribir, false si el buffer está lleno
bool ring_buffer_write(ring_buffer_t *rb, uint8_t data);

// Lee un byte del buffer circular
// Parámetros:
//   - rb: puntero al buffer circular
//   - data: puntero donde se guardará el byte leído
// Retorna: true si se pudo leer, false si el buffer está vacío
bool ring_buffer_read(ring_buffer_t *rb, uint8_t *data);

// Retorna la cantidad de bytes almacenados en el buffer
// Parámetros:
//   - rb: puntero al buffer circular
// Retorna: número de bytes almacenados
uint16_t ring_buffer_count(ring_buffer_t *rb);

// Verifica si el buffer está vacío
// Parámetros:
//   - rb: puntero al buffer circular
// Retorna: true si está vacío, false si contiene datos
bool ring_buffer_is_empty(ring_buffer_t *rb);

// Verifica si el buffer está lleno
// Parámetros:
//   - rb: puntero al buffer circular
// Retorna: true si está lleno, false si hay espacio disponible
bool ring_buffer_is_full(ring_buffer_t *rb);

// Vacía el buffer circular
// Parámetros:
//   - rb: puntero al buffer circular
void ring_buffer_flush(ring_buffer_t *rb);

#endif // RING_BUFFER_H
