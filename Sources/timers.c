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
#include <time.h>

#define SETENA0 *(volatile unsigned long *)0xE000E100
#define TIM1_UP_IRQChannel (1 << 25)

unsigned long joySelect;
unsigned long joyDown;
unsigned long joyUp;
unsigned long joyRight;
unsigned long joyLeft;

char direction;
int status;

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
				if (rand()%2 && yGhost1 < GLCD_HEIGHT - LARGEUR_BOULE)
				{
					yGhost1++;
				}
				else if (yGhost1 > 0)
				{
					yGhost1--;
				}
				if (rand()%2 && xGhost1 < GLCD_WIDTH - LARGEUR_BOULE)
				{
					xGhost1++;
				}
				else if (xGhost1 > 0)
				{
					xGhost1--;
				}
				
				// Move fantome 2
				if (rand()%2 && yGhost2 < GLCD_HEIGHT - LARGEUR_BOULE)
				{
					yGhost2++;
				}
				else if (yGhost2 > 0)
				{
					yGhost2--;
				}
				if (rand()%2 && xGhost2 < GLCD_WIDTH - LARGEUR_BOULE)
				{
					xGhost2++;
				}
				else if (xGhost2 > 0)
				{
					xGhost2--;
				}
				
				// Move fantome 3
				if (rand()%2 && yGhost3 < GLCD_HEIGHT - LARGEUR_BOULE)
				{
					yGhost3++;
				}
				else if (yGhost3 > 0)
				{
					yGhost3--;
				}
				if (rand()%2 && xGhost3 < GLCD_WIDTH - LARGEUR_BOULE)
				{
					xGhost3++;
				}
				else if (xGhost3 > 0)
				{
					xGhost3--;
				}
				
				// Move fantome 4
				if (rand()%2 && yGhost4 < GLCD_HEIGHT - LARGEUR_BOULE)
				{
					yGhost4++;
				}
				else if (yGhost4 > 0)
				{
					yGhost4--;
				}
				if (rand()%2 && xGhost4 < GLCD_WIDTH - LARGEUR_BOULE)
				{
					xGhost4++;
				}
				else if (xGhost4 > 0)
				{
					xGhost4--;
				}
				
				// gestion des touchés
        if (xPowerUp <= xBoule + LARGEUR_BOULE && xBoule <= xPowerUp + LARGEUR_BOULE && yPowerUp <= yBoule + HAUTEUR_BOULE && yBoule <= yPowerUp + HAUTEUR_BOULE)
        {
            isEated = true;
        }

        if ((xGhost1 <= xBoule + LARGEUR_BOULE && xBoule <= xGhost1 + LARGEUR_BOULE && yGhost1 <= yBoule + HAUTEUR_BOULE && yBoule <= yGhost1 + HAUTEUR_BOULE) ||
            (xGhost2 <= xBoule + LARGEUR_BOULE && xBoule <= xGhost2 + LARGEUR_BOULE && yGhost2 <= yBoule + HAUTEUR_BOULE && yBoule <= yGhost2 + HAUTEUR_BOULE) ||
            (xGhost3 <= xBoule + LARGEUR_BOULE && xBoule <= xGhost3 + LARGEUR_BOULE && yGhost3 <= yBoule + HAUTEUR_BOULE && yBoule <= yGhost3 + HAUTEUR_BOULE) ||
            (xGhost4 <= xBoule + LARGEUR_BOULE && xBoule <= xGhost4 + LARGEUR_BOULE && yGhost4 <= yBoule + HAUTEUR_BOULE && yBoule <= yGhost4 + HAUTEUR_BOULE))
        {
            isTheEnd = true;
        }
				
    }
}
