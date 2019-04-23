#ifndef MAIN_INCLUDE_WIFI_H_
#define MAIN_INCLUDE_WIFI_H_

#include "includes.h"

void wifi_init(void);
esp_err_t wifi_event_handler(void *ctx, system_event_t *event);

#endif /* MAIN_INCLUDE_WIFI_H_ */
