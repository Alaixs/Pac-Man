/**
  ******************************************************************************************************************
  * @file    menu.c
  * @author  IUT Informatique La Rochelle
  * @version v1.0
  * @date    2023
  * @modification	
  * @brief   Gestion du menu
  ******************************************************************************************************************/

#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "GLCD.h"

#include "menu.h"
#include "ext_globales.h"
#include "GPIO.h"

#include "stdio.h"

//affichage de l'écran d'accueil
void displayMenu(MenuSelected menuSelected)
{	
	clearScreenGLCD();	
	displayLogo();
	
	if(menuSelected==JOUER)
	{ 
		GLCD_SetForegroundColor(GLCD_COLOR_RED);
		GLCD_DrawString  (100, 100,"Jouer");
		GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
		GLCD_DrawString (100, 140, "Quitter");
	}
	else if(menuSelected==QUITTER)
	{ 
		GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
		GLCD_DrawString (100, 100,"Jouer");
		GLCD_SetForegroundColor(GLCD_COLOR_RED);
		GLCD_DrawString (100, 140,"Quitter");
	}
}

int refreshMenu(void) {
    static MenuSelected menuSelected = JOUER;

    if (joytickUpPressed() && menuSelected == QUITTER) {
        menuSelected = JOUER;
        displayMenu(menuSelected);
    }
    if (joytickDownPressed() && menuSelected == JOUER) {
        menuSelected = QUITTER;
        displayMenu(menuSelected);
    }

    if (userButtonPressed() && menuSelected == JOUER) {
        return 1;
    }
    else if (userButtonPressed() && menuSelected == QUITTER) {
        return -1;
    }
    return 0;
}


void displayLogo(void)
{ 
	GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
	GLCD_SetForegroundColor(GLCD_COLOR_YELLOW);
	GLCD_SetFont(&GLCD_Font_16x24);
	GLCD_DrawString  (90, 5,"PAC-MAN");
}

void displayGameLosed(void)
{
    char chaine[20];
    clearScreenGLCD();
    displayLogo();
    
    GLCD_SetForegroundColor(GLCD_COLOR_RED);
    GLCD_DrawString  (20, 100,"Perdu !");
    GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
    sprintf(chaine,"Votre score : %d",points);
    GLCD_DrawString (20, 140, chaine);
    
    while(!userButtonPressed());
}

void displayGameFinished(void)
{
      char chaine[20];
    clearScreenGLCD();
    displayLogo();

    GLCD_SetForegroundColor(GLCD_COLOR_YELLOW);
    GLCD_DrawString  (20, 100,"Temps ecoule !");
    GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
    sprintf(chaine,"Votre score : %d",points);
    GLCD_DrawString (20, 140, chaine);

    while(!userButtonPressed());
}
