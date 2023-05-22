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
#include "fantome.h"
#include "GPIO.h"
#include <time.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------
Function prototypes
----------------------------------------------------------------------------*/
void Enable_GPIO(void);
void Init_GPIO(void);

/*----------------------------------------------------------------------------
Global variables
----------------------------------------------------------------------------*/
int xBoule = 0;
int yBoule = 0;
int menu = 1;
int oldXBoule=0;
int oldYBoule=0;
bool alreadyGenerate = false;
int xGhost1;
int yGhost1;
int xPowerUp;
int yPowerUp;

/*----------------------------------------------------------------------------
Main program
----------------------------------------------------------------------------*/
int main(void) {
Enable_GPIO(); // Enable GPIO ports
Init_GPIO(); // Initialize GPIO ports
	
// Initialize random engine
//srand(time(NULL)); 
	
// Initialize the LCD
initGLCD();
	
// Display the home screen menu
displayMenu(JOUER);
while (!refreshMenu());

// Configure and start the timer
cfgTimer1();
clearScreenGLCD();

xGhost1 = rand()%(GLCD_WIDTH-LARGEUR_BOULE);
yGhost1 = rand()%(GLCD_HEIGHT-HAUTEUR_BOULE);
	
xPowerUp = rand()%(GLCD_WIDTH-LARGEUR_BOULE);
yPowerUp = rand()%(GLCD_HEIGHT-HAUTEUR_BOULE);
	
while (1) 
	{
		
		GLCD_DrawBitmap(xBoule, yBoule,
		LARGEUR_BOULE, HAUTEUR_BOULE,
		(const unsigned char*)bmpBoule);
		
		GLCD_DrawBitmap(xGhost1, yGhost1,
		LARGEUR_BOULE, HAUTEUR_BOULE,
		(const unsigned char*)bmpfantomepacmanpng);
		
		if (rand()%2 && !alreadyGenerate)
		{
			GLCD_DrawBitmap(rand()%31*10, rand()%23*10,
			LARGEUR_BOULE, HAUTEUR_BOULE,
			(const unsigned char*)bmpPowerUp);
			
			alreadyGenerate = true;
		}
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