// game.c

#include "game.h"
#include "GLCD.h"
#include "GLCD_Config.h"
#include "ext_globales.h"
#include "homescreen.h"
#include "boule.h"
#include "timers.h"
#include "menu.h"
#include "fantome.h"
#include "GPIO.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*----------------------------------------------------------------------------
Function prototypes
----------------------------------------------------------------------------*/
void Enable_GPIO(void);
void Init_GPIO(void);

/*----------------------------------------------------------------------------
Global variables
----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
Global variables
----------------------------------------------------------------------------*/
int xBoule = GLCD_WIDTH/2;
int yBoule = GLCD_HEIGHT/2;
int menu = 1;
int oldXBoule=0;
int oldYBoule=0;

int xGhost1;
int yGhost1;

int xGhost2;
int yGhost2;

int xGhost3;
int yGhost3;

int xGhost4;
int yGhost4;

int xPowerUp;
int yPowerUp;
int isEated = false;
int points = 0;
int isTheEnd = false;


/*----------------------------------------------------------------------------
Local variables
----------------------------------------------------------------------------*/
char score[12];


void initializeGame(void) {
    Enable_GPIO(); // Activer les ports GPIO
    Init_GPIO(); // Initialiser les ports GPIO
	
	    xGhost1 = 0;
    yGhost1 = 0;
    
    xGhost2 = GLCD_WIDTH - LARGEUR_BOULE;
    yGhost2 = 0;
    
    xGhost3 = GLCD_WIDTH - LARGEUR_BOULE;
    yGhost3 = GLCD_HEIGHT - HAUTEUR_BOULE;
    
    xGhost4 = 0;
    yGhost4 = GLCD_HEIGHT - HAUTEUR_BOULE;
	
	  xPowerUp = rand()%(GLCD_WIDTH-LARGEUR_BOULE);
    yPowerUp = rand()%(GLCD_HEIGHT-HAUTEUR_BOULE);

}

void displayHomeScreen(void) {
    initGLCD();  // Initialiser l'écran LCD
    displayMenu(JOUER);  // Afficher le menu principal
}

void configureTimer(void) {
    cfgTimer1();  // Configurer et démarrer le timer
}

void updateGame(void) {
	
	    char score[10];
    // Mettre à jour le jeu (affichage, déplacements, etc.)
    if (status <= 10) {
        switch(direction) {
            case 'R':
                GLCD_DrawBitmap(xBoule, yBoule, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bpmBouleOuverteDroite);
                break;
            case 'D':
                GLCD_DrawBitmap(xBoule, yBoule, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bpmBouleOuverteBas);
                break;
            case 'U':
                GLCD_DrawBitmap(xBoule, yBoule, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bpmBouleOuverteHaut);
                break;
            case 'L':
                GLCD_DrawBitmap(xBoule, yBoule, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bpmBouleOuverteGauche);
                break;
            default:
                GLCD_DrawBitmap(xBoule, yBoule, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpBoule);
                break;
        }
    }
    else {
        GLCD_DrawBitmap(xBoule, yBoule, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpBoule);
    }

    sprintf(score, "%d", points);
    GLCD_DrawString(150, 0, score);

    // Dessiner les autres éléments du jeu (fantômes, bonus, etc.)
    GLCD_DrawBitmap(xGhost1, yGhost1, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpfantomerougepng);
    GLCD_DrawBitmap(xGhost2, yGhost2, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpfantomerosepng);
    GLCD_DrawBitmap(xGhost3, yGhost3, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpfantomebleupng);
    GLCD_DrawBitmap(xGhost4, yGhost4, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpfantomeorangepng);

    if (isEated) {
        GLCD_DrawBitmap(xPowerUp, yPowerUp, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpErase);
        points += 10;
        isEated = false;

        xPowerUp = rand() % (GLCD_WIDTH - LARGEUR_BOULE);
        yPowerUp = rand() % (GLCD_HEIGHT - HAUTEUR_BOULE);
    }

    GLCD_DrawBitmap(xPowerUp, yPowerUp, LARGEUR_BOULE, HAUTEUR_BOULE, (const unsigned char*)bmpPowerUp);
}

void displayGameOver(void) {
	
    displayGameLosed();
}
