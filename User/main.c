#include "stm32f10x.h"
#include "app.h"
#include "delay.h"

#define HSB 0xFF00
#define LSB 0x00FF

unsigned char RX_dat;  
int main(void)
{
	uint16_t DATA=0;
	char Str[] = {"Hello World!"};
	unsigned char DATA_L,DATA_H;
  All_Init();
	USART2_Puts(Str);
  while(1)
  {
		int i = 0;
		while(DATA != USART_ReceiveData(USART2))
		{
			unsigned int BIT=1;
			DATA = USART_ReceiveData(USART2); //unsigned short int(Return Parameter) 16bit
			UART_Put_Num(i);
			//DATA_L = (unsigned char)(DATA&LSB);
			//DATA_H = (unsigned char)((DATA&HSB)>>8);
			//USART2_Putc(DATA_L);
			//USART2_Putc(DATA_H);
			USART2_Putc((char)DATA);
//			for(i=0;i<16;i++)
//			{
//				BIT = BIT<<1;
//				UART_Put_Num((int)(DATA|BIT));
//			}
			i++;
		}
  }
	return 0;
}
void USART2_IRQHandler(void)
{                                                      //??????
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)    //????????
    {
			RX_dat=receive_char();
			USART2_Putc(RX_dat);
    }
}