#include "stm32f10x.h"
#include "app.h"
#include "delay.h"
int main(void)
{
	uint16_t DATA=0;
	char Str[] = {"Hello World!"};
  All_Init();
	USART2_Puts(Str);
  while(1)
  {
		int i = 0;
		while(DATA != USART_ReceiveData(USART2))
		{
			unsigned int BIT=1;
			DATA = USART_ReceiveData(USART2);
			for(i=0;i<16;i++)
			{
				BIT = BIT<<1;
				UART_Put_Num((int)(DATA|BIT));
			}
		}
  }
	return 0;
}
