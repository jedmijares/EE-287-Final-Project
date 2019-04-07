#include "SysTick.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"

void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;// reload value
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
                              // enable SysTick with core clock and interrupts
  NVIC_ST_CTRL_R = 0x07;
  EnableInterrupts();
}

volatile unsigned long ms = 0;

void SysTick_Handler(void)
{
  //GPIO_PORTF_DATA_R ^= 0x04;       // toggle PF2
  ms = ms + 1;
}

unsigned long millis(void) {return ms;}

void delay1ms(int millis){
	//Use the Systick Timer to generate a 1ms delay
	int i = 0;
	for(i = 0; i < millis; i++)
	{
		//NVIC_ST_RELOAD_R = 80000-1;  // number of counts to wait
		NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
		while((NVIC_ST_CTRL_R&0x00010000)==0){} // wait for count flag
	}
}
