/**
  ******************************************************************************************************************
  * @file    boule.h 
  * @author  IUT Informatique La Rochelle
  * @version v1.2
  * @date    2021
  * @modification	rien pour le moment
  * @brief   declarations pour l'affichage du bitmap de la boule 
  ******************************************************************************************************************/


#ifndef __BOULE_H
#define __BOULE_H

#define HAUTEUR_BOULE	16
#define LARGEUR_BOULE	16

extern const unsigned short bmpBoule[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpErase[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpPowerUp[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bpmBouleOuverteDroite[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bpmBouleOuverteBas[16*16];
extern const unsigned short bpmBouleOuverteGauche[16*16];
extern const unsigned short bpmBouleOuverteHaut[16*16];

#endif
