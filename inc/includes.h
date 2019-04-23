#ifndef MAIN_INCLUDE_INCLUDES_H_
#define MAIN_INCLUDE_INCLUDES_H_

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event_loop.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "nvs_flash.h"

#include "mqtt_client.h"

#include "driver/gpio.h"

#include "configs.h"

#include "sdkconfig.h"

#endif /* MAIN_INCLUDE_INCLUDES_H_ */
