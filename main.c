#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO 2 //wbudowana dioda

void app_main(){

    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT); //ustawienie pinu na wyjscie

    while(1) {                                  //nieskonczona petla
	    printf("Turning off the LED\n");        //przeslanie wiadomosci 
        gpio_set_level(BLINK_GPIO, 0);          //ustawienie stanu nieskiego
        vTaskDelay(1000 / portTICK_PERIOD_MS);  //opoznienie 1000ms
	    printf("Turning on the LED\n");         //przeslanie wiadomosci
        gpio_set_level(BLINK_GPIO, 1);          //ustawienie stanu wysokiego
        vTaskDelay(1000 / portTICK_PERIOD_MS);  //opoznienie 1000ms
    }
}