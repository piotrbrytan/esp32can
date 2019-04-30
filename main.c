#include "inc/includes.h"
//#include "inc/wifi.h"
//#include "inc/mqtt.h"
#include "inc/can.h"

void app_main() {
	can_start_app();

	can_status();
	xTaskCreate(&can_receive_task, "CAN_rx", 4096, NULL, 1, NULL);

	can_stop_app();
}

