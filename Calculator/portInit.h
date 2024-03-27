#ifndef portInit_h

//CLOCK
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//PORTA
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define E												(*((volatile unsigned long *)0x40004010)) //PA2
#define RS											(*((volatile unsigned long *)0x40004020)) //PA3
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))

//PORTB
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC)) //all pins
#define DB4 										(*((volatile unsigned long *)0x40005010)) //PB2
#define DB5 										(*((volatile unsigned long *)0x40005020)) //PB3
#define DB6 										(*((volatile unsigned long *)0x40005100)) //PB6
#define DB7 										(*((volatile unsigned long *)0x40005200)) //PB7
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))

//PORTD
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_R        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))

//PORTE
#define GPIO_PORTE_DATA_R  			(*((volatile unsigned long *) 0x400243FC))
#define GPIO_PORTE_DIR_R   			(*((volatile unsigned long *) 0x40024400))
#define GPIO_PORTE_AFSEL_R  		(*((volatile unsigned long *) 0x40024420))
#define GPIO_PORTE_PUR_R  			(*((volatile unsigned long *) 0x40024510))
#define GPIO_PORTE_PDR_R				(*((volatile unsigned long *) 0x40024514))
#define GPIO_PORTE_ODR_R				(*((volatile unsigned long *) 0x4002450C))
#define GPIO_PORTE_DEN_R   			(*((volatile unsigned long *) 0x4002451C))
#define GPIO_PORTE_AMSEL_R  		(*((volatile unsigned long *) 0x40024528))
#define GPIO_PORTE_PCTL_R   		(*((volatile unsigned long *) 0x4002452C))
#define GPIO_PORTE_IS_R 				(*((volatile unsigned long *) 0x40024404))
#define GPIO_PORTE_IBE_R 				(*((volatile unsigned long *) 0x40024408))
#define GPIO_PORTE_IEV_R  			(*((volatile unsigned long *) 0x4002440C))
#define GPIO_PORTE_ICR_R 				(*((volatile unsigned long *) 0x4002441C))
#define GPIO_PORTE_IM_R 				(*((volatile unsigned long *) 0x40024410))

void Ports_Init(void);

#endif