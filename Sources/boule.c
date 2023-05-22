/**
  ******************************************************************************************************************
  * @file    boule.c 
  * @author  PCo     IUT Informatique La Rochelle
  * @version v1.2
  * @date    2021
  * @modification
  * @brief   définitions pour la description du bitmap d'une boule
  ******************************************************************************************************************/

#include "ext_globales.h"
#include "GLCD_Config.h"
#include "boule.h"


const unsigned short bmpBoule[HAUTEUR_BOULE*LARGEUR_BOULE]={
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,0x0000,
	0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,
	0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,
	0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,
	0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,
	0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,
	0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,
	0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,
	0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,
	0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,
	0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,
	0x0000,0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0xFF80,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
}; 


const unsigned short bmpPowerUp[HAUTEUR_BOULE*LARGEUR_BOULE]={
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0xA000,0xB000,0xA000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xA000,0xB000,0xA000,0x0000,0x0000,
	0x0000,0xA000,0xE800,0xF800,0xE800,0xA000,0x0000,0x0000,0x0000,0x0000,0xA000,0xE800,0xF800,0xE800,0xA000,0x0000,
	0x0000,0xB000,0xF800,0xF800,0xF800,0xB000,0x0000,0x0000,0x0000,0x0000,0xB000,0xF800,0xF800,0xF800,0xB000,0x0000,
	0x0000,0xA000,0xE800,0xF800,0xE800,0xA000,0x0000,0x0000,0x0000,0x0000,0xB000,0xF800,0xF800,0xE800,0xA000,0x0000,
	0x0000,0x0000,0xA000,0xB000,0xA800,0x0000,0x0000,0x0000,0x0000,0x0000,0x2C60,0xB000,0xB000,0xA000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0462,0x0000,0x0000,0x0000,0x0000,0x0462,0x0462,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0462,0x0462,0x0000,0x0000,0x0462,0x0462,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0462,0x0462,0x0000,0x0462,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x04E2,0x04E2,0x0462,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0482,0x04E2,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0462,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0462,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
};
