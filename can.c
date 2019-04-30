#include "inc/includes.h"
#include "inc/can.h"

const can_timing_config_t t_config = CAN_TIMING_CONFIG_125KBITS();
const can_filter_config_t f_config = CAN_FILTER_CONFIG_ACCEPT_ALL();
const can_general_config_t g_config =
		CAN_GENERAL_CONFIG_DEFAULT(CAN_TX_GPIO, CAN_RX_GPIO, CAN_MODE_NORMAL);

void route_module(uint32_t id) {
	switch (id) {
	case 0x555: //LED ON
		gpio_pad_select_gpio(BUILDIN_LED);
		gpio_set_direction(BUILDIN_LED, GPIO_MODE_INPUT_OUTPUT);
		gpio_set_level(BUILDIN_LED, 1);
		break;
	case 0x556: //LED OFF
		gpio_pad_select_gpio(BUILDIN_LED);
		gpio_set_direction(BUILDIN_LED, GPIO_MODE_INPUT_OUTPUT);
		gpio_set_level(BUILDIN_LED, 0);
		break;
	default:
		break;
	}
}

void can_start_app(void) {
	if (can_driver_install(&g_config, &t_config, &f_config) == ESP_OK) {
		printf("Driver installed\n");
	} else {
		printf("Failed to install driver\n");
		return;
	}

	if (can_start() == ESP_OK) {
		printf("Driver started\n");
	} else {
		printf("Failed to start driver\n");
		return;
	}
}

void can_stop_app(void) {
	if (can_stop() == ESP_OK) {
		printf("Driver stopped\n");
	} else {
		printf("Failed to stop driver\n");
		return;
	}

	if (can_driver_uninstall() == ESP_OK) {
		printf("Driver uninstalled\n");
	} else {
		printf("Failed to uninstall driver\n");
		return;
	}
}

void can_receive_task(void *arg) {
	can_message_t message;
	if (can_receive(&message, pdMS_TO_TICKS(100)) == ESP_OK) {
		printf("Message received\n");
	} else {
		printf("Failed to receive message\n");
		return;
	}

	if (message.flags & CAN_MSG_FLAG_EXTD) {
		printf("Message is in Extended Format\n");
	} else {
		printf("Message is in Standard Format\n");
	}
	printf("ID is %d\n", message.identifier);
	if (!(message.flags & CAN_MSG_FLAG_RTR)) {
		for (int i = 0; i < message.data_length_code; i++) {
			printf("Data byte %d = %d\n", i, message.data[i]);
		}
	}

	route_module(message.identifier);
}

void can_status(void) {
	can_message_t message;
	message.identifier = 0x554;
	message.flags = CAN_MSG_FLAG_NONE;
	message.data_length_code = 1;

	if (gpio_get_level(BUILDIN_LED)) {
		message.data[0] = 1;
	} else {
		message.data[0] = 0;
	}

	if (can_transmit(&message, pdMS_TO_TICKS(1000)) == ESP_OK) {
		printf("Message queued for transmission\n");
	} else {
		printf("Failed to queue message for transmission\n");
	}
}
