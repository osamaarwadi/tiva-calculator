#include "keypad.h"
#include "portInit.h"
#include "clockinit.h"
#include "string.h"

unsigned char ReadChar(void){
	
	int row;
	int col;
	unsigned char chars[4][4] = { {'1','2','3','+'},
											 {'4','5','6','-'},
											 {'7','8','9','*'},
											 {'/','0','c','='} };

		row = -1;
		GPIO_PORTD_DATA_R = 0x00;
		for (int i = 0; i < 4; i++){
			GPIO_PORTD_DATA_R = (0x01 << i);
			SysTick_Wait_ms(5);
			for (int j = 0; j < 4; j++){
				SysTick_Wait_ms(5);
				if ((GPIO_PORTE_DATA_R & 0x0F) & (0x01 << j)){
					row = j;
					col = i;
				 }
			}
		}
		if (row == -1){return 'k'; }
		return chars[row][col];
}