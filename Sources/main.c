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
#include <stdio.h>

/*----------------------------------------------------------------------------
Function prototypes
----------------------------------------------------------------------------*/
void Enable_GPIO(void);
void Init_GPIO(void);

/*----------------------------------------------------------------------------
Global variables
----------------------------------------------------------------------------*/
int xBoule = GLCD_WIDTH/2;
int yBoule = GLCD_HEIGHT/2;
int menu = 1;
int oldXBoule=0;
int oldYBoule=0;
int xGhost1;
int yGhost1;
int xPowerUp;
int yPowerUp;
int isAlreadyGenerate = false;
int isEated = false;


/*----------------------------------------------------------------------------
Local variables
----------------------------------------------------------------------------*/
int points = 0;
char score[12];


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
		if (status <= 10)
		{
			switch(direction)
			{
				case 'R':
					GLCD_DrawBitmap(xBoule, yBoule,
												LARGEUR_BOULE, HAUTEUR_BOULE,
												(const unsigned char*)bpmBouleOuverteDroite);
					break;
				case 'D':
					GLCD_DrawBitmap(xBoule, yBoule,
												LARGEUR_BOULE, HAUTEUR_BOULE,
												(const unsigned char*)bpmBouleOuverteBas);
					break;
				case 'U':
					GLCD_DrawBitmap(xBoule, yBoule,
												LARGEUR_BOULE, HAUTEUR_BOULE,
												(const unsigned char*)bpmBouleOuverteHaut);
					break;
				case 'L':
					GLCD_DrawBitmap(xBoule, yBoule,
												LARGEUR_BOULE, HAUTEUR_BOULE,
												(const unsigned char*)bpmBouleOuverteGauche);
					break;
				default:
					GLCD_DrawBitmap(xBoule, yBoule,
												LARGEUR_BOULE, HAUTEUR_BOULE,
												(const unsigned char*)bmpBoule);
					break;
			}
		}
		else 
		{
			GLCD_DrawBitmap(xBoule, yBoule,
											LARGEUR_BOULE, HAUTEUR_BOULE,
											(const unsigned char*)bmpBoule);
		}
		
		sprintf(score, "%d", points);	
		GLCD_DrawString  (100, 0,score);
		
		
		
		GLCD_DrawBitmap(xGhost1, yGhost1,
		LARGEUR_BOULE, HAUTEUR_BOULE,
		(const unsigned char*)bmpfantomepacmanpng);
		
		if (isEated)
		{
			GLCD_DrawBitmap(xPowerUp, yPowerUp,
											LARGEUR_BOULE, HAUTEUR_BOULE,
											(const unsigned char*)bmpErase);
			points+=10;
			isAlreadyGenerate = false;
			isEated = false;
		}
		
		if (rand()%2 && !isAlreadyGenerate)
		{
			
			xPowerUp = rand()%(GLCD_WIDTH-LARGEUR_BOULE);
			yPowerUp = rand()%(GLCD_HEIGHT-HAUTEUR_BOULE);
			
			isAlreadyGenerate = true;
		}
			
		GLCD_DrawBitmap(xPowerUp, yPowerUp,
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