#include "ring_buffer.h"

// Inicializa un buffer circular
// Parámetros:
//   - rb: puntero al buffer circular a inicializar
//   - buffer: puntero al array que se usará como almacenamiento
//   - capacity: tamaño máximo del buffer
void ring_buffer_init(ring_buffer_t *rb, uint8_t *buffer, uint16_t capacity)
{
    // Asigna el buffer y su capacidad
    rb->buffer = buffer;
    rb->capacity = capacity;
    
    // Inicializa los índices de lectura y escritura
    rb->head = 0;
    rb->tail = 0;
}

// Escribe un byte en el buffer circular
// Parámetros:
//   - rb: puntero al buffer circular
//   - data: byte a escribir
// Retorna: true si se pudo escribir, false si el buffer está lleno
bool ring_buffer_write(ring_buffer_t *rb, uint8_t data)
{
    // Verifica si el buffer está lleno
    if (ring_buffer_is_full(rb)) {
        return false;  // No se puede escribir si está lleno
    }

    // Escribe el dato en la posición actual del head
    rb->buffer[rb->head] = data;
    
    // Avanza el índice de escritura, volviendo al inicio si llega al final
    rb->head = (rb->head + 1) % rb->capacity;
    
    return true;
}

// Lee un byte del buffer circular
// Parámetros:
//   - rb: puntero al buffer circular
//   - data: puntero donde se guardará el byte leído
// Retorna: true si se pudo leer, false si el buffer está vacío
bool ring_buffer_read(ring_buffer_t *rb, uint8_t *data)
{
    // Verifica si el buffer está vacío
    if (ring_buffer_is_empty(rb)) {
        return false;  // No se puede leer si está vacío
    }

    // Lee el dato de la posición actual del tail
    *data = rb->buffer[rb->tail];
    
    // Avanza el índice de lectura, volviendo al inicio si llega al final
    rb->tail = (rb->tail + 1) % rb->capacity;
    
    return true;
}

// Retorna la cantidad de bytes almacenados en el buffer
// Parámetros:
//   - rb: puntero al buffer circular
// Retorna: número de bytes almacenados
uint16_t ring_buffer_count(ring_buffer_t *rb)
{
    // Si head es mayor que tail, el número de elementos es la diferencia
    if (rb->head >= rb->tail) {
        return rb->head - rb->tail;
    }
    // Si tail es mayor que head, el número de elementos es la capacidad menos la diferencia
    return rb->capacity - (rb->tail - rb->head);
}

// Verifica si el buffer está vacío
// Parámetros:
//   - rb: puntero al buffer circular
// Retorna: true si está vacío, false si contiene datos
bool ring_buffer_is_empty(ring_buffer_t *rb)
{
    // El buffer está vacío cuando head y tail están en la misma posición
    return rb->head == rb->tail;
}

// Verifica si el buffer está lleno
// Parámetros:
//   - rb: puntero al buffer circular
// Retorna: true si está lleno, false si hay espacio disponible
bool ring_buffer_is_full(ring_buffer_t *rb)
{
    // El buffer está lleno cuando el siguiente elemento después de head
    // sería igual a tail
    return ((rb->head + 1) % rb->capacity) == rb->tail;
}

// Vacía el buffer circular
// Parámetros:
//   - rb: puntero al buffer circular
void ring_buffer_flush(ring_buffer_t *rb)
{
    // Reinicia los índices de lectura y escritura
    rb->head = 0;
    rb->tail = 0;
}