/**
  ******************************************************************************************************************
  * @file    timers.c 
  * @brief   Configuration des timers
  * @version v2.0
  * @date    2021
  * @modification  Rien pour le moment
  ******************************************************************************************************************/

#include "stm32f10x.h"                  /* STM32F10x.h definitions            */
#include "GLCD_Config.h"
#include "GLCD.h"
#include "boule.h"
#include "ext_globales.h"
#include "timers.h"
#include "GPIO.h"
#include <stdlib.h>

#define SETENA0 *(volatile unsigned long *)0xE000E100
#define TIM1_UP_IRQChannel (1 << 25)

unsigned long joySelect;
unsigned long joyDown;
unsigned long joyUp;
unsigned long joyRight;
unsigned long joyLeft;

char direction;
int status;
int sensFantome;

/**
  * @brief  Configuration du timer1 pour générer des interruptions
  * @param  None
  * @retval None
  */
void cfgTimer1(void)
{
    RCC->APB2ENR |= (1 << 11);
    TIM1->PSC = 450;
    TIM1->ARR = 2000;
    TIM1->DIER |= UIE;
    TIM1->CR1 |= 0x0001;
    SETENA0 |= TIM1_UP_IRQChannel;
}

void TIM1_UP_TIM10_IRQHandler(void)
{
    if (TIM1->SR & UIF)
    {
        joySelect = GPIOG->IDR & (1 << JOY_SELECT);
        joyDown = GPIOD->IDR & (1 << JOY_DOWN);
        joyUp = GPIOG->IDR & (1 << JOY_UP);
        joyLeft = GPIOG->IDR & (1 << JOY_LEFT);
        joyRight = GPIOG->IDR & (1 << JOY_RIGHT);

        TIM1->SR &= ~UIF;

			  // Gestion du temps pour move skin
        status += 1;

        if (status >= 20)
        {
            status = 0;
        }

        // Changement de direction en fonction de la direction du joystick
        if (joyLeft == APPUYE)
        {
            direction = 'L';
        }
        else if (joyUp == APPUYE)
        {
            direction = 'U';
        }
        else if (joyDown == APPUYE)
        {
            direction = 'D';
        }
        else if (joyRight == APPUYE)
        {
            direction = 'R';
        }

        // Modification des coordonnées en fonction de la direction sélectionnée
        if (direction == 'D')
        {
            if (yBoule < GLCD_HEIGHT - HAUTEUR_BOULE)
            {
                yBoule += 1;
            }
        }
        else if (direction == 'U')
        {
            if (yBoule > 0)
            {
                yBoule -= 1;
            }
        }
        else if (direction == 'L')
        {
            if (xBoule > 0)
            {
                xBoule -= 1;
            }
        }
        else if (direction == 'R')
        {
            if (xBoule < GLCD_WIDTH - LARGEUR_BOULE)
            {
                xBoule += 1;
            }
        }

				// modification des coordonnées des fantomes
				// Move fantome 1
				if (yGhost1 < yPowerUp)
				{
					yGhost1++;
				}
				else if (yGhost1 > yPowerUp)
				{
					yGhost1--;
				}
				else if (xGhost1 < xPowerUp)
				{
					xGhost1++;
				}
				else if (xGhost1 > xPowerUp)
				{
					xGhost1--;
				}
				
				// Move fantome 2
				if (yGhost2 < GLCD_HEIGHT - LARGEUR_BOULE && xGhost2 == 0)
					yGhost2++;
				else if (yGhost2 == GLCD_HEIGHT - LARGEUR_BOULE && xGhost2 < GLCD_WIDTH - HAUTEUR_BOULE)
					xGhost2++;
				else if (xGhost2 == GLCD_WIDTH - HAUTEUR_BOULE && yGhost2 > 0)
					yGhost2--;
				else if (yGhost2 == 0 && xGhost2 > 0)
					xGhost2--;
				
				// gestion des touchés
        if (xPowerUp <= xBoule + LARGEUR_BOULE && xBoule <= xPowerUp + LARGEUR_BOULE && yPowerUp <= yBoule + HAUTEUR_BOULE && yBoule <= yPowerUp + HAUTEUR_BOULE)
        {
					isEated = true;
        }

        if ((xGhost1 <= xPowerUp + LARGEUR_BOULE && xPowerUp <= xGhost1 + LARGEUR_BOULE && yGhost1 <= yPowerUp + HAUTEUR_BOULE && yPowerUp <= yGhost1 + HAUTEUR_BOULE))
        {
            isEated = true;
        }
				
    }
}
