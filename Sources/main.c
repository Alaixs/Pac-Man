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
#include "boule.h"
#include "timers.h"
#include "menu.h"
#include "fantome.h"
#include "GPIO.h"
#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*----------------------------------------------------------------------------
Function prototypes
----------------------------------------------------------------------------*/
void Enable_GPIO(void);
void Init_GPIO(void);


/*----------------------------------------------------------------------------
Main program
----------------------------------------------------------------------------*/

int main(void) {
    initializeGame();
    displayHomeScreen();
    while (1) {
        if (refreshMenu() == 1) {

					  clearScreenGLCD();
            configureTimer();
        
            while (!isTheEndByF && !isTheEndByTime) {
                updateGame();
            }
						if (isTheEndByF)
							displayGameLosed();
						else if (isTheEndByTime)
							displayGameFinished();
            break;
        }
        else if (refreshMenu() == -1) {
            // L'utilisateur a sélectionné QUITTER
						clearScreenGLCD();
            return 0;  // Terminer le programme
        }
    }

    return 0;
}

/*----------------------------------------------------------------------------
Enable GPIO ports
----------------------------------------------------------------------------*/
void Enable_GPIO(void) {
RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
RCC->APB2ENR |= (1 << 5); // Enable GPIOD clock
}

/*----------------------------------------------------------------------------
Initialize GPIO ports
----------------------------------------------------------------------------*/
void Init_GPIO(void) {
GPIOB->CRH = 0x33333333; // Set mode=0b11 (50MHz) and CNF=0b00 (Push-Pull) for PB8 to PB15 (Leds 8 to 15)
GPIOG->CRH |= 0x44400000; // Set mode=0b00 (Input Mode) and CNF=0b01 (Floating Input) for PG15, PG14, and PG13
GPIOG->CRL |= 0x40000000; // Set mode=0b00 (Input Mode) and CNF=0b01 (Floating Input) for PG7
GPIOD->CRL |= 0x00004000; // Set mode=0b00 (Input Mode) and CNF=0b01 (Floating Input) for PD3
}
