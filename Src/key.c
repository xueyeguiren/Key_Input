#include "key.h"

//每10ms扫描一次按键，以下控制量单位为10ms
#define KEY_DELAY 5	//延时

volatile uint8_t key_scan_flag = 0;

static uint8_t cn = 0;
static uint16_t new_value = 0;
static uint16_t old_value = 0;

//按键的引脚输入
uint16_t get_key_input(void)
{
	//PE4~PE2 读取IO输入【根据实际电路修改】
	return (GPIOE->IDR & (0x001C));
}

//按键扫描
uint8_t key_scan(void)
{
	volatile uint16_t val_read;

	key_scan_flag=0;
	val_read = get_key_input();

	if(0x001C != val_read){	//如果有按键按下
		if(0 == cn){
			old_value = val_read;
		}
		if(cn <= KEY_DELAY){
			cn++;
		}
		if(KEY_DELAY == cn){
			new_value = val_read;
			if(new_value == old_value){
				switch(new_value){
				case 0x000C:
					return KEY_0_PRESS;
				case 0x0014:
					return KEY_1_PRESS;
				case 0x0018:
					return KEY_2_PRESS;
				default:
					return KEY_NO_ONE;
				}
			}
		}
	}
}
