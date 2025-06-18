#include "led_driver.h"

// Inicializa el LED configurándolo como salida y apagándolo
// Esta función es llamada una vez al inicio para configurar el LED
// Parámetros:
//   - led: puntero a la estructura que contiene la configuración del LED
void led_init(led_handle_t *led) {
    // HAL_GPIO_WritePin es una función de la HAL (Hardware Abstraction Layer) de STM32
    // Escribe el valor GPIO_PIN_RESET (0) en el pin especificado
    // Esto apaga el LED ya que en la mayoría de las placas los LEDs están conectados
    // con el cátodo a GND y el ánodo a través de una resistencia al pin
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
}

// Enciende el LED
// Parámetros:
//   - led: puntero a la estructura que contiene la configuración del LED
void led_on(led_handle_t *led) {
    // Escribe GPIO_PIN_SET (1) en el pin, lo que enciende el LED
    // En la mayoría de las placas STM32, GPIO_PIN_SET significa nivel alto (3.3V)
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_SET);
}

// Apaga el LED
// Parámetros:
//   - led: puntero a la estructura que contiene la configuración del LED
void led_off(led_handle_t *led) {
    // Escribe GPIO_PIN_RESET (0) en el pin, lo que apaga el LED
    // GPIO_PIN_RESET significa nivel bajo (0V)
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
}

// Cambia el estado actual del LED
// Si está encendido lo apaga, si está apagado lo enciende
// Parámetros:
//   - led: puntero a la estructura que contiene la configuración del LED
void led_toggle(led_handle_t *led) {
    // HAL_GPIO_TogglePin es una función de la HAL que invierte el estado actual del pin
    // Si el pin está en alto, lo pone en bajo y viceversa
    HAL_GPIO_TogglePin(led->port, led->pin);
}
