#ifndef __KEY_H
#define __KEY_H

#include "stm32f4xx_hal.h"

//键值列表
#define KEY_NO_ONE 	0	//无按键
#define KEY_0_PRESS 1	//K0键
#define KEY_1_PRESS 2	//K1键
#define KEY_2_PRESS 3	//K2键

extern volatile uint8_t key_scan_flag;//volatile 每次都从地址读，防止被优化无法读取最新的值
extern uint8_t key_scan(void);

#endif
