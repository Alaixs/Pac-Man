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

extern int xGhost1;
extern int yGhost1;

extern int xGhost2;
extern int yGhost2;

extern int xGhost3;
extern int yGhost3;

extern int xGhost4;
extern int yGhost4;

extern int xPowerUp;
extern int yPowerUp;
extern int isEatedByPM;
extern int isEatedByF;
extern char direction;
extern int status;
extern int points;
extern int isTheEnd;
extern int visibleTime;
extern int variableTime;

#endif
