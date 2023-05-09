/*----------------------------------------------------------------------------
 * Name:    Joy_Led.c
 * Purpose: GPIO usage for STM32
 * Version: 2.00
 * Programme de test du joystick du Kit STM32 : Allumer la LED15 si action sur joystick
 * *----------------------------------------------------------------------------*/

#include <stm32f10x.h>        // STM32F10x Library Definitions

#define joydown	3
#define joyup	15
#define joyright	13
#define joyleft	14
#define joyselect	7



#define APPUYE 0


unsigned long joySelect;
unsigned long joyDown;
unsigned long joyUp;
unsigned long joyRight;
unsigned long joyLeft;

void Enable_GPIO(void);
void Init_GPIO(void);

int main (void)
{
	Enable_GPIO(); // Mise en service des ports
	Init_GPIO();  // Initialisation des Ports

	while(1)
	{
		joySelect = GPIOG->IDR & (1<<joyselect);
		joyDown = GPIOD->IDR & (1<<joydown);
		joyUp = GPIOG->IDR & (1<<joyup);
		joyLeft = GPIOG->IDR & (1<<joyleft);    
		joyRight = GPIOG->IDR & (1<<joyright);
		
		if ( joySelect == APPUYE || joyRight == APPUYE || joyUp == APPUYE || joyDown == APPUYE || joyLeft == APPUYE ) 	// Si appui 
			
            GPIOB->ODR = 0x8000;    // LED PB15 ON
        else
            GPIOB->ODR = 0x0000;    // LED PB15 OFF
    }
}	
               
void Enable_GPIO(void)
{
	RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
	RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
	RCC->APB2ENR |= (1 << 5); // Enable GPIOD clock
}

void Init_GPIO(void)
{
	GPIOB->CRH = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull) pour PB8 à PB15 (Leds 8 à 15)
	GPIOG->CRH |= 0x44400000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG15, PG14 et PG13
	GPIOG->CRL |= 0x40000000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG7
	GPIOD->CRL |= 0x00004000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PD3
	
}