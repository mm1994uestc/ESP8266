#include "stm32f10x.h"
#include "app.h"
#include "delay.h"
			   
u8 All_Init(void)
{
	SystemInit(); 
	delay_init(72);
	Usart_Configuration();
	return 1;
}
