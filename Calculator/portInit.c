//All port initializations
//Ports A2 A3 B2 B3 B6 B7 D0-3 E1-4

#include "portInit.h"

void Ports_Init(void){	
	volatile unsigned long delay1;
  SYSCTL_RCGC2_R |= 0x00000001;     // 1) A clock
  delay1 = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTA_LOCK_R = 0x4C4F434B;   // 2) unlock changes to CR
  GPIO_PORTA_CR_R = 0x0C;           // unlock changes to pins  for following registers     
  GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTA_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTA_DIR_R = 0x0C;          // 5) PA2,PA3 output
  GPIO_PORTA_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTA_DEN_R = 0x0C;          // 7) enable digital pins PA2, PA3   

	volatile unsigned long delay2;
  SYSCTL_RCGC2_R |= 0x00000002;     // 1) B clock
  delay2 = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTB_LOCK_R = 0x4C4F434B;   // 2) unlock changes to CR
  GPIO_PORTB_CR_R = 0xCC;           // unlock changes to pins  for following registers     
  GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R = 0xCC;          // 5) PB2,PB3 output
  GPIO_PORTB_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTB_DEN_R = 0xCC;          // 7) enable digital pins PB2, PB3, PB6, PB7 

	volatile unsigned long delay3;
	SYSCTL_RCGC2_R |= 0x08;
	delay3 = SYSCTL_RCGC2_R;
	GPIO_PORTD_AMSEL_R &= 0x00;
	GPIO_PORTD_PCTL_R &= 0x00;
	GPIO_PORTD_DIR_R |= 0x0F;
	GPIO_PORTD_AFSEL_R &= 0x00;
	GPIO_PORTD_PUR_R |= ~0x0F;
	GPIO_PORTD_DEN_R |= 0x0F;
	
/*
  SYSCTL_RCGC2_R |= 0x00000008;     // 1) D clock
  delay3 = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTD_LOCK_R = 0x4C4F434B;   // 2) unlock changes to CR
  GPIO_PORTD_CR_R = 0x0F;           // unlock changes to pins  for following registers     
  GPIO_PORTD_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTD_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTD_DIR_R = 0x0F;          // 5) PD0-3 output
  GPIO_PORTD_AFSEL_R = 0x00;        // 6) no alternate function
  //GPIO_PORTD_PUR_R = 0x0F;          // 4 pullup resistors
  GPIO_PORTD_DEN_R = 0x0F;          // 7) enable digital pins PD0-3    
*/

	volatile unsigned long delay4;
	SYSCTL_RCGC2_R |= 0x00000010;
	delay4 = SYSCTL_RCGC2_R;
	GPIO_PORTE_AMSEL_R &= 0x00;
	GPIO_PORTE_PCTL_R &= 0x00000000;
	GPIO_PORTE_DIR_R &= ~0x0F;
	GPIO_PORTE_AFSEL_R &= 0x00;
	GPIO_PORTE_PDR_R |= 0x0F;
	GPIO_PORTE_ODR_R |= 0x0F;
	GPIO_PORTE_DEN_R |= 0x0F;
	GPIO_PORTE_IS_R &= ~0x0F;     	
	GPIO_PORTE_IBE_R &= ~0x0F;    		
	GPIO_PORTE_IEV_R |= 0x0F;    		

/*
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) E clock
  delay4 = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTE_LOCK_R = 0x4C4F434B;   // 2) unlock changes to CR
  GPIO_PORTE_CR_R = 0x0F;           // unlock changes to pins  for PE0-3
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x00;          // 5) PE0-3 input
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTE_PDR_R = 0x0F;          // 4 pulldown resistors
  GPIO_PORTE_DEN_R = 0x0F;          // 7) enable digital pins PE0-3
*/
}