/**
  ******************************************************************************************************************
  * @file    timers.c 
  * @author  IUT Informatique La Rochelle
  * @version v2.0
  * @date    2021
  * @modification	rien pour le moment
  * @brief   configurations des timers
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
#define TIM1_UP_IRQChannel (1<<25)

unsigned long joySelect;
unsigned long joyDown;
unsigned long joyUp;
unsigned long joyRight;
unsigned long joyLeft;

char direction;
int status;


/**
  * @brief  configuration du timer1 pour générer des interruptions
  * @param  None
  * @retval None
  */
void cfgTimer1(void)
{
	RCC->APB2ENR |= (1 << 11);
	TIM1->PSC = 450;
	TIM1->ARR = 1000;
	TIM1->DIER |= UIE;
	TIM1->CR1 |= 0x0001;
	SETENA0 |= TIM1_UP_IRQChannel;
}

void TIM1_UP_TIM10_IRQHandler (void)
{
  if ( TIM1->SR & UIF )
	{ 
		joySelect = GPIOG->IDR & (1<<JOY_SELECT);
		joyDown = GPIOD->IDR & (1<<JOY_DOWN);
		joyUp = GPIOG->IDR & (1<<JOY_UP);
		joyLeft = GPIOG->IDR & (1<<JOY_LEFT);    
		joyRight = GPIOG->IDR & (1<<JOY_RIGHT);
		
    TIM1->SR &= ~UIF;
		// Changement de direction en fonction de la direction du joystick
		
		status+=1;
		
		if (status <=20)
		{
			status=0;
		}
		
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
		
		// Modification des coordonnées en fonction de la direction selectionnée
		if (direction == 'D')
		{
			if (yBoule < GLCD_HEIGHT-HAUTEUR_BOULE)
			{
				oldYBoule = yBoule;
				oldXBoule = xBoule;
				yBoule += 1;
			}
		}
		else if (direction == 'U')
		{
			if (yBoule > 0)
			{
				oldYBoule = yBoule;
				oldXBoule = xBoule;
				yBoule -= 1;
			}
		}
		else if (direction == 'L')
		{
			if (xBoule > 0)
			{
				oldYBoule = yBoule;
				oldXBoule = xBoule;
				xBoule -= 1;
			}
		}
		else if (direction == 'R')
		{
			if (xBoule < GLCD_WIDTH-LARGEUR_BOULE)
			{
				oldYBoule = yBoule;
				oldXBoule = xBoule;
				xBoule += 1;
			}
		}
		
		if (xPowerUp <= xBoule+LARGEUR_BOULE && xBoule <= xPowerUp+LARGEUR_BOULE && yPowerUp <= yBoule+HAUTEUR_BOULE && yBoule <= yPowerUp+HAUTEUR_BOULE)
		{
			isEated = true;
		}
	}
}




