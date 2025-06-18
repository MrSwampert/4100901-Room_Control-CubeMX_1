#ifndef LED_DRIVER_H
#define LED_DRIVER_H

// Incluye el tipo uint8_t, uint16_t, etc.
#include <stdint.h>
// Incluye las definiciones de GPIO y HAL necesarias para el control del LED
#include "main.h"

// Estructura que define el controlador de LED
// Esta estructura contiene toda la información necesaria para controlar un LED específico
typedef struct {
    GPIO_TypeDef *port;  // Puntero al puerto GPIO donde está conectado el LED (ej: GPIOA, GPIOB, etc.)
    uint16_t pin;        // Número del pin específico donde está conectado el LED (ej: GPIO_PIN_5)
} led_handle_t;

// API pública - Funciones disponibles para el usuario

// Inicializa el LED configurándolo como salida y apagándolo
// Parámetro: puntero a la estructura led_handle_t que contiene la configuración del LED
void led_init(led_handle_t *led);

// Enciende el LED
// Parámetro: puntero a la estructura led_handle_t que contiene la configuración del LED
void led_on(led_handle_t *led);

// Apaga el LED
// Parámetro: puntero a la estructura led_handle_t que contiene la configuración del LED
void led_off(led_handle_t *led);

// Cambia el estado del LED (si está encendido lo apaga, si está apagado lo enciende)
// Parámetro: puntero a la estructura led_handle_t que contiene la configuración del LED
void led_toggle(led_handle_t *led);

#endif // LED_DRIVER_H
