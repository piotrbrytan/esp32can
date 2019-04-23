#include "inc/includes.h"
#include "inc/wifi.h"
#include "inc/mqtt.h"

void blinky(void *pvParameter);

//funkcja main
void app_main() {
    esp_log_level_set("*", ESP_LOG_INFO);
    esp_log_level_set("MQTT_CLIENT", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_TCP", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_SSL", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT", ESP_LOG_VERBOSE);
    esp_log_level_set("OUTBOX", ESP_LOG_VERBOSE);

	xTaskCreate(&blinky, "blinky", 512, NULL, 1, NULL);

    nvs_flash_init();
    wifi_init();
    mqtt_app_start();
}

//funkcja migajaca dioda
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
