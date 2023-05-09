/*----------------------------------------------------------------------------
 * Name:    Bouton_Led.c
 * Purpose: GPIO usage for STM32
 * Version: 2.00
 * *----------------------------------------------------------------------------*/

#include <stm32f10x.h>        // STM32F10x Library Definitions

#define APPUYE 0

unsigned long bouton;

void Enable_GPIO(void);
void Init_GPIO(void);

int main (void)
{
	Enable_GPIO(); // Mise en service des ports
	Init_GPIO();  // Initialisation des Ports

	while(1)
	{
		bouton = GPIOG->IDR & 0x0100;
		if ( bouton == APPUYE ) 	// Si appui sur BP_USER
            GPIOB->ODR = 0x8000;    // LED PB15 ON
        else
            GPIOB->ODR = 0x0000;    // LED PB15 OFF
    }
}	

void Enable_GPIO(void)
{
	RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
	RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
}

void Init_GPIO(void)
{
	GPIOB->CRH = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull) pour PB8 à PB15 (Leds 8 à 15)
	GPIOG->CRH = 0x00000004; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour PG8 (Bouton User)
}
