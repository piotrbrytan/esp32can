/**
* @file wifi.h
* @brief Ten plik zawiera delkarację funkcji dotyczących wifi.
*
* @author Piotr Brytan 
*
* @date 31/04/2019
*/
#ifndef MAIN_INCLUDE_WIFI_H_
#define MAIN_INCLUDE_WIFI_H_

#include "includes.h"

/**
 * @brief Inicjalizacja wifi
 *
 * Funkcja ta inicjalizuje wifi, tworzony jest config na podstawie pliku configs.h. 
*/
void wifi_init(void);

/**
 * @brief Event handler wifi
 *
 * Funkcja ta zawiera reakcję na różne eventy jakie mogą być wywołane przy korzystaniu z wifi.
*/
esp_err_t wifi_event_handler(void *ctx, system_event_t *event);

#endif /* MAIN_INCLUDE_WIFI_H_ */
