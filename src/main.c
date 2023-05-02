/**
  ******************************************************************************************************************
  * @file    main.c 
  * @author IUT Informatique La Rochelle
  * @version v1.1
  * @date    2021
  * @modification	rien pour le moment
  * @brief   template pour piloter l'afficheur LCD des cartes MCBSTM32EXL
  ******************************************************************************************************************/

#include "stm32f10x.h"                  /* STM32F10x.h definitions            */
#include "GLCD_Config.h"
#include "boule.h"
#include "ext_globales.h"
#include "globales.h"
#include "timers.h"

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {

	int xBouleOld;
	
 /* Initialize graphical LCD display   */
  	GLCD_Initialize();                          
  	GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
	  GLCD_SetForegroundColor(GLCD_COLOR_WHITE);

/* Clear graphical LCD display        */
	GLCD_ClearScreen();               
	
	// affichage d'une cellule
	xBoule=5;yBoule=100;
	GLCD_DrawBitmap ( xBoule, yBoule ,
						 LARGEUR_BOULE , HAUTEUR_BOULE,
						 (unsigned char *) bmpBoule);
	xBouleOld=xBoule;
	
	cfgTimer1(); // pour la gestion du deplacement à 1pixel tous les 10ms

	while(1){
		//votre code
	}
}
