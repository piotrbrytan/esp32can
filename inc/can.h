#ifndef MAIN_INC_CAN_H_
#define MAIN_INC_CAN_H_

#include "includes.h"

void can_receive_task(void *arg);
void can_start_app(void);
void can_stop_app(void);

#endif /* MAIN_INC_CAN_H_ */
