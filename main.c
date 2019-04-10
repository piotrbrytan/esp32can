#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"

#define BLINK_GPIO 2

void blinky(void *pvParameter) {

	gpio_pad_select_gpio(BLINK_GPIO);
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
	while (1) {
		gpio_set_level(BLINK_GPIO, 0);
		vTaskDelay(1000 / portTICK_RATE_MS);
		gpio_set_level(BLINK_GPIO, 1);
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}

void app_main() {
	xTaskCreate(&blinky, "blinky", 512, NULL, 1, NULL);
}
