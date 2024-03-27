#include "clockinit.h"
#include "keypad.h"
#include "lcd.h"
#include "portinit.h"
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos=0;
char key_pressed;
char expression[16];
float ans = 0;
char ans_arr[16];
int out = 0;

int main(void){
	PLL_Init();
	SysTick_Init();
	Ports_Init();
	LCD_Init();
	SysTick_Wait_ms(10);


	while(out==0){
		key_pressed = ReadChar();
		if (key_pressed != 'k'){
		if (key_pressed == 'c'){
			reset_expression(expression);
			ClearDisplay();
			SendDisplayArr(expression);
		}
		else if (key_pressed == '=') {
			add_to_expression(expression, key_pressed);
			ClearDisplay();
			SendDisplayArr(expression);
			ans = calculate(expression);
			SysTick_Wait_ms(1);
			num_to_char(ans, ans_arr);
			SendDisplayCommand(0xC0);
			SendDisplayArr(ans_arr);
		}
		else {
			add_to_expression(expression, key_pressed);
			ClearDisplay();
			SendDisplayArr(expression);
		}
	}
}
}