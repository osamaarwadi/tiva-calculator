#include "lcd.h"
#include "clockinit.h"
#include "portInit.h"
#include "string.h"

void ENPulse(void){
	GPIO_PORTA_DATA_R |= 0x04; //E
	SysTick_Wait(36); //450 ns
	GPIO_PORTA_DATA_R &= ~0x04; //E
}

void SendDisplayNibble(char RS_value, char bits){
	if (RS_value == 0){
	GPIO_PORTA_DATA_R &= ~0x08;
	} else {
	GPIO_PORTA_DATA_R |= 0x08;
	}
	if(bits & 0x08){
		GPIO_PORTB_DATA_R |= 0x80;
	} else {
		GPIO_PORTB_DATA_R &= ~0x80;
	}
	if(bits & 0x04){
		GPIO_PORTB_DATA_R |= 0x40;
	} else {
		GPIO_PORTB_DATA_R &= ~0x40;
	}
	if(bits & 0x02){
		GPIO_PORTB_DATA_R |= 0x08;
	} else {
		GPIO_PORTB_DATA_R &= ~0x08;
	}
	if(bits & 0x01){
		GPIO_PORTB_DATA_R |= 0x04;
	} else {
		GPIO_PORTB_DATA_R &= ~0x04;
	}
	ENPulse();
	GPIO_PORTB_DATA_R = 0x00;
	SysTick_Wait_ms(20); // 20 ms
}

void SendDisplayCommand(char bits){
	SysTick_Wait_ms(20); // 20 ms
	SendDisplayNibble(0, ((bits >> 4) & 0x0F));
	SendDisplayNibble(0, bits & 0x0F);
	SysTick_Wait_ms(10); // 10 ms
}

void SendDisplayChar(char bits){
	SysTick_Wait_ms(20); // 20 ms
	SendDisplayNibble(1, ((bits >> 4) & 0x0F));
	SendDisplayNibble(1, bits & 0x0F);
	SysTick_Wait_ms(10); // 10 ms
}

void SendDisplayArr(char chars[]){
	for (int i=0; i < 16; i++){
		if (chars[i] != '\0'){
			SendDisplayChar(chars[i]);
		}
	}
	SysTick_Wait_ms(10); // 10 ms
}


void LCD_Init(void){
	SysTick_Wait_ms(40); // 40ms
	SendDisplayNibble(0, 0x03);
	SysTick_Wait_ms(5); // 4.1 ms
	SendDisplayNibble(0, 0x03);
	SysTick_Wait_ys(100); // 100 ys
	SendDisplayNibble(0, 0x03);
	SysTick_Wait_ys(37); // 37 ys
	SendDisplayNibble(0, 0x02);	
	SendDisplayCommand(0x28);
	SendDisplayCommand(0x0E);
	SendDisplayCommand(0x01);
	SendDisplayCommand(0x06);
	SysTick_Wait_ms(100);
}

void ClearDisplay(void){
	SendDisplayCommand(0x01);
	SysTick_Wait_ys(100);
}