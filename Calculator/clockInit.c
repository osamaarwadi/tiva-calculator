#include "clockinit.h"

void PLL_Init(void){
	// 0) Use RCC2
	SYSCTL_RCC2_R |= 0x80000000; // USERCC2
	// 1) bypass PLL while initializing
	SYSCTL_RCC2_R |= 0x00000800; // BYPASS2, PLL bypass
	// 2) select the crystal value and oscillator source
	SYSCTL_RCC_R = (SYSCTL_RCC_R &~0x000007C0) // clear XTAL field, bits 10-6
	+ 0x00000540; // 10101, configure for 16 MHz crystal
	SYSCTL_RCC2_R &= ~0x00000070; // configure for main oscillator source
	// 3) activate PLL by clearing PWRDN
	SYSCTL_RCC2_R &= ~0x00002000;
	// 4) set the desired system divider
	SYSCTL_RCC2_R |= 0x40000000; // use 400 MHz PLL
	SYSCTL_RCC2_R = (SYSCTL_RCC2_R&~ 0x1FC00000) // clear system clock divider
	+ (4<<22); // configure for 80 MHz clock
	// 5) wait for the PLL to lock by polling PLLLRIS
	while((SYSCTL_RIS_R&0x00000040)==0){}; // wait for PLLRIS bit
	// 6) enable use of PLL by clearing BYPASS
	SYSCTL_RCC2_R &= ~0x00000800;
}
void SysTick_Init(void)
{
 NVIC_ST_CTRL_R = 0; // disable SysTick during setup
 NVIC_ST_RELOAD_R = 0x00FFFFFF; // maximum reload value
 NVIC_ST_CURRENT_R = 0; // any write to current clears it
 NVIC_ST_CTRL_R = 0x00000005; // enable SysTick with core clock
}

void SysTick_Wait(unsigned long delay){
 NVIC_ST_RELOAD_R = delay-1; // number of counts to wait
 NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
 while((NVIC_ST_CTRL_R&0x00010000)==0)
{ }// wait for count flag

}
void SysTick_Wait_ys(unsigned long delay){
	unsigned long i;
	for( i = 0; i < delay; i++){
		SysTick_Wait(80);
	}
}
void SysTick_Wait_ms(unsigned long delay){
	unsigned long i;
	for( i = 0; i < delay; i++){
		SysTick_Wait_ys(1000);
	}
}
void SysTick_Wait_s(unsigned long delay){
	unsigned long i;
	for( i = 0; i < delay; i++){
		SysTick_Wait_ms(1000);
	}
}
