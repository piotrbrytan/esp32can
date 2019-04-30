#ifndef MAIN_INC_CAN_H_
#define MAIN_INC_CAN_H_

#include "includes.h"

void route_module(uint32_t id);
void can_start_app(void);
void can_stop_app(void);
void can_receive_task(void *arg);
void can_status(void);

#endif /* MAIN_INC_CAN_H_ */
