/**
  ******************************************************************************************************************
  * @file    main.c 
  * @author  IUT Informatique La Rochelle
  * @version v1.0
  * @date    2023
  * @modification	
  * @brief   
  ******************************************************************************************************************/
#include "GLCD.h"
#include "GLCD_Config.h"
#include "ext_globales.h"
#include "homescreen.h"
#include "boule.h"
#include "timers.h"
#include "menu.h"
#include "GPIO.h"

/*----------------------------------------------------------------------------
Function prototypes
----------------------------------------------------------------------------*/
void Enable_GPIO(void);
void Init_GPIO(void);

/*----------------------------------------------------------------------------
Global variables
----------------------------------------------------------------------------*/
int xBoule = GLCD_SIZE_X/2;
int yBoule = GLCD_SIZE_Y/2;
int menu = 1;
int oldXBoule=0;
int oldYBoule=0;
char dir;

/*----------------------------------------------------------------------------
Main program
----------------------------------------------------------------------------*/
int main(void) {
Enable_GPIO(); // Enable GPIO ports
Init_GPIO(); // Initialize GPIO ports

// Initialize the LCD
initGLCD();

// Display the home screen menu
displayMenu(JOUER);
while (!refreshMenu());

// Configure and start the timer
cfgTimer1();
clearScreenGLCD();

while (1) 
	{
		GLCD_DrawBitmap(oldXBoule, oldYBoule,
		LARGEUR_BOULE, HAUTEUR_BOULE,
		(const unsigned char*)bmpEraseBoule);
		
		GLCD_DrawBitmap(xBoule, yBoule,
		LARGEUR_BOULE, HAUTEUR_BOULE,
		(const unsigned char*)bmpBoule);
		
		GLCD_DrawBitmap(200, 200,
		LARGEUR_BOULE, HAUTEUR_BOULE,
		(const unsigned char*)bmpPowerUp);
	}
}









/*----------------------------------------------------------------------------
Enable GPIO ports
----------------------------------------------------------------------------*/
void Enable_GPIO(void) {
RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
RCC->APB2ENR |= (1 << 5); // Enable GPIOD clock
}

/*----------------------------------------------------------------------------
Initialize GPIO ports
----------------------------------------------------------------------------*/
void Init_GPIO(void) {
GPIOB->CRH = 0x33333333; // Set mode=0b11 (50MHz) and CNF=0b00 (Push-Pull) for PB8 to PB15 (Leds 8 to 15)
GPIOG->CRH |= 0x44400000; // Set mode=0b00 (Input Mode) and CNF=0b01 (Floating Input) for PG15, PG14, and PG13
GPIOG->CRL |= 0x40000000; // Set mode=0b00 (Input Mode) and CNF=0b01 (Floating Input) for PG7
GPIOD->CRL |= 0x00004000; // Set mode=0b00 (Input Mode) and CNF=0b01 (Floating Input) for PD3
}