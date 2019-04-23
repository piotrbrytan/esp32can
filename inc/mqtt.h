#ifndef MAIN_INCLUDE_MQTT_H_
#define MAIN_INCLUDE_MQTT_H_

#include "includes.h"

esp_err_t mqtt_event_handler(esp_mqtt_event_handle_t event);
void mqtt_app_start(void);

#endif /* MAIN_INCLUDE_MQTT_H_ */
