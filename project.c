#include "project.h"
#include <stdio.h>
#include <stdint.h>

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


void SetupHardware()
{
	UartSetup();
//	UartSetup2();
}

void UnlockPins()
{
	//Need to Unlock PF4
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0xFF;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0; 
	
}

int  main(void)
{
		
		uint8_t temp;
    volatile uint32_t ui32Loop;
	
	
	
    // Enable the GPIO port that is used for the on-board LED.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SetupHardware();

		
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    
		}
		
		UnlockPins();		//Function that unlocks certain pins that are needed.
    
    
}

