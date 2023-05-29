/**
  ******************************************************************************************************************
  * @file    menu.h 
  * @author  IUT Informatique La Rochelle
  * @version v1.0
  * @date    2023
  * @modification	
  * @brief   Gestion du menu
  ******************************************************************************************************************/
	
#ifndef __MENU_H
#define __MENU_H

typedef enum {JOUER, QUITTER} MenuSelected;

void displayMenu(MenuSelected menuSelected);
void displayLogo(void);
int refreshMenu(void);
void displayGameLosed(void);
void displayGameFinished(void);

#endif
