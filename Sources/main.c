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


/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main(void){
	
	//initalisation du LCD
	initGLCD();

  //affichage de l'�cran d'accueil

	
		GLCD_DrawBitmap ( 100, 100 ,
						 LARGEUR_HOMESCREEN , HAUTEUR_HOMESCREEN,
						 (unsigned char *) bmpHomescreen);
	
	
	while(1)
	{		

		
	}
}






