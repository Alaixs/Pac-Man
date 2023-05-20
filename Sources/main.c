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

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/

void Enable_GPIO(void);
void Init_GPIO(void);

// Initialisation des variables externes
int xBoule = 0;
int yBoule = 0;
int menu = 1;
int oldXBoule;
int oldYBoule;


int main (void){
	Enable_GPIO(); // Mise en service des ports
	Init_GPIO();  // Initialisation des Ports
	
	//initalisation du LCD
	initGLCD();
	GLCD_DrawBitmap(170,200,
									LARGEUR_BOULE, HAUTEUR_BOULE,
									(const unsigned char *)bmpBoule);
	
	
	//lancement du timer
	cfgTimer1();
	
	
  //affichage de l'�cran d'accueil

	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_SetFont(&GLCD_Font_16x24);
	GLCD_DrawChar(125,100,'P');
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_DrawChar(138,100,'A');
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_DrawChar(155,100,'C');
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_DrawChar(170,100,'M');
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_DrawChar(185,100,'A');
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
	GLCD_DrawChar(200,100,'N');
	GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);

  //affichage de l'�cran d'accueil
	while (1)// boucle de jeu
	{
		while(!menu) // boucle d'affichage en jeu
		{
			GLCD_DrawBitmap(xBoule,yBoule,
											LARGEUR_BOULE, HAUTEUR_BOULE,
											(const unsigned char *)bmpBoule);
			GLCD_DrawBitmap(oldXBoule,oldYBoule,
											LARGEUR_BOULE, HAUTEUR_BOULE,
											(const unsigned char *)bmpEraseBoule);
		}
	}
}
               
void Enable_GPIO(void){
	RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
	RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
	RCC->APB2ENR |= (1 << 5); // Enable GPIOD clock
}

void Init_GPIO(void){
	GPIOB->CRH = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull) pour PB8 � PB15 (Leds 8 � 15)
	GPIOG->CRH |= 0x44400000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG15, PG14 et PG13
	GPIOG->CRL |= 0x40000000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG7
	GPIOD->CRL |= 0x00004000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PD3
	
}