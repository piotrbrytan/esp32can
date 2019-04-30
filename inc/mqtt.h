/**
* @file mqtt.h 
* @brief Ten plik zawiera delkarację funkcji dotyczących mqtt 
*
* @author Piotr Brytan 
*
* @date 31/04/2019
*/
#ifndef MAIN_INCLUDE_MQTT_H_
#define MAIN_INCLUDE_MQTT_H_

#include "includes.h"
 
/**
 * @brief Event handler mqtt
 *
 * Funkcja ta zawiera reakcję na różne eventy jakie mogą być wywołane przy korzystaniu z mqtt, reakcje na publish, subscribe itd.
*/
esp_err_t mqtt_event_handler(esp_mqtt_event_handle_t event);

/**
 * @brief Inicjalizacja mqtt
 *
 * Funkcja ta inicjalizuje mqtt, tworzony jest config na podstawie pliku configs.h. 
*/
void mqtt_app_start(void);

#endif /* MAIN_INCLUDE_MQTT_H_ */
