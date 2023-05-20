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

#define SETENA0 *(volatile unsigned long *)0xE000E100
#define TIM1_UP_IRQChannel (1<<25)

unsigned long joySelect;
unsigned long joyDown;
unsigned long joyUp;
unsigned long joyRight;
unsigned long joyLeft;

char direction;


/**
  * @brief  configuration du timer1 pour générer des interruptions
  * @param  None
  * @retval None
  */
void cfgTimer1(void)
{
	RCC->APB2ENR |= (1 << 11);
	TIM1->PSC = 450;
	TIM1->ARR = 64000;
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
		
		// Test de si nous sommes dans le menu ou le jeu
		if (menu == 1)
		{
			// Si joystick appuyé clear screen et passage au jeu
			if (joySelect == APPUYE)
			{
				clearScreenGLCD();
				menu = 0;
			}
		}
		// test en mode jeu
		else if (menu == 0)
		{
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
		
			// Modification des coordonnées en fonction de la direction selectionnée
			if (direction == 'U')
			{
				if (yBoule < GLCD_SIZE_Y)
				{
					oldYBoule = yBoule;
					yBoule += 10;
				}
			}
			else if (direction == 'D')
			{
				if (yBoule > 0)
				{
					oldYBoule = yBoule;
					yBoule -= 10;
				}
			}
			else if (direction == 'L')
			{
				if (xBoule > 0)
				{
					oldXBoule = xBoule;
					xBoule -= 10;
				}
			}
			else if (direction == 'R')
			{
				if (xBoule < GLCD_SIZE_X)
				{
					oldXBoule = xBoule;
					xBoule += 10;
				}
			}
		}
  }
}



