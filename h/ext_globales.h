/**
  ******************************************************************************************************************
  * @file    ext_globales.h 
  * @author  IUT Informatique La Rochelle
  * @version v1.1
  * @date    2021
  * @modification	rien pour le moment
  * @brief   déclarations des variables globales
  ******************************************************************************************************************/

#ifndef __EXT_GLOBALES_H
#define __EXT_GLOBALES_H

#include "Board_GLCD.h"

extern GLCD_FONT GLCD_Font_6x8;
extern GLCD_FONT GLCD_Font_16x24;


extern int xBoule;
extern int yBoule;
extern int menu;
extern int oldYBoule;
extern int oldXBoule;
extern int xGhost1;
extern int yGhost1;
extern int oldXGhost1;
extern int oldYGhost1;
extern int xPowerUp;
extern int yPowerUp;
extern int isAlreadyGenerate;
extern int isEated;
extern char direction;
extern int status;

#endif