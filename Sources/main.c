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


#define JOY_DOWN	3
#define JOY_UP	15
#define JOY_RIGHT	13
#define JOY_LEFT	14
#define JOY_SELECT	7
	
#define APPUYE 0x0000

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
unsigned long joySelect;
unsigned long joyDown;
unsigned long joyUp;
unsigned long joyRight;
unsigned long joyLeft;

void Enable_GPIO(void);
void Init_GPIO(void);

int main (void){
	Enable_GPIO(); // Mise en service des ports
	Init_GPIO();  // Initialisation des Ports
	
	//initalisation du LCD
	initGLCD();

  //affichage de l'�cran d'accueil

	
		GLCD_DrawBitmap ( 100, 100 ,
						 LARGEUR_HOMESCREEN , HAUTEUR_HOMESCREEN,
						 (unsigned char *) bmpHomescreen);
	
	
	while(1)
	{		
		  joySelect = GPIOG->IDR & (1<<JOY_SELECT);
		  joyDown = GPIOD->IDR & (1<<JOY_DOWN);
		  joyUp = GPIOG->IDR & (1<<JOY_UP);
		  joyLeft = GPIOG->IDR & (1<<JOY_LEFT);    
		  joyRight = GPIOG->IDR & (1<<JOY_RIGHT);
		
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